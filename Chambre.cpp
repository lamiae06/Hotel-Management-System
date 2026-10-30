#include "Chambre.h"
#include<iostream>
using namespace std;
int Chambre::nbrchambre = 0;
Chambre::Chambre(int n,double p) :
	numero(n), prixnuit(p), occupee(false)
{
	nbrchambre++;
}

bool Chambre::estLibre() const
{
	return !occupee;
}

bool Chambre::occuper()
{
	occupee = true;
	return occupee;
}

bool Chambre::liberer()
{
	occupee = false;
	return occupee;
}

int Chambre::getNumero() const
{
	return numero;
}

double Chambre::getPrix() const
{
	return prixnuit;
}

Chambre::~Chambre()
{
	nbrchambre--;
	cout << "chambre supprimer" << endl;
}








