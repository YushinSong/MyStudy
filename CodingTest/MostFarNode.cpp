#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <iostream>

using namespace std;
vector <vector<int>> graph;

int search_cnt(int number) {
	bool check[20000];
	memset(check, false, sizeof(check));

	queue <int> q;
	q.push(number);
	check[number] = true;

	int prev = 0;

	while (1) {
		int loop = q.size();
		int cnt = 0;

		for (int i = 0; i < loop; i++) { // �� for������ ��� ��带 ���ƺ� �� ����
			int cur_number = q.front();
			q.pop();

			for (int k = 0; k < graph[cur_number].size(); k++) { // cur_number��忡 ����� �ٸ� ���� �ȱ�
				if (check[graph[cur_number][k]] == false) { // ��� ����� ǥ���ΰ�?
					check[graph[cur_number][k]] = true;
					q.push(graph[cur_number][k]); // k�� ��忡 ����� i�� q�� �ִ´�
					cnt += 1;
				}
			}
		}

		if (q.empty()) {
			break;
		}
		prev = cnt;
	}

	return prev;
}


int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	int max_number = 0;
	for (int i = 0; i < edge.size(); i++) {
		max_number = max(max_number, edge[i][0]);
		max_number = max(max_number, edge[i][1]);
	}

	graph.resize(max_number);

	for (int i = 0; i < edge.size(); i++) {
		graph[edge[i][0] - 1].push_back(edge[i][1] - 1);
		graph[edge[i][1] - 1].push_back(edge[i][0] - 1);
	}

	answer = max(answer, search_cnt(0));

	return answer;
}