#pragma once
class Chambre
{
	const int numero;
	double prixnuit;
	bool occupee;
	static int nbrchambre;
public:
	Chambre(int , double);
	bool estLibre() const;
	bool occuper();
	bool liberer();
	int getNumero() const;
	double getPrix() const;
	~Chambre();

};

