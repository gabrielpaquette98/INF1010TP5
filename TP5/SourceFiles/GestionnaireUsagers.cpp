/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie, 1894061 et 1899088
*******************************************/

#include "../HeaderFiles/GestionnaireUsagers.h"

GestionnaireUsagers::GestionnaireUsagers() {
	// ne rien faire
};

GestionnaireUsagers::~GestionnaireUsagers() {
	// ne rien faire
}

double GestionnaireUsagers::obtenirChiffreAffaires() const {
	double chiffreAffaires = 0.0;
	// TODO utiliser pourChaqueElement
	std::for_each(
		conteneur_.begin(),
		conteneur_.end(),
		[&](Usager* const usager) { chiffreAffaires += (*usager).obtenirTotalAPayer(); }
	);
};

// TODO verifier
void GestionnaireUsagers::encherir(Client* client, ProduitAuxEncheres* produit, double montant) const {
	if (montant <= produit->obtenirPrix()) {
		return;
	}
	else {
		produit->mettreAJourEnchere(client, montant);
	}
};

void GestionnaireUsagers::reinitialiser() {
	// TODO utiliser pourChaqueElement
	std::for_each(
		conteneur_.begin(),
		conteneur_.end(),
		[](Usager* usager) { (*usager).reinitialiser(); }
	);
};

void GestionnaireUsagers::afficherProfils() const {
	// TODO utiliser pourChaqueElement
	std::for_each(
		conteneur_.begin(),
		conteneur_.end(),
		[](Usager* usager) { 
			if (dynamic_cast<Fournisseur*>(usager) != nullptr) {
				Fournisseur fournisseurTemp = *dynamic_cast<Fournisseur*>(usager);
				fournisseurTemp.afficher();
			}
			else if (dynamic_cast<ClientPremium*>(usager) != nullptr) {
				ClientPremium clientPremiumTemp = *dynamic_cast<ClientPremium*>(usager);
				clientPremiumTemp.afficher();
			}
			else if (dynamic_cast<Client*>(usager) != nullptr) {
				Client clientTemp = *dynamic_cast<Client*>(usager);
				clientTemp.afficher();
			}
			else {
				std::cout << '\t' << '\t' << std::left << "PROFIL INVALIDE" << endl;
			}
		}
	);
}