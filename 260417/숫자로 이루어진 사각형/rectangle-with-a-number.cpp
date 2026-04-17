#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    int num = 1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(num == 10) num = 1;
            cout << num << " ";
            num++;
        }
        cout << "\n";
    }
    return 0;
}