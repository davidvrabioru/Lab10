#pragma once
#include <string>
#include<iostream>
#include<vector>
#include "Repo.h"
#include "RepoCSV.h"
#include "RepoHTML.h"
#include "RepoFile.h"
#include "Mancare.h"
#include "Comanda.h"
#include "Shopping.h"
using namespace std;
template<class T>
class Service {
private:
	Repo<Comanda&>& r;

public:
	Service(Repo<Comanda&>& repo) :r(repo) { r = repo;};
	~Service();
	void addElem(T t);
	int delElem(int);
	int updateElem(int, T);
	int getSize();
	Comanda& find(int i);
	map<int, Comanda&> showElem();
	map<int, Comanda&> show(string);
	string getType(T);

};

template<class T> Service<T>::~Service() {

}
template<class T> void Service<T>::addElem(T t) {
	r.addElem(t);
}
template<class T> int Service<T>::delElem(int i)
{
	r.delElem(i);
		
	return 0;

}
template<class T> int Service<T>::updateElem(int i, T t) {

	r.updateElem(i, t);
		
	return 0;
}
template<class T> int Service<T>::getSize() {

	return r.getSize();
}
template<class T> map<int, Comanda&> Service<T>::showElem() {

	return r.getAll();
}
template<class T> Comanda& Service<T>::find(int i) {

	return r.find(i);
}
template<class T> map<int, Comanda&> Service<T>::show(string username) {

	int key = 0;
	map<int, Comanda&> elem;
	elem = r.getAll();
	map<int, Comanda&> rez;
	for (auto i = elem.begin(); i != elem.end(); i++) {
		string ch_username = i->second.getNumeClient();
		if (username.compare(ch_username) == 0) {
			rez.insert(pair<int, Comanda&>(key++, i->second));

		}
	}
	return rez;
}
template<class T> string Service<T>::getType(T t) {

	return typeid(t).name();
}
