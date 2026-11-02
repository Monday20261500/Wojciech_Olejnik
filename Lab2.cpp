#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
class tablica{
    private:
        int* tab;
        int rozmiar;
    public:
        tablica(int wielkosc = 10)
        {
        	rozmiar = wielkosc;
            tab = new int[wielkosc];
            for (int i = 0;i < wielkosc;i++)
            {
            	tab[i] = 0;
			}
        }
        ~tablica() {
        	delete[] tab;
        	std::cout<<"Tablica o wielkosci "<<rozmiar<<" zostala pokonana"<<std::endl;
 		}
};
class samochod {
    private:
        std::string make;
        std::string model;
        int rokProdukcji;
    public:
        samochod(std::string make = "Toyota(chyba)", std::string model = "Corrola(prawdobodobnie)", int rokProdukcji = 1999)
        {
            this->make = make;
            this->model = model;
            this->rokProdukcji = rokProdukcji;
        }
		~samochod() {
			std::cout<<"Deskruktor wywolany dla "<<make<<" "<<model<<std::endl;
		}
};
int main(){
	int wybor;
	std::cout<<"wybierz zadanie wpisujac jego numer";
	std::cin>>wybor;
	switch (wybor) {
		case 1:
		{
			samochod MineSamochod;
    		samochod HisSamochod("Toyota(napewno)", "Corrola(bez dwoch zdan)", 2022);
			break;
		}
		case 2:
		{
			tablica MineTablica;
    		tablica HisTablica(5);
			break;
		}
		default:
		{
			std::cout<<"Nie wybrales zadania";
			break;
		}
	}
	return 0;
}