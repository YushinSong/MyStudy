#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// ������ ���̰� �ε�����, �ش� �����϶� ����� ���� ���� �޸������̼��� ����.
// ���� ���غ���, �Ǻ���ġ ������ ���Դ�.

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
