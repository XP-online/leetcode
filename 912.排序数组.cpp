/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
      if (nums.size() <= 1) return nums;
      qsort(nums, 0, nums.size() - 1);
      return nums;
    }

private:
  void qsort(vector<int>& arr, int first, int end) {
    if (first >= end) return;
    //取出中值,并对简单定位三个数的位置
    int middle = findmiddle(arr, first, end);
    //对于小于等于3的区间可以直接返回
    if (end <= first + 2) return;

    int right = end - 2;   
    for (int left = first + 1; left < right; left++) {
      if (arr[left] >= middle) {
        while (right > left) {
          if (arr[right] <= middle) {
            swap(arr[left], arr[right]);
            break;
          }
          right--;
        }
      }
    }
    if(arr[right] < arr[end - 1]){
      right++;
    }else{
      swap(arr[right], arr[end - 1]);
    }

    qsort(arr, first, right - 1);
    qsort(arr, right + 1, end);
  }
  int findmiddle(vector<int>& arr, int first, int end) {
    int middle = (first + end) / 2;
    int index = middle;
    if (arr[first] > arr[end]) {
      swap(arr[first], arr[end]);
    }
    if (arr[first] > arr[middle]) {
      swap(arr[first], arr[middle]);
    }
    if (arr[middle] > arr[end]) {
      swap(arr[middle], arr[end]);
    }
    swap(arr[middle], arr[end - 1]);
    return arr[end - 1];
  }
};
// @lc code=end
int main(){
    return 0;
}
