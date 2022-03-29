#include <iostream>
#include <cmath>

using namespace std;

bool buttons[10];

int distance(int num) // 숫자가 주어지면 그 숫자가 고장났는지 판별하고, 숫자 몇 번 누르는지 확인
{
	if (num == 0)
	{
		if (buttons[0])
			return 0;
		else
			return 1;
	}
	int len = 0;
	while (num > 0)
	{
		if (buttons[num % 10]) // 누르려던 숫자가 고장났다면 0리턴
			return 0;
		num /= 10;
		len += 1;
	}

	return len;
}
int solution(int N)
{
	int result = abs(N - 100); // 초기값 100에서 목표까지 도달하는 최대 경우

	for (int i = 0; i < 1000000; ++i) // 최대 채널이 500000이다. 5,6,7,8이 고장났을 경우가 있어 1000000까지로 잡는다.
	{ // 0~1000000까지 목표에 최소 경로로 도달 가능한 숫자를 찾는다.
		int dis = distance(i);
		if (dis) // 해당 숫자(i)를 누를 수 있다면
		{
			int pressPM = abs(N - i); // 해당 숫자에서 목표까지 +.-를 누르는 수
			if (result > pressPM + dis)
				result = pressPM + dis;
		}
	}

	return result;
}
int main()
{
	int N, M; // 이동하려는 채널, 고장난 버튼의 수
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int temp;
		cin >> temp;

		buttons[temp] = 1;
	}

	cout << solution(N);
}