#include <string>
#include <vector>
#include <stack>
using namespace std;
int get_idx(int idx, int len) {
    return idx + 1 == len ? 0 : idx + 1;
}
int solution(string s) {
    int res = 0;
    for (int start_idx = 0;start_idx < s.length();start_idx++) {
        stack<char> st;
        int idx = start_idx;
        int cnt = 0;
        bool flag = true;
        while (!cnt) {
            char ch = s[idx];
            idx = get_idx(idx,s.length());
            if (ch == '[' || ch == '(' || ch == '{') st.push(ch);
            else {
                if (st.empty()) {
                    flag = false;
                    break;
                }
                else {
                    if (ch == ']') {
                        if (st.top() == '[') st.pop();
                        else {
                            flag = false;
                            break;
                        }
                    }else if (ch == ')') {
                        if (st.top() == '(') st.pop();
                        else {
                            flag = false;
                            break;
                        }
                    }else if (ch == '}') {
                        if (st.top() == '{') st.pop();
                        else {
                            flag = false;
                            break;
                        }
                    }
                }
            }
            if (idx == start_idx) cnt++;
        }
        if (!flag) continue;
        if (flag && st.empty()) res++;
    }
    return res;
}