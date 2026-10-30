#pragma once
#include<iostream>
using namespace std;
#include "Client.h"
#include "Chambre.h"
#include "Date.h"
#include "Reservation.h"

class Hotel
{
	string nom;
	Chambre** chambres;
	Client** clients;
	Reservation** reservations;
	int* nb;
	int* cap;
public:
	Hotel(string, int*, int*);
	Hotel(const Hotel&) = delete;
	Hotel& operator=(const Hotel&) = delete;
	void ajouterChambre(int, double);
	Client enregistrerClient(Client*);
	Reservation reserver(int, int, Date, int);
	bool annuler(int) ;
	Reservation facturer(const Reservation&);
	void chiffreAffaires() const;
	~Hotel();

};

