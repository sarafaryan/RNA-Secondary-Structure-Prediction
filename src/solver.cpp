#include "../include/solver.h"
#include <vector>

int solve() {
    return 42;
}

int solve(rnaSeq rnaseq) {
    int n = rnaseq.length();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1));

    for(int k = 5 ; k < n ; k++) {
        for(int i = 1 ; i <= (n-k) ; i++) {
            int j = i + k;
            int &res = dp[i][j];

            for(int t = i ; t <= (j-5) ; j++) 
                if(complement_base(rnaseq[t]) == rnaseq[j])
                    res = std::max(res, 1 + dp[i][t - 1] + dp[t + 1][j - 1]);
            
            res = std::max(res, dp[i][j - 1]);
        }
    }

    return dp[1][n];
}