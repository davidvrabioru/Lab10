#pragma once
#include <string>
#include<ostream>
using namespace std;
class User {
private:

	string username;
	string password;

public:
	User();
	User(string, string p);
	~User();
	string getUsername();
	string getPassword();
	bool operator==(const User&);
};