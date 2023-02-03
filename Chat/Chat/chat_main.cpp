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
	char open;
	cout << "Выберите,что вы хотите сделать" << endl;
	cout << "1.Создать аккаунт" << endl << "2.Войти в аккаунт" << endl << "3.Отобразить всех пользователей" << endl << "4.Выйти из чата" << endl;
	cin >> open;
	clearCin();
	while (open != '4')
	{
		switch (open)
		{
		case '1':
		{
			cout << "Введите имя: ";
			getline(cin, userName);
			cout << "Введите логин: ";
			getline(cin, login);
			cout << "Введите пароль: ";
			cin >> password;
			clearCin();
			data[i] = User(userName, login, password);
			++i;
			data = data->plusOneElement(data, size); // меняет размер массива на + 1
			++size;
			break;
		}
		case '2':
		{
			if (size == 1)
			{
				cout << "Не создано еще ни одного аккаунта" << endl;
				break;
			}
			cout << "Введите логин" << endl;
			getline(cin, login);
			cout << "Введите пароль" << endl;
			cin >> password;
			clearCin();
			bool b;
			int i = 0;
			for (; i < size; i++)
			{
				b = data[i].Check(login, password);
				if (b == true)
				{
					string name = data[i].GetUserName();
					char choiceInsideCase2;
					cout << "Выберите действие:" << endl << "1.Написать сообщение" << endl << "2.Показать сообщение" << endl << "3.Выйти из аккаунта" << endl;
					cin >> choiceInsideCase2;
					clearCin();
					while (choiceInsideCase2 != '3')
					{
						switch (choiceInsideCase2)
						{
						case '1':
						{
							char choice2;
							cout << "Кому вы хотите написать сообщение:" << endl << "1.Определенному пользователю" << endl << "2.Групповое сообщение" << endl;
							cin >> choice2;
							clearCin();
							switch (choice2)
							{
							case '1':
							{
								cout << "Имена пользователей:" << endl;
								for (int j = 0; j < i; ++j)
								{
									cout << '-' << data[j].GetUserName() << endl;
								}
								for (int j = i + 1; j < size - 1; ++j)
								{
									cout << '-' << data[j].GetUserName() << endl;
								}
								cout << endl;
								cout << "Введите имя пользователя кому хотите написать сообщение: ";
								getline(cin, userName);
								for (int k = 0; k < size - 1; ++k)
								{
									if (userName == data[k].GetUserName())
									{
										string message;
										cout << "Введите сообщение: ";
										getline(cin, message);
										message = "У вас сообщение от пользователя " + data[i].GetUserName() + ": " + '\"' + message + '\"';
										data[k].SetMessage(message);
										MessageArray msg;
										msg.Test(data[k].GetMessage());
										cout << msg << endl;
									}
								}
								break;
							}
							case '2':
							{
								string message;
								string groupmessage;
								cout << "Введите сообщение: ";
								getline(cin, message);
								for (int k = 0; k < size - 1; ++k)
								{
									groupmessage = ' ';
									if (name != data[k].GetUserName())
									{
										groupmessage = "У вас сообщение от пользователя " + data[i].GetUserName() + ": " + '\"' + message + '\"';
										data[k].SetMessage(groupmessage);
									};
								}
								break;
							}
							}
							break;
						}
						case '2':
						{

							cout << data[i].GetMessage() << '\n' << endl;
							/*system("pause>0");*/
							break;
						}
						case '3':
						{
							cout << "Выход из аккаунта произведен" << endl;
							break;
						}
					    }
						cout << "Выберите действие:" << endl << "1.Написать сообщение" << endl << "2.Показать сообщение" << endl << "3.Выйти из аккаунта" << endl;
					cin >> choiceInsideCase2;
					clearCin();
					};
					break;
				};
			};
			if (b == false)
			{
				cout << "Неверный логин или пароль" << endl;
			};
			break;
		}
		case '3':
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
		case '4':
		{
			break;
		};
		}
		cout << "1.Создать аккаунт" << endl << "2.Войти в аккаунт" << endl << "3.Отобразить всех пользователей" << endl << "4.Выйти из чата" << endl;
		cin >> open;
		clearCin();
	}
	return 0;
}