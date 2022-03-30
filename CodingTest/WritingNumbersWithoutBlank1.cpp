#include <iostream>
#include <cmath>

using namespace std;

int digit(long long N) // 몇자리 수인지 확인
{
	int count = 0;
	while (N > 0)
	{
		N /= 10;
		++count;
	}
	return count;
}
long long solution(long long N)
{
	long long result = 0;
	int digitCount = digit(N);

	for (int i = 1; i < digitCount; ++i)
	{
		result += (i * (9 * pow(10, (i - 1))));
	}
	result += ((N - pow(10, digitCount - 1)) + 1) * digitCount;

	return result;
}
int main()
{
	long long N;
	cin >> N;

	cout << solution(N);
}