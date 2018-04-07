/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "../HeaderFiles/GestionnaireProduits.h"
#include "../HeaderFiles/ProduitAuxEncheres.h"
#include <functional>

GestionnaireProduits::GestionnaireProduits() {
	// ne rien faire
};

GestionnaireProduits::~GestionnaireProduits() {
	// ne rien faire
};

void GestionnaireProduits::reinitialiserClient() {
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		if (dynamic_cast<ProduitAuxEncheres*>(it->second) != nullptr) {
			(*dynamic_cast<ProduitAuxEncheres*>(it->second)).modifierEncherisseur(nullptr);
			(*dynamic_cast<ProduitAuxEncheres*>(it->second))
				.modifierPrix((*dynamic_cast<ProduitAuxEncheres*>(it->second)).obtenirPrixInitial());
		}
	}
	conteneur_.clear();
}

void GestionnaireProduits::reinitialiserFournisseur() {
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		it->second->modifierFournisseur(nullptr);
	}
}

void GestionnaireProduits::afficher() const {
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		it->second->afficher();
	}
}

double GestionnaireProduits::obtenirTotalAPayer() const {
	// TODO utiliser pourChaqueElement
	double montantTotal = 0.0;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		montantTotal += it->second->obtenirPrix();
	}
	return montantTotal;
}

double GestionnaireProduits::obtenirTotalApayerPremium() const {
	// TODO utiliser pourChaqueElement
	double montantTotal = 0.0;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		if (it->second->obtenirPrix() > RABAIS_PAR_PRODUIT) {
			montantTotal += it->second->obtenirPrix() - RABAIS_PAR_PRODUIT;
		}
	}
	return montantTotal;
}

Produit* GestionnaireProduits::trouverProduitPlusCher() const {
	// TODO verifier
	auto it = std::max_element(
		conteneur_.begin(),
		conteneur_.end(),
		[](pair<int, Produit*> premierPoduit, pair<int, Produit*> secondProduit) {
			return premierPoduit.second->obtenirPrix() < secondProduit.second->obtenirPrix();
		}
	);
	return (it->second);
}

// TODO verifier
vector<pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre(double min, double max) const {
	vector<pair<int, Produit*>> resultats;
	copy_if(conteneur_.begin(), 
		conteneur_.end(), 
		back_inserter(resultats), 
		FoncteurIntervalle(min, max));
	return resultats;
}

Produit* GestionnaireProduits::obtenirProduitSuivant(Produit* produit) const {
	auto it = find_if(conteneur_.begin(),
		conteneur_.end(),
		bind(greater<pair<int, Produit*>>(), 
			placeholders::_1,
			make_pair(produit->obtenirReference(), produit)));
	return it->second;
}