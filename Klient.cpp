#include <iostream>
#include "Klient.h"

void Klient::set_imie(std::string arg)
{
	imie = arg;
}
void Klient::set_nazwisko(std::string arg)
{
	nazwisko=arg;
}
void Klient::set_meil(std::string arg)
{
	meil=arg;
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


