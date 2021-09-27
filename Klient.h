#ifndef KLIENT_H
#define KLIENT_H

class Klient {

    std::string imie, nazwisko, meil,nick;
    int id_{ rand() };
    size_t passw{ 0 };
public:
    void set_nick(std::string);
    void set_imie(std::string);
    void set_nazwisko(std::string);
    void set_meil(std::string);
    void set_passw(size_t);
    void set_id(int);
    size_t get_passw();
    std::string get_imie();
    std::string get_nazwisko();
    std::string get_meil();
    std::string get_nick();
    int return_id();
    Klient(std::string= "Brak", std::string= "Brak", std::string= "Brak");
    ~Klient();
    //logowanie to do
};


#endif // !KLIENT>H

