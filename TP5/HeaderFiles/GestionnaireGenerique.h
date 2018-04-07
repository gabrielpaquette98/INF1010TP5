/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteurs: Ryan Hardie, 1899088 et 1894061
*******************************************/

#ifndef GESTIONNAIREGENERIQUE_H
#define GESTIONNAIREGENERIQUE_H

#pragma once

#include "./Foncteur.h"
#include <algorithm>

//T: donnees (produit ou usager);
//C: conteneur (multimap, set, etc);
//A: type des foncteurs d'ajout
//S: type des foncteurs de suppression
template<typename T, typename C, typename A, typename S>

class GestionnaireGenerique {

public:

	C obtenirConteneur();

	void ajouter(T* element);

	void supprimer(T* element);

	template<typename Predicate>
	void pourChaqueElement(Predicate foncteur);

protected:
	C conteneur_;

};

#endif // !GESTIONNAIREGENERIQUE_H

template<typename T, typename C, typename A, typename S>
C GestionnaireGenerique<T, C, A, S>::obtenirConteneur() {
	return conteneur_;
}

template<typename T, typename C, typename A, typename S>
void GestionnaireGenerique<T, C, A, S>::ajouter(T* element) {
	A foncteurAjout(conteneur_);
	conteneur_ = foncteurAjout(element);
}

template<typename T, typename C, typename A, typename S>
void GestionnaireGenerique<T, C, A, S>::supprimer(T* element) {
	S foncteurRetrait(conteneur_);
	conteneur_= foncteurRetrait(element);
}

template<typename T, typename C, typename A, typename S>
template<typename Predicate>
void GestionnaireGenerique<T, C, A, S>::pourChaqueElement(Predicate foncteur) {
	std::for_each(conteneur_.begin(), conteneur_.end(), foncteur);
}