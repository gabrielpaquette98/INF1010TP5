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
			if (dynamic_cast<ProduitAuxEncheres*>(produit) != nullptr) {
				ProduitAuxEncheres produitAReinit = *dynamic_cast<ProduitAuxEncheres*>(produit);
				produitAReinit.modifierEncherisseur(nullptr);
				produitAReinit.modifierPrix(produitAReinit.obtenirPrixInitial());
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
	// TODO utiliser pourChaqueElement
	double montantTotal = 0.0;
	std::for_each(
		conteneur_.begin(),
		conteneur_.end(),
		[&](Produit* produit) {
			montantTotal += (*produit).obtenirPrix();
		}
	);
	return montantTotal;
}

double GestionnaireProduits::obtenirTotalApayerPremium() const {
	// TODO utiliser pourChaqueElement
	double montantTotal = 0.0;
	std::for_each(
		conteneur_.begin(),
		conteneur_.end(),
		[&](Produit* produit) {
			if ((*produit).obtenirPrix() > RABAIS_PAR_PRODUIT) {
				montantTotal += (*produit).obtenirPrix() - RABAIS_PAR_PRODUIT;
			}
		}
	);
	return montantTotal;
}

Produit GestionnaireProduits::trouverProduitPlusCher() const {
	// TODO utiliser max_element avec une fonction lambda a l'interieur
	// TODO se renseigner sur comment comparer deux objets dans une fonction lambda
	std::max_element(
		conteneur_.begin(),
		conteneur_.end(),
		[&](Produit* produit) {
			//...
		}
	);
	//...
}

vector<pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre(double min, double max) const {
	vector<pair<int, Produit*>> resultats;
	copy_if(
		conteneur_.begin(),
		conteneur_.end(),
		std::back_inserter(resultats),
		FoncteurIntervalle(min, max)
	);
}

Produit* GestionnaireProduits::obtenirProduitSuivant(Produit* produit) const {
	// TODO utiliser bind dans un find_if
	//...
}