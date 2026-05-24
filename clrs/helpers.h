#pragma once

#include <iostream>
#include <vector>

inline void print(std::vector<int>& nums) {
    for (size_t i = 0; i < nums.size(); i++) {
        if (i) std::cout << ' ';
        std::cout << nums[i];
    }
    std::cout << std::endl;
}
