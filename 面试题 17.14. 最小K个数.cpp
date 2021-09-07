#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
  vector<int> smallestK(vector<int>& arr, int k) {
    vector<int> ret;
    if (k > arr.size()) {
      return ret;
    }
    int left = 0;
    int right = arr.size() - 1;
    silp(arr, k, left, right);
    for (int i = 0; i < k; i++) {
      ret.push_back(arr[i]);
    }
    return ret;
  }

  void silp(vector<int>& arr, int& k, int left, int right) {
    cout<<"run silp"<<endl;
    if (left >= right) return;
    int middle = findmiddle(arr, left, right);
    //对于小于等于3的区间可以直接返回
    if (right <= left + 2) {
      return;
    }
    //确定middle的位置
    int end = right - 2;
    for (int first = left + 1; first < end; first++) {
      if (arr[first] >= middle) {
        while (first < end) {
          if (arr[end] < middle) {
            swap(arr[first], arr[end]);
            break;
          }
          end--;
        }
      }
    }
    if (end < right -1 && arr[end] < arr[right - 1]) {  //此时说明right-1 之前的数都比 arr[right-1](也就是middle)小
      end = right -1;
    } else {
      swap(arr[end], arr[right - 1]);
    }

    //判断middle的点是不是正好等于k
    if (k == end || k == end + 1) {
      return;
    } else if (end > k) {
      right = end - 1;
    } else if (end < k) {
      left = end + 1;
    }
    silp(arr, k, left, right);
  }

  int findmiddle(vector<int>& arr, int left, int right) {
    int middle = (left + right) / 2;
    int index = middle;
    if (arr[left] > arr[right]) {
      swap(arr[left], arr[right]);
    }
    if (arr[left] > arr[middle]) {
      swap(arr[left], arr[middle]);
    }
    if (arr[middle] > arr[right]) {
      swap(arr[middle], arr[right]);
    }
    swap(arr[middle], arr[right - 1]);
    return arr[right - 1];
  }
};

int main() {
  vector<int> arr {
    62577, -220, -8737, -22, -6, 59956, 5363, -16699, 0, -10603, 64, -24528, -4818, 96, 5747, 2638,
        -223, 37663, -390, 35778, -4977, -3834, -56074, 7, -76, 601, -1712, -48874, 31, 3, -9417,
        -33152, 775, 9396, 60947, -1919, 683, -37092, -524, -8, 1458, 80, -8, 1, 7, -355, 9, 397,
        -30, -21019, -565, 8762, -4, 531, -211, -23702, 3, 3399, -67, 64542, 39546, 52500, -6263, 4,
        -16, -1, 861, 5134, 8, 63701, 40202, 43349, -4283, -3, -22721, -6, 42754, -726, 118, 51,
        539, 790, -9972, 41752, 0, 31, -23957, -714, -446, 4, -61087, 84, -140, 6, 53, -48496, 9,
        -15357, 402, 5541, 4, 53936, 6, 3, 37591, 7, 30, -7197, -26607, 202, 140, -4, -7410, 2031,
        -715, 4, -60981, 365, -23620, -41, 4, -2482, -59, 5, -911, 52, 50068, 38, 61, 664, 0, -868,
        8681, -8, 8, 29, 412
  };
  int k = 131;
  Solution s;
  vector<int> ret = s.smallestK(arr, k);
  for (auto it : ret) {
    cout << it << ' ';
  }
  return 0;
}