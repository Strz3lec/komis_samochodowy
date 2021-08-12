#include <iostream>
#include "Klient.h"

void Klient::set_imie()
{
	std::cout<<"Wprowadź imię"<<std::endl;
	std::cin >> imie;
}
void Klient::set_nazwisko()
{
	std::cout << "Wprowadź nazwisko" << std::endl;
	std::cin >> nazwisko;
}
void Klient::set_meil()
{
	std::cout << "Wprowadź meil" << std::endl;
	std::cin >> meil;
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


