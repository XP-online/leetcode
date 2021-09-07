/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      if(nums.empty()) return 0;
      vector<int> dp(nums.size(),0);
      dp[0] = 1;
      
      for(int i=1; i<nums.size(); i++){
        for(int it = 0; it<i; it++){
          if(nums[it] < nums[i] && dp[it] > dp[i]){
            dp[i] = dp[it];
          }
        }
        dp[i]++;
      }
      int ret = 1;
      for(int i=0; i<dp.size(); i++){
        if(dp[i] > ret){
            ret = dp[i];
          }
      }
      return ret;
    }
};
// @lc code=end

int main() { return 0; }