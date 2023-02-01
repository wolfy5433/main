#include "chat.h"

using namespace std;

User::User(string userName, string login, int password) : _userName(userName), _login(login), _password(password)
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

User* User::plusOneElement(User* data, int size)
{
	User* coppyOfData = new User[size + 1];
	for (int i = 0; i < size; ++i)
		coppyOfData[i] = data[i];
	delete[] data;
	return coppyOfData;
}

string User::GetUserName()
{
	return _userName;
}

void User::SetMessage(string message)
{
	_message = message;
}

string User::GetMessage()
{
	return _message;
}

ostream& operator<<(ostream& output, const User& us)
{
	output << us._userName << endl;
	output << us._login << endl;
	output << us._password << endl;

	return output;
}
int User::Check(string login, int password)
{
	int count = 0;
	if ((_login == login) && (_password == password))
	{
		cout << _userName << ", вход в аккаунт произведен успешно" << endl;
		count += 1;
	}
	return count;
};