#ifndef MENU_H
#define MENU_H
//----------------------------------menu główne---------------------------------------------
void menu();
//----------------------------------menu logowań--------------------------------------------
void menu_log();
//----------------------------------menu samochodów-----------------------------------------
void bd_(Car*obj);
Car* auto_();
void menu_cars();
void menu_cars_logged();//to do
void menu_cars_file_opening();//nie do końca działa
void cars_show(); // odczytywanie pliku w którym są zapisane pojazdy
void cars_add();//dodawanie aut do listy i pliku; to do


#endif //!MENU>H
