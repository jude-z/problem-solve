#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
bool is_prime(string num_str) {
    ll num = stoll(num_str);
    if (num == 1) return  false;
    for (ll i = 2;i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
int solution(int n, int k) {
    string str;
    while (n > 0) {
        str += to_string(n % k);
        n /= k;
    }
    reverse(str.begin(),str.end());
    string input;
    vector<string> v;
    for (int i = 0; i<str.length();i++) {
        char ch = str[i];
        if (ch == '0') {
            if (!input.empty()) v.push_back(input);
            input = "";
        }else {
            input += ch;
        }
    }
    if (!input.empty()) v.push_back(input);
    int res = 0;
    for (auto& val : v) {
        if (is_prime(val)) res++;
    }
    return res;
}