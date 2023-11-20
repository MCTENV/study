
size_t FindTargetIdx(const std::vector<int>& nums, int target) {
    size_t idx = 0;
    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            idx = i;
            break;
        }
    }
    return idx;
}

size_t FindTargetIdxFromSortedVector(const std::vector<int>& nums, int target) {
    size_t idx = 0;
    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            idx = i;
            break;
        }
    }
    return idx;
}