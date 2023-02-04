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
					cout << "Такой логин уже существует. Пожалуйста,придумайте другой логин" << endl;
					z = 0;
					getline(cin, login);
				}
			}
			cout << "Введите пароль: ";
			getline(cin, password);
			data[i] = User(userName, login, password);
			arr[i] = MessageArray(0);
			++i;
			data = data->plusOneElement(data, size); // меняет размер массива на + 1
			arr = arr->plusOneElement(arr, size);
			++size;
			break;
		}
		case '2':
		{
			if (size == 1)
			{
				cout << "Не создано еще ни одного аккаунта\n" << endl;
				break;
			}
			cout << "Введите логин" << endl;
			getline(cin, login);
			cout << "Введите пароль" << endl;
			getline(cin, password);
			bool b;
			int i = 0;
			for (; i < size; i++)
			{
				b = data[i].CheckEnter(login, password);
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
							cout << "Кому вы хотите написать сообщение:" << endl << "1.Определенному пользователю" << endl << "2.Групповое сообщение" << endl<<"3.Вернутся назад"<<endl;
							cin >> choice2;
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
								cout << "Кому вы хотите написать сообщение:" << endl << "1.Определенному пользователю" << endl << "2.Групповое сообщение" << endl << "3.Вернутся назад"<<endl;
								cin >> choice2;
								clearCin();
							};
							break;
						}
						case '2':
						{
							cout << arr[i] << endl;
							//cout << data[i].GetMessage() << '\n' << endl;
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