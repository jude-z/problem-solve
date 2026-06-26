#include <string>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;
int grid[101][101];
int visited[101];
int n;
int check(int node) {
    bool flag = true;
    int cnt = 1;
    for (int i = 1;i<=n;i++) {
        if (grid[node][i]) {
            if (!visited[i]) {
                flag = false;
                visited[i] = 1;
                cnt += check(i);

            }
        }
    }
    return cnt;
}
int solution(int N, vector<vector<int>> wires) {
    n = N;
    for (auto wire : wires) {
        int from = wire[0];
        int to = wire[1];
        grid[from][to] = 1;
        grid[to][from] = 1;
    }
    int min_val = INT_MAX;
    for (auto wire : wires) {
        int from = wire[0];
        int to = wire[1];
        grid[from][to] = 0;
        grid[to][from] = 0;
        fill(visited, visited + 101,0);
        visited[1] = 1;
        int size = check(1);
        int another_size = n - size;
        int sub = abs(size - another_size);
        min_val = min(min_val,sub);
        grid[from][to] = 1;
        grid[to][from] = 1;
    }
    return min_val;
}