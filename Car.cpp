#include <iostream>
#include "Car.h"

void Car::set_marka(std::string ma)
{
	marka = ma;
}
void Car::set_model(std::string mo)
{
	model = mo;
}
void Car::set_gearbox(std::string g)
{
	gearbox=g;
}
void Car::set_stan(std::string s) {
	stan = s;
}
void Car::set_typ(std::string t) {
	typ = t;
}
void Car::set_rocznik(int r)
{
	rocznik = r;
}
void Car::set_cena(int c)
{
	cena = c;
}
void Car::set_przebieg(long int p)
{
	przebieg = p;
}


std::string Car::get_marka()
{
	return marka;
}
std::string Car::get_model()
{
	return model;
}
std::string Car::get_stan()
{
	return stan;
}
std::string Car::get_typ()
{
	return typ;
}
std::string Car::get_gearbox()
{
	return gearbox;
}

int Car::get_rocznik()
{
	return rocznik;
}

int Car::get_cena()
{
	return cena;
}

long int Car::get_przebieg()
{
	return przebieg;
}

Car::Car(std::string ma, std::string mo, std::string g, std::string s, std::string t, int r, int c, long int p)
{
	marka = ma;
	model = mo;
	gearbox = g;
	stan = s;
	typ = t;
	rocznik = r;
	cena = c;
	przebieg = p;
}
Car::~Car() {
};
