#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cctype>
class osoba {
	private:
		std::string imie;
		std::string nazwisko;
		std::string email;
		std::string telefon;
		int wiek;
	public:
		osoba(std::string imie = "brak imienia", std::string nazwisko = "brak nazwiska", int wiek = 0, std::string email = "brak emaila", std::string telefon = "brak telefonu")
		{
			this->imie = imie;
			this->nazwisko = nazwisko;
			this->wiek = wiek;
			this->email = email;
			this->telefon = telefon;
		}
		std::string GetImie() const {
			return imie;
		}
		std::string GetNazwisko() const {
			return nazwisko;
		}
		std::string GetEmail() const {
			return email;
		}
		std::string GetTelefon() const {
			return telefon;
		}
		int GetWiek() const {
			return wiek;
		}
		void setImie(const std::string& noweImie) {
			imie = noweImie;
		}
		void setNazwisko(const std::string& noweNazwisko) {
			nazwisko = noweNazwisko;
		}
		void setEmail(const std::string& noweEmail) {
			if (noweEmail.find("@") != std::string::npos)
				email = noweEmail;
			else
				std::cout<<"Email bez @"<<std::endl;
		}
		void setTelefon(const std::string& noweTelefon) {
			if (std::all_of(noweTelefon.begin(), noweTelefon.end(), ::isdigit) == 1 && noweTelefon.length() == 9)
				telefon = noweTelefon;
			else
				std::cout<<"Telefon nie ma 9 cyfr"<<std::endl;
		}
		void setWiek(int noweWiek) {
			if (noweWiek >= 0)
				wiek = noweWiek;
			else
				std::cout<<"podany wiek jest ujemny"<<std::endl;
		}
};
class Pracownik {
	protected:
		std::string stanowisko;
		float wynagrodzenie;
	public:
		Pracownik(const std::string& stanowisko = "brak stanowiska", float wynagrodzenie = 0)
		: stanowisko(stanowisko), wynagrodzenie(wynagrodzenie) {}
};
class Nauczyciel : public Pracownik {
	private:
		std::string przedmiot;
	public:
		Nauczyciel(const std::string& stanowisko = "brak stanowiska", float wynagrodzenie = 0, const std::string& przedmiot = "brak przedmiotu")
		: Pracownik (stanowisko, wynagrodzenie), przedmiot(przedmiot) {}
		void pokazDane() const {
			std::cout<<"Nauczyciel"<<std::endl;
			std::cout<<"stanowisko: "<<stanowisko<<std::endl;
			std::cout<<"wynagrodzenie: "<<wynagrodzenie<<std::endl;
			std::cout<<"przedmiot: "<<przedmiot<<std::endl;
		} 
		
};
class Administracja : public Pracownik {
	private:
		std::string dzial;
	public:
		Administracja(const std::string& stanowisko = "brak stanowiska", float wynagrodzenie = 0, const std::string& dzial = "brak dzialu")
		: Pracownik (stanowisko, wynagrodzenie), dzial(dzial) {}
		void pokazDane() const {
			std::cout<<"Administracja"<<std::endl;
			std::cout<<"stanowisko: "<<stanowisko<<std::endl;
			std::cout<<"wynagrodzenie: "<<wynagrodzenie<<std::endl;
			std::cout<<"dzial: "<<dzial<<std::endl;
		} 
		
};
int main() {
	int wybor;
	std::cout<<"wybierz zadanie wpisujac jego numer (1 lub 2)";
	std::cin>>wybor;
	switch (wybor) {
		case 1:
		{
			osoba MineOsoba;
			MineOsoba.setImie("Marcus");
			MineOsoba.setNazwisko("Wolfgang");
			MineOsoba.setEmail("marcus.wolfgang@gmail.com");
			MineOsoba.setTelefon("689534934");
			MineOsoba.setWiek(31);
			std::cout<<MineOsoba.GetImie()<<std::endl;
			std::cout<<MineOsoba.GetNazwisko()<<std::endl;
			std::cout<<MineOsoba.GetEmail()<<std::endl;
			std::cout<<MineOsoba.GetTelefon()<<std::endl;
			std::cout<<MineOsoba.GetWiek()<<std::endl;
			osoba HisOsoba;
			HisOsoba.setImie("Friedrich");
			HisOsoba.setNazwisko("Schneider");
			HisOsoba.setEmail("friedrich.schneidergmail.com");
			HisOsoba.setTelefon("68954934");
			HisOsoba.setWiek(-34);
			std::cout<<HisOsoba.GetImie()<<std::endl;
			std::cout<<HisOsoba.GetNazwisko()<<std::endl;
			std::cout<<HisOsoba.GetEmail()<<std::endl;
			std::cout<<HisOsoba.GetTelefon()<<std::endl;
			std::cout<<HisOsoba.GetWiek()<<std::endl;
		}
		case 2:
		{
			Nauczyciel MineNauczyciel;
			Administracja MineAdministracja;
			MineNauczyciel.pokazDane();
			MineAdministracja.pokazDane();
			Nauczyciel HisNauczyciel("Dr.Hab.", 7809.23f, "Fizyka kwantowa");
			Administracja HisAdministracja("Spc.Spraw Zagranicznych", 7809.22f, "Ksiegowosc");
			HisNauczyciel.pokazDane();
			HisAdministracja.pokazDane();
			break;
		}
		default:
		{
			std::cout<<"Nie wybrales zadania"<<std::endl;
		}
	}
	return 0;
}