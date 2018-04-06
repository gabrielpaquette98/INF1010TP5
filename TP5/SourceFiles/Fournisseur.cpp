#include "../HeaderFiles/Fournisseur.h"
#include <iostream>

Fournisseur::Fournisseur()
    : Usager()
{
}

Fournisseur::Fournisseur(const string &nom, const string &prenom, int identifiant,
                         const string &codePostal)
    : Usager(nom, prenom, identifiant, codePostal), catalogue_(nullptr)
{
	// TODO : À modifier
}

GestionnaireProduits* Fournisseur::obtenirCatalogue() const
{
	// TODO : À modifier
    return catalogue_;
}

void Fournisseur::afficherCatalogue() const
{
	// TODO : À modifier
    cout << "CATALOGUE (de " << obtenirNom() << ")"
         << "\n";
	catalogue_->afficher();
    cout << endl;
}

void Fournisseur::afficher() const
{
	// TODO : À modifier
    Usager::afficher();
    cout << "\t\tcatalogue:\t" << catalogue_->obtenirConteneur().size() << " elements" << endl;
}

void Fournisseur::reinitialiser()
{
	// TODO : À modifier
	catalogue_->reinitialiserFournisseur();
}

void Fournisseur::ajouterProduit(Produit *produit)
{
	// TODO : À modifier
	catalogue_->ajouter(produit);
}

void Fournisseur::enleverProduit(Produit *produit)
{
	// TODO : À modifier
	catalogue_->supprimer(produit);
}
