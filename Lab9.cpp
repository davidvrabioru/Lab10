#include <iostream>
#include "TesteEntitati.h"
#include "TesteRepo.h"
#include "RepoFile.h"
#include "Mancare.h"
#include "Shopping.h"
#include "Service.h"
#include "UI.h"

using namespace std;


int main()
{
	cout << endl;
	cout << "Testele: ";
	testComanda();
	testMancare();
	testShopping();
	addElemComanda();
	deleteElemComanda();
	updateElemComanda();
	getAllComanda();
	addElemMancare();
	deleteElemMancare();
	updateElemMancare();
	getAllMancare();
	addElemShopping();
	deleteElemShopping();
	updateElemShopping();
	getAllShopping();
	
	cout << "Succes!" << endl;
	RepoFile<Comanda&> r;
	Service<Comanda&> s(r);
	UI u(s);
	u.showUI();


}