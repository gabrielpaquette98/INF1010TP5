#pragma once

#include "Usager.h"
#include <algorithm>
#include <set>
#include <map>

template<typename T>
class FoncteurEgal
{
public:
	FoncteurEgal(T* t) {
		t_ = t;
	}

	bool operator() (const pair<int, T*>& tAComparer) const {
		return tAComparer.second == t_;
	}

private:
	T * t_;
};

class FoncteurGenerateurId
{
public:
	FoncteurGenerateurId() {
		id_ = 0;
	}

	int operator() () {
		return  id_++;
	}

private:
	int id_;
};

class FoncteurDiminuerPourcent
{
public:
	FoncteurDiminuerPourcent(int pourcentage) {
		pourcentage_ = pourcentage;
	}

	void operator() (const pair<int, Produit*>& p) {
		double nouveauPrix = p.second->Produit::obtenirPrix() * (1 - (pourcentage_ / 100.0));
		p.second->modifierPrix(nouveauPrix);
	}

private:
	int pourcentage_;
};

class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double borneInf, double borneSup) : borneSup_(borneSup), borneInf_(borneInf) {};

	bool operator() (const pair<int, Produit*> & p)
	{
		return ((p.second->obtenirPrix() >= borneInf_) && (p.second->obtenirPrix() <= borneSup_));

	}
private:
	double borneInf_, borneSup_;
};

class AjouterProduit {
public:
	AjouterProduit(multimap<int, Produit*>& multimap) : multimap_(multimap) {};

	multimap<int, Produit*>& operator() (Produit* produit) {
		multimap_.insert(pair<int, Produit*>(produit->obtenirReference(), produit));
		return multimap_;
	};
private:
	multimap<int, Produit*> &multimap_;
};

class SupprimerProduit {
public:
	SupprimerProduit(multimap<int, Produit*>& multimap) : multimap_(multimap) {};

	multimap<int, Produit*>& operator() (Produit* produit) {
		FoncteurEgal<Produit> fonteurComparaison(produit);
		auto position = find_if(multimap_.begin(), multimap_.end(), fonteurComparaison);
		if (position != multimap_.end())
			multimap_.erase(position);
		return multimap_;
	};
private:
	multimap<int, Produit*> &multimap_;
};

class AjouterUsager {
public:
	AjouterUsager(set<Usager*>& set) : set_(set) {};

	set<Usager*>& operator() (Usager* usager) {
		set_.insert(usager);
		return set_;
	};
private:
	set<Usager*>& set_;
};

class SupprimerUsager {
public:
	SupprimerUsager(set<Usager*>& set) : set_(set) {};

	set<Usager*>& operator() (Usager* usager) {
		auto position = set_.find(usager);
		if (position != set_.end())
			set_.erase(position);
		return set_;
	};
private:
	set<Usager*>& set_;
};
