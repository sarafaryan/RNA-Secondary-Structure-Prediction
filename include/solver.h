#pragma once
#include "rnaSeq.h"
#include <vector>

int solve();

std::vector<std::pair<int, int>> solve(rnaSeq);

std::vector<std::pair<int, int>> find_pairs(
    std::vector<std::vector<int>> &dp,
    std::vector<std::vector<int>> &previous_state,
    int l,
    int r
);
