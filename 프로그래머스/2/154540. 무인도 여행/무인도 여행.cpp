#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int row, col;
vector<vector<char>> grid;
vector<vector<int>> visited;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
bool check_range(int y, int x) {
    return y > -1 && y < row && x > -1 && x < col;
}
int area(int y, int x) {
    int val = grid[y][x] - '0';
    for (int i = 0; i<4;i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (!check_range(ny,nx)) continue;
        if (grid[ny][nx] == 'X') continue;
        if (visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        val += area(ny,nx);
    }
    return val;
}
vector<int> solution(vector<string> maps) {
    vector<int> res;
    row = maps.size();
    col = maps[0].length();
    grid = vector<vector<char>>(row,vector<char>(col));
    visited = vector<vector<int>>(row,vector<int>(col));
    for (int i = 0; i<row;i++) {
        for (int j = 0;j<col;j++) {
            grid[i][j] = maps[i][j];
        }
    }
    for (int i = 0;i<row;i++) {
        for (int j =0;j<col;j++) {
            if (grid[i][j] != 'X' && !visited[i][j]) {
                visited[i][j] = 1;
                res.push_back(area(i,j));
            }
        }
    }
    if (res.empty()) res = vector<int>{-1};
    sort(res.begin(),res.end());
    return res;
}