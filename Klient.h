#ifndef KLIENT_H
#define KLIENT_H

class Klient {
public:
    void set_imie(std::string);
    void set_nazwisko(std::string);
    void set_meil(std::string);
    std::string get_imie();
    std::string get_nazwisko();
    std::string get_meil();
private:
    std::string imie, nazwisko, meil;
};


#endif // !KLIENT>H

