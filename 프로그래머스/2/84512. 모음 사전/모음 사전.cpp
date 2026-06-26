#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int visited[5];
vector<string> res;
void dfs(int depth, string str) {
    if (str.length()) res.push_back(str);
    if (depth == 5) return;
    dfs(depth + 1, str + 'A');
    dfs(depth + 1, str + 'E');
    dfs(depth + 1, str + 'I');
    dfs(depth + 1, str + 'O');
    dfs(depth + 1, str + 'U');
}
int solution(string word) {
    vector<char> v{'A','E','I','O','U'};
    dfs(0,"");
    return (find(res.begin(),res.end(),word) - res.begin()) + 1;

}