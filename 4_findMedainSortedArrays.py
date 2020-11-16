# -*- coding: utf-8 -*-
"""
Created on Mon Mar  2 17:26:20 2020

@author: P_Wan
"""
#我自己设计的方法，虽然运行速度很快，但内存占用大
#这大概是由于sort函数导致的吧
class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        nums = nums1+nums2
        nums.sort()
        a = nums[int((len(nums)-1)/2)]
        b = nums[int(len(nums)/2)]
        return (a + b)/2

nums1 = [1]
nums2 = [3,4]
a = Solution()
b = a.findMedianSortedArrays(nums1,nums2)
print(b)