#include <iostream>

#define endl '\n'

using namespace std;

void solution(string command, int &bit)
{
	int x = 0;
	if (command != "all" && command != "empty")
		cin >> x;

	if (command == "add")
	{
		bit |= (1 << x);
	}
	else if (command == "remove")
	{
		bit &= ~(1 << x);
	}
	else if (command == "check")
	{
		if (bit & (1 << x))
			cout << "1" << endl;
		else cout << "0" << endl;
		return;
	}
	else if (command == "toggle")
	{
		bit ^= (1 << x);
	}
	else if (command == "all")
	{
		bit = (1 << 21) - 1;
	}
	else if (command == "empty")
	{
		bit = 0;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int M;
	cin >> M;

	int bit = 0;

	for (int i = 0; i < M; ++i)
	{
		string command;
		cin >> command;

		solution(command, bit);
	}
}