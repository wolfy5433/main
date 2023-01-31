#include "chat.h"
#include <iostream>

using namespace std;

User::User(const char* userName, const char* login, int password) : _userName(userName), _login(login), _password(password)
{
	
}

User::~User()
{

}

User::User(const User& other)
{
	_userName = other._userName;
	_login = other._login;
	_password = other._password;
}

ostream& operator<<(ostream& output, const User& us)
{
	output << us._userName << endl;
	output << us._login << endl;
	output << us._password << endl;

	return output;
}