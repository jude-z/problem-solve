#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(),
    [](const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
    });
    int cnt = 0;
    int pos = routes[0][1];
    cnt++;
    for (auto& route : routes) {
        int from = route[0];
        int to = route[1];
        if (pos >= from && pos <= to) continue;
        cnt++;
        pos = to;
    }
    return cnt;
}