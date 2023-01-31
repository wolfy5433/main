#pragma once

class User
{
private:
	string _userName;
	string _login;
	int _password; 

public:
	//User() = default;
	User(string userName, string login, int password);
};

