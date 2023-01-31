#pragma once

class User
{
private:
	const char* _userName;
	const char* _login;
	int _password; 

public:
	User() = default;
	User(const char* userName, const char* login, int password);
	User(const User& other);
	~User();
	friend std::ostream& operator<<(std::ostream& output, const User& us);
};

