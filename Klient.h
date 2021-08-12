#ifndef KLIENT_H
#define KLIENT_H

class Klient {

    std::string imie, nazwisko, meil;

public:

    void set_imie();
    void set_nazwisko();
    void set_meil();
    std::string get_imie();
    std::string get_nazwisko();
    std::string get_meil();
    Klient(std::string= "Brak", std::string= "Brak", std::string= "Brak");
    ~Klient();
};


#endif // !KLIENT>H

