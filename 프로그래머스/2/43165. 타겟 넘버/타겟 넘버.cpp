#include <string>
#include <vector>

using namespace std;
int res;
int n;
vector<int> visited;
void calc(vector<int>& numbers,int target) {
    int sum = 0;
    for (int i = 0; i<n;i++) {
        if (visited[i] == 1) {
            sum += numbers[i];
        }else if (visited[i] == -1) {
            sum -= numbers[i];
        }
    }
    if (sum == target) res++;
}
void dfs(int depth,vector<int>& numbers,int target) {
    if (depth == n) {
        calc(numbers,target);
        return;
    }
    visited[depth] = 1;
    dfs(depth + 1, numbers,target);
    visited[depth] = -1;
    dfs(depth + 1, numbers,target);
}
int solution(vector<int> numbers, int target) {
    n = numbers.size();
    visited = vector<int>(n);
    dfs(0,numbers,target);
    return res;
}