#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int num_idx(string str) {
    for (int i = 0; i<str.length();i++) {
        char ch = str[i];
        if (isdigit(ch)) {
            return i;
        }
    }
    return -1;
}
int last_idx(string str, int idx) {
    for (int i = idx;i<str.length();i++) {
        char ch = str[i];
        if (!isdigit(ch)) return i-1;
    }
    return str.length() - 1;
}
bool comp(string str1, string str2) {
    int first_idx1 = num_idx(str1);
    int first_idx2 = num_idx(str2);
    int last_idx1 = last_idx(str1,first_idx1);
    int last_idx2 = last_idx(str2,first_idx2);
    string head1 = str1.substr(0,first_idx1);
    transform(head1.begin(),head1.end(),head1.begin(),[](char ch) {
        return toupper(ch);
    });
    string head2 = str2.substr(0,first_idx2);
    transform(head2.begin(),head2.end(),head2.begin(),[](char ch) {
        return toupper(ch);
    });
    string number1 = str1.substr(first_idx1,last_idx1 -first_idx1 + 1);
    string number2 = str2.substr(first_idx2,last_idx2-first_idx2 + 1);
    if (head1 != head2) return head1 < head2;
    if (stoi(number1) != stoi(number2)) return stoi(number1) < stoi(number2);
    return false;
}
vector<string> solution(vector<string> files) {
    stable_sort(files.begin(),files.end(),comp);
    return files;
}