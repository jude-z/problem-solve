#include <vector>
#include <climits>
#include <queue>
#include <map>
using namespace std;

vector<int> solution(int k, vector<int> scores) {
    vector<int> res;
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int score : scores) {
        pq.push(score);
        if (pq.size() > k) pq.pop();
        res.push_back(pq.top());
    }
    return res;

}