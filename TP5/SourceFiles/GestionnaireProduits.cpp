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
	std::for_each(
		conteneur_.begin(),
		conteneur_.end(),
		[](Produit* produit) { 
			//...
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
	//...
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

vector<pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre() const {
	//...
}

Produit* GestionnaireProduits::obtenirProduitSuivant(Produit* produit) const {
	//...
}