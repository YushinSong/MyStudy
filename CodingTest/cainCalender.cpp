#include <iostream>
#include <vector>

using namespace std;

// x는 M의 나머지, y도 N의 나머지.
int solution(int M, int  N, int  x, int y)
{
	int countY = 0;

	for (int i = x; i < (M * N); i += M) // 다음 x는 M 후에 나타난다. M후의 수의 y만 계속 확인한다.
	{
		int temp = i % N;
		if (temp == 0)
			temp = N;
		if (temp == y)
			return i;
	}
	return -1;
}
int main()
{
	int T;
	cin >> T;
	vector<vector<int>> yearCase;

	for (int i = 0; i < T; ++i)
	{
		vector<int> temp;
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		temp.push_back(M); temp.push_back(N); temp.push_back(x); temp.push_back(y);
		yearCase.push_back(temp);
	}

	for (int i = 0; i < T; ++i)
	{
		cout << solution(yearCase[i][0], yearCase[i][1], yearCase[i][2], yearCase[i][3]) << endl;
	}
}