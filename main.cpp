#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "Klient.h"
#include "Car.h"

int main()
{
    setlocale(LC_ALL, "");
   /* _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
    Klient K1;/* trochę zmieniłem jak to jest napisane po tym jak obejrzałem ten tutorial bo jest to na razie dla mnie bardziej przejrzyste*/
    K1.set_imie();
    K1.set_nazwisko();
    K1.set_meil();
    system("cls");
    std::cout<< K1.get_imie()<<std::endl;
    std::cout<< K1.get_nazwisko() << std::endl;
    std::cout<< K1.get_meil() << std::endl;
    Car C1;
    C1.set_marka();
    C1.set_model();
    C1.set_rocznik();
    system("cls");
    std::cout << C1.get_marka() << std::endl;
    std::cout << C1.get_model() << std::endl;
    std::cout << C1.get_rocznik() << std::endl;
    
}

