/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] 分割平衡字符串
 */
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
  int balancedStringSplit(string s) {
    auto it = s.begin();
    int count = 0, left = 0, right = 0;

    while (it != s.end()) {
      if (*it == 'L') {
        left++;
      } else if (*it == 'R') {
        right++;
      }
      if (left == right) {
        left = 0;
        right = 0;
        count++;
      }
      it++;
    }
    return count;
  }
};
// @lc code=end

int main() { return 0; }