#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class User
{
protected:
	string _userName;
	string _login;
	int _password;
	string _message;

public:
	User() = default;
	User(string userName, string login, int password);
	User(const User& other);
	~User();
	virtual User* plusOneElement(User* data, int size);
	string GetUserName();
	void SetMessage(string message);
	string GetMessage();
	friend ostream& operator<<(ostream& output, const User& us);
	bool Check(string login, int password);
};

class MessageArray : public User
{
private:
	string* _msgArr = nullptr;
	int _size = 0;

public:
	MessageArray() = default;
	MessageArray(int size);
	void CoppyOfMsgArr(int newSize); 
	~MessageArray();
	MessageArray* plusOneElement(MessageArray* arr, int size);
	void Test(string msg);
	friend ostream& operator<<(ostream& output, const MessageArray& msgArr);
};

void clearCin();

