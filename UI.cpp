#include "UI.h"
#include "Service.h"
#include "Mancare.h"
#include "Shopping.h" 
#include "Login.h"
#include "RepoCSV.h"
#include "RepoHTML.h"
#include "User.h"
void UI::choseFile() {
	int o;
	cout << "Alege tip de fisier:  \n";
	cout << "1.CSV. \n";
	cout << "2.HTML" << endl;
	cin >> o;
	if (o == 1) {
		cout << "Ati ales fisierul de tip CSV." << endl;
		RepoCSV<Comanda&>& r = *new RepoCSV<Comanda&>("Comenzi.csv");
		Service<Comanda&>* s = new Service<Comanda&>(r);
		this->s = s;
	}
	else if (o == 2) {

		RepoHTML<Comanda&>& r = *new RepoHTML<Comanda&>("Comenzi.html");
		Service<Comanda&>* s = new Service<Comanda&>(r);
		this->s = s;
	}
	else if (o == 8) exit(0);
	else {
		cout << "Optiune inexistenta!" << endl;
		choseFile();
	}
}
void UI::addComandaMancare() {

	char numeClient[10];
	string adresaClient;
	string cuv;
	float pretTotal;
	vector<string> listaPreparate = { };
	int n;
	cout << "Nume: "; cin >> numeClient;
	cout << "Adresa: "; std::getline(std::cin >> std::ws, adresaClient);
	cout << "Pret: "; cin >> pretTotal;
	cout << "Lista Preparate \n";
	cout << "Numar preparate: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Preparat" << " " << i << ":";
		cin >> cuv;
		listaPreparate.push_back(cuv);
	}
	Mancare* m = new Mancare(numeClient, adresaClient, pretTotal, listaPreparate);
	s->addElem(*m);

}

void UI::addComandaShopping() {

	char numeClient[10];
	string adresaClient;
	string cuv;
	float pretTotal;
	vector<string> listaCumparaturi;
	char numeMagazin[10];
	int n;
	cout << "Nume: "; cin >> numeClient;
	cout << "Adresa: "; std::getline(std::cin >> std::ws, adresaClient);
	cout << "Pret: "; cin >> pretTotal;
	cout << "Lista cumparaturi \n";
	cout << "Numar cumparaturi: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Produsul " << " " << i << ":";
		cin >> cuv;
		listaCumparaturi.push_back(cuv);
	}
	cout << "Nume magazin: "; cin >> numeMagazin;
	Shopping* sp = new Shopping(numeClient, adresaClient, pretTotal, listaCumparaturi, numeMagazin);
	s->addElem(*sp);
}
void UI::showComenzi() {

	map<int, Comanda&> elem;
	elem = s->showElem();
	for (auto i = elem.begin(); i != elem.end(); i++) {
		cout << "Comanda" << " " << (i->first) << "\n";
		cout << " " << endl;
		cout << (i->second).toStringCSV() << endl;
		cout << "-------------------------------" << endl;
	}
}

void UI::deleteComanda() {
	int pos;
	cout << "Dati pozitia comenzii pe care doriti sa o stergeti: "; cin >> pos;
	s->delElem(pos);
	cout << "Elementul a fost sters cu succes.";
	
	 

}

void UI::updateComanda() {

	int pos;
	char numeClient[10];
	string adresaClient;
	string cuv;
	float pretTotal;
	int n;
	vector<string> listaPreparate;
	cout << "Dati pozitia comenzii pe care doriti sa o modificati: "; cin >> pos;
	std::map<int, Comanda&>::iterator it;
	map<int, Comanda&> elem = s->showElem();
	it = elem.find(pos);
	dynamic_cast<Comanda&> (s->showElem().find(pos)->second); // covert to derived class 
	if (typeid(s->showElem().find(pos)->second) == typeid(Mancare)) {
		cout << "Num: "; cin >> numeClient;
		cout << "Adresa: "; std::getline(std::cin >> std::ws, adresaClient);
		cout << "Pret: "; cin >> pretTotal;
		cout << "Lista Preparate \n";
		cout << "Numar preparate: "; cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "Preparat" << " " << i << ":";
			cin >> cuv;
			listaPreparate.push_back(cuv);
		}
		Mancare* m = new Mancare(numeClient, adresaClient, pretTotal, listaPreparate);
		
			s->updateElem(pos, *m);
			cout << "Modificarea a avut succes!.";
		
		

	}
	else {
		vector<string> listaCumparaturi;
		char numeMagazin[10];
		int k;
		cout << "Nume: "; cin >> numeClient;
		cout << "Adresa: "; std::getline(std::cin >> std::ws, adresaClient);
		cout << "Pret Total: "; cin >> pretTotal;
		cout << "Lista cumparaturi \n";
		cout << "Numar cumparaturi: "; cin >> k;
		for (int i = 0; i < k; i++) {
			cout << "Produsul " << " " << i << ":";
			cin >> cuv;
			listaCumparaturi.push_back(cuv);
		}
		cout << "Nume magazin: "; cin >> numeMagazin;
		Shopping* sp = new Shopping(numeClient, adresaClient, pretTotal, listaCumparaturi, numeMagazin);
		
			s->updateElem(pos, *sp);
			cout << "Modificarea a avut succes.";
		
		 
	}
}
void UI::searchByName() {

	string numeClient;
	cout << "Nume client: "; std::getline(std::cin >> std::ws, numeClient);
	cout << "Comenzi: " << endl;
	map<int, Comanda&> elem;
	elem = s->show(numeClient);
	for (auto i = elem.begin(); i != elem.end(); i++) {
		cout << "Comanda" << " " << i->first << endl;
		cout << (i->second).toStringCSV() << endl;
	}
}

void UI::login() {

	// initializare

	User u1("david", "1234");
	User u2("Andrei", "1234");

	vector<User> users;
	users.push_back(u1);
	users.push_back(u2);






	bool succes = false;
	string username, password;
	string a, b;
	while (!succes) {
		cout << "Bine ati venit!" << endl;
		cout << "ID: "; cin >> username;
		cout << "Parola: "; cin >> password;
		for (int i = 0; i < users.size(); i++)
		{
			a = users[i].getPassword();
			b = users[i].getUsername();
			if (( b == username) && (a == password))
			{
				
				succes = true;
			
			}
		}
			
	}
	showComenzi();
}
void UI::Logout() {

	logIn = false;
}
void UI::showUI() {

	choseFile();
	login();
	PrintMenu();
}
void UI::PrintMenu() {

	cout << endl;
	while (true) {
		cout << endl;
		std::cout << "\n";
		std::cout << "-------------- Main Menu --------------" << std::endl;
		std::cout << "Alegeti o optiune: " << std::endl;
		std::cout << "1. Adaugare comanda din categoria mancare." << std::endl;
		std::cout << "2. Adaugare comanda din categoria shopping." << std::endl;
		std::cout << "3. Afisare comenzi." << std::endl;
		std::cout << "4. Modificare comanda." << std::endl;
		std::cout << "5. Cautare dupa nume client." << std::endl;
		std::cout << "6. Stergere comanda." << std::endl;
		std::cout << "7. Logout." << std::endl;
		std::cout << "8. Exit." << std::endl;
		std::cout << "---------------------------------------"<<endl;
		int opt;
		cin >> opt;
		switch (opt) {
		case 1: {
			addComandaMancare();
			break; }
		case 2: {
			addComandaShopping(); 
			 break; }
		case 3: {showComenzi(); break; 
		}
		case 4: {updateComanda(); break;
		}
		case 5: {searchByName(); break;
		}
		case 6: {deleteComanda(); break; 
		}
		case 7: {

			Logout(); 
			showUI();
			break; 
		}
		case 8: {cout << "Programul se inchide!" << endl; exit(0); }
		default: {cout << "Optiune invalida. Va rugam sa aelgeti doar din meniul afisat!" << endl; }
		}
	}
}
