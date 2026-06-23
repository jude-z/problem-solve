#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    vector<int> score(3, 0);
    int idx = -1;

    for (int i = 0; i < dartResult.size(); i++) {
        char ch = dartResult[i];

        if (isdigit(ch)) {
            idx++;

            if (ch == '1' &&
                i + 1 < dartResult.size() &&
                dartResult[i + 1] == '0') {
                score[idx] = 10;
                i++;
            } else {
                score[idx] = ch - '0';
            }
        }

        else if (ch == 'S') {
        }
        else if (ch == 'D') {
            score[idx] *= score[idx];
        }
        else if (ch == 'T') {
            score[idx] *= score[idx] * score[idx];
        }

        else if (ch == '*') {
            score[idx] *= 2;

            if (idx > 0)
                score[idx - 1] *= 2;
        }
        else if (ch == '#') {
            score[idx] *= -1;
        }
    }

    return score[0] + score[1] + score[2];
}