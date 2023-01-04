#include "Rue.h"

#include <iostream>
#include <list>
using namespace std;

//BALJ17058609 - baldo jérôme 

int main()
{
    //declaration et initialisation d'un objet rue qui stocke les numeros de maison 
    Rue nouvelleRue;
    //tant que partie est  vrai alors la boucle continue 
    while (nouvelleRue.GetPartie() == true)
    {
        nouvelleRue.AffichMenu();
        nouvelleRue.ControlMenu();
    }

   
}


