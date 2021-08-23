#ifndef KLIENT_H
#define KLIENT_H

class Klient {

    std::string imie, nazwisko, meil;

public:

    void set_imie(std::string);
    void set_nazwisko(std::string);
    void set_meil(std::string);
    std::string get_imie();
    std::string get_nazwisko();
    std::string get_meil();
    Klient(std::string= "Brak", std::string= "Brak", std::string= "Brak");
    ~Klient();
    //logowanie to do
};


#endif // !KLIENT>H

