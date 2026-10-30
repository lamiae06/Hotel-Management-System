#include "Date.h"
#include<iostream>
using namespace std;
Date::Date(int j, int m, int a)
{
    int tab[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (a <= 0)
    {
        cout << "Annee invalide !" << endl;
        jour = 1;
        mois = 1;
        annee = 2000;
        return;
    }
    if (m < 1 || m > 12)
    {
        cout << "Mois invalide !" << endl;
        jour = 1;
        mois = 1;
        annee = 2000;
        return;
    }
    if (a % 400 == 0 || (a % 4 == 0 && a % 100 != 0))
    {
        tab[1] = 29;
    }

    if (j < 1 || j > tab[m - 1])
    {
        cout << "Jour invalide !" << endl;
        jour = 1;
        mois = 1;
        annee = 2000;
        return;
    }
    jour = j;
    mois = m;
    annee = a;
}

void Date::afficher() const
{
	cout << jour << "/" << mois << "/" << annee << endl;
}

