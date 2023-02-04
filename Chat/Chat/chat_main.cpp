#include "chat.h"
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size = 1;
	User* data = new User[size];
	string userName, login;
	MessageArray* arr = new MessageArray[size];
	string password;
	int i = 0;
	char open;
	cout << "Выберите,что вы хотите сделать" << '\n' << endl;
	cout << "1.[Создать аккаунт] 2.[Войти в аккаунт] 3.[Отобразить всех пользователей] 4.[Выйти из чата]" << endl;
	cin >> open;
	clearCin();
	cout << endl;
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
			for (int z=0; z < i; z++)
			{
				while(login==data[z].GetLogin())
				{
					cout << "Такой логин уже существует. Пожалуйста,придумайте другой логин: " ;
					z = 0;
					getline(cin, login);
				}
			}
			cout << "Введите пароль(Все пробелы будут удалены!): ";
			getline(cin, password);
			password.erase(remove_if(password.begin(), password.end(), isspace), password.end());
			cout << endl;
			data[i] = User(userName, login, password);
			arr[i] = MessageArray(0);
			++i;
			data = data->plusOneElement(data, size); // меняет размер массива на + 1
			arr = arr->plusOneElement(arr, size);
			++size;
			cout << "Аккаунт успешно создан\n" << endl;
			break;
		}
		case '2':
		{
			if (size == 1)
			{
				cout << "Не создано еще ни одного аккаунта\n" << endl;
				break;
			}
			cout << "Введите логин: " ;
			getline(cin, login);
			cout << "Введите пароль: ";
			getline(cin, password);
			cout << endl;
			bool b;
			int i = 0;
			for (; i < size; i++)
			{
				b = data[i].CheckEnter(login, password);
				if (b == true)
				{
					cout << endl;
					string name = data[i].GetUserName();
					char choiceInsideCase2;
					cout << "Выберите действие:" << endl << "1.[Написать сообщение] 2.[Показать сообщение] 3.[Выйти из аккаунта]" << endl;
					cin >> choiceInsideCase2;
					clearCin();
					while (choiceInsideCase2 != '3')
					{
						switch (choiceInsideCase2)
						{
						case '1':
						{
							char choice2;
							cout << endl;
							cout << "Кому вы хотите написать сообщение: 1.[Определенному пользователю] 2.[Групповое сообщение] 3.[Вернутся назад]"<<endl;
							cin >> choice2;
							cout << endl;
							clearCin();
							while (choice2 != '3')
							{
								switch (choice2)
								{
								case '1':
								{
									cout << "Имена пользователей:" << endl;
									for (int j = 0; j < i; ++j)
									{
										cout << '-' << data[j].GetUserName() << "; ";
									}
									for (int j = i + 1; j < size - 1; ++j)
									{
										cout << '-' << data[j].GetUserName() << "; ";
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
											cout << endl;
											message = "У вас сообщение от пользователя " + data[i].GetUserName() + ": " + '\"' + message + '\"';
											data[k].SetMessage(message);
											arr[k].PushBackMessage(data[k].GetMessage());
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
											groupmessage = "У вас групповое сообщение от пользователя " + data[i].GetUserName() + ": " + '\"' + message + '\"';
											data[k].SetMessage(groupmessage);
											arr[k].PushBackMessage(data[k].GetMessage());
										};
									}
									break;
								}
								case '3':
								{
									break;
								}
								}
								cout << endl;
								cout << "Кому вы хотите написать сообщение: 1.[Определенному пользователю] 2.[Групповое сообщение] 3.[Вернутся назад]" << endl;
								cin >> choice2;
								cout << endl;
								clearCin();
							};
							break;
						}
						case '2':
						{
							cout << endl;
							cout << arr[i] << endl;
							break;
						}
						case '3':
						{
							break;
						}
					    }
						cout << "Выберите действие:" << endl << "1.[Написать сообщение] 2.[Показать сообщение] 3.[Выйти из аккаунта]" << endl;
						cin >> choiceInsideCase2;
					clearCin();
					};
					break;
				};
			};
			if (b == false)
			{
				cout << "Неверный логин или пароль\n" << endl;
			};
			break;
		}
		case '3':
		{
			if (size == 1)
			{
				cout << "Не создано еще ни одного аккаунта\n" << endl;
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
		cout<<endl;
		cout << "Выберите,что вы хотите сделать" << '\n' << endl;
		cout << "1.[Создать аккаунт] 2.[Войти в аккаунт] 3.[Отобразить всех пользователей] 4.[Выйти из чата]" << endl;
		//cout << "1.Создать аккаунт" << endl << "2.Войти в аккаунт" << endl << "3.Отобразить всех пользователей" << endl << "4.Выйти из чата" << endl;
		cin >> open;
		clearCin();
		cout << endl;
	};
	delete[] data;
	delete[] arr;
	return 0;
}