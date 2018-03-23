/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteurs: Ryan Hardie, 1899088 et 1894061
*******************************************/

#ifndef GESTIONNAIREUSAGER_H
#define GESTIONNAIREUSAGER_H

#pragma once

#include "GestionnaireGenerique.h"
#include <set>

//T: donnees (produit ou usager);
//C: conteneur (multimap, set, etc);
//A: type des foncteurs d'ajout
//S: type des foncteurs de suppression
template<typename T, typename C, typename A, typename S>

class GestionnaireUsager : public GestionnaireGenerique {

public:
	double obtenirChiffreAffaires() const;

protected:

private:

};

// TODO : La classe ressemble beaucoup à la classe Gestionnaire
/*
Les méthodes retrouvées de la classe Gestionnaire sont :
- double obtenirChiffreAffaires() const;
- void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
- void reinitialiser();
- void afficherProfils() const;
*/

#endif // !GESTIONNAIREUSAGER_H