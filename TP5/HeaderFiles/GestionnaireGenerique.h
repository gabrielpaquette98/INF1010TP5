/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteurs: Ryan Hardie, 1899088 et 1894061
*******************************************/

#ifndef GESTIONNAIREGENERIQUE_H
#define GESTIONNAIREGENERIQUE_H

#pragma once

//T: donnees (produit ou usager);
//C: conteneur (multimap, set, etc);
//A: type des foncteurs d'ajout
//S: type des foncteurs de suppression
template<typename T, typename C, typename A, typename S>

class GestionnaireGenerique {

public:
	C obtenirConteneur();
	void ajouter(T* item);
	void supprimer(T* item);
	template<typename Predicate>
	void pourChaqueElement(Predicate element);

protected:
	C conteneur_;

};

#endif // !GESTIONNAIREGENERIQUE_H