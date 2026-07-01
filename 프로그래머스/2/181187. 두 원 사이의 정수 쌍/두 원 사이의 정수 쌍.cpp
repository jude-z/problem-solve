#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;

long long solution(int r1, int r2) {
    ll res = 0;
    for (int y = 1;y<=r2;y++) {
        int db_upper_limit = floor(sqrt(1LL * r2*r2 - 1LL * y*y));
        int db_lower_limit = ceil(sqrt(1LL * r1*r1 - 1LL * y*y));

        int it_upper_limit = (int)db_upper_limit;
        int it_lower_limit = (int)db_lower_limit;

        if (y > r1) {
            res += (it_upper_limit + 1);
            continue;
        }
        res += (it_upper_limit - it_lower_limit + 1);
    }
    return 4 * res;
}
