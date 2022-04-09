#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int N; // ���� ����
char signs[11][11]; // �Էµ� ��ȣ��
int arr[12]; // ���� ����� �迭

bool check(int cnt)
{
	int sum = 0; // ���� ��� Ȯ���� ����
	for (int i = cnt; i >= 0; --i)
	{
		sum += arr[i];
		if (signs[i][cnt] == '+' && sum <= 0)
			return false;
		else if (signs[i][cnt] == '0' && sum != 0)
			return false;
		else if (signs[i][cnt] == '-' && sum >= 0)
			return false;
	}
	return true;
}
void dfs(int cnt)
{
	if (cnt == N) // ������ �ϼ����� ��
	{
		for (int i = 0; i < N; ++i)
			cout << arr[i] << " ";
		cout << endl;
		exit(0);
	}
	for (int i = -10; i <= 10; ++i)
	{
		arr[cnt] = i;
		if(check(cnt))
			dfs(cnt + 1);
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for(int j=i;j<N;++j)
		{
			cin >> signs[i][j];
		}
	}

	dfs(0);
}