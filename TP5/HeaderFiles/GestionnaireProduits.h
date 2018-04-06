/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#ifndef GESTIONNAIREPRODUITS_H
#define GESTIONNAIREPRODUITS_H

#pragma once

#include "./GestionnaireGenerique.h"
#include "./Produit.h"

#include "./ProduitSolde.h"
#include <map>
#include <vector>

const uint8_t RABAIS_PAR_PRODUIT = 5;

// TODO : Créer la classe GestionnaireProduits

class GestionnaireProduits : public GestionnaireGenerique 
	<Produit, multimap<int, Produit*>, AjouterProduit, SupprimerProduit> {
	
public:
	GestionnaireProduits();
	~GestionnaireProduits();
	void reinitialiserClient();
	void reinitialiserFournisseur();
	void afficher() const;
	double obtenirTotalAPayer() const;
	double obtenirTotalApayerPremium() const;
	Produit trouverProduitPlusCher() const;
	vector<pair<int, Produit*>> obtenirProduitsEntre(double min, double max) const;
	Produit* obtenirProduitSuivant(Produit* produit) const;

protected:

private:

};

#endif // !GESTIONNAIREPRODUITS_H