#include "../HeaderFiles/Client.h"
#include "../HeaderFiles/ProduitAuxEncheres.h"
#include <iostream>

Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient),
	panier_(new GestionnaireProduits())
{

}

Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, identifiant, codePostal),
      codeClient_(codeClient),
	panier_(new GestionnaireProduits())
{

}

unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}

GestionnaireProduits* Client::obtenirPanier() const
{
    return panier_;
}

double Client::obtenirTotalAPayer() const
{
	return panier_->obtenirTotalAPayer();
}

void Client::afficherPanier() const
{
    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
	panier_->afficher();
}

void Client::afficher() const
{
    Usager::afficher();
	cout << "\t\tcode client:\t" << codeClient_ << endl
		<< "\t\tpanier:\t\t" << panier_->obtenirConteneur().size() << " elements" << endl;
}

void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient_;
}

void Client::enleverProduit(Produit *produit)
{
	// TODO : � verifier
	panier_->supprimer(produit);
}

void Client::ajouterProduit(Produit *produit)
{
	// TODO : � verifier
	panier_->ajouter(produit);
}

void Client::reinitialiser()
{
	panier_->reinitialiserClient();
}

Produit* Client::trouverProduitPlusCher() const {
	return panier_->trouverProduitPlusCher();
}
