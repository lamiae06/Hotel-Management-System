#pragma once
#include<iostream>
using namespace std;
class Client
{
	const int id;
	string nom;
	static int nbClients;
	static int compteur;
public:
	Client(string);
	~Client();
	int getId()const;
	string getNom()const;

};

