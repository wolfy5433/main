#include "chat.h"

using namespace std;

int main()
{
	SetConsoleCP(1251); // Возможность читать и вносить через cin кирилицу
	SetConsoleOutputCP(1251);

	int size = 1;
	User* data = new User[size]; // Массив для хранения аккаунтов
	MessageArray* arr = new MessageArray[size]; // Массив для хранения сообщений

	string userName, login, password;
	
	cout << "Добро пожаловать в чат.\nВыберите,что вы хотите сделать:" << endl;
	cout << "1.[Создать аккаунт] 2.[Войти в аккаунт] 3.[Отобразить всех пользователей] 4.[Выйти из чата]" << endl;

	int i = 0; // Счётчик, который увеличивается, при создании нового элемента массива
	char open;
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
			while (userName.empty())
			{
				cout << "Строка с именем не должна быть пустой. Пожалуйста, введите имя: ";
				getline(cin, userName);
			}

			cout << "Введите логин: ";
			getline(cin, login);
			while (login.empty())
			{
				cout << "Строка с логином не должна быть пустой. Пожалуйста, введите логин: ";
				getline(cin, login);
			}
			for (int z = 0; z < i; z++)
			{
				while (login == data[z].GetLogin())
				{
					cout << "Такой логин уже существует. Пожалуйста, придумайте другой логин: ";
					z = 0;
					getline(cin, login);
					while (login.empty())
					{
						cout << "Строка с логином не должна быть пустой. Пожалуйста, введите логин: ";
						getline(cin, login);
					}
				}
			}
			
			cout << "Введите пароль (все пробелы будут удалены!): ";
			getline(cin, password);
			password.erase(remove_if(password.begin(), password.end(), isspace), password.end()); // Удаляет все пробелы
			while (password.empty())
			{
				cout << "Строка с паролем не должна быть пустой. Пожалуйста, введите пароль: ";
				getline(cin, password);
				password.erase(remove_if(password.begin(), password.end(), isspace), password.end());
			}
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
				b = data[i].CheckEnter(login, password); // Проверяет на соответствие логина и пароля
				if (b == true)
				{
					string name = data[i].GetUserName();

					char choiceInsideCase2;
					cout << "Выберите действие:" << endl << "1.[Написать сообщение] 2.[Показать сообщение] 3.[Сменить пароль] 4.[Выйти из аккаунта]" << endl;
					cin >> choiceInsideCase2;
					clearCin();
					cout << endl;

					while (choiceInsideCase2 != '4')
					{
						switch (choiceInsideCase2)
						{
						case '1':
						{
							cout << "Кому вы хотите написать сообщение:\n1.[Определенному пользователю] 2.[Групповое сообщение] 3.[Вернутся назад]"<<endl;
							char choice2;
							cin >> choice2;
							cout << endl;
							clearCin();

							while (choice2 != '3')
							{
								switch (choice2)
								{
								case '1': // сообщение пользователю
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
											while (message.empty())
											{
												cout << "Сообщение не отправлено(отсутсвует текст). Введите сообщение: ";
												getline(cin, message);
											}
											message = "У вас сообщение от пользователя " + data[i].GetUserName() + ": " + '\"' + message + '\"';
											data[k].SetMessage(message); // присваивает _message в классе User значение message
											arr[k].PushBackMessage(data[k].GetMessage()); // Записывает сообщение в массив через геттер GetMessage()
											cout << "Сообщение успешно отправлено!" << endl;
										}
									}

									break;
								}
								case '2': // групповое сообщение
								{
									string message;
									string groupmessage;
									cout << "Введите сообщение: ";
									getline(cin, message);
									while (message.empty())
									{
										cout << "Сообщение не отправлено(отсутсвует текст). Введите сообщение: ";
										getline(cin, message);
									}
									for (int k = 0; k < size - 1; ++k)
									{
										groupmessage = ' ';
										if (name != data[k].GetUserName())
										{
											groupmessage = "У вас групповое сообщение от пользователя " + data[i].GetUserName() + ": " + '\"' + message + '\"';
											data[k].SetMessage(groupmessage);
											arr[k].PushBackMessage(data[k].GetMessage()); // Записывает сообщение в массив
										};
									}
									cout << "Сообщение успешно отправлено!" << endl;

									break;
								}
								default:
								{
									cout << "Неверное значение\n" << endl;

									break;
								}
								}
								cout << endl;
								cout << "Кому вы хотите написать сообщение:\n1.[Определенному пользователю] 2.[Групповое сообщение] 3.[Вернутся назад]" << endl;
								cin >> choice2;
								cout << endl;
								clearCin();
							};

							break;
						}
						case '2':
						{
							cout << arr[i];
							system("pause>0"); // Ставит программу на паузу, чтобы пользователь прочитал сообщение

							break;
						}
						case '3': //Смена пароля на новый
						{
							string newpassword;
							cout << "Введите старый пароль: ";
							getline(cin, newpassword);
							while (newpassword != data[i].GetPassword())
							{
								cout << "Пароль неверный" << endl;
								cout << "Введите старый пароль: ";
								getline(cin, newpassword);
							}
								cout << "Введите новый пароль: ";
								getline(cin, newpassword);
								newpassword.erase(remove_if(newpassword.begin(), newpassword.end(), isspace), newpassword.end()); // Удаляет все пробелы
								while (newpassword.empty())
								{
									cout << "Строка с паролем не должна быть пустой. Пожалуйста, введите пароль: ";
									getline(cin, newpassword);
									newpassword.erase(remove_if(newpassword.begin(), newpassword.end(), isspace), newpassword.end());
								}
								while (newpassword == data[i].GetPassword())
								{
									cout << "Это ваш старый пароль! Придумайте другой пароль: ";
									getline(cin, newpassword);
									newpassword.erase(remove_if(newpassword.begin(), newpassword.end(), isspace), newpassword.end());
									while (newpassword.empty())
									{
										cout << "Строка с паролем не должна быть пустой. Пожалуйста, введите пароль: ";
										getline(cin, newpassword);
										newpassword.erase(remove_if(newpassword.begin(), newpassword.end(), isspace), newpassword.end());
									}
								}
								data[i].SetPassword(newpassword);
								cout << "Пароль успешно изменен!\n" << endl;
							
							break;
						}
						default:
						{
							cout << "Неверное значение\n" << endl;

							break;
						}
					    }

					cout << "Выберите действие:\n1.[Написать сообщение] 2.[Показать сообщение] 3.[Сменить пароль] 4.[Выйти из аккаунта]" << endl;
					cin >> choiceInsideCase2;
					clearCin();

					cout << endl;
					};

					cout << endl;

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
			for (int i = 0; i < size-1 ; ++i)
			{
				cout << "Аккаунт номер " << i + 1 << ':' << '\n' << data[i] << endl;
			}

			break;
		}
		default:
		{
			cout << "Неверное значение\n" << endl;

			break;
		};
		}
		cout << "1.[Создать аккаунт] 2.[Войти в аккаунт] 3.[Отобразить всех пользователей] 4.[Выйти из чата]" << endl;

		cin >> open;
		clearCin();
		cout << endl;
	}

	delete[] data;
	delete[] arr;

	return 0;
}