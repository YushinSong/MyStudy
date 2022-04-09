#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int N; // 순열 길이
char signs[11][11]; // 입력된 기호들
int arr[12]; // 순열 저장될 배열

bool check(int cnt)
{
	int sum = 0; // 더한 결과 확인할 변수
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
	if (cnt == N) // 순열을 완성했을 때
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