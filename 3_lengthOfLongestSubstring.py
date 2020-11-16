# -*- coding: utf-8 -*-
"""
Created on Fri Feb 28 17:33:45 2020

@author: P_Wan
"""
##提前复习知识点部分
#list_position_name= ['网络工程师', '网络工程师', '网络工程师', 
#                     '网络工程师', '网络工程师', '网络工程师',
#                     '网络工程师', '网络工程师', '网络工程师',
#                     '网络工程师', '会计', '房产经纪', '美发师',
#                     '质量管理员', '房产销售', '跟单员', '客户经理',
#                     '销售经理', '后期制作', '经纪人', '导购',
#                     '房产经纪', '财务审计', '测试开发工程师',
#                     '软件测试工程师', '初中级功能测试工程师',
#                     'BMS软件测试工程师', '软件测试工程师 SW Tester',
#                     '软件测试员', '测试部经理', '软件测试经理/主管',
#                     '中级测试工程师', '884-软件测试工程师', '测试工程师',
#                     '软硬件测试工程师', '测试工程师', '软件测试工程师',
#                     '高级测试经理', '软件测试工程师', '软件测试经理/主管',
#                     '软件测试工程师', '软件测试', '软件测试（常州）']
## 查找相同职位名称位置
#list_price_positoin_address = []
#for i in list_position_name:
#    address_index = [x for x in range(len(list_position_name)) if list_position_name[x] == i]
#    list_price_positoin_address.append([i, address_index])
#dict_address = dict(list_price_positoin_address)
#print(dict_address)

#自行解题部分
inpt = 'pwwkew'

#分析长度，剔除异常--by wzy
#实验了半天：不可行，作为警示放在这里：无法应对无重复情形，且长含短没解决
#class Solution1(object):
#    def lengthOfLongestSubstring(self, s):
##        ads_idx = []
#        length = 0
#        for i in set(s):
#            tmp = [j for j in range(len(s)) if s[j] == i]
#            Dtmp = [tmp[j+1]-tmp[j] for j in range(len(tmp)-1)] if len(tmp)>1 else [0,0]
#            
#            length = max(length,max(Dtmp))
##            ads_idx.append(tmp)
#        
#        
#        return length
#
#a=Solution1()
#res = a.lengthOfLongestSubstring(inpt)
#print(res)


##滑动窗口解法--by 娃哈哈店长
##滑动窗口是一种很妙的解法，它让窗口一直维持在不重复内部数值的
##状态，一滑到底，妙哉妙哉
#class Solution2(object):
#    def lengthOfLongestSubstring(self, s):
#            length,j = 0,-1
#            for i,x in enumerate(s):#
#                print(i,x)
#                if x in s[j+1:i]:
#                    length = max(length,i-j-1)
#                    j = s[j+1:i].index(x)+j+1
#            return max(length,len(s)-1-j)
#
#a=Solution2()
#res = a.lengthOfLongestSubstring(inpt)
#print(res)
            
#自行编写滑动窗口解法(到头来还是和他一样，只是s[i]代替enumerate)
class Solution3:
    def lengthOfLongestSubstring(self, s):
        length, j= 0, 0
        for i in range(len(s)):
            print(s[j:i])
            if s[i] in s[j:i]:
                length = max(length,i-j)
                j += s[j:i].index(s[i])+1
        return max(length,len(s)-j)
    
inpt = "aab"
a=Solution3()
res = a.lengthOfLongestSubstring(inpt)
print(res)
            
            
            
            
            
            
            
            
            