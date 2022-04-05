#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int arr[14];
bool visited[14];
vector<int> nums;

void dfs(int now, int cnt)
{
	if (cnt == 6) // 순열을 완성했을 때
	{
		for (int i = 0; i < 6; ++i)
			cout << arr[i] << " ";
		cout << endl;
		return;
	}
	for (int i = now; i < nums.size(); ++i)
	{
		if (!visited[i]) // 아직 들르지 않았을 때
		{
			visited[i] = true;
			arr[cnt] = nums[i];
			dfs(i + 1, cnt + 1);
			visited[i] = false;
		}
	}
}
int main()
{
	int num;
	while (cin >> num && num) // 첫번째 수 입력되는 만큼, 첫번째 수가 0이 아닐때까지
	{
		vector<int> tempV;
		for (int i = 0; i < num; ++i)
		{
			int temp;
			cin >> temp;
			tempV.push_back(temp);
		}
		nums = tempV;
		dfs(0, 0); // 현재 숫자, 방문한 숫자 수
		cout << endl;
	}
}