#include <iostream>
#include <vector>

#define endl '\n'
#define INTMAX 2147483647

using namespace std;

int N; // 숫자의 수
vector<int> nums; // 입력된 숫자
int minNum = INTMAX;
int maxNum = INTMAX * -1;

int operators[4]; // 연산자마다의 개수 + - * /
bool visited[101]; // 연산자 방문여부 체크

void dfs(int result, int cnt) // 현재 계산, 깊이 수
{
	if (cnt >= N)
	{
		minNum = min(minNum, result);
		maxNum = max(maxNum, result);
		return;
	}
	for (int i = 0; i < 4; ++i) // 연산자마다 검색
	{
		if (operators[i] > 0) // 해당 연산자 더 사용 가능할 때
		{
			--operators[i];
			if (i == 0) // +
				dfs(result + nums[cnt], cnt + 1);
			else if (i == 1) // -
				dfs(result - nums[cnt], cnt + 1);
			else if (i == 2) // *
				dfs(result * nums[cnt], cnt + 1);
			else if (i == 3) // /
				dfs(result / nums[cnt], cnt + 1);
			++operators[i]; // 빠져나옴
		}
	}
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
	for (int i = 0; i < 4; ++i)
	{
		cin >> operators[i];
	}

	dfs(nums[0], 1); // 이미 첫번째 숫자 넣은거니까 깊이 1

	cout << maxNum << endl << minNum;
}