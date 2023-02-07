#include "chat.h"

using namespace std;

User::User(string userName, string login, string password) : _userName(userName), _login(login), _password(password)
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

string User::GetUserName() const
{
	return _userName;
}

void User::SetMessage(string message)
{
	_message = message;
}

void User::SetPassword(string newpassword)
{
	_password = newpassword;
}

string User::GetMessage() const
{
	return _message;
}

string User::GetPassword() const
{
	return _password;
}

string User::GetLogin() const
{
	return _login;
}

ostream& operator<<(ostream& output, const User& us)
{
	output <<"Имя пользователя: "<< us._userName << endl;
	output <<"Логин: "<<us._login << endl;

	return output;
}

bool User::CheckEnter(string login, string password)
{
	if ((_login == login) && (_password == password))
	{
		cout << _userName << ", вход в аккаунт произведен успешно!\n" << endl;
		return true;
	}
	return false;
}
 
MessageArray::MessageArray(int size) : _msgArr(new string[size]), _size(size)
{
	
}

MessageArray::MessageArray(const MessageArray& other)
{
	this->_size = other._size;
	
	this->_msgArr = new string[other._size];

	for (int i = 0; i < _size; ++i)
	{
		_msgArr[i] = other._msgArr[i];
	}
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

void MessageArray::PushBackMessage(string msg)
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
		output << msgArr._msgArr[i] << endl;
	}
	output << '\n';
	return output;
}

MessageArray* MessageArray::plusOneElement(MessageArray* arr, int size)
{
	MessageArray* coppyOfarray = new MessageArray[size + 1];
	for (int i = 0; i < size; ++i)
		coppyOfarray[i] = arr[i];
	delete[] arr;
	return coppyOfarray;
}

void clearCin() // Очищает буфер от символов, введённых через cin
{
	cin.clear();
	cin.ignore(32767, '\n'); 
}