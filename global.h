#ifndef GLOBAL_H
#define GLOBAL_H
#include <vector>
#include <map>
#include <iostream>
#include "Klient.h"
#include "Car.h"
static std::vector <Car*> baza;
static std::vector <Klient*> kl_baza;
static std::map<std::pair<std::string, int>, int> user_id;
static bool is_logged = 0;
static Klient* current_user = new Klient;
#endif // !GLOBAL_H

