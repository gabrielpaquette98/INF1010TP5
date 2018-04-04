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
#include <map>
#include <vector>

// TODO : Créer la classe GestionnaireProduits

class GestionnaireProduits : GestionnaireGenerique 
	<Produit, multimap<int, Produit*>, AjouterProduit, SupprimerProduit> {
	
public:
	GestionnaireProduits();
	GestionnaireProduits();
	void reinitialiserClient();
	void reinitialiserFournisseur();
	void afficher() const;
	double obtenirTotalAPayer() const;
	double obtenirTotalApayerPremium() const;
	Produit trouverProduitPlusCher() const;
	vector<pair<int, Produit*>> obtenirProduitsEntre() const;
	Produit* obtenirProduitSuivant(Produit* produit) const;

protected:

private:

};

#endif // !GESTIONNAIREPRODUITS_H