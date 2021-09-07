#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void quicksort(vector<int>& arr) {
    if (arr.size() <= 1) return;

    qsort(arr, 0, arr.size() - 1);
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

int main() {
  Solution s;
  vector<int> arr{4,2,3,1,5,5,6};
  s.quicksort(arr);
  for(auto it: arr){
    cout << it << ' ';
  }
  return 0;
}