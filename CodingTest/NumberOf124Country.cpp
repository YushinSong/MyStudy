#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    int remain = 0;

    while (n != 0)
    {
        remain = n % 3;
        n /= 3;

        if (remain == 0) {
            answer = "4" + answer;
            n--;
        }
        else if (remain == 1) {
            answer = "1" + answer;
        }
        else if (remain == 2) {
            answer = "2" + answer;
        }
    }

    return answer;
}