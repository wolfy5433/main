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
		cout << "������� ���: ";
		getline(cin, userName);
		cout << "������� �����: ";
		getline(cin, login);
		cout << "������� ������: ";
		cin >> password;
		
		data[i] = User(userName, login, password);
		++i;

		data = data->plusOneElement(data, size); // ������ ������ ������� �� + 1
		++size;

		cout << "������� ����� �����, ����� ���������� ��� 0 ��� ����������� ���� ����������������� �������������: ";
		cin >> open;
		cin.clear();
		cin.ignore(32767, '\n');
	}
	cout << endl;
	for (int i = 0; i < size - 1; ++i)
	{
		cout << "������� ����� " << i + 1 << ':' << '\n' << data[i] << endl;
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