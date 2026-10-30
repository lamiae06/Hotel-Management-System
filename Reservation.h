#pragma once
#include<iostream>
using namespace std;
#include "Client.h"
#include "Chambre.h"
#include "Date.h"
class Reservation
{
	const int id;
	Client* client;
	Chambre* chambre;
	Date arrivee;
	int nuits;
	static int compteur;
public:
	Reservation(Client& , Chambre&, Date, int);
	double montant()const;
	void afficher() const;
	int getId() const;
	Chambre* getChambre() const;

};