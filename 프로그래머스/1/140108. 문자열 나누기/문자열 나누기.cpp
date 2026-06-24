#include <string>
#include <iostream>
using namespace std;
int res;
int solution(string s) {
    char first = 0;
    int first_cnt = 0;
    int second_cnt = 0;
    for (int i = 0; i<s.length();i++) {
        char ch = s[i];
        if (first == 0) {
            first = ch;
            first_cnt++;
        }else {
            if (ch == first) {
                first_cnt++;
            }else {
                second_cnt++;
            }
            if (first_cnt == second_cnt) {
                first = 0;
                first_cnt = 0;
                second_cnt = 0;
                res++;
            }
        }
    }

    if (first_cnt != 0) res++;

    return res;
}

