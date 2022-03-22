#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// vector의 인덱스는 숫자를 뜻한다.
// 값은 그 숫자에 도달할 수 있는 경우의 수를 뜻한다.

int solution(int num)
{
	vector<int> numVector;
	numVector.assign(num + 1, 0);
	
	//numVector[0] = 0; numVector[1] = 0; // 0과 1에 도달할 방법은 무조건 0번이다.

	for (int i = 2; i < num + 1; ++i)
	{
		numVector[i] = numVector[i - 1] + 1; // 1을 빼는 경우
		if (i % 2 == 0)
		{
			numVector[i] = min(numVector[i], numVector[i / 2] + 1); // 2로 나눠지는 경우
		}
		if (i % 3 == 0)
		{
			numVector[i] = min(numVector[i], numVector[i / 3] + 1);	// 3으로 나눠지는 경우
		}
	}

	return numVector[num];
}

int main()
{
	int num;
	cin >> num;

	cout << solution(num);
}