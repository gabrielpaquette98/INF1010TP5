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
#include "./ProduitAuxEncheres.h"
#include "./ProduitSolde.h"
#include <map>
#include <vector>

// TODO : Cr�er la classe GestionnaireProduits

class GestionnaireProduits : GestionnaireGenerique 
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