#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int w, h = 0;
    int temp = 0;

    temp = sqrt((brown + 4) * (brown + 4) / 4 - 4 * (brown + yellow));
    w = ((brown + 4) / 2 + temp) / 2;
    h = ((brown + 4) / 2 - temp) / 2;
    answer.push_back(w);
    answer.push_back(h);

    return answer;
}