/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();
    int middle;
    while (left < right) {
      middle = (left + right) / 2;
      if (nums[middle] == target) {
        return middle;
      } else if (nums[middle] > target) {
        right = middle;
      } else if (nums[middle] < target) {
        left = middle + 1;
      }
    }
    return -1;
  }
};
// @lc code=end

int main() { return 0; }
