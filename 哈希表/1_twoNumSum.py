# -*- coding: utf-8 -*-
"""
Created on Wed Sep 25 23:34:09 2019

@author: P_Wan
"""

class Solution():
    
    
    #----------有前提条件的解法-----------  
    def twoSum(self, nums, target):
        
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        sorted_id = sorted(range(len(nums)), key=lambda k: nums[k])
        head = 0
        tail = len(nums) - 1
        sum_result = nums[sorted_id[head]] + nums[sorted_id[tail]]
        while sum_result != target:
            if sum_result > target:
                tail -= 1
            elif sum_result < target:
                head += 1
            sum_result = nums[sorted_id[head]] + nums[sorted_id[tail]]
        return [sorted_id[head], sorted_id[tail]]
    
    
     #----------暴力解法-----------     
    def twoSum2(self, nums, target):
           
        
        for i in range(len(nums)-1):
            for j in range(i+1,len(nums)):
                if nums[i] == target - nums[j]:
                    return [i,j]
                    break
    
     #----------一层for------------------     
    def twoSum3(self, nums, target):
        lens = len(nums)
        j=-1
        for i in range(lens):
            if (target - nums[i]) in nums:
                #如果要我来实现他的想法，估计会重新定义一个和nums一样的数组
                #然后每轮去除这个数组里当前的num1，再进行if比较(见3_1)
                if (nums.count(target - nums[i]) == 1)\
                    &(target - nums[i] == nums[i]):
                    #如果num2=num1,且nums中只出现了一次，说明找到是num1本身。
                    continue
                else:
                    j = nums.index(target - nums[i],i+1) 
                    #index(x,i+1)是从num1后的序列后找num2    
                    #难道从后面找是省时间吗？
                    #懂了，不是为了省时间，而是怕找到重复的
                    break
        if j>0:
            return [i,j]
        else:
            return []
        
    #----------一层for+我自己的一处想法-----------        
    def twoSum3_1(self, nums, target):
        lens = len(nums)
        j=-1
        for i in range(lens):
            nums2 = nums.copy()
            nums2.remove(nums[i])
            if (target - nums[i]) in nums2:
                #这里不能把上一行带进来，与Matlab有一些不同
                j = nums2.index(target - nums[i]) + 1                
                break
        if j>0:
            return [i,j]
        else:
            return []
        
   #----------一层for优化-----------     
    def twoSum4(self, nums, target):
        lens = len(nums)
        j = -1
        for i in range(1,lens):
            temp = nums[:i]
            if (target - nums[i]) in temp:
                j = temp.index(target - nums[i])
                break
        if j>=0:
            return [j,i]
        
        
        


    
a = Solution()

