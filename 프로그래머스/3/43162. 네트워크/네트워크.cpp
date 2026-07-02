#include <string>
#include <vector>

using namespace std;
vector<int> visited;
void dfs(int node,vector<vector<int>>& computers) {
    vector<int>& v = computers[node];
    for (int i = 0; i<v.size();i++) {
        if (!v[i]) continue;
        if (visited[i]) continue;
        visited[i] = 1;
        dfs(i, computers);
    }
}
int solution(int n, vector<vector<int>> computers) {
    visited = vector<int>(n);
    int cnt = 0;
    for (int i = 0; i<n;i++) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(i,computers);
            cnt++;
        }
    }
    return cnt;
}