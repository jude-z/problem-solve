#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int size = progresses.size();
    vector<int> days(size);
    vector<int> res;
    for (int i = 0; i<size;i++) {
        days[i] = ((100 - progresses[i]) % speeds[i]) == 0 ? ((100 - progresses[i]) / speeds[i]) : ((100 - progresses[i]) / speeds[i]) + 1;
    }

    int cnt = 0;
    stack<int> s;
    for (int i = 0; i<size;i++) {
        if (s.empty()) {
            s.push(days[i]);
            cnt++;
        }else {
            if (days[i] <= s.top()) cnt++;
            else {
                res.push_back(cnt);
                s.pop();
                cnt = 0;
                i--;
            }
        }
    }
    if (!s.empty()) res.push_back(cnt);
    return res;

}