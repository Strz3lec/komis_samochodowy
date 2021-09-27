#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
#include <vector>
#include "Klient.h"
#include "Car.h"
#include "Menu.h"
#include "global.h"


int main()
{
	srand(time(NULL));
    setlocale(LC_ALL, "");
	menu_cars_file_opening();//wczytuje pojazdy z pliku do bazy danych
	menu_log_file_openning();//wczytuje klientów z pliku do bazy danych
	std::cout << kl_baza.size();
	
    /*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
	std::cout << "WITAMY W KOMISIE SAMOCH0DOWYM!!!!\n";
	Sleep(3000);
	while (true) {
		menu();
	}
	delete current_user;
}

