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
	cout << "��������,��� �� ������ �������" << endl;
	cout << "1.������� �������" << endl << "2.����� � �������" << endl << "3.���������� ���� �������������" << endl << "4.����� �� ����" << endl;
	cin >> open;
	clearCin();
	while (open != 4)
	{
		switch (open)
		{
		case 1:
		{
			cout << "������� ���: ";
			getline(cin, userName);
			cout << "������� �����: ";
			getline(cin, login);
			cout << "������� ������: ";
			cin >> password;
			clearCin();
			data[i] = User(userName, login, password);
			++i;
			data = data->plusOneElement(data, size); // ������ ������ ������� �� + 1
			++size;
			break;
		}
		case 2:
		{
			if (size == 1)
			{
				cout << "�� ������� ��� �� ������ ��������" << endl;
				break;
			}
			cout << "������� �����" << endl;
			getline(cin, login);
			cout << "������� ������" << endl;
			cin >> password;
			clearCin();
			bool b;
			int i = 0;
			for (; i < size; i++)
			{
				b = data[i].Check(login, password);
				if (b == true)
				{
					char choiceInsideCase2;
					cout << "�������� ��������:" << endl << "1.�������� ���������" << endl << "2.�������� ���������" << endl;
					cin >> choiceInsideCase2;
					clearCin();
					switch (choiceInsideCase2)
					{
					case '1':
					{
						cout << "����� �������������:" << endl;
						for (int j = 0; j < i; ++j)
						{
							cout << '-' << data[j].GetUserName() << endl;
						}
						for (int j = i + 1; j < size - 1; ++j)
						{
							cout << '-' << data[j].GetUserName() << endl;
						}
						cout << endl;
						cout << "������� ��� ������������ ���� ������ �������� ���������: ";
						getline(cin, userName);
						for (int k = 0; k < size - 1; ++k)
						{
							if (userName == data[k].GetUserName())
							{
								string message;
								cout << "������� ���������: ";
								getline(cin, message);
								message = "� ��� ��������� �� ������������ " + data[i].GetUserName() + ": " + '\"' + message + '\"';
								data[k].SetMessage(message);
							}
						}
						break;
					}
					case '2':
					{
						cout << data[i].GetMessage() << '\n' << endl;
						system("pause>0");
						break;
					}

					default:
					{
						cout << "�����" << endl;
					}
					}
					break;
				};
			};
			if (b == false)
			{
				cout << "�������� ����� ��� ������" << endl;
			};
			break;
		}
		case 3:
		{
			if (size == 1)
			{
				cout << "�� ������� ��� �� ������ ��������" << endl;
				break;
			}
			cout << endl;
			for (int i = 0; i < size-1 ; ++i)
			{
				cout << "������� ����� " << i + 1 << ':' << '\n' << data[i] << endl;
			}
		}
		case 4:
		{
			break;
		};
		}
		cout << "1.������� �������" << endl << "2.����� � �������" << endl << "3.���������� ���� �������������" << endl << "4.����� �� ����" << endl;
		cin >> open;
		clearCin();
	}
	return 0;
}