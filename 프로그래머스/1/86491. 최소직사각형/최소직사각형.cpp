#include <string>
#include <vector>
using namespace std;
int solution(vector<vector<int>> sizes) {
    int big = 0;
    int small = 0;
    for(auto val : sizes){
        big = max(big, max(val[0],val[1]));
        small = max(small, min(val[0],val[1]));
    }

    return big * small;
}