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
	/*cout << "�������� �������" << endl;
	cout << "������� ���: ";
	getline(cin, userName);
	cout << "������� �����: ";
	getline(cin, login);
	cout << "������� ������: ";
	cin >> password;
	cin.clear();
	cin.ignore(32767, '\n');*/
	/*data[i] = User(userName, login, password);*/
	/*data = data->plusOneElement(data, size);
	size++;
	i++;*/
	cout << "��������,��� �� ������ �������" << endl;
	cout << "1.������� �������" << endl << "2.����� � �������" << endl << "3.���������� ���� �������������" << endl << "4.����� �� ����" << endl;
	cin >> open;
	cin.clear();
	cin.ignore(32767, '\n');
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
			cin.clear();
			cin.ignore(32767, '\n');
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
			string LoginCheck;
			int PasswordCheck;
			cout << "������� �����" << endl;
			cin >> LoginCheck;
			cout << "������� ������" << endl;
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
		cin.clear();
		cin.ignore(32767, '\n');
	}
	return 0;
}