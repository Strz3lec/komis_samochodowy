#include <iostream>
#include <conio.h>
#include <vector>
#include "Klient.h"

void Klient::set_nick(std::string n)
{
	nick = n;
}

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

void Klient::set_passw(size_t hashed_passw) {
	passw = hashed_passw;
}

void Klient::set_id(int i)
{
	id_ = i;
}

size_t Klient::get_passw()
{
	return passw;
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

std::string Klient::get_nick()
{
	return nick;
}


int Klient::return_id()
{
	return id_;
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


