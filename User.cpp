#include "User.h"
#include "Login.h"
#include<sstream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include "User.h"
User::User() {
	//cout << "const implicit";
	this->username = "";
	this->password = "";
}
User::User(string username, string  password) {
	//cout << "constructor with param" << endl;
	this->username = username;
	this->password = password;
}

string User::getPassword()
{
	return this->password;
}
string User::getUsername()
{
	return this->username;
}



bool User::operator==(const User& u)
{
	return (this->username == u.username) && (this->password == u.password);
}

User::~User() {

	//cout << "Destructor";

	this->username = "";
	this->password = "";

}

