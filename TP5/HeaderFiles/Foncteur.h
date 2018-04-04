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

// TODO : Créer le FoncteurEgal
template<typename T>
class FoncteurEgal
{
public:
	FoncteurEgal(T* t) 
		: t_(t) {};
	bool operator()(pair<int, T*> p) { return p.second == t_ };
private:
	T* t_;
};

// TODO : Créer le FoncteurGenerateurId
class FoncteurGenerateurId
{
public:
	FoncteurGenerateurId() 
		: id_(0) {};
	int operator()() { return id_++; };
private:
	int id_;
};

// TODO : Créer le FoncteurDiminuerPourcent
class FoncteurDiminuerPourcent
{
public:
	FoncteurDiminuerPourcent(int pourcentage) 
		: pourcentage_(pourcentage) {};
	void operator()(const pair<int, Produit*>& p) 
	{ 
		p.second->modifierPrix(p.second->obtenirPrix * ((100 - pourcentage_) / 100.0)); 
	}
private:
	int pourcentage_;
};

// TODO : Créer le FoncteurIntervalle
class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double borneInf, double borneSup) 
		: borneInf_(borneInf), borneSup_(borneSup) {};
	bool operator()(const pair<int, Produit*> &p) 
	{ 
		return (p.second->obtenirPrix() >= borneInf_) && (p.second->obtenirPrix() <= borneSup_); 
	};
private:
	double borneInf_;
	double borneSup_;
};

// TODO : Créer le Foncteur AjouterProduit
class AjouterProduit
{
public:
	AjouterProduit(multimap<int, Produit*> & m) 
		: multimap_(m) {};
	multimap<int, Produit*> & operator()(Produit* p) 
	{ 
		multimap_.insert(pair<int, Produit*>(p->obtenirReference(), p));
		return multimap_;
	};
private:
	multimap<int, Produit*> & multimap_;
};

// TODO : Créer le Foncteur SupprimerProduit
class SupprimerProduit
{
public:
	SupprimerProduit(multimap<int, Produit*> & m) 
		: multimap_(m) {};
	multimap<int, Produit*> & operator()(Produit* p) 
	{ 
		FoncteurEgal<Produit> foncteurProduitEgal(p); 
		multimap<int, Produit*>::iterator itProduitTrouve = find_if(multimap_.begin(), multimap_.end(), foncteurProduitEgal());
		if (itProduitTrouve != multimap_.end())
			multimap_.erase(itProduitTrouve);
		return multimap_;
	};
private:
	multimap<int, Produit*> & multimap_;
};

//TODO : Créer le Foncteur AjouterUsager
class AjouterUsager
{
public:
	AjouterUsager(set<Usager*> & set) 
		: set_(set) {  };
	set<Usager*> & operator()(Usager* usager) 
	{ 
		set_.insert(usager);
		return set_;
	};
private:
	set<Usager*> &set_;
};


class SupprimerUsager
{
public:
	SupprimerUsager(set<Usager*> & set) 
		: set_(set) {  };
	set<Usager*> & operator()(Usager* usager) 
	{ 
		FoncteurEgal<Usager> foncteurUsagerEgal(pair<int, Usager*> p(0, usager));
		set<Usager*>::iterator itUsagerTrouve = find_if(set_.begin(), set_.end(), foncteurUsagerEgal());
		if (itUsagerTrouve != set_.end())
			set_.erase(itUsagerTrouve);
		return set_;
	};
private:
	set<Usager*> &set_;
};
