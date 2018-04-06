#include "../HeaderFiles/Client.h"
#include "../HeaderFiles/ProduitAuxEncheres.h"
#include <iostream>

Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient),
	panier_(nullptr)
{

}

Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, identifiant, codePostal),
      codeClient_(codeClient),
	panier_(nullptr)
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
	// TODO : À modifier
    /*Usager::afficher();
	cout << "\t\tcode client:\t" << codeClient_ << endl
		<< "\t\tpanier:\t\t" << panier_->obtenirConteneur().size() << " elements" << endl;*/
}

void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient_;
}

void Client::enleverProduit(Produit *produit)
{
	// TODO : À modifier
    /*for (unsigned int i = 0; i < panier_.size(); i++)
    {
        if (panier_[i] == produit)
        {
            panier_[i] = panier_[panier_.size() - 1];
            panier_.pop_back();
            return;
        }
    }*/
}

void Client::ajouterProduit(Produit *produit)
{
	// TODO : À modifier
    /*for (unsigned int i = 0; i < panier_.size(); i++)
        if (panier_[i] == produit)
            return;
    panier_.push_back(produit);*/
}

void Client::reinitialiser()
{
	panier_->reinitialiserClient();
	// TODO : À modifier
    /*for (unsigned int i = 0; i < panier_.size(); i++)
    {
        ProduitAuxEncheres *produit = dynamic_cast<ProduitAuxEncheres *>(panier_[i]);
        if (produit) {
            produit->modifierEncherisseur(nullptr);
            produit->modifierPrix(produit->obtenirPrixInitial());
        }
    }
    panier_.clear();*/
}
