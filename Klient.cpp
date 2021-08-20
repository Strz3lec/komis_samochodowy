#include <iostream>
#include "Klient.h"

void Klient::set_imie(std::string i)
{
	imie = i;
}
void Klient::set_nazwisko(std::string n)
{
	nazwisko = n;
}
void Klient::set_meil(std::string m)
{
	meil = m;
}

std::string Klient::get_imie()
{
	return imie;
}
std::string Klient::get_nazwisko()
{
	return nazwisko;
}
std::string Klient::get_meil()
{
	return meil;
}

Klient::Klient(std::string i, std::string n, std::string m)
{
	imie=i;
	nazwisko=n;
	meil=m;
}

Klient::~Klient()
{
}


