#include <iostream>
#include <cmath>

using namespace std;

bool buttons[10];

int distance(int num) // ���ڰ� �־����� �� ���ڰ� ���峵���� �Ǻ��ϰ�, ���� �� �� �������� Ȯ��
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
		if (buttons[num % 10]) // �������� ���ڰ� ���峵�ٸ� 0����
			return 0;
		num /= 10;
		len += 1;
	}

	return len;
}
int solution(int N)
{
	int result = abs(N - 100); // �ʱⰪ 100���� ��ǥ���� �����ϴ� �ִ� ���

	for (int i = 0; i < 1000000; ++i) // �ִ� ä���� 500000�̴�. 5,6,7,8�� ���峵�� ��찡 �־� 1000000������ ��´�.
	{ // 0~1000000���� ��ǥ�� �ּ� ��η� ���� ������ ���ڸ� ã�´�.
		int dis = distance(i);
		if (dis) // �ش� ����(i)�� ���� �� �ִٸ�
		{
			int pressPM = abs(N - i); // �ش� ���ڿ��� ��ǥ���� +.-�� ������ ��
			if (result > pressPM + dis)
				result = pressPM + dis;
		}
	}

	return result;
}
int main()
{
	int N, M; // �̵��Ϸ��� ä��, ���峭 ��ư�� ��
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int temp;
		cin >> temp;

		buttons[temp] = 1;
	}

	cout << solution(N);
}