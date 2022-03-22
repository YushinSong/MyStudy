#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// 연속된 덧셈들을 괄호로 묶으면 최솟값이 된다.
// 즉, 처음 -가 출현하기 전까지는 양수로 더해지다가 이후 계속 뺄셈이 되는 것이다.
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
			if (isMinus) // -가 한번이라도 출현한 이후
			{
				result -= stoi(temp);
			}
			else // 아직 -가 출현하기 전
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