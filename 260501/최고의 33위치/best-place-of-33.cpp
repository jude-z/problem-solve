#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int max_val = 0;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> map = vector<vector<int>>(n,vector<int>(n));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0;i<n-2;i++){
        for(int j= 0;j<n-2;j++){
            int sum = 0;
            for(int k = i;k<i+3;k++){
                for(int l = j;l<j+3;l++){
                    if(map[k][l]) sum++;
                }
            }
            max_val = max(max_val,sum);
        }
    }

    cout << max_val;

    // Please write your code here.
    return 0;
}