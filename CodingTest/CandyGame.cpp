#include <iostream>
#include <algorithm>

using namespace std;


int countColumn(char board[51][51], int num)
{
	int max = 1;
	for (int i = 0; i < num; ++i)
	{
		int count = 1;
		for (int j = 0; j < num; ++j)
		{
			if (board[i][j] == board[i][j + 1]) // 오른쪽 보드가 같은 경우
				++count;
			else // 같지 않은 경우
			{
				if (count > max)
					max = count;
				count = 1;
			}
		}
	}
	return max;
}
int countRow(char board[51][51], int num)
{
	int max = 1;
	for (int i = 0; i < num; ++i)
	{
		int count = 1;
		for (int j = 0; j < num; ++j)
		{
			if (board[j][i] == board[j + 1][i]) // 아래 보드가 같은 경우
				++count;
			else // 같지 않은 경우
			{
				if (count > max)
					max = count;
				count = 1;
			}
		}
	}
	return max;
}
void solution(char board[51][51], int num)
{
	int maxCount = 0;

	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			if (board[i][j] != board[i][j + 1])
			{
				swap(board[i][j], board[i][j + 1]);

				if (maxCount < max(countColumn(board, num), countRow(board, num)))
					maxCount = max(countColumn(board, num), countRow(board, num));

				swap(board[i][j], board[i][j + 1]);
			}

			if (board[j][i] != board[j + 1][i])
			{
				swap(board[j][i], board[j + 1][i]);

				if (maxCount < max(countColumn(board, num), countRow(board, num)))
					maxCount = max(countColumn(board, num), countRow(board, num));

				swap(board[j][i], board[j + 1][i]);
			}
		}
	}

	cout << maxCount << endl;
}
int main()
{
	char board[51][51];
	int num;
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			cin >> board[i][j];
		}
	}

	solution(board, num);
}