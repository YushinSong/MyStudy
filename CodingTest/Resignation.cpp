#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int N;  // 일정 수
vector<pair<int, int>> counseling;
int maxProfit;

void solution(int i, int p) // 일정의 인덱스, 현재까지의 수익
{
	if (i > N) // 일정을 초과한 경우
		return;
	if (i == N) // 일정을 모두 확인한 경우
	{
		if (p > maxProfit)
			maxProfit = p;
		return;
	}

	solution(i + counseling[i].first, p + counseling[i].second); // 일정을 선택한 경우
	solution(i + 1, p); // 선택하지 않은 경우
}
int main()
{
	cin >> N; 

	for (int i = 0; i < N; ++i)
	{
		int T, P;
		cin >> T >> P;

		counseling.push_back(make_pair(T, P));
	}
	
	solution(0, 0);

	cout << maxProfit;

	return 0;
}