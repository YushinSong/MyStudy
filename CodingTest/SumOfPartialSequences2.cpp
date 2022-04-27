#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int N; // 입력된 정수의 수
vector<int> nums; // 입력된 정수들
vector<bool> able(2000001); // 만들 수 있는 정수

void dfs(int sum, int index) // 지금까지 더한 값, nums인덱스 
{
	able[sum] = true;
	if (index >= N) // 모든 수를 확인한 경우
		return;

	dfs(sum, index + 1); // 현재 인덱스의 수를 선택한 경우
	dfs(sum + nums[index], index + 1); // 현재 인덱스의 수를 선택하지 않은 경우
}
int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	dfs(0, 0);
	for (int i = 1; i < able.size(); ++i)
	{
		if (able[i] == false)
		{
			cout << i;
			break;
		}
	}
}