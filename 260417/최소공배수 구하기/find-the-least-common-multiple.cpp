#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int n,m;
    cin >> n >> m;
    int min_val = min(n,m);
    int max_val = 1;
    for(int i = 2;i<=min_val;i++){
        if(n % i == 0 && m % i == 0) max_val = max(max_val,i);
    }
    cout << max_val * (n / max_val) * (m / max_val);

    return 0;
}