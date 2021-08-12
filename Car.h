#ifndef CAR_H
#define CAR_H

class Car {
	std::string marka, model;
	int rocznik;
public:
	void set_marka();
	void set_model();
	void set_rocznik();

	std::string get_marka();
	std::string get_model();
	int get_rocznik();

	Car(std::string = "Brak", std::string = "brak", int = 0);
	~Car();
};

#endif // !CAR_>H
