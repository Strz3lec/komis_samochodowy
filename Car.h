#ifndef CAR_H
#define CAR_H
class Car {
	std::string marka, model,stan,typ,gearbox;
	int rocznik,cena;
	long int przebieg;
public:
	Car(std::string = "Brak", std::string = "brak", std::string = "manualna", std::string = "używany", std::string = "benzyna", int = 0, int = 0, long int = 0);
	~Car();

	void set_marka(std::string);
	void set_model(std::string);
	void set_gearbox(std::string);
	void set_stan(std::string);
	void set_typ(std::string);
	void set_rocznik(int);
	void set_cena(int);
	void set_przebieg(long int);
	std::string get_marka();
	std::string get_model();
	std::string get_gearbox();
	std::string get_stan();
	std::string get_typ();
	int get_rocznik();
	int get_cena();
	long int get_przebieg();
	
	friend  std::ostream& operator<<(std::ostream& os, const Car& ptr) {

		os << "Samochod: " << std::endl; //lets pretend its styled nicely.
		os << "Marka: " << ptr.marka << std::endl;
		os << "Model: " << ptr.model << std::endl;
		os << "Skrzynia biegów: " << ptr.gearbox << std::endl ;
		os << "Stan: " << ptr.stan << std::endl;
		os << "Typ: " << ptr.typ << std::endl;
		os << "Rocznik: " << ptr.rocznik << std::endl;
		os << "Przebieg: " << ptr.przebieg << std::endl;
		os << "cena" << ptr.cena << std::endl<<std::endl;
		return os;
	}
};

#endif // !CAR_>H
