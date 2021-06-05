#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> window;
        int left = 0, right = 0;
        int res=0;
        while(right < s.size()){
            //window.
            char c = s[right];

            window[c]++;
            while(window[c] > 1){
                char strleft = s[left];
                window[strleft]--;
                left++;
            }
            res = max(res, right-left+1);
            right++;
        }
        return res;
    }
};

int main()
{
    Solution s;
    int res = s.lengthOfLongestSubstring("pwwkew");
    cout << res << endl;
    return 0;
}