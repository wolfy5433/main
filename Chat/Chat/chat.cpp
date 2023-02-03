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
bool User::Check(string login, int password)
{
	if ((_login == login) && (_password == password))
	{
		cout << _userName << ", ���� � ������� ���������� �������" << endl;
		return true;
	}
	return false;
};
 
MessageArray::MessageArray(int size) : _msgArr(new string[size]), _size(size)
{

}

void MessageArray::CoppyOfMsgArr(int newSize)
{
	string* msgArr = new string[newSize];
	for (int index = 0; index < _size; ++index)
	{
		msgArr[index] = _msgArr[index];
	};

	delete[] _msgArr;
	_msgArr = msgArr;
	_size = newSize;
}

void MessageArray::Test(string msg)
{
	CoppyOfMsgArr(_size + 1);
	_msgArr[_size - 1] = msg;
}

MessageArray::~MessageArray()
{

}

ostream& operator<<(ostream& output, const MessageArray& msgArr)
{
	for (int i = 0; i < msgArr._size; ++i)
	{
		output << msgArr._msgArr[i] << ' ';
	}
	output << '\n';
	return output;
}

void clearCin()
{
	cin.clear();
	cin.ignore(32767, '\n');
}