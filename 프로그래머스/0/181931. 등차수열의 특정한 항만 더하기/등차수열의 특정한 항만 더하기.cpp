#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int res = 0;
    for(int i = 0; i<included.size();i++){
        if(included[i]){
            res += (a + i * d);
        }
    }
    int answer = 0;
    return res;
}