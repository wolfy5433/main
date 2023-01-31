#include <iostream>
#include "chat.h"

using namespace std;

int main()
{
	User* user[2];
	user[0] = new User("Test", "test", 1234);
	cout << *user[0];

	user[1] = user[0];
	
	cout << '\n' << endl;

	cout << *user[1];

	return 0;
}