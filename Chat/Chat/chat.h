#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class User
{
private:
	string _userName;
	string _login;
	int _password;
	string _message;

public:
	User() = default;
	User(string userName, string login, int password);
	User(const User& other);
	~User();
	User* plusOneElement(User* data, int size);
	string GetUserName();
	void SetMessage(string message);
	string GetMessage();
	friend ostream& operator<<(ostream& output, const User& us);
};

