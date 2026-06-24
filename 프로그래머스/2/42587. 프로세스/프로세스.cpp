#include <vector>
#include <iostream>
using namespace std;
int max_val(vector<int>& v) {
    int value = -1;
    for (int i = 0; i<v.size();i++) {
        if (v[i] > value) value = v[i];
    }
    return value;
}
int solution(vector<int> v, int location) {
    int size = v.size();
    vector<int> res(size);
    int rank = 1;
    int max_value = max_val(v);
    while (1) {
        for (int i = 0; i < size;i++) {
            if (res[i]) continue;
            if (v[i] == max_value) {
                res[i] = rank++;
                v[i] = 0;
                max_value = max_val(v);
            }
            if (res[location]) {
                return res[location];
            }
            if (i == size -1) i = -1;
        }
    }

}
