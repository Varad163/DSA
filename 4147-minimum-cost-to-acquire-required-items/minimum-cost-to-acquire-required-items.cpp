
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        long long c1 = 1LL * need1 * cost1
                     + 1LL * need2 * cost2;

        long long mn = min(need1, need2);
        long long mx = max(need1, need2);

        long long c2 = mn * costBoth;

        if (need1 > need2) {
            c2 += 1LL * (need1 - need2) * cost1;
        } 
        else {
            c2 += 1LL * (need2 - need1) * cost2;
        }

        long long c3 = mx * costBoth;

        return min({c1, c2, c3});
    }
};
