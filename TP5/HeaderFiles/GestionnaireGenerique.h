/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

// TODO : Créer la classe GestionnaireGenerique

template<typename T, typename C> //T: donnees (produit ou usager); C: conteneur (multimap, set, etc)
class GestionnaireGenerique
{
public:
	void ajouter();
	void supprime();
	C obtenirConteneur();
	pourChaqueElement()
protected:
	C conteneur_;
};

//attribut protected: conteneur_ 

// TODO : Méthodes :
/*
- ajouter()
- supprime()
- obtenirConteneur()
- pourChaqueElement()
*/