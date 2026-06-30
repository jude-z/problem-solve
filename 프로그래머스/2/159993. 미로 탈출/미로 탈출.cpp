#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int row, col;
vector<vector<char>> grid;
int visited[101][101][2];
class Position {
public:
    int y;
    int x;
    bool on;
    Position(int y, int x, bool on):y(y),x(x),on(on){}
    Position(){}
};
pair<int,int> start,final,lever;
bool check_range(int y, int x) {
    return y > -1 && y < row && x > -1 && x < col;
}
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
int solution(vector<string> maps) {
    row = maps.size();
    col = maps[0].size();
    grid = vector(row,vector<char>(col));
    for (int i = 0; i<row;i++) {
        for (int j = 0; j<col;j++) {
            grid[i][j] = maps[i][j];
            if (grid[i][j] == 'S') start = {i,j};
            if (grid[i][j] == 'L') lever = {i,j};
            if (grid[i][j] == 'E') final = {i,j};
        }
    }

    queue<Position> q;
    q.push(Position{start.first,start.second,false});
    visited[start.first][start.second][0] = 1;
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        bool turn_on = q.front().on;
        q.pop();
        for (int i = 0; i<4;i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!check_range(ny,nx)) continue;
            if (visited[ny][nx][turn_on ? 1 : 0]) continue;
            if (grid[ny][nx] == 'X') continue;
            int value = visited[y][x][turn_on ? 1 : 0];
            bool next_on = turn_on;
            if (ny == lever.first && nx == lever.second) next_on = true;
            visited[ny][nx][next_on ? 1 : 0] = value + 1;
            q.push({ny,nx,next_on});
        }
    }

    return visited[final.first][final.second][1] - 1;
}
