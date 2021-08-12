#include <iostream>
#include <string>
#include "Klient.h"
int main()
{
   /* _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
    Klient* Marcin = new Klient;
    Marcin->set_imie("Marcin");
    Marcin->set_nazwisko("Niewiadomski");
    Marcin->set_meil("mniewiadomski@cos_tam.pl");
    std::cout<<Marcin->get_imie()<<std::endl;
    std::cout<< Marcin->get_nazwisko() << std::endl;
    std::cout<< Marcin->get_meil() << std::endl;
    delete Marcin;
}

