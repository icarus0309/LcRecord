# -*- coding: utf-8 -*-
"""
Created on Tue Mar  3 19:26:17 2020

Leetcode第五题：寻找最长回文子串

每个除了我自己外的函数名后面写的是作者的LeetCode账户名（没标的说明我一时还没找到...找到了就补上）

A:  运行时间：6.599094867706299s
    我自己想的，从第一个开始遍历，取它后面所有元素中与它相同的元素，逐一向内进行比较，
    时间复杂度极端情况到o(n^3)，比如本例，毕竟三个循环嵌套，最快可以到o(n^2)
    在LeetCode上超出时间限制，提交失败—_—|||
    
B： 运行时间：0.05983924865722656s
    中心扩散法。很巧妙的方法，用大i来控制j的两种情况变化，即中心单元素或中心双元素。
    单元素情况比较简单，直接给定大i的一个二分情况就好了；双元素得另外考虑：另一个元素是否越界、
    双元素是否对等。后面的结果提取则更是简洁巧妙，利用了由中向外的特性省去了A中的繁琐步骤。
    时间复杂度不会超过o(n^2)，不至于线性。
    
    
C： 运行时间：0.11569523811340332s
    这个方法和方法B一样的道理，但是他没有意识到两种情况可以合并，所以每次迭代多判断一次分支，
    因而总体运行效率略低于B。
    
D： 动态规划。我刚才开始看数据结构的网课，所以动态规划...就是迭代+递归的意思？
    巧妙地借助“表格”存储了较短回文串的存在与否信息，一层层往前推进，时间复杂度实打实的o(n^2)，
    所以总打不过B、C。
    
E： 刚说完动态规划不如中心扩展就被打脸了。来来来我们来看看这个DP有啥特殊：
    我去！我举报它作弊！它利用了python数组可以倒序的特殊特性，python是用c写的所以这
    大概调用了c的底层？这样的话算法复杂分析没啥意义，用c打python就是降维打击。

F: manacher-马拉车算法：首先添加符号使得总长度为奇数（奇数+偶数+2=奇数）
    原理就是给每个字符中间塞个同样的东西进去，这样就可以每个字符都能独自当中心了，省去了B、C
    的if判断。用一个数组P存储当前对应位置的最长单边边界长度，其实就是原字符串的回文长度。
    #4#3#2#1#2#3#5#-->用1作中心判断时，往左边数，必然在4前的#停止，返回给1位置的P值就是
    该#与1的位置距离，中间只有2、3和与他们各自抱团的#,即2、3这种元素的两倍再加个1位置就是
    我们要找的P，刚好2、3在右边都有，调过来替代#，所以去掉所有#可以看出当前P值就是当前回文长度。
    用#作中心时同理，只是长度必然为偶数，上面的情况长度必然为奇数。


@author: ~
"""

class Solution:
        
    def longestPalindromeA(self,s):
        res = []
        for i in range(len(s)):
            idx = len(s)-1-s[-1:i:-1].index(s[i]) if s[i] in s[-1:i:-1] else 0
            while idx:
                j,k = i,idx
                while k>j:
                    j += 1
                    k -= 1
                    if not s[j]==s[k]:
                        idx = idx-1-s[idx-1:i:-1].index(s[i]) if s[i] in s[idx-1:i:-1] else 0
                        break
                if s[k]==s[j]:
                    res += [ s[i:idx+1] ]
                idx = 0 if -1<=k-j<=0 else idx
        if res:
            ilength = [len(i) for i in res]
            return res[ilength.index(max(ilength))]        
        return s[0] if s else ""
        
    def longestPalindromeB(self, s):
        a = ''
        for i in range(2 * len(s) - 1):
            j = i // 2
            if i % 2 == 1 and j+1 <= len(s)-1 and s[j] == s[j+1]:
                l, r = j, j + 1
            if i % 2 == 0:
                l, r = j, j
            while l >= 0 and r <= len(s)-1 and s[l] == s[r]:
                    l -= 1
                    r += 1
            if len(s[l+1:r]) > len(a):
                a = s[l+1:r]
        return a
    
    
    def longestPalindromeC(self, s):
        length = len(s)
        if length == 0:
            return ''
        maxl = s[0]
        for i in range(1,length):
            cur = 1
            while i - cur >=0 and i + cur<length:
                if s[i-cur] == s[i+cur]:
                    if len(maxl) < 2*cur + 1:
                        maxl = s[i-cur:i+cur+1]
                    cur += 1
                else:
                    break
            cur = 1
            while i - cur>=0 and i+cur-1<length:
                if s[i+cur-1] == s[i-cur]:
                    if 2*cur > len(maxl):
                        maxl = s[i-cur:i+cur]
                    cur += 1
                else:
                    break
        return maxl
    
    def longestPalindromeD(self, s):#liweiwei1419
        size = len(s)
        if size < 2:
            return s
    
        dp = [[False for _ in range(size)] for _ in range(size)]
        #生成一个表：（以ababb为例）
        #--------------------------
        #   0 | 1 | 2 | 3 | 4
        #0  0   0   0   0   0
        #1  0   0   0   0   0
        #2  0   0   0   0   0
        #3  0   0   0   0   0
        #4  0   0   0   0   0
        #--------------------------
        max_len = 1
        start = 0
    
        for i in range(size):
            dp[i][i] = True     #给对角线赋值为1
        for j in range(1, size):
            for i in range(0, j):
                if s[i] == s[j]:
                    if j - i < 3:
                        dp[i][j] = True
                    else:
                        dp[i][j] = dp[i + 1][j - 1]
                else:
                    dp[i][j] = False
    
                if dp[i][j]:
                    cur_len = j - i + 1
                    if cur_len > max_len:
                        max_len = cur_len
                        start = i
        return s[start:start + max_len]
    
    def longestPalindromeE(self,s):#ekko-8
        str_length = len(s)
        max_length = 0
        start = 0
        for i in range(str_length):
            #这里的处理非常巧，非常厉害，我也是想了很久才明白
            #作者的思路十分具有侵略性：让节点呈线性迭代下去，反正所有的回文子串均有尾巴，
            #所以每次都从尾巴开始选，那么，只有大于当前的最长距离的子串才是有资格进行筛选的
            #（这是为什么i+2的原因）以及数组切片时下表超出是没关系的（取值不行）
            #再加上python自带列表倒序功能，这个方法是毋庸置疑的线性
            #第二个if是考虑到回文子串的两种对称方式，可以注意到只有第一种的话奇偶性是不变的
            #总之这不是我能想到的办法
            if i - max_length >= 1 and s[i - max_length - 1:i + 2] ==\
                                        s[i - max_length - 1:i + 2][::-1]:
                start = i - max_length - 1
                max_length += 2
                continue
            if i - max_length >= 0 and s[i - max_length:i + 2] ==\
                                        s[i - max_length:i + 2][::-1]:
                start = i - max_length
                max_length += 1
        return s[start:start + max_length+1]

    def longestPalindromeF(self, s):#clay001
        if len(s)== 0:return ""
        s_new  = '#' + '#'.join(s) + '#'
        mx = 0
        mid = 0
        l = len(s_new)
        p = [1]*l        
        for i in range(l):
            if i<mx:
                p[i] = min(mx-i,p[2*mid-i])
            while( i-p[i]>=0 and i+p[i]<l and s_new[i-p[i]] == s_new[i+p[i]]):
                p[i] += 1
            if i+p[i] > mx:
                mx = i+p[i]
                mid = i
        maxr = max(p)
        ans = p.index(maxr)
        maxr -= 1
        return s_new[ans-maxr:ans+maxr+1].replace('#',"")
                    



import time
a=Solution()
s="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
#s='abaaabaaaaaaabbbabbbbbbdjqwoijdojqwfqwqiwoioqwhfqw'
st = time.time()
b = a.longestPalindromeA(s)
end = time.time()
print( '我自己的方法：\t',end - st )

c = a.longestPalindromeB(s)
end2 = time.time()
print( '中心扩展法一：\t',end2 - end )

d = a.longestPalindromeC(s)
end3 = time.time()
print( '中心扩展法二：\t',end3 - end2 )

e = a.longestPalindromeD(s)
end4 = time.time()
print( '动态规划法一：\t',end4 - end3 )

f = a.longestPalindromeE(s)
end5 = time.time()
print( '动态规划法二：\t',end5 - end4 )

g = a.longestPalindromeF(s)
end6 = time.time()
print( '马拉车算法一：\t',end6 - end5 )





















