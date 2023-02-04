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
	string _password;
	string _message;

public:
	User() = default;
	User(string userName, string login, string password);
	User(const User& other);
	~User();
	 User* plusOneElement(User* data, int size);
	 string GetUserName() const;
 void SetMessage(string message);
	 string GetMessage() const;
	 string GetLogin() const;
	friend ostream& operator<<(ostream& output, const User& us);
	bool CheckEnter(string login, string password);
};
;
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
	void PushBackMessage(string msg);
	friend ostream& operator<<(ostream& output, const MessageArray& msgArr);
};

void clearCin();

