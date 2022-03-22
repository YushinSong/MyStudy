#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// ���ӵ� �������� ��ȣ�� ������ �ּڰ��� �ȴ�.
// ��, ó�� -�� �����ϱ� �������� ����� �������ٰ� ���� ��� ������ �Ǵ� ���̴�.
int solution(string input)
{
	int result = 0;
	int inputLen = input.size();
	bool isMinus = false;

	string temp = "";
	for (int i = 0; i < inputLen + 1; ++i)
	{
		if (input[i] == '-' || input[i] == '+' || i == inputLen)
		{
			if (isMinus) // -�� �ѹ��̶� ������ ����
			{
				result -= stoi(temp);
			}
			else // ���� -�� �����ϱ� ��
			{
				result += stoi(temp);
			}
			temp = "";

			if (input[i] == '-')
				isMinus = true;
		}
		else
		{
			temp += input[i];
		}
	}

	return result;
}
int main()
{
	string input;
	cin >> input;

	cout << solution(input);
}