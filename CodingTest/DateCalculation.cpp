#include <iostream>

using namespace std;

int solution(int E, int  S, int  M)
{
	int result = 0;
	int e = 0, s = 0, m = 0;

	while (!(e == E && s == S && m == M))
	{
		++result;
		++e, ++s, ++m;
		if (e > 15)
			e = 1;
		if (s > 28)
			s = 1;
		if (m > 19)
			m = 1;
	}

	return result;
}
int main()
{
	int E, S, M;
	cin >> E >> S >> M;

	cout << solution(E, S, M);
}