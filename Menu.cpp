#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <Windows.h>
#include "Car.h"
#include "Menu.h"

int bd_cars_size = 0; // ilość obiektów w bazie danych samochodów
Car* bd_cars = new Car[bd_cars_size];
void menu();
void menu_cars();
void cars_show();
void cars_add();
void bd_(Car* obj);
Car* auto_();

void menu()
{
	int d;// zmienna do podejmowania decyzji
	system("cls");
	std::cout << "1. Logowanie/Rejestracja\n";
	std::cout << "2. Pojazdy\n";
	std::cout << "3. Moje konto\n";
	std::cout << "4. Exit\n\n";
	std::cout << "Co chcesz zrobić? ";
	std::cin >> d;
	switch (d) 
	{
	case 1:
	case 2:system("cls");
		menu_cars();
	case 3:
	case 4:std::cout << std::endl<<"Thanks for using this programm see you soon :)";
		Sleep(2000);
		exit(0);
	default:
		std::cout << std::endl<<"It's impossible to do this action. Choose again what do you want to do.";
		menu();
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
void menu_log()
{
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------

void menu_cars()
{
	system("cls");
	int odp;
	std::cout << "1. Pokaż listę pojazdów\n";
	std::cout << "2. Dodaj pojazd\n";
	std::cout << "3. Menu\n";
	std::cout << "Wybór: ";
	std::cin >> odp;
	switch (odp) {
	case 1: cars_show();
		break;
	case 2: cars_add();
		break;
	case 3: menu();
		break;
	default: std::cout << "There's no such a choice. Choose again";
		Sleep(2000);
		menu_cars();
	}
}
void bd_(Car* obj)
{
	Car* temp = new Car[bd_cars_size];
	temp = bd_cars;
	bd_cars = new Car[bd_cars_size + 1];//update wilekości bazy danych
	for (int i = 0; i < bd_cars_size; i++) {
		bd_cars[i].set_marka(temp->get_marka());
		bd_cars[i].set_model(temp->get_model());
		bd_cars[i].set_model(temp->get_gearbox());
		bd_cars[i].set_stan(temp->get_stan());
		bd_cars[i].set_typ(temp->get_typ());
		bd_cars[i].set_rocznik(temp->get_rocznik());
		bd_cars[i].set_przebieg(temp->get_przebieg());
		bd_cars[i].set_cena(temp->get_cena());
	}
	bd_cars[bd_cars_size].set_marka(obj->get_marka());
	bd_cars[bd_cars_size].set_model(obj->get_model());
	bd_cars[bd_cars_size].set_model(obj->get_gearbox());
	bd_cars[bd_cars_size].set_stan(obj->get_stan());
	bd_cars[bd_cars_size].set_typ(obj->get_typ());
	bd_cars[bd_cars_size].set_rocznik(obj->get_rocznik());
	bd_cars[bd_cars_size].set_przebieg(obj->get_przebieg());
	bd_cars[bd_cars_size].set_cena(obj->get_cena());
	bd_cars_size++;
	std::cout << "baza powiększona";//test
	delete[] temp;
}
Car* auto_() {

	Car* car_ = new Car;
	std::string marka, model, stan, typ, gearbox;
	int rocznik, cena;
	long int przebieg;
	std::cout << "Marka: ";
	std::cin >> marka;
	car_->set_marka(marka);
	std::cout << "Model: ";
	std::cin >> model;
	car_->set_model(model);
	std::cout << ": ";
	std::cin >> model;
	car_->set_model(model);
	return car_;

}
void menu_cars_file_opening()
{
	int l_num = 1;//liczy linie
	std::fstream cars;
	cars.open("cars.txt", std::ios::in);
	if (cars.good() == false) {
		std::cout << "Unable to open the file 'cars.txt'.";
		std::cout << "Sending back to menu ...";
		Sleep(2000);
		menu();
	}
	std::string line;
	while (std::getline(cars, line)) {
		if (l_num > 8) { l_num = 1; };
		switch (l_num)
			std::cout << line << std::endl;
	}
}

void cars_show()
{
	system("cls");
	for (int i = 0; i < bd_cars_size; i++) { std::cout << bd_cars[i]; }
	Sleep(4000);
	std::cout << "Back to menu (click eneter) ";
	getchar();
	menu();
}

void cars_add()
{
}

