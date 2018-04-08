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
}

GestionnaireProduits* Fournisseur::obtenirCatalogue() const
{
    return catalogue_;
}

void Fournisseur::afficherCatalogue() const
{
    cout << "CATALOGUE (de " << obtenirNom() << ")"
         << "\n";
	catalogue_->afficher();
    cout << endl;
}

void Fournisseur::afficher() const
{
    Usager::afficher();
    cout << "\t\tcatalogue:\t" << catalogue_->obtenirConteneur().size() << " elements" << endl;
}

void Fournisseur::reinitialiser()
{
	catalogue_->reinitialiserFournisseur();
}

void Fournisseur::ajouterProduit(Produit *produit)
{
	Fournisseur* fournisseurPrecedent = produit->obtenirFournisseur();
	if (fournisseurPrecedent != nullptr) {
		fournisseurPrecedent->obtenirCatalogue()->supprimer(produit);
	}
	catalogue_->ajouter(produit);
}

void Fournisseur::enleverProduit(Produit *produit)
{
	catalogue_->supprimer(produit);
	produit->modifierFournisseur(nullptr);
}

Produit* Fournisseur::trouverProduitPlusCher() const {
	return catalogue_->trouverProduitPlusCher();
}

void Fournisseur::diminuerPrix(int pourcent) {
	catalogue_->pourChaqueElement(FoncteurDiminuerPourcent(pourcent));
}