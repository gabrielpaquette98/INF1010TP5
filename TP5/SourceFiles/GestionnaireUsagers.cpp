/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie, 1894061 et 1899088
*******************************************/

#include "../HeaderFiles/GestionnaireUsagers.h"

GestionnaireUsagers::GestionnaireUsagers() {
	//...
};

GestionnaireUsagers::~GestionnaireUsagers() {
	//...
}

double GestionnaireUsagers::obtenirChiffreAffaires() const {
	double chiffreAffaires = 0.0;
	std::for_each(
		conteneur_.begin(),
		conteneur_.end(),
		[&](Usager* const usager) { chiffreAffaires += (*usager).obtenirTotalAPayer(); }
	);
};

void GestionnaireUsagers::encherir(Client* usager, ProduitAuxEncheres* produit, double montant) const {
	//...
};

void GestionnaireUsagers::reinitialiser() {
	std::for_each(
		conteneur_.begin(),
		conteneur_.end(),
		[](Usager* usager) { (*usager).reinitialiser(); }
	);
};

void GestionnaireUsagers::afficherProfils() const {
	std::for_each(
		conteneur_.begin(),
		conteneur_.end(),
		[](Usager* usager) {
		(*usager).afficher();
			//...
		}
	);
}