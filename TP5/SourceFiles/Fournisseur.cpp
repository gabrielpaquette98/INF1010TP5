#include "../HeaderFiles/Fournisseur.h"
#include <iostream>

Fournisseur::Fournisseur()
    : Usager(), catalogue_(new GestionnaireProduits())
{
}

Fournisseur::Fournisseur(const string &nom, const string &prenom, int identifiant,
                         const string &codePostal)
    : Usager(nom, prenom, identifiant, codePostal), catalogue_(new GestionnaireProduits())
{
	// TODO : � modifier
}

GestionnaireProduits* Fournisseur::obtenirCatalogue() const
{
	// TODO : � modifier
    return catalogue_;
}

void Fournisseur::afficherCatalogue() const
{
	// TODO : � modifier
    cout << "CATALOGUE (de " << obtenirNom() << ")"
         << "\n";
	catalogue_->afficher();
    cout << endl;
}

void Fournisseur::afficher() const
{
	// TODO : � modifier
    Usager::afficher();
    cout << "\t\tcatalogue:\t" << catalogue_->obtenirConteneur().size() << " elements" << endl;
}

void Fournisseur::reinitialiser()
{
	// TODO : � modifier
	catalogue_->reinitialiserFournisseur();
}

void Fournisseur::ajouterProduit(Produit *produit)
{
	// TODO : � modifier
	catalogue_->ajouter(produit);
}

void Fournisseur::enleverProduit(Produit *produit)
{
	// TODO : � modifier
	catalogue_->supprimer(produit);
	produit->modifierFournisseur(nullptr);
}

Produit* Fournisseur::trouverProduitPlusCher() const {
	return catalogue_->trouverProduitPlusCher();
}

void Fournisseur::diminuerPrix(int pourcent) {
	catalogue_->pourChaqueElement(FoncteurDiminuerPourcent(pourcent));
}