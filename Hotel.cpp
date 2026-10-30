#include "Hotel.h"
#include <stdexcept>

Hotel::Hotel(string n, int* nbre, int* capacite)
{
    nom = n;

    nb = new int[3];
    cap = new int[3];

    if (nbre == nullptr || capacite == nullptr)
        throw invalid_argument("Les tableaux de compteurs sont obligatoires.");

    for (int i = 0; i < 3; i++)
    {
        nb[i] = nbre[i] < 0 ? 0 : nbre[i];
        cap[i] = capacite[i] < 0 ? 0 : capacite[i];
        if (nb[i] > cap[i])
            nb[i] = 0;
    }

    chambres = new Chambre * [cap[0]];
    clients = new Client * [cap[1]];
    reservations = new Reservation * [cap[2]];

    for (int i = 0; i < cap[0]; i++)
        chambres[i] = nullptr;

    for (int i = 0; i < cap[1]; i++)
        clients[i] = nullptr;

    for (int i = 0; i < cap[2]; i++)
        reservations[i] = nullptr;
}


void Hotel::ajouterChambre(int numero, double prix)
{

    if (nb[0] >= cap[0])
    {
        cout << "Ajout refuse : hotel complet." << endl;
        return;
    }

    for (int i = 0; i < nb[0]; i++)
    {
        if (chambres[i]->getNumero() == numero)
        {
            cout << "Ajout refuse : numero deja existant." << endl;
            return;
        }
    }

    chambres[nb[0]] = new Chambre(numero, prix);

    nb[0]++;

    cout << "Chambre ajoutee." << endl;
}


Client Hotel::enregistrerClient(Client* c)
{
    if (c == nullptr)
        throw invalid_argument("Le client ne peut pas etre nul.");


    if (nb[1] >= cap[1])
    {
        cout << "Enregistrement refuse : capacite maximale atteinte."
            << endl;

        return *c;
    }

    for (int i = 0; i < nb[1]; i++)
    {
        if (clients[i]->getId() == c->getId())
        {
            cout << "Enregistrement refuse : client deja enregistre."
                << endl;

            return *c;
        }
    }

    clients[nb[1]] = c;

    nb[1]++;

    cout << "Client enregistre." << endl;

    return *c;
}


Reservation Hotel::reserver(int idClient, int numeroChambre,
    Date date, int nuits)
{

    if (nuits <= 0)
    {
        cout << "Reservation refusee : nombre de nuits invalide."
            << endl;

        throw "Reservation refusee";
    }

    Client* client = nullptr;

    for (int i = 0; i < nb[1]; i++)
    {
        if (clients[i]->getId() == idClient)
        {
            client = clients[i];
            break;
        }
    }

    if (client == nullptr)
    {
        cout << "Reservation refusee : client non enregistre."
            << endl;

        throw "Reservation refusee";
    }


    Chambre* chambre = nullptr;

    for (int i = 0; i < nb[0]; i++)
    {
        if (chambres[i]->getNumero() == numeroChambre)
        {
            chambre = chambres[i];
            break;
        }
    }

    if (chambre == nullptr)
    {
        cout << "Reservation refusee : chambre inexistante."
            << endl;

        throw "Reservation refusee";
    }


    if (!chambre->estLibre())
    {
        cout << "Reservation refusee : chambre occupee."
            << endl;

        throw "Reservation refusee";
    }


    if (nb[2] >= cap[2])
    {
        cout << "Reservation refusee : capacite maximale atteinte."
            << endl;

        throw "Reservation refusee";
    }


    reservations[nb[2]] =
        new Reservation(*client, *chambre, date, nuits);

    nb[2]++;

    chambre->occuper();

    cout << "Reservation acceptee." << endl;

    return *reservations[nb[2] - 1];
}


bool Hotel::annuler(int id)
{
    int position = -1;

    for (int i = 0; i < nb[2]; i++)
    {
        if (reservations[i]->getId() == id)
        {
            position = i;
            break;
        }
    }

    if (position == -1)
    {
        cout << "Annulation refusee : reservation inexistante."
            << endl;

        return false;
    }

    Chambre* chambre = reservations[position]->getChambre();

    chambre->liberer();

    delete reservations[position];

    for (int i = position; i < nb[2] - 1; i++)
    {
        reservations[i] = reservations[i + 1];
    }

    reservations[nb[2] - 1] = nullptr;

    nb[2]--;

    cout << "Reservation annulee." << endl;

    return true;
}


Reservation Hotel::facturer(const Reservation& r)
{

    cout << "Montant de la reservation : "
        << r.montant() << " DH" << endl;

    return r;
}


void Hotel::chiffreAffaires() const
{
    double total = 0;

    for (int i = 0; i < nb[2]; i++)
    {
        total += reservations[i]->montant();
    }

    cout << "Chiffre d'affaires : "
        << total << " DH" << endl;
}


Hotel::~Hotel()
{

    for (int i = 0; i < nb[2]; i++)
    {
        delete reservations[i];
    }

    delete[] reservations;


    for (int i = 0; i < nb[0]; i++)
    {
        delete chambres[i];
    }

    delete[] chambres;


    delete[] clients;


    delete[] nb;
    delete[] cap;

    cout << "Hotel detruit." << endl;
}