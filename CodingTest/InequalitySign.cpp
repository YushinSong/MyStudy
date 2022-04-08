#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

#define INT_MAX 2147483647

using namespace std;

int k; // 부등호의 수
bool visited[11];
vector<string> result; // 부등호 만족하는 수열들
vector<char> signs; // 입력된 부등호들

bool check(string s)
{
	for (int i = 0; i < k; ++i)
	{
		if (signs[i] == '<')
		{
			if (s[i] > s[i + 1])
				return false;
		}
		else
		{
			if (s[i] < s[i + 1])
				return false;
		}
	}
	return true;
}
void dfs(int cnt, string permu) // 총 본 숫자 수
{
	if (cnt == k + 1) // 순열 완성했을 때
	{
		if (check(permu))
		{
			result.push_back(permu);
		}
		return;
	}
	for (int i = 0; i <= 9; ++i)
	{
		if (!visited[i]) // 방문한 적 없는 숫자
		{
			visited[i] = true;
			dfs(cnt + 1, permu + to_string(i)); // 다음 숫자 체크
			visited[i] = false; 
		}
	}
}
int main()
{
	cin >> k;

	for (int i = 0; i < k; ++i)
	{
		char temp;
		cin >> temp;
		signs.push_back(temp);
	}

	dfs(0, "");

	cout << *max_element(result.begin(), result.end()) << '\n' << *min_element(result.begin(), result.end()) << '\n';
}