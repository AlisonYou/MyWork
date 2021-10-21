# 第一题
# x=[]
# 列表里添加元素
# for i in range(1,6,2):
#     x.append(i)
#     x.append(i)
# 方法1      若列表y中没有elem，则加入
# for elem in x:
#     if elem not in y:
#         y.append(elem)
# print(y)
# 方法2      列表转换成集合，自动剔除相同元素，再转回列表
# x=list(set(x))
# print(x)
# 总结:1.集合里无重复元素
# 2.列表元素可以重合
# 3. elem in x 相当于增强for

# 第二题
# s = [9, 7, 8, 3, 2, 1, 5, 6]
# 循环从 0-s.len-1
# for i  in range(0,s.__len__()):
# 如果能被2整除则为偶数
#     if s[i]%2==0:
#         s[i]=s[i]**2
# print(s)
# 总结:1.  i**2 = i的平方
# 2.对象.__len__()可以获得对象长度


# 第三题
# s=input("请输入一个字符串:")
# x=[]
# for i in range(0,s.__len__()):
# ord( char )可以将字符转换成unicode 数字
#     x.append(ord(s[i]))
# print(x)
# 总结:1.ord( char )可以将字符转换成unicode 数字



# 第四题
#   和
# sum=0
#   个数
# i=0
#  平均数
# avg=0.0
# x=int(input("请输入:"))
# while x!=-1:
#     i+=1
#     sum+=x
#     x = int(input("请输入:"))
#如果除数/个数为0
# if i==0:
# 指定平均数为0，否则会报算法异常
#     avg=0
# else: avg=sum/i
# print("数据个数: %d  ,  总和: %d  ,   平均值:  %.3f"%(i,sum,avg))
# 总结:1.int()可以将字符转化成int
# 2.print(" " %（）)形式可以指定格式



# # 第五题

# import sys
# # 打开io输出流
# f=open("out.txt","w")
# # 如果py文件作为主程序运行
# if __name__=='__main__':
#     # 获取命令行参数，argv[0]为文件名
#
#     n = int(sys.argv[1])
#
# try:
#      # 写入 0~n
#     for i in range(0,n+1):
#         f.write(str(i)+" ")
#     f.write("\n")
#      # 写入 0~n的2倍
#     for i in range(0,n+1):
#         f.write(str(2*i)+" ")
#     f.write("\n")
#      # 写入2的 0~n次幂
#     for i in range(0, n + 1):
#         f.write(str(2 ** i) + " ")
# except ArithmeticError as e:
#     print(e)
# else:
#     print("----------结束-----------")
#    # 最终关闭流
# finally:
#     f.close()
# 总结:1.if __name__=='__main__':    可以判断该程序是作为模块运行，还是主程序
# 2.可以通过sys.argv获得命令行参数——字符串数组
# 3.file.write()可以将字符串内容写入指定文件



# 第六题
#  打开文件
# f=open("work2.txt","w",)
# try:
#     while 1:
#         s=input("请输入:")
#         if s=="Q":
#             break
#         f.write(s+'\n')
#
# except IOError as e:
#     print(e)
# else:
#     print("---------结束----------")
# finally:
#  关闭流
#     f.close()
# 总结:1. try except else finally 异常处理
# 2.最后必须关闭流



# 第七题
# a=1;b=0
# 断言程序开关
# if input("是否启动断言程序( y/n ):  ")=='y':
#  断言除数不为0
#     assert b!=0,"错误:除数不能为0"
# c=a/b
#总结:1.断言    assert 表达式,描述语句
