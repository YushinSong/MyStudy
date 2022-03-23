#include <iostream>
#include <vector>

using namespace std;
// 메모이제이션을 위한 전역변수
int memo[1000];

// 
int solution(vector<int> biseok)
{
	memo[0] = biseok[0];
	memo[1] = biseok[0] + biseok[1];
	memo[2] = max(biseok[1] + biseok[2], biseok[0] + biseok[2]);
	for (int i = 3; i < biseok.size(); ++i)
	{
		int first = memo[i - 3] + biseok[i] + biseok[i - 1]; // 세번째 전의 비석을 먹고, 바로 전의 비석을 먹는 경우
		int second = memo[i - 2] + biseok[i];				 // 두번째 전의 비석을 먹는 경우
		memo[i] = max(first, second);
	}

	return memo[biseok.size() - 1];
}
int main()
{
	int num;
	cin >> num;
	vector<int> biseok;

	for (int i = 0; i < num; ++i)
	{
		int temp;
		cin >> temp;
		biseok.push_back(temp);
	}

	cout << solution(biseok);
}