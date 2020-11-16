# -*- coding: utf-8 -*-
"""
Created on Tue Feb 25 00:35:16 2020

@author: P_Wan
"""
# 理解错误，以为链表是列表
#def addTwoNumbers(l1, l2):
#    num1, num2 = 0, 0 
#    len1 = len(l1)
#    for i in range(len1):
#        num1 *= 10
#        num1 += l1[-1]
#        l1.pop(len1-i-1)
#    len2 = len(l2)
#    for i in range(len2):
#        num2 *= 10
#        num2 += l2[-1]
#        l2.pop(len2-i-1)
#    added = num1 + num2
#    print(added)
#    
#    addedList = []
#    while added>0:
#        tmp = added%10
#        addedList.append(tmp)
#        added //= 10
#    return addedList
#
#
#l1 =[1,2,3]
#l2 = [1,2,4,5,3,4,1,4]
#
#res = addTwoNumbers(l1, l2)
#
#print(res)



##创建链表
#
#class LNode(object):
#    #结点初始化函数, p 即模拟所存放的下一个结点的地址
#    #为了方便传参, 设置 p 的默认值为 0 
#    def __init__(self, data, p=0):
#        self.data = data
#        self.next = p
#
#class LinkList(object):
#    def __init__(self):
#        self.head = None
#
#    #链表初始化函数,方法类似于尾插
#    def initList(self, data):
#        #创建头结点
#        self.head = LNode(data[0])
#        p = self.head
#        #逐个为 data 内的数据创建结点, 建立链表
#        for i in data[1:]:
#            node = LNode(i)
#            p.next = node
#            p = p.next
#
#    #链表判空
#    def isEmpty(self):
#        if self.head.next == 0:
#            print("Empty List!")
#            return 1
#        else:
#            return 0
#
#    #取链表长度
#    def getLength(self):
#        if self.isEmpty():
#            exit(0)
#
#        p = self.head
#        len = 0
#        while p:
#            len += 1
#            p = p.next
#        return len
#
#    #遍历链表
#    def traveList(self):
#        if self.isEmpty():
#            exit(0)
#        print('\rlink list traving result: ')
#        p = self.head
#        while p:
#            print(p.data),
#            p = p.next
#
#    #链表插入数据函数
#    def insertElem(self, key, index):
#        if self.isEmpty():
#            exit(0)
#        if index<0 or index>self.getLength()-1:
#            print("\rKey Error! Program Exit.")
#            exit(0)
#
#        p = self.head
#        i = 0
#        while i<=index:
#            pre = p
#            p = p.next
#            i += 1
#
#        #遍历找到索引值为 index 的结点后, 在其后面插入结点
#        node = LNode(key)
#        pre.next = node
#        node.next = p
#
#    #链表删除数据函数
#    def deleteElem(self, index):
#        if self.isEmpty():
#            exit(0)
#        if index<0 or index>self.getLength()-1:
#            print("\rValue Error! Program Exit.")
#            exit(0)
#
#        i = 0
#        p = self.head
#        #遍历找到索引值为 index 的结点
#        while p.next:
#            pre = p
#            p = p.next
#            i += 1
#            if i==index:
#                pre.next = p.next
#                p = None
#                return 1
#
#        #p的下一个结点为空说明到了最后一个结点, 删除之即可
#        pre.next = None
#
##初始化链表与数据
#data = [1,2,3,4,5]
#l = LinkList()
#l.initList(data)            
#l.traveList()
#
##插入结点到索引值为3之后, 值为666
#l.insertElem(666, 3)
#l.traveList()
#
##删除索引值为4的结点
#l.deleteElem(4)
#l.traveList()


class ListNode(): #leetcode的官方类
    def __init__(self, val):
        if isinstance(val,int):
            self.val = val
            self.next = None
            
        elif isinstance(val,list):
            self.val = val[0]
            self.next = None
            cur = self
            for i in val[1:]:
                cur.next = ListNode(i)
                cur = cur.next
    
    def gatherAttrs(self):
#        tmp = [k for k in self.__dict__.keys()]
        return ", ".join("{}: {}".format(k, getattr(self, k)) for k in self.__dict__.keys())

    def __str__(self):
        return self.__class__.__name__+"{"+"{}".format(self.gatherAttrs())+"}"
        
#  ListNode {val: 7, next: ListNode {val: 0, next: ListNode {val: 5, next: ListNode {val: 1, next: None}}}}


class Solution(object):
	def addTwoNumbers(self, l1, l2):
		# 定义一个进位标志
		a,b,p,carry = l1,l2,None,0
		while a or b:
			# a和b节点的值相加，如果有进位还要加上进位的值
			val = (a.val if a else 0)+(b.val if b else 0)+carry
			# 根据val判断是否有进位,不管有没有进位，val都应该小于10
			carry,val = 1 if val>=10 else 0,val%10
			p,p.val = a if a else b, val
			# a和b指针都前进一位
			a,b = a.next if a else None,b.next if b else None
			# 根据a和b是否为空，p指针也前进一位
			p.next = a if a else b
		# 不要忘记最后的边界条件，如果循环结束carry>0说明有进位需要处理这个条件	
		if carry:
			p.next = ListNode(carry)
		# 每次迭代实际上都是将val赋给a指针的，所以最后返回的是l1
		return l1

l1 = ListNode([1,3,6,9])
l2 = ListNode([4,4,5])
a = Solution()
res = a.addTwoNumbers(l1,l2)
while res:
    print(res.val)
    res = res.next



class Solution2(object):
	def addTwoNumbers(self, l1, l2):
		# 主要逻辑都在内部函数中实现
		def add(a,b,carry):
			# 递归的终止条件是a和b都为空
			# 如果carry大于0需要返回一个进位标志
			if not (a or b):
				return ListNode(1) if carry else None
			# 如果a为空则将ListNode(0)赋给a，对于b也是
			a = a if a else ListNode(0)
			b = b if b else ListNode(0)
			#处理val，以及进位标志
			val = a.val + b.val + carry
			carry = 1 if val>=10 else 0
			a.val = val%10
			# 现在a的值就是两个节点相加后的和了
			# 之后再次递归计算a.next和b.next
			a.next = add(a.next,b.next,carry)
			return a
		return add(l1,l2,0)
    

    






#解释后面返回类的名字       
#class Foo(object):
#    def get_cls_name( self ):
#        return self.__class__.__name__
#
#
#class Bar(Foo):
#    def __init__( self ):
#        name = self.get_cls_name()
#        print(name)
#    pass
#
#
#b = Bar()






#
#class Human(object):
#    #特殊方法: __方法名__  方法名:不是随便起的,来自于对object中的特殊方法的重写
# 	def __init__(self,age,name):
# 		self.age = age
# 		self.name = name
# 	def __str__(self):#在print直接打印对象时调用
# 		return '我叫:%s,我%d岁'%(self.name,self.age)#返回的是一个字符串
# 	__repr__ = __str__#间接打印时会调用__repr__
#
# 	#运算符重载
# 	def __add__(self,other):#会在对象相加时直接调用
# 		return self.age+other.age
#
# 	#一般方法:
# 	def prtInfo(self):
# 		print(self.name,self.age)
#
#hm1 = Human(15,'小红')
#hm2 = Human(20,'小张')
## hm1.prtInfo()
#print(hm1)
#lt = []
#lt.append(hm1)
#print(lt)
#print(hm1+hm2)












