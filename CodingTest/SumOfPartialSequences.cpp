#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int N, S; // 입력된 정수의 수, 나와야하는 값
int countCase; // 경우의 수
vector<int> nums; // 입력된 정수들

void dfs(int index, int sum) // 현재 보는 인덱스, 지금까지 더한 값
{
	if (index >= N) // 모든 수를 확인한 경우
		return;

	sum += nums[index];

	if (sum == S) // 수를 맞춘 경우
		++countCase;

	dfs(index + 1, sum); // 현재 인덱스의 수를 선택한 경우
	dfs(index + 1, sum - nums[index]); // 현재 인덱스의 수를 선택하지 않은 경우
}
int main()
{
	cin >> N >> S;

	for (int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;

		nums.push_back(temp);
	}

	dfs(0, 0);

	cout << countCase << endl;
}