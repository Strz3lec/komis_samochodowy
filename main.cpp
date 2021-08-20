#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "Klient.h"
#include "Car.h"
#include "Menu.h"


int main()
{
    setlocale(LC_ALL, "");
   /* _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
	std::cout << "WITAMY W KOMISIE SAMOCH0DOWYM!!!!\n";
	Sleep(3000);
	menu();
    
}

