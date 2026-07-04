#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Group {
    int dia = 0;
    int iron = 0;
    int stone = 0;
};

int solution(vector<int> picks, vector<string> minerals) {
    vector<Group> groups;

    int totalPick = picks[0] + picks[1] + picks[2];
    int maxMinerals = min((int)minerals.size(), totalPick * 5);

    for (int i = 0; i < maxMinerals; i += 5) {
        Group g;

        for (int j = i; j < min(i + 5, maxMinerals); j++) {
            if (minerals[j] == "diamond")
                g.dia++;
            else if (minerals[j] == "iron")
                g.iron++;
            else
                g.stone++;
        }

        groups.push_back(g);
    }

    sort(groups.begin(), groups.end(), [](const Group &a, const Group &b) {
        int costA = a.dia * 25 + a.iron * 5 + a.stone;
        int costB = b.dia * 25 + b.iron * 5 + b.stone;
        return costA > costB;
    });

    int answer = 0;
    int idx = 0;

    while (picks[0] > 0 && idx < groups.size()) {
        answer += groups[idx].dia + groups[idx].iron + groups[idx].stone;
        picks[0]--;
        idx++;
    }

    while (picks[1] > 0 && idx < groups.size()) {
        answer += groups[idx].dia * 5 + groups[idx].iron + groups[idx].stone;
        picks[1]--;
        idx++;
    }

    while (picks[2] > 0 && idx < groups.size()) {
        answer += groups[idx].dia * 25 + groups[idx].iron * 5 + groups[idx].stone;
        picks[2]--;
        idx++;
    }

    return answer;
}