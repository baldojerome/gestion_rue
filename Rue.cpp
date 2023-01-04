#include "Rue.h"

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

//BALJ17058609 - baldo jerome 

Rue::Rue()
{
	//partie initialiser a true 
	this->partie = true;
}

Rue::~Rue()
{
}
//getter pour verifier partie
bool Rue::GetPartie()
{
	return partie;
}
//modifie lle booleen partie pour arretr la partie 
void Rue::SetPartie(bool partie)
{
	this->partie = partie;
}
//getter pour la valeur la plus haute de la list 
int Rue::GetValHaute()
{
	return valHaute;
}
//methode pour modifier la valeur la plus haute de la list 
void Rue::SetValHaute(int num)
{
	this->valHaute = num;
}
// getter pour la valeur la plus basse de la list 
int Rue::GetValBasse()
{
	return valBasse;
}
//methode pour modifier la valeur la plus basse de la list 
void Rue::SetValBasse(int num)
{
	this->valBasse = num;
}
//methode pour aficher le menu contextuel 
void Rue::AffichMenu()
{
	for (int i = 0; i < 50; i++)
	{
		cout << "-";
	}
	cout << endl << endl;

	cout << "(0) - Afficher la rue" << endl;
	cout << "(1) - Ajouter une maison" << endl;
	cout << "(2) - Supprimer une maison" << endl;
	cout << "(3) - Rechercher une maison" << endl;
	cout << "(4) - Quitter la rue" << endl;

	cout << endl;
	for (int i = 0; i < 50; i++)
	{
		cout << "-";
	}
	cout << endl << endl;
}
//methode pour controler le menu 
// il aiguille sur une des methodes 
void Rue::ControlMenu()
{
	int choixMenu = -1;
	cout << "Votre choix : ";
	cin >> choixMenu;
	cout << endl;
	switch (choixMenu)
	{
		case(0):
			this->AffichRue();
			break;
		case(1):
			this->AjoutMaison();
			break;
		case(2):
			this->SupprimMaison();
			break;
		case(3):
			this->RecherchMaison();
			break;
		case(4):
			this->SetPartie(false);
			break;
		default:
			cerr << "Mauvaise entree. Veuillez recommencer." << endl;
			break;
	}
}
//methode pour ajouter une maison 
// verifie sur numero entre 400 et 600
void Rue::AjoutMaison()
{
	int numMaison = -1;
	cout << "Quel est le # civique de la maison?  (entre 400 et 600) : ";
	cin >> numMaison;
	//on verifie si le numero entre est bien entre 400 et 600 inclus
	if (numMaison >= 400 && numMaison <= 600)
	{
		if (numMaison > this->GetValHaute())
		{
			this->maison.push_back(numMaison);
			this->SetValHaute(numMaison);
		}
		else if (numMaison < this->GetValBasse())
		{
			this->maison.push_front(numMaison);
			this->SetValBasse(numMaison);
		}
		else
		{
			int rang = 0;
			list<int>::iterator i = this->maison.begin();

			while (numMaison > *i)
			{
				rang++;
				++i;
			}

			list<int>::iterator it = this->maison.begin();
			advance(it, rang);
			
			this->maison.insert(it, numMaison);
		}
	}
	else
	{
		//entree erronne alors  recursivite pour relancer la methode 
		this->AjoutMaison();
	}
	
}
//methode pour supprimer maison 
void Rue::SupprimMaison()
{
	//input du numero 
	int numMaison = -1;
	cout << "Quel est le # civique de la maison a supprimer? (entre 400 et 600) : ";
	cin >> numMaison;
	bool verif = this->VerifMaison(numMaison);
	//verification si le numero existe 
	if (verif)
	{
		//si oui alors on supprime 
		int rang = 0;
		list<int>::iterator i = this->maison.begin();
		//on cherche le rang de la case a supprimer 
		while (numMaison != *i)
		{
			rang++;
			++i;
		}

		list<int>::iterator it = this->maison.begin();
		//advance permet de positionner l'iterateur sur le rang de la case 
		advance(it, rang);
		//avec iterateur positionner suppression de la case 
		this->maison.erase(it);

		cout << "Maison " << numMaison << " a ete supprimee." << endl;
	}
	else
	{
		//si non alors maison inexistante 
		cout << "Maison " << numMaison << " inexistante" << endl;
	}
}

//methode pour rechercher une maison 
//utilise la methode verifmaison pour verifier si la maison existe 
void Rue::RecherchMaison()
{
	//input du numero de la maison a chercher 
	int numero = -1;
	cout << "Quel est le # civique de la maison? (entre 400 et 600) : ";
	cin >> numero;
	bool recherche = this->VerifMaison(numero);
	//verification par l'intermediaire de VerifMaison()
	if (recherche)
	{
		//si oui alors la maison existe 
		cout << "La maison " << numero << " existe dans la rue." << endl;
	}
	else 
	{
		//si non alors la maison n'existe pas  
		cout << "Maison " << numero << " inexistante." << endl;
	}
}
//methode permettant de  verifier sur le numero existe dans la  list
//entree : numero cherche / sortie : bool 
bool Rue::VerifMaison(int numeroM)
{
	bool verif = (find(this->maison.begin(), this->maison.end(), numeroM) != this->maison.end());
	return verif;
}
//methode pour lafficher la rue  avec tous les numéros de maisons 
void Rue::AffichRue()
{
	cout << "Voici la rue (" << this->maison.size() << " maisons)" << endl << endl;
	cout << " | ";
	list<int>::iterator it;
	for (it = this->maison.begin(); it != this->maison.end(); it++)
	{
		cout << *it;
		cout << " | ";
	}
	cout << endl << endl;
} 

