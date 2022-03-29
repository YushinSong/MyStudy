#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int N, K;  // 물품의 수, 버틸 수 있는 수
vector<pair<int, int>> weightValue;
int memo[101][100001];

int solution(int i, int w) {

	if (i == N) 
		return 0;
	if (memo[i][w] > 0) 
		return memo[i][w];

	int case1 = 0;
	if (w + weightValue[i].first <= K) // 버틸 수 있는 무게를 초과하지 않은 경우. 선택 가능
		case1 = weightValue[i].second + solution(i + 1, w + weightValue[i].first);  // 현재 인덱스의 물건을 선택한 경우

	int case2 = solution(i + 1, w); // 물건을 선택하지 않은 경우

	memo[i][w] = max(case1, case2);

	return memo[i][w];
}
int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; ++i)
	{
		int W, V;
		cin >> W >> V;

		weightValue.push_back(make_pair(W, V));
	}

	cout << solution(0, 0);

	return 0;
}
