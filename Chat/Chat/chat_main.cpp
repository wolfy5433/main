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
	cout << "��������,��� �� ������ �������" << '\n' << endl;
	cout << "1.[������� �������] 2.[����� � �������] 3.[���������� ���� �������������] 4.[����� �� ����]" << endl;
	cin >> open;
	clearCin();
	cout << endl;
	while (open != '4')
	{
		switch (open)
		{
		case '1':
		{
			cout << "������� ���: ";
			getline(cin, userName);
			cout << "������� �����: ";
			getline(cin, login);
			for (int z=0; z < i; z++)
			{
				while(login==data[z].GetLogin())
				{
					cout << "����� ����� ��� ����������. ����������,���������� ������ �����" << endl;
					z = 0;
					getline(cin, login);
				}
			}
			cout << "������� ������: ";
			getline(cin, password);
			data[i] = User(userName, login, password);
			arr[i] = MessageArray(0);
			++i;
			data = data->plusOneElement(data, size); // ������ ������ ������� �� + 1
			arr = arr->plusOneElement(arr, size);
			++size;
			break;
		}
		case '2':
		{
			if (size == 1)
			{
				cout << "�� ������� ��� �� ������ ��������\n" << endl;
				break;
			}
			cout << "������� �����" << endl;
			getline(cin, login);
			cout << "������� ������" << endl;
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
					cout << "�������� ��������:" << endl << "1.�������� ���������" << endl << "2.�������� ���������" << endl << "3.����� �� ��������" << endl;
					cin >> choiceInsideCase2;
					clearCin();
					while (choiceInsideCase2 != '3')
					{
						switch (choiceInsideCase2)
						{
						case '1':
						{
							char choice2;
							cout << "���� �� ������ �������� ���������:" << endl << "1.������������� ������������" << endl << "2.��������� ���������" << endl<<"3.�������� �����"<<endl;
							cin >> choice2;
							clearCin();
							while (choice2 != '3')
							{
								switch (choice2)
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
											arr[k].PushBackMessage(data[k].GetMessage());
										}
									}
									break;
								}
								case '2':
								{
									string message;
									string groupmessage;
									cout << "������� ���������: ";
									getline(cin, message);
									for (int k = 0; k < size - 1; ++k)
									{
										groupmessage = ' ';
										if (name != data[k].GetUserName())
										{
											groupmessage = "� ��� ��������� ��������� �� ������������ " + data[i].GetUserName() + ": " + '\"' + message + '\"';
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
								cout << "���� �� ������ �������� ���������:" << endl << "1.������������� ������������" << endl << "2.��������� ���������" << endl << "3.�������� �����"<<endl;
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
							cout << "����� �� �������� ����������" << endl;
							break;
						}
					    }
						cout << "�������� ��������:" << endl << "1.�������� ���������" << endl << "2.�������� ���������" << endl << "3.����� �� ��������" << endl;
					cin >> choiceInsideCase2;
					clearCin();
					};
					break;
				};
			};
			if (b == false)
			{
				cout << "�������� ����� ��� ������" << endl;
			};
			break;
		}
		case '3':
		{
			if (size == 1)
			{
				cout << "�� ������� ��� �� ������ ��������\n" << endl;
				break;
			}
			cout << endl;
			for (int i = 0; i < size-1 ; ++i)
			{
				cout << "������� ����� " << i + 1 << ':' << '\n' << data[i] << endl;
			}
		}
		case '4':
		{
			break;
		};
		}
		cout << "1.[������� �������] 2.[����� � �������] 3.[���������� ���� �������������] 4.[����� �� ����]" << endl;
		//cout << "1.������� �������" << endl << "2.����� � �������" << endl << "3.���������� ���� �������������" << endl << "4.����� �� ����" << endl;
		cin >> open;
		clearCin();
		cout << endl;
	};
	delete[] data;
	delete[] arr;
	return 0;
}