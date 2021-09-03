#include <vector>

using namespace std;

class Solution {
public:
  vector<int> smallestK(vector<int>& arr, int k) {}

  int slipIndex(vector<int>& arr, int first, int end) {
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
    swap(arr[middle], arr[end-1]);
    return arr[end-1];
  }
};

int main() { return 0; }