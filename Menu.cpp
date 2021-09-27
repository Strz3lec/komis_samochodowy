#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <vector>
#include <Windows.h>
#include "Global.h"
#include "Car.h"
#include "Menu.h"
#include <sstream>


void menu();
void menu_cars();
void cars_show();
void cars_add();
void bd_(Car* obj);
Car* auto_();

void menu()//menu główne
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
	case 1: menu_log();
	case 2:system("cls");
		menu_cars();
	case 3:
	case 4:std::cout << std::endl << "Thanks for using this programm see you soon :)";
		Sleep(2000);
		exit(0);
	default:
		std::cout << std::endl << "It's impossible to do this action. Choose again what do you want to do.";
		menu();
	}
}
void menu_is_logged(Klient*user)//menu główne po zalogowaniu
{
	int d;
	system("cls");
	std::cout << "Zalogowano: " << user->get_nick()<<std::endl;
	std::cout << "1. Logowanie/Rejestracja\n";
	std::cout << "2. Pojazdy\n";
	std::cout << "3. Moje konto\n";
	std::cout << "4. Exit\n\n";
	std::cout << "Co chcesz zrobić? ";
	std::cin >> d;
	switch (d)
	{
	case 1: menu_log();
	case 2:system("cls");
		menu_cars();
	case 3:
	case 4:std::cout << std::endl << "Thanks for using this programm see you soon :)";
		Sleep(2000);
		exit(0);
	default:
		std::cout << std::endl << "It's impossible to do this action. Choose again what do you want to do.";
		menu();
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------
void menu_log()
{
	system("cls");
	int odp;
	std::cout << "1.Zaloguj\n" << "2.Zarejestruj\n"<<"3.Menu\n";
	std::cin >> odp;
	switch (odp) {
	case 1: logowanie();
	case 2: rejestracja();
	case 3: if (is_logged == 1)
		menu_is_logged(current_user);
	default: std::cout << "There's no such a choice. Choose again";
		Sleep(2000);
		menu_log();
	}
}
auto password_hide()
{
	std::string pass = "";
	std::string star = "";
	char ch;
	ch = _getch();
	while (ch != 13) {
		pass.push_back(ch);
		if (ch == 8 && pass.size() != 0) {
			star.pop_back();
			pass.pop_back();
		}
		else
			star.push_back('*');

		std::cout << '*';
		ch = _getch();
	}
	return pass;
}
struct passwords {
	size_t password1, password2;
};
passwords* passw_validation(passwords* passed_tuple) {
	std::string passw1,passw2;
	std::cout << std::endl << "Hasło: ";
	passw1 = password_hide();
	passed_tuple->password1 = std::hash<std::string>{}(passw1);
	std::cout << std::endl << "Powtórze hasło: ";
	passw2 = password_hide();
	passed_tuple->password2 = std::hash<std::string>{}(passw2);
	if (passed_tuple->password1 != passed_tuple->password2) {
		std::cout << std::endl << std::endl << "Hasła nie są takie same";
		passw_validation(passed_tuple);
	}
	return passed_tuple;
}
void rejestracja() {
	system("cls");
	std::fstream file("files/users.txt", std::ios::out | std::ios::app);
	passwords* tuple = new passwords;
	Klient* klient = new Klient;
	std::string login, imie, nazwisko, meil;
	std::cout << "\t\t\t\t\tRejestracja. \n\n";
	std::cout << "\nLogin: "; std::cin >> login;
	std::cout << "\nImię: "; std::cin >> imie;
	std::cout << "\nNazwsiko: "; std::cin >> nazwisko;
	std::cout << "\nMeil: "; std::cin >> meil;
	tuple = passw_validation(tuple);

	if (tuple != NULL) {
		klient->set_imie(imie);
		if (kl_baza.size() < 1)
			file << imie;
		else
			file << std::endl << imie;
		klient->set_nazwisko(nazwisko);
		file << std::endl << nazwisko;
		klient->set_meil(meil);
		file << std::endl << meil;
		klient->set_nick(login);
		file << std::endl << login;
		klient->set_passw(tuple->password1);
		file << std::endl << tuple->password1;
		file << std::endl << klient->return_id();
		kl_baza.push_back(klient);
		std::cout << "\nUser added to database\n\n";
		user_id[{login, tuple->password2}] = klient->return_id();
	}
	delete klient;
	delete tuple;
	menu_log();
}
size_t validate_passw() {
	size_t pas;
	std::string passw_;
	std::cout << "Enter password: \n";
	passw_ = password_hide();
	pas = std::hash<std::string>{}(passw_);
	return pas;
}
void logowanie()
{
	system("cls");
	std::string login;
	size_t password;
	int id;
	std::cout << " \t\t\t\t\Logowanie.\n\n";
	std::cout << "Login: ";
	std::cin >> login;
	password = validate_passw();//gdzieś tu jest błąd
	id = user_id[{login, password}];
	for (auto const i : kl_baza) {
		if (i->return_id() == id)
		{
			is_logged = 1;
			current_user = i;
			menu_is_logged(current_user);
		}
		else {
			std::cout << "\n\nNie udało się zalogować!!!!!!";
			Sleep(2000);
			menu_log();
		}
	}
}

void kl_(Klient* obj) {
	kl_baza.push_back(obj);
}

void menu_log_file_openning()
{
	int l_num = 1;//liczy linie
	std::fstream users;
	users.open("files/users.txt", std::ios::in);
	if (users.good() == false) {
		std::cout << "Unable to open the file 'cars.txt'.";
		std::cout << "Sending back to menu ...";
		Sleep(2000);
		menu();
	}
	std::string line;
	std::stringstream lne;
	size_t result;
	Klient* obj = new Klient;
	while (std::getline(users, line)) {
		switch (l_num) {
		case 1: obj->set_imie(line);
			break;
		case 2: obj->set_nazwisko(line);
			break;
		case 3: obj->set_meil(line);
			break;
		case 4:obj->set_nick(line);
			break;
		case 5:
			 lne<<line;
			 lne >> result;
			obj->set_passw(result);//tu wyskakuje wyjątek ale nie wiem dlaczego!!!!!!!!!!!!!!!!!!
			break;
		case 6:obj->set_id(std::stoi(line));
			break;
		default: std::cout << "Something went wrong to menu";
			Sleep(3000);
			exit(1);

		}
		if (l_num == 6) {
			l_num = 0;
			kl_(obj);
			obj = new Klient;
		}
		l_num++;
		/*std::cout << line << std::endl;*/
	}

	for (auto const& i:kl_baza) {
		std::cout << i->get_nick() << std::endl;
		std::cout << i->get_imie() << std::endl;
		std::cout << i->get_nazwisko() << std::endl;
		std::cout << i->get_meil() << std::endl;
		std::cout << i->return_id() << std::endl;
		std::cout << i->get_passw() << std::endl;
	}
	Sleep(5000);
	delete obj;
	
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

void bd_(Car* obj)
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
	if (baza.size() < 1)
		file << marka;
	else
		file << std::endl << marka;
	file  << std::endl << marka;
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
	Car* obj = new Car;
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
		default: std::cout << "Something went wrong to menu";
			Sleep(3000);
			exit(1);

		}
		if (l_num == 8) { 
			l_num = 0;
			bd_(obj);
			obj = new Car;
		}
		l_num++;
		/*std::cout << line << std::endl;*/
	}
	delete obj;
	/*menu_cars();*/

	/*std::cout << "1.Back to cars menu\n";
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
	}*/

}

void cars_show() {
	int d;
	system("cls");
	for (auto const& i : baza) {
		std::cout << i->get_marka() << std::endl;
		std::cout << i->get_model() << std::endl;
		std::cout << i->get_gearbox() << std::endl;
		std::cout << i->get_stan() << std::endl;
		std::cout << i->get_typ() << std::endl;
		std::cout << i->get_rocznik() << std::endl;
		std::cout << i->get_przebieg() << std::endl;
		std::cout << i->get_cena() << std::endl << std::endl;
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
//----------------------------------------------menu moje konto----------------------------------------------------------------------------------
