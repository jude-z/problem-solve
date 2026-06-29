#include <vector>
using namespace std;
vector<int> solution(int n, long long k) {
    vector<int> nums;
    vector<int> answer;

    long long fact = 1;

    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
        fact *= i;
    }

    k--; 

    while (n) {
        fact /= n;

        int idx = k / fact;

        answer.push_back(nums[idx]);
        nums.erase(nums.begin() + idx);

        k %= fact;
        n--;
    }

    return answer;
}