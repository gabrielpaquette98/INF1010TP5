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
		[](pair<int, Produit*> produit) {
			if (dynamic_cast<ProduitAuxEncheres*>(produit.second) != nullptr) {
				ProduitAuxEncheres produitAReinit = *dynamic_cast<ProduitAuxEncheres*>(produit.second);
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
		[](pair<int, Produit*> produit) { produit.second->modifierFournisseur(nullptr); }
	);
}

void GestionnaireProduits::afficher() const {
	// TODO utiliser pourChaqueElement
	std::for_each(
		conteneur_.begin(),
		conteneur_.end(),
		[](pair<int, Produit*> produit) {
			if (dynamic_cast<ProduitAuxEncheres*>(produit.second) != nullptr) {
				ProduitAuxEncheres produitAafficher = *dynamic_cast<ProduitAuxEncheres*>(produit.second);
				produitAafficher.afficher();
			}
			else if (dynamic_cast<ProduitSolde*>(produit.second) != nullptr) {
				ProduitSolde produitAafficher = *dynamic_cast<ProduitSolde*>(produit.second);
				produitAafficher.afficher();
			}
			else {
				produit.second->afficher();
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
		[&](pair<int, Produit*> produit) {
		montantTotal += produit.second->obtenirPrix();
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
		[&](pair<int, Produit*> produit) {
			if (produit.second->obtenirPrix() > RABAIS_PAR_PRODUIT) {
				montantTotal += produit.second->obtenirPrix() - RABAIS_PAR_PRODUIT;
			}
		}
	);
	return montantTotal;
}

Produit* GestionnaireProduits::trouverProduitPlusCher() const {
	// TODO verifier
	std::max_element(
		conteneur_.begin(),
		conteneur_.end(),
		[](pair<int, Produit*> premierPoduit, pair<int, Produit*> secondProduit) {
			return premierPoduit.second->obtenirPrix() < secondProduit.second->obtenirPrix();
		}
	);
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

/*Produit* GestionnaireProduits::obtenirProduitSuivant(Produit* produit) const {
	// TODO utiliser bind dans un find_if
	std::find_if(
		conteneur_.begin(),
		conteneur_.end(),
		//...
	);
	//...
}*/