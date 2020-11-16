# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

class Solution:
    def gcdOfStrings(self, str1, str2):
        for i in range(min(len(str1), len(str2)), 0, -1):
            if (len(str1) % i) == 0 and (len(str2) % i) == 0:
                if str1[: i] * (len(str1) // i) == str1 and str1[: i] * (len(str2) // i) == str2:
                    return str1[: i]
        return ''
    
    def gcdOfStringsB(self,str1,str2):
        if str2+str1!=str1+str2:
            return ''
        

#作者：LeetCode-Solution
#链接：https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/solution/zi-fu-chuan-de-zui-da-gong-yin-zi-by-leetcode-solu/
#来源：力扣（LeetCode）
#著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
        
a=Solution()
s1='ABABAB'
s2='ABAB'
print(a.gcdOfStrings(s1,s2))








def gcdOfStrings(str1,str2):
    for i in range(min(len(str1,str2),0,-1)):
        if (len(str1)%i)==0 and (len(str2)%i)==0:
            if str1[:i]*(len(str1)//i)==str1 and str1[:i]*(len(str2)//i)==str2:
                return str1[:i]
        return ''


















