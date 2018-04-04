/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteurs: Ryan Hardie, 1899088 et 1894061
*******************************************/

#ifndef GESTIONNAIREUSAGER_H
#define GESTIONNAIREUSAGER_H

#pragma once

#include "./GestionnaireGenerique.h"
#include "./Usager.h"
#include "./Client.h"
#include "./Foncteur.h"
#include "./ProduitAuxEncheres.h"
#include <set>

class GestionnaireUsagers : public GestionnaireGenerique 
	<Usager, set<Usager*>, AjouterUsager , SupprimerUsager> {

public:
	GestionnaireUsagers();
	GestionnaireUsagers();
	double obtenirChiffreAffaires() const;
	void encherir(Client* usager, ProduitAuxEncheres* produit, double montant) const;
	void reinitialiser();
	void afficherProfils() const;

protected:

private:

};

#endif // !GESTIONNAIREUSAGERS_H