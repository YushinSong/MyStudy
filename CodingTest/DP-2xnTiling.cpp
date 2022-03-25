#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 가로의 길이가 인덱스고, 해당 길이일때 방법의 수가 값인 메모이제이션을 쓰자.
// 직접 구해보니, 피보나치 수열이 나왔다.

int solution(int num)
{
	vector<int> memo;
	memo.assign(num + 1, 0);

	memo[1] = 1;
	memo[2] = 2;
	for (int i = 3; i <= num; ++i)
	{
		memo[i] = (memo[i - 1] + memo[i - 2]) % 10007;
	}
	return memo[num];
}
int main()
{
	int n;
	cin >> n;

	cout << solution(n);
}
