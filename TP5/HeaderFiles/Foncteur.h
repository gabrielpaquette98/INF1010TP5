/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie - 1894061 & 1899088
*******************************************/

#include <algorithm>
#include "Usager.h"
#include <set>
#include <map>

#pragma once

// TODO : Cr�er le FoncteurEgal
template<typename T>
class FoncteurEgal
{
public:
	FoncteurEgal(T* t) { t_ = t; };
	bool operator()(pair<int, T*> p) { return p.second == t_ };
private:
	T* t_;
};


// TODO : Cr�er le FoncteurGenerateurId
class FoncteurGenerateurId
{
public:
	FoncteurGenerateurId() { id_ = 0; };
	int operator()() { return id_++; };
private:
	int id_;
};
/*
Attributs :
- id_;
M�thodes :
- operator(); Incr�menter id_ � chaque appel
*/

// TODO : Cr�er le FoncteurDiminuerPourcent
class FoncteurDiminuerPourcent
{
public:
	FoncteurDiminuerPourcent(int pourcentage) { pourcentage_ = pourcentage; }
	void operator()(const pair<int, Produit*>& p) { p.second->modifierPrix(p.second->obtenirPrix * ((100 - pourcentage_) / 100.0)); }
private:
	int pourcentage_;
};
/*
Attributs :
- pourcentage_;
M�thodes :
- operator(); Calule le nouveau prix du Produit de la pair pass� en param�tre et le modifie
*/

// TODO : Cr�er le FoncteurIntervalle
class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double borneInf, double borneSup)
	{
		borneInf_ = borneInf;
		borneSup_ = borneSup;
	};
	bool operator()(const pair<int, Produit*> &p) { return (p.second->obtenirPrix() >= borneInf_) && (p.second->obtenirPrix() <= borneSup_); };
private:
	double borneInf_;
	double borneSup_;
};
/*
Attributs :
- borneInf_;
- borneSup_;
M�thodes :
- operator(); V�rifie que le Produit associ� � la pair pass� en param�tre est compris entre les bornes borneInf_ et borneSup_ (retourne un bool�en)
*/

// TODO : Cr�er le Foncteur AjouterProduit
class AjouterProduit
{
public:
	AjouterProduit(const multimap<int, Produit*> & m) /*: multimap_(m)*/
	{ 
		multimap_ = m;
	};
	multimap<int, Produit*> & operator()(const pair<int, Produit*> &p) { multimap_.insert(p); };
private:
	multimap<int, Produit*> & multimap_;
};
/*
Attributs :
- &multimap_;
M�thodes :
- operator(); Ajoute dans la multimap la pair pass� par param�tre et retourne la multimap_;
*/

// TODO : Cr�er le Foncteur SupprimerProduit
class SupprimerProduit
{
public:
	SupprimerProduit(const multimap<int, Produit*> & m) /*: multimap_(m)*/
	{
		multimap_ = m;
	};
	multimap<int, Produit*> & operator()(const pair<int, Produit*> &p) { multimap_.begin(), multimap_.end(),  };
private:
	multimap<int, Produit*> & multimap_;
};
/*
Attributs :
- &multimap_;
M�thodes :
- operator(); Utilise la fonction find_if avec le FoncteurEgal. Si le Produit existe,
				on supprime le Produit et on retourne la multimap_,
				sinon on retourne juste la multimap_ sans supprimer l'�l�ment.
*/

//TODO : Cr�er le Foncteur AjouterUsager
/*
Attributs :
- &set;
M�thodes :
- operateur(); Trouve l'Usager dans le set_, s'il existe on le supprime et on retourne le set_, sinon on retourne juste directement le set_.
*/
