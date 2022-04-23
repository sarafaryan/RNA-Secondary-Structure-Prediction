#include "../include/solver.h"

int solve() {
    return 42;
}

std::vector<std::pair<int, int>> solve(rnaSeq rnaseq) {
    int n = rnaseq.length();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1));
    std::vector<std::vector<int>> previous_state(n + 1, std::vector<int>(n + 1, -1));

    for(int k = 5; k <= n; k++) {
        for(int i = 1; i + k <= n; i++) {
            int j = i + k;
            int &res = dp[i][j];

            for(int t = i; t <= j - 5; t++) {
                if(complement_base(rnaseq[t]) == rnaseq[j]) {
                    int val = 1 + dp[i][t - 1] + dp[t + 1][j - 1];
                    if(val > res) {
                        res = val;
                        previous_state[i][j] = t;
                    }
                }
            }

            if(dp[i][j - 1] > res) {
                res = dp[i][j - 1];
                previous_state[i][j] = j - 1;
            }
        }
    }

    return find_pairs(dp, previous_state, 1, n);
}

std::vector<std::pair<int, int>> find_pairs(std::vector<std::vector<int>> &dp, std::vector<std::vector<int>> &previous_state, int l, int r) {
    if(l < 1 or r < l or dp.size() - 1 < r or previous_state[l][r] == -1)
        return {};
    int t = previous_state[l][r];
    if(t == r - 1)
        return find_pairs(dp, previous_state, l, r - 1);
    
    auto left = find_pairs(dp, previous_state, l, t - 1);
    auto right = find_pairs(dp, previous_state, t + 1, r - 1);

    std::vector<std::pair<int, int>> ans {{ {t, r} }};
    ans.insert(ans.end(), left.begin(), left.end());
    ans.insert(ans.end(), right.begin(), right.end());

    return ans;
}