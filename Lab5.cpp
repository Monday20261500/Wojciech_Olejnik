#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cctype>
namespace Zad2{   // poprawnie
class Pojazd {
	protected:
		std::string marka;
		std::string model;
	public:
		Pojazd(const std::string& marka = "Toyota",const std::string& model = "Corrola") 
		: marka(marka), model(model) {}
		virtual ~Pojazd() = default;
		virtual void przyspiesz() = 0;
		void zatrzymaj() {
			std::cout<<"Pojazd hamuje"<<std::endl;
			std::cout<<marka<<std::endl<<model<<std::endl;
			std::cout<<"Pojazd sie wywroclawil w poznaniu"<<std::endl;   // ???
		}
};
class Samochod : public Pojazd {
	public:
		Samochod(const std::string& marka = "Toyota", const std::string& model = "Corrola")
		: Pojazd(marka, model) {}
		void przyspiesz() {
			std::cout<<"Samochod przyspiesza"<<std::endl;
			std::cout<<marka<<std::endl<<model<<std::endl;
		}
};
class Rower : public Pojazd {
	public:
		Rower(const std::string& marka = "Trek", const std::string& model = "Marlin")
		: Pojazd(marka, model) {}
		void przyspiesz() override{
			std::cout<<"Rower przypiesza"<<std::endl;
			std::cout<<marka<<std::endl<<model<<std::endl;
		}
};
}
namespace Zad1_3_5_6{ //private po prostu uniemozliwia urzcie metod wykorzystujacych prywatne atrybuty ???  // nie w tym rzecz - poprawic
class Pojazd {                                                                                  // brak dziedziczenia protected - uzupelnic
	protected:
		std::string marka;
		std::string model;
	public:
		Pojazd(const std::string& marka = "Toyota",const std::string& model = "Corrola") 
		: marka(marka), model(model) {}
		virtual ~Pojazd() = default;
		virtual void przyspiesz(){
			std::cout<<"Pojazd przyspiesza"<<std::endl;
			std::cout<<marka<<std::endl<<model<<std::endl;
		}
		void zatrzymaj() {
			std::cout<<"Pojazd hamuje"<<std::endl;
			std::cout<<marka<<std::endl<<model<<std::endl;
			std::cout<<"Pojazd sie wywroclawil w poznaniu"<<std::endl;
		}
};
class Samochod : public Pojazd {
	public:
		Samochod(const std::string& marka = "Toyota", const std::string& model = "Corrola")
		: Pojazd(marka, model) {}
		void przyspiesz() override{
			std::cout<<"Samochod przyspiesza"<<std::endl;
			std::cout<<marka<<std::endl<<model<<std::endl;
		}
};
class Rower : public Pojazd {
	public:
		Rower(const std::string& marka = "Trek", const std::string& model = "Marlin")
		: Pojazd(marka, model) {}
		void przyspiesz() override{
			std::cout<<"Rower przypiesza"<<std::endl;
			std::cout<<marka<<std::endl<<model<<std::endl;
		}
};
}
namespace Zad7{   // poprawnie
class Silnikowy {
	public:
		virtual ~Silnikowy() = default;
		virtual void przyspiesz() {
			std::cout<<"Silnikowy przypiesza"<<std::endl;
		}
};
class Elektryczny {
	public:
		virtual ~Elektryczny() = default;
		virtual void ladowanie() {
			std::cout<<"Elektryczny sie laduje"<<std::endl;
		}
};
class Hybrydowy : public Silnikowy, public Elektryczny {
	public:
		void przyspiesz() override {
        	std::cout << "Hybrydowy laczy dwa napedy podczas przyspieszania:" << std::endl;
        	Silnikowy::przyspiesz();
        	std::cout << "Elektryczny wspomaga silnik spalinowy" << std::endl;
    	}
};
}
namespace Zad9{   // poprawnie
class Pojazd {
	protected:
		std::string marka;
		std::string model;
	public:
		Pojazd(const std::string& marka = "Toyota",const std::string& model = "Corrola") 
		: marka(marka), model(model) {}
		virtual ~Pojazd() = default;
		virtual void przyspiesz() = 0;
		void zatrzymaj() {
			std::cout<<"Pojazd hamuje"<<std::endl;
			std::cout<<marka<<std::endl<<model<<std::endl;
			std::cout<<"Pojazd sie wywroclawil w poznaniu"<<std::endl;
		}
};
class Samochod : public Pojazd {
	public:
		Samochod(const std::string& marka = "Toyota", const std::string& model = "Corrola")
		: Pojazd(marka, model) {}
		void przyspiesz() override{
			std::cout<<"Samochod przyspiesza"<<std::endl;
			std::cout<<marka<<std::endl<<model<<std::endl;
		}
};
class ElektrycznySamochod : public Samochod {
	public:
		ElektrycznySamochod(const std::string& marka = "Nissan", const std::string& model = "Leaf")
			: Samochod(marka, model) {}
		void przyspiesz() override{
			std::cout<<"Samochod przyspiesza(Elektrycznie)"<<std::endl;
			std::cout<<marka<<std::endl<<model<<std::endl;
		}
};
}
namespace Zad10{   // poprawnie
class Pojazd {
	protected:
		std::string marka;
		std::string model;
	public:
		Pojazd(const std::string& marka = "Toyota",const std::string& model = "Corrola") 
		: marka(marka), model(model) {}
		virtual ~Pojazd() = default;
		virtual void przyspiesz()
		{
			std::cout<<"Pojazd przyspiesza"<<std::endl;
			std::cout<<marka<<std::endl<<model<<std::endl;
		}
		void zatrzymaj() {
			std::cout<<"Pojazd hamuje"<<std::endl;
			std::cout<<marka<<std::endl<<model<<std::endl;
			std::cout<<"Pojazd sie wywroclawil w poznaniu"<<std::endl;
		}
};
class Silnikowy : virtual public Pojazd{
	public:
		virtual ~Silnikowy() = default;
		Silnikowy(const std::string& marka = "Toyota", const std::string& model = "Corrola")
		: Pojazd(marka, model) {}
		virtual void przyspiesz() {
			std::cout<<"Silnikowy przypiesza"<<std::endl;
		}
};
class Elektryczny : virtual public Pojazd{
	public:
		virtual ~Elektryczny() = default;
		Elektryczny(const std::string& marka = "Nissan", const std::string& model = "Leaf")
		: Pojazd(marka, model) {}
		virtual void ladowanie() {
			std::cout<<"Elektryczny sie laduje"<<std::endl;   
		}
};
class Hybryda : public Silnikowy, public Elektryczny {
	public:
		Hybryda(const std::string& marka = "Nissan", const std::string& model = "Leaf")
		: Pojazd(marka, model) {}
		void przyspiesz() override {
        	std::cout<<"Hybrydowy laczy dwa napedy podczas przyspieszania:" << std::endl;
        	Silnikowy::przyspiesz();
        	std::cout<<"Elektryczny wspomaga silnik spalinowy"<<std::endl;
        	std::cout<<"Elektryczny sie wykrzaczyl ... bo tak"<<std::endl;
		}
};
}
int main() {
	int wybor;
	std::cout<<"wybierz zadanie wpisujac jego numer (1, 2, 7, 9, 10)";
	std::cin>>wybor;
	switch (wybor) {
		case 1:
		{
			using namespace Zad1_3_5_6;
			Pojazd MinePojazd("Toyota", "Camry");
			Samochod MineSamochod;
			Rower MineRower;
			MinePojazd.przyspiesz();
			MineSamochod.przyspiesz();
			MineRower.przyspiesz();
			MinePojazd.zatrzymaj();
			MineSamochod.zatrzymaj();
			MineRower.zatrzymaj();
			break;
		}
		case 2:
		{
			using namespace Zad2;
			Samochod MineSamochod;
			Rower MineRower;
			MineSamochod.przyspiesz();
			MineRower.przyspiesz();
			MineSamochod.zatrzymaj();
			MineRower.zatrzymaj();
			break;
		}
		case 7:
		{
			using namespace Zad7;
			Hybrydowy MineHybrydowy;
			MineHybrydowy.przyspiesz();
			MineHybrydowy.ladowanie();
			break;
		}
		case 9:
		{
			using namespace Zad9;
			ElektrycznySamochod MineElektrycznySamochod;
			MineElektrycznySamochod.przyspiesz();
			break;
		}
		case 10:
		{
			using namespace Zad10;
			Hybryda MineHybryda;
			MineHybryda.przyspiesz();
			break;
		}
		default:
		{
			std::cout<<"Nie wybrales zadania"<<std::endl;
		}
	}
	return 0;
}
