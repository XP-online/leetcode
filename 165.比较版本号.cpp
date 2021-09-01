/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
  int compareVersion(string version1, string version2) {
    //结尾加点统一算法
    version1 += '.';
    version2 += '.';
    //用来储存每次遇到'.'之前的字符串
    string str1,str2;
    int num1=0,num2=0;
    //双指针遍历
    auto it1 = version1.begin();
    auto it2 = version2.begin();
    while (it1 != version1.end()|| it2 != version2.end())
    {
      str1.clear();
      str2.clear();
      while (it1 != version1.end())
      {
        if(*it1 == '.'){
          it1++;
          break;
        }else{
          str1 += *it1;
        }
        it1++;
      }
      while (it2 != version2.end())
      {
        if(*it2 == '.'){
          it2++;
          break;
        }else{
          str2 += *it2;
        }
        it2++;
      }
      //获取本次的版本号比较
      num1 = atoi(str1.c_str());
      num2 = atoi(str2.c_str());
      if(num1 > num2){
        return 1;
      }
      if(num1 < num2){
        return -1;
      }
    }
    return 0;
  }
};
// @lc code=end
int main() { return 0; }
