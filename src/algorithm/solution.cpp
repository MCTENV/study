// 生成一个名为Solution的类，类中存在方法BubbleSort为冒泡排序的实现
// public:
class Solution {
public:
    void BubbleSort(std::vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    std::swap(nums[j], nums[j + 1]);
                }
            }
        }
    }
};

// Solution 使用
int main() {
    std::vector<int> nums = {5, 4, 3, 2, 1};
    Solution solution;
    solution.BubbleSort(nums);
    for (auto i : nums) {
        std::cout << i << " ";
    }
    return 0;
}