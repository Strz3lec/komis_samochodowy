#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <Windows.h>
#include "Global.h"
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
		menu_cars_file_opening();
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
	while (true) {
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
			break;
		}
	}
}
void bd_(Car* obj)//error chyba gdzieś tutaj
{
	baza.push_back(obj);
}
Car* auto_() {

	Car* car_ = new Car;
	std::fstream file("files/cars.txt", std::ios::out | std::ios::app);
	std::string marka, model, stan, typ, gearbox;
	int rocznik, cena;
	long int przebieg;
	std::cout << "Marka: ";
	std::cin >> marka;
	car_->set_marka(marka);
	file << std::endl<<std::endl << marka;
	std::cout << "Model: ";
	std::cin >> model;
	car_->set_model(model);
	file << std::endl << model;
	std::cout << "Skrzynia biegów: ";
	std::cin >> gearbox;
	car_->set_gearbox(gearbox);
	file << std::endl << gearbox;
	std::cout << "Stan: ";
	std::cin >> stan;
	car_->set_stan(stan);
	file << std::endl << stan;
	std::cout << "Typ: ";
	std::cin >> typ;
	car_->set_typ(typ);
	file << std::endl << typ;
	std::cout << "Rocznik: ";
	std::cin >> rocznik;
	car_->set_rocznik(rocznik);
	file << std::endl << rocznik;
	std::cout << "Przebieg: ";
	std::cin >> przebieg;
	car_->set_przebieg(przebieg);
	file << std::endl << przebieg;
	std::cout << "Cena: ";
	std::cin >> cena;
	car_->set_cena(cena);
	file << std::endl << cena;
	return car_;

}
void menu_cars_file_opening()
{
	int l_num = 1;//liczy linie
	std::fstream cars;
	cars.open("files/cars.txt", std::ios::in);
	if (cars.good() == false) {
		std::cout << "Unable to open the file 'cars.txt'.";
		std::cout << "Sending back to menu ...";
		Sleep(2000);
		menu();
	}
	std::string line;
	Car* obj=new Car;
	while (std::getline(cars, line)) {
		switch (l_num) {
		case 1: obj->set_marka(line);
			break;
		case 2: obj->set_model(line);
			break;
		case 3: obj->set_gearbox(line);
			break;
		case 4:obj->set_stan(line);
			break;
		case 5:obj->set_typ(line);
			break;
		case 6:obj->set_rocznik(std::stoi(line));
			break;
		case 7:obj->set_cena(std::stoi(line));
			break;
		case 8:obj->set_przebieg(std::stoi(line));
			break;
		case 9:break;
		default: std::cout << "Something went wrong to menu";
			Sleep(3000);
			exit(1);
		}
		if (l_num < 9) {
			l_num = 1;
			bd_(obj);
			delete obj;
			obj = new Car;
		}
		l_num++;
		/*std::cout << line << std::endl;*/
	}
	delete obj;
	menu_cars();
	int d;
	
	std::cout << "1.Back to cars menu\n";
	std::cout << "2.Back to menu\n";
	while (true)
	{
		std::cin >> d;
		switch (d)
		{
		case 1: menu_cars();
		case 2: menu();
		default:
			std::cout << "There's no such a choice. Choose again";
			Sleep(2000);
			break;
		}
	}

}


void cars_show(){
	int d;
	system("cls");
	for (auto const& i:baza) { 
		std::cout << i->get_marka() << std::endl;
		std::cout << i->get_model() << std::endl;
		std::cout << i->get_gearbox() << std::endl;
		std::cout << i->get_stan() << std::endl;
		std::cout << i->get_typ() << std::endl;
		std::cout << i->get_rocznik() << std::endl;
		std::cout << i->get_przebieg() << std::endl;
		std::cout << i->get_cena() << std::endl;
	}
	Sleep(4000);
	std::cout << "1.Back to cars menu\n";
	std::cout << "2.Back to menu\n";
	while (true)
	{
		std::cin >> d;
		switch (d)
		{
		case 1: menu_cars();
		case 2: menu();
		default:
			std::cout << "There's no such a choice. Choose again";
			Sleep(2000);
			break;
		};
	};
	
}

void cars_add()
{
	system("cls");
	bd_(auto_());
	
}

