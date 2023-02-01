#include "chat.h"

using namespace std;



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int size = 1;
	User* data = new User[size];

	string userName, login;
	int password;

	int i = 0;
	int open = 1;
	while (open != 0)
	{
		cout << "¬ведите им€: ";
		getline(cin, userName);
		cout << "¬ведите логин: ";
		getline(cin, login);
		cout << "¬ведите пароль: ";
		cin >> password;
		
		data[i] = User(userName, login, password);
		++i;

		data = data->plusOneElement(data, size); // мен€ет размер массива на + 1
		++size;

		cout << "¬ведите любуй цифру, чтобы продолжить или 0 дл€ отображени€ всех зарегестрированых пользователей: ";
		cin >> open;
		cin.clear();
		cin.ignore(32767, '\n');
	}
	cout << endl;
	for (int i = 0; i < size - 1; ++i)
	{
		cout << "јккаунт номер " << i + 1 << ':' << '\n' << data[i] << endl;
	}

	
	
	/*string x, y;
	int u;

	getline(cin, x);
	getline(cin, y);
	cin >> u;
	cin.clear();
	cin.ignore(32767, '\n');
	
	User a(x, y, u);
	cout << a;

	string b;
	getline(cin, b);

	a.SetMessage(b);

	cout << a.GetMessage() << endl;

	getline(cin, b);

	a.SetMessage(b);

	cout << a.GetMessage() << endl;*/

	return 0;
}