#include "Reservation.h"
#include<iostream>
using namespace std;

int Reservation::compteur = 0;

Reservation::Reservation(Client& cl, Chambre& ch, Date d, int n)
	: id(++compteur), client(&cl), chambre(&ch), arrivee(d), nuits(n)
{
}

double Reservation::montant() const
{
	return nuits * chambre->getPrix();
}

void Reservation::afficher() const
{
	cout << "Reservation " << id
		<< " | Client : " << client->getNom()
		<< " | Chambre : " << chambre->getNumero()
		<< " | Date d'arrivee : ";
	arrivee.afficher();
}

int Reservation::getId() const
{
	return id;
}

Chambre* Reservation::getChambre() const
{
	return chambre;
}
