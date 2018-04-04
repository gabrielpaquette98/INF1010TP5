/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "../HeaderFiles/GestionnaireProduits.h"

GestionnaireProduits::GestionnaireProduits() {
	// ne rien faire
};

GestionnaireProduits::~GestionnaireProduits() {
	// ne rien faire
};

void GestionnaireProduits::reinitialiserClient() {
	// TODO utiliser pourChaqueElement
	// TODO s'informer de l'utilite de cette methode pour savoir si elle est correctement implementee
	std::for_each(
		conteneur_.begin(),
		conteneur_.end(),
		[](Produit* produit) { 
			if (dynamic_cast<ProduitAuxEncheres*>(produit) != nullptr) {
				ProduitAuxEncheres produitAReinit = *dynamic_cast<ProduitAuxEncheres*>(produit);
				produitAReinit.modifierEncherisseur(nullptr);
				produitAReinit.modifierPrix(produitAReinit.obtenirPrixInitial);
			}
		}
	);
}

void GestionnaireProduits::reinitialiserFournisseur() {
	// TODO utiliser pourChaqueElement
	std::for_each(
		conteneur_.begin(),
		conteneur_.end(),
		[](Produit* produit) { (*produit).modifierFournisseur(nullptr); }
	);
}

void GestionnaireProduits::afficher() const {
	// TODO utiliser pourChaqueElement
	std::for_each(
		conteneur_.begin(),
		conteneur_.end(),
		[](Produit* produit) {
			if (dynamic_cast<ProduitAuxEncheres*>(produit) != nullptr) {
				ProduitAuxEncheres produitAafficher = *dynamic_cast<ProduitAuxEncheres*>(produit);
				produitAafficher.afficher();
			}
			else if (dynamic_cast<ProduitSolde*>(produit) != nullptr) {
				ProduitSolde produitAafficher = *dynamic_cast<ProduitSolde*>(produit);
				produitAafficher.afficher();
			}
			else {
				produit->afficher();
			}
		}
	);
}

double GestionnaireProduits::obtenirTotalAPayer() const {
	//...
}

double GestionnaireProduits::obtenirTotalApayerPremium() const {
	//...
}

Produit GestionnaireProduits::trouverProduitPlusCher() const {
	//...
}

vector<pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre(double min, double max) const {
	//...
}

Produit* GestionnaireProduits::obtenirProduitSuivant(Produit* produit) const {
	//...
}