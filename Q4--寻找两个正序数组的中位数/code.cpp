#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int length = nums1.size()+nums2.size();
        double res = 0.0;
        int middle1,middle2;
        if (length%2 == 0)
        {
            middle1 = length/2;
            middle2 = length/2+1;
        }else{
            middle1 = (length/2)+1;
            middle2 = middle1;
        }
        vector<int> sum;
        while ((nums1.size() != 0) || (nums2.size()!=0))
        {
            if((nums1.size() != 0) && (nums2.size()!=0)){
                if (nums1.back() > nums2.back())
                {
                    sum.push_back(nums1.back());
                    nums1.pop_back();
                }else{
                    sum.push_back(nums2.back());
                    nums2.pop_back();
                }
            }else if(nums1.size() != 0){
                sum.push_back(nums1.back());
                nums1.pop_back();
            }else{
                sum.push_back(nums2.back());
                nums2.pop_back();
            }
            if(sum.size() >= middle2){
                break;
            }
        }
        res = (sum[middle1-1]+sum[middle2-1])/2.0;       
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> n1{1,2};
    vector<int> n2{3,4};
    double res = s.findMedianSortedArrays(n1,n2);
    
    cout << "res=" << res << endl;
    return 0;
}