#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<std::pair<int, int>> twoSum(const std::vector<int>& nums, int target) {
    std::vector<std::pair<int, int>> results = {};
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i]+nums[j] == target){
                results.push_back({i, j});
            };
        };
    };
    return results;
}


std::vector<std::pair<int, int>> twoSumOptimized(const std::vector<int>& nums, int target) {
    std::vector<std::pair<int, int>> results = {};
    std::unordered_map<int, int> pricesMap;
    for (int i = 0; i < nums.size(); ++i) {

        int diff = target - nums[i];

        if (pricesMap.find(diff) != pricesMap.end()){
            results.push_back({pricesMap[diff], i});

        } 
        pricesMap[nums[i]] = i;

    };
    return results;
}


int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    auto results = twoSumOptimized(nums, target);

    for (const auto& pair: results) {
        std::cout << "Indices: " << pair.first << ", " << pair.second << std::endl;
    };

    return 0;
}