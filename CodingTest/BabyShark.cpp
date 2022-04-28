#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

#define SIZE 21

using namespace std;

struct BabyShark
{
	int height, width;
	int size;
	int eat;
	int moveTime;
};
BabyShark baby;
struct Fish
{
	int height, width;
	int distance;
};
vector<Fish> eatFish;

int N; // ���� ũ��
vector<vector<int>> seaMap; // �Էµ� �ٴ� ��
vector<vector<int>> passTime; // �������µ� �ɸ� �ð�
bool visited[SIZE][SIZE];	// �湮üũ

int moveH[4] = { -1, 0, 0, 1 };
int moveW[4] = { 0, -1, 1, 0 };

void clearEverything()
{
	eatFish.clear();
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			visited[i][j] = false;
		}
	}
}
void bfs(int babyH, int babyW)
{
	queue<pair<pair<int, int>, int>> bfsq;
	bfsq.push({ { babyH, babyW }, 0 });
	visited[babyH][babyW] = true;

	while (!bfsq.empty())
	{
		int nowH = bfsq.front().first.first;
		int nowW = bfsq.front().first.second;
		int nowD = bfsq.front().second;
		bfsq.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nextH = nowH + moveH[i];
			int nextW = nowW + moveW[i];

			if (nextH >= N || nextH < 0 || nextW >= N || nextW < 0)
				continue;

			if (!visited[nextH][nextW])
			{
				if (seaMap[nextH][nextW] == 0) // �ƹ��͵� ����
				{
					visited[nextH][nextW] = true;
					bfsq.push({ { nextH, nextW }, nowD + 1 });
				}
				else if (seaMap[nextH][nextW] < baby.size) // ����Ⱑ ���� �۴�
				{
					Fish temp; 
					temp.height = nextH; temp.width = nextW;
					temp.distance = nowD + 1;

					eatFish.push_back(temp);
					visited[nextH][nextW] = true;
					bfsq.push({ { nextH, nextW }, nowD + 1 });
				}
				else if (seaMap[nextH][nextW] == baby.size) // ����Ⱑ ���� ����
				{
					visited[nextH][nextW] = true;
					bfsq.push({ { nextH, nextW }, nowD + 1 });
				}
			}
		}
	}
}
int main()
{
	cin >> N;

	seaMap.assign(N, vector<int>(0, 0));
	passTime.assign(N, vector<int>(0, 0));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int temp;
			cin >> temp;
			seaMap[i].push_back(temp);
			passTime[i].push_back(0);
			if (temp == 9)
			{
				baby.height = i; baby.width = j;
				baby.size = 2; baby.eat = 0; baby.moveTime = 0;
				seaMap[i][j] = 0;
			}
		}
	}

	while (true)
	{
		clearEverything();

		bfs(baby.height, baby.width); // �Ʊ��� ���� ��ġ
		if (eatFish.empty()) // ���̻� ���� �� �ִ� ����Ⱑ ����
		{
			cout << baby.moveTime;
			break;
		}
		else // ���� �� �ִ� ����Ⱑ ����
		{
			sort(eatFish.begin(), eatFish.end(), [](const Fish& a, const Fish& b) {
				if (a.distance <= b.distance)
				{
					if (a.distance == b.distance)
					{
						if (a.height <= b.height)
						{
							if (a.height == b.height)
							{
								if (a.width < b.width)
								{
									return true;
								}
								return false;
							}
							return true;
						}
						return false;
					}
					return true;
				}
				return false;
			});

			seaMap[eatFish[0].height][eatFish[0].width] = 9; // ������ �̵�
			seaMap[baby.height][baby.width] = 0;
			baby.height = eatFish[0].height; baby.width = eatFish[0].width;
			++baby.eat; // �ϳ� �Ա�
			baby.moveTime += eatFish[0].distance; // ������� �Ÿ���ŭ �̵��ð� ���ϱ�

			if (baby.eat >= baby.size) // ũ�� Ŀ����ŭ �Ծ���
			{
				baby.eat = 0;
				++baby.size;
			}
		}
	}
}