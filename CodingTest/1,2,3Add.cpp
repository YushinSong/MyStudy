#include <iostream>
#include <vector>

using namespace std;

int countCase[12];

void numCheck(int num, int now)
{
	if (num == now)
		++countCase[num];
	if (num < now)
		return;

	numCheck(num, now + 1); // 1�� ���� ���
	numCheck(num, now + 2); // 2�� ���� ���
	numCheck(num, now + 3); // 3�� ���� ���
}
int main()
{
	int T;
	cin >> T;
	vector<int> numCase;

	for (int i = 0; i < T; ++i)
	{
		int temp;
		cin >> temp;
		numCase.push_back(temp);
	}

	for (int i = 0; i < T; ++i)
	{
		numCheck(numCase[i], 0);
		cout << countCase[numCase[i]] << endl;
	}
}