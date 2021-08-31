/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> answer(n + 1);
    for (auto& item : bookings) {
      answer[item[0] - 1] += item[2];
      answer[item[1]] -= item[2];
    }
    answer.pop_back();
    for (int i = 1; i < n; i++) {
      answer[i] += answer[i - 1];
    }
    return answer;
  }
};
// @lc code=end
int main() {
  vector<vector<int>> bookings{{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
  Solution s;
  auto answer = s.corpFlightBookings(bookings, 5);
  for (auto it : answer) {
    cout << it << " ";
  }
  return 0;
}
