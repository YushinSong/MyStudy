#include <string>
#include <vector>

using namespace std;

void dfs(int num, vector<vector<int>>& computers)
{
    if (computers[num][num] == 0)
        return;

    computers[num][num] = 0;
    for (int i = 0; i < computers.size(); ++i)
    {
        if (computers[num][i] == 1)
            dfs(i, computers);
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    for (int i = 0; i < computers.size(); ++i)
    {
        if (computers[i][i] == 1) // 순회안함
        {
            dfs(i, computers);
            ++answer;
        }
    }

    return answer;
}