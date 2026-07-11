#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    string res;
    int idx1 = 0;
    int idx2 = 0;
    bool flag = true;
    while(idx1 < str1.length() && idx2 < str2.length()){
        if(flag) {res += str1[idx1++]; flag = false;}
        else {res += str2[idx2++]; flag = true;}
    }
    while(idx1 < str1.length()){
        res += str1[idx1++];
    }
    while(idx2 < str2.length()){
        res += str2[idx2++];
    }
    return res;
}