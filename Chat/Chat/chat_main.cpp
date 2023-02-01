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
	int open;
	/*cout << "Создайте аккаунт" << endl;
	cout << "Введите имя: ";
	getline(cin, userName);
	cout << "Введите логин: ";
	getline(cin, login);
	cout << "Введите пароль: ";
	cin >> password;
	cin.clear();
	cin.ignore(32767, '\n');*/
	/*data[i] = User(userName, login, password);*/
	/*data = data->plusOneElement(data, size);
	size++;
	i++;*/
	cout << "Выберите,что вы хотите сделать" << endl;
	cout << "1.Создать аккаунт" << endl << "2.Войти в аккаунт" << endl << "3.Отобразить всех пользователей" << endl << "4.Выйти из чата" << endl;
	cin >> open;
	cin.clear();
	cin.ignore(32767, '\n');
	while (open != 4)
	{
		switch (open)
		{
		case 1:
		{
			cout << "Введите имя: ";
			getline(cin, userName);
			cout << "Введите логин: ";
			getline(cin, login);
			cout << "Введите пароль: ";
			cin >> password;
			cin.clear();
			cin.ignore(32767, '\n');
			data[i] = User(userName, login, password);
			++i;
			data = data->plusOneElement(data, size); // меняет размер массива на + 1
			++size;
			break;
		}
		case 2:
		{
			if (size == 1)
			{
				cout << "Не создано еще ни одного аккаунта" << endl;
				break;
			}
			string LoginCheck;
			int PasswordCheck;
			cout << "Введите логин" << endl;
			cin >> LoginCheck;
			cout << "Введите пароль" << endl;
			cin >> PasswordCheck;
			int b;
			for (int i = 0; i < 2; i++)
			{
				b = data[i].Check(LoginCheck, PasswordCheck);
				if (b == 1)
				{
					break;
				};
			};
			if (b == 0)
			{
				cout << "Неверный логин или пароль" << endl;
			};
			break;
		}
		case 3:
		{
			if (size == 1)
			{
				cout << "Не создано еще ни одного аккаунта" << endl;
				break;
			}
			cout << endl;
			for (int i = 0; i < size-1 ; ++i)
			{
				cout << "Аккаунт номер " << i + 1 << ':' << '\n' << data[i] << endl;
			}
		}
		case 4:
		{
			break;
		};
		}
		cout << "1.Создать аккаунт" << endl << "2.Войти в аккаунт" << endl << "3.Отобразить всех пользователей" << endl << "4.Выйти из чата" << endl;
		cin >> open;
		cin.clear();
		cin.ignore(32767, '\n');
	}
	return 0;
}