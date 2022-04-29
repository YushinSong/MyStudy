#include <iostream>
#include <vector>
#include <string>

#define INTMAX 2147483647

using namespace std;

string nowBlub, goalBlub;
int N; // ������ ��

void switchNum(string &temp, int index) // ��� ���� ����ġ
{
	if (index > 0)
		temp[index - 1] = (temp[index - 1] == '0') ? '1' : '0';
	temp[index] = (temp[index] == '0') ? '1' : '0';
	if (index < N - 1)
		temp[index + 1] = (temp[index + 1] == '0') ? '1' : '0';
}
int changeBlub(bool startBlub)
{
	int cnt = 0;
	string tempNow = nowBlub;

	if (startBlub)
	{
		switchNum(tempNow, 0);
		++cnt;
	}

	for (int i = 1; i < N; ++i)
	{
		if (tempNow[i - 1] != goalBlub[i - 1]) // i-1�� ������ �ֱ� ������, i-1�� �ٸ����� i�� ������.
		{
			switchNum(tempNow, i);
			++cnt;
		}
	}

	if (tempNow != goalBlub)
		return INTMAX;
	return cnt;
}
int main()
{
	cin >> N >> nowBlub >> goalBlub;

	int result = min(changeBlub(false), changeBlub(true));
	if (result == INTMAX)
		cout << -1;
	else
		cout << result;
}