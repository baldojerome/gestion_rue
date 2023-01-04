#pragma once

#include <list>
#include <iostream>

using namespace std;

class Rue
{
	private:
		bool partie;
		list<int> maison{401, 402, 403, 405, 406};
		int valHaute = 406;
		int valBasse = 401;
	public:
		Rue();
		~Rue();
		bool GetPartie();
		void SetPartie(bool partie);
		int GetValHaute();
		void SetValHaute(int num);
		int GetValBasse();
		void SetValBasse(int num);
		void AffichMenu();
		void ControlMenu();
		void AjoutMaison();
		void SupprimMaison();
		void RecherchMaison();
		bool VerifMaison(int numeroM);
		void AffichRue();
};

