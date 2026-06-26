#include <string>
#include <vector>
using namespace std;


int roll_cnt(char ch) {
    int front_cnt = ch - 'A';
    int back_cnt = abs('Z' - ch) + 1;
    return min(front_cnt,back_cnt);
}
int solution(string name) {

    int len = name.length();
    int move = len - 1;
    for (int i = 0; i<len;i++) {
        int next = i + 1;
        while (next < len && name[next] == 'A') next++;
        move = min(move, i * 2 + len - next);
        move = min(move, 2 * (len - next) + i);
    }

    int res = 0;
    res += move;
    for (char ch : name) {
        if (ch == 'A') continue;
        res += roll_cnt(ch);
    }
    return res;
}