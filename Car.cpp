#include <iostream>
#include "Car.h"

void Car::set_marka()
{
	std::cout << "Wprowadź markę samochodu\n";
	std::cin >> marka;
}

void Car::set_model()
{
	std::cout << "Wprowadź model samochodu\n";
	std::cin >> model;
}

void Car::set_rocznik()
{
	std::cout << "Wprowadź rocznik samochodu\n";
	std::cin >> rocznik;
}

std::string Car::get_marka()
{
	return marka;
}

std::string Car::get_model()
{
	return model;
}

int Car::get_rocznik()
{
	return rocznik;
}

Car::Car(std::string ma, std::string mo, int r)
{
	marka = ma;
	model = mo;
	rocznik = r;
}
Car::~Car() {
};
