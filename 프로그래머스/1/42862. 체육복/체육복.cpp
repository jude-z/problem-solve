#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    vector<int> real_lost;
    for (int l : lost) {
        auto it = find(reserve.begin(), reserve.end(), l);
        if (it != reserve.end()) {
            reserve.erase(it); 
        } else {
            real_lost.push_back(l);
        }
    }

    lost = real_lost;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    vector<bool> used(reserve.size(), false);

    int answer = n - lost.size();

    for (int l : lost) {
        for (int i = 0; i < reserve.size(); i++) {
            if (!used[i] && abs(reserve[i] - l) == 1) {
                used[i] = true;
                answer++;
                break;
            }
        }
    }

    return answer;
}