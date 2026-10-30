#include "Client.h"
 int Client::nbClients=0;
 int Client::compteur=0;
Client::Client(string n):
	id(compteur+1)
{
	this->nom = n;
	nbClients++;
	compteur++;
}

Client::~Client()
{
}

int Client::getId() const
{
	return id;
}

string Client::getNom() const
{
	return nom;
}





