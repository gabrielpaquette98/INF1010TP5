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

// TODO verifier si cette methode a vraiment sa place dans GestionnaireUsagers
void GestionnaireUsagers::encherir(Client* usager, ProduitAuxEncheres* produit, double montant) const {
	//...
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
		[](Usager* usager) { (*usager).afficher(); }
	);
}