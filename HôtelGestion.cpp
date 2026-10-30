#include <iostream>
#include <exception>
#include "Hotel.h"

int main()
{
    int nombres[3] = { 0, 0, 0 };
    int capacites[3] = { 3, 3, 3 };

    Client client1("Alice");
    Client client2("Bob");

    try
    {
        Hotel hotel("Hotel Central", nombres, capacites);

        hotel.ajouterChambre(101, 450.0);
        hotel.ajouterChambre(102, 600.0);
        hotel.ajouterChambre(101, 500.0);

        hotel.enregistrerClient(&client1);
        hotel.enregistrerClient(&client2);
        hotel.enregistrerClient(&client1);

        Date arrivee(15, 6, 2026);
        Reservation reservation = hotel.reserver(
            client1.getId(), 101, arrivee, 3);

        hotel.facturer(reservation);
        hotel.chiffreAffaires();

        if (hotel.annuler(reservation.getId()))
            std::cout << "Reservation annulee avec succes." << std::endl;

        hotel.chiffreAffaires();

        try
        {
            hotel.reserver(client2.getId(), 999, arrivee, 2);
        }
        catch (const std::exception& erreur)
        {
            std::cout << erreur.what() << std::endl;
        }
    }
    catch (const std::exception& erreur)
    {
        std::cerr << "Erreur : " << erreur.what() << std::endl;
        return 1;
    }

    return 0;
}
