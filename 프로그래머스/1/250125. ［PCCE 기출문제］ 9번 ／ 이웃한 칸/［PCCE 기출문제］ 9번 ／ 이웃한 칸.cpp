#include <string>
#include <vector>

using namespace std;
int n;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
bool check_range(int y, int x){
    return y > -1 && y < n && x > -1 && x < n;
}
int solution(vector<vector<string>> board, int h, int w) {
    n = board.size();
    string color = board[h][w];
    int res = 0;
    for(int i = 0; i<4;i++){
        int ny = h + dy[i];
        int nx = w + dx[i];
        if(!check_range(ny,nx)) continue;
        if(board[ny][nx] == color) res++; 
    }
    return res;
    
}