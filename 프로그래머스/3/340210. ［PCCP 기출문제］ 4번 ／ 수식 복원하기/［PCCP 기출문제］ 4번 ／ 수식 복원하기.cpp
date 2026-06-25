#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
string trim(string s) {
    string str;
    for(int i = 0; i<s.length();i++){
        char ch = s[i];
        if(ch != ' ') str += ch;
    }
    return str;
}
int to_value(string str, int base) {
    str = trim(str);
    int res = 0;
    for (char ch : str) {
        res = res * base + (ch - '0');
    }
    return res;
}
bool final_check(int num1, int num2, char oper, int final_value) {
    if (oper == '+') return num1 + num2 == final_value;
    else if (oper == '-') return num1 - num2 == final_value;
}
string return_value(int num1, int num2, char oper,int base){
    int num;
    if(oper == '+') num = num1 + num2;
    if(oper == '-') num = num1 - num2;
    if (num == 0) return "0";
    string res;
    while (num > 0) {
        res += (num % base) + '0';
        num /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}
string ret_value(string expression,vector<int>& v) {

    int oper_idx,equal_idx;
    if (expression.find('+') != -1) oper_idx = expression.find('+');
    if (expression.find('-') != -1) oper_idx = expression.find('-');
    equal_idx = expression.find("=");

    string num1_str = expression.substr(0,oper_idx);
    string num2_str = expression.substr(oper_idx + 1, equal_idx - oper_idx - 1);

    vector<string> candidate;
    for (auto base : v) {
        int num1 = to_value(num1_str,base);
        int num2 = to_value(num2_str, base);
        candidate.push_back(return_value(num1,num2,expression[oper_idx],base));
    }
    bool is_same = true;
    string str = candidate[0];
    for (auto val : candidate) {
        if (str != val) {
            is_same = false;
            break;
        }
    }
    string final_str = is_same ? str : "?";


    int x_idx = expression.find("X");
    string res;
    for (int i = 0; i<x_idx;i++) {
        res += expression[i];
    }
    res += final_str;
    for (int i = x_idx +1;i<expression.length();i++) {
        res += expression[i];
    }
    return res;
}
bool check(string expression,int base){
    int oper_idx,equal_idx;
    if (expression.find('+') != -1) oper_idx = expression.find('+');
    if (expression.find('-') != -1) oper_idx = expression.find('-');
    equal_idx = expression.find('=');

    string num1_str = expression.substr(0,oper_idx);
    string num2_str = expression.substr(oper_idx + 1, equal_idx - oper_idx -1);
    string final_str = expression.substr(equal_idx + 1);

    int num1 = to_value(num1_str,base);
    int num2 = to_value(num2_str, base);
    int final_num = to_value(final_str,base);

    return final_check(num1,num2,expression[oper_idx],final_num);

}
vector<string> solution(vector<string> expressions) {
    int max_value = -1;
    for(auto expression : expressions){
        for(int i = 0; i<expression.length();i++){
            char ch = expression[i];
            if(isdigit(ch)){
                max_value = max(max_value,ch - '0');
            }
        }
    }
    for(int num = max_value + 1;num <= 9;num++){
        bool flag = true;
        for(auto expression : expressions){
            if(expression.find("X") != -1) continue;
            if(!check(expression,num)){
                flag = false;
                break;
            }
        }
        if(flag){
            v.push_back(num);
        }
    }
    vector<string> result;

    for(auto expression : expressions){
        int idx = expression.find("X");
        if(idx != -1){
            result.push_back(ret_value(expression,v));
        }
    }

    return result;
}