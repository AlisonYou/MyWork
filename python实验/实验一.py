import datetime
import random
# 第一题
name=input('请输入您的姓名:')
birthday=input('请输入您的出生年份:')
# #获得当前年份
year=datetime.date.today().year

# # 输出结果
print('您好！',name,'。您',year-int(birthday),'岁')
# 总结: 1.datetime.date.today().year方法可以获得当前时间 ——年
# 2.print()中使用 ’,‘ 逗号间隔可以拼接字符串


# 第二题
#
# 获得两个随机数
a = random.randint(0, 100)
b = random.randint(0, 100)
# 比较出较大值和较小值
x = max(a, b)
y = min(a, b)
#求余
r = x % y

while r != 0:

    x = y
    y = r
    r = x % y

print(a, "和", b, "的最大公约数为", y," ,   最小倍数为：",a*b/y)
#总结:1.辗转相除求得两数   当被除数能被除数整除时：最大公约数=除数    最小倍数=两正数之和/最大公约数
#2.随时整数可以使用 random.ranint(开始，结束),开始、结束都包括在随机数之内

# 第三题
for i in range(1,1001):
    if i%3==2 and i%5==3 and i%7==2:
        print(i,end=' ')
#总结:1.且（&&）可以使用  and表示
#2. %  代表求余
#3.print()函数中，end赋值可以修改输出语句末尾内容


# 第四题
#
# 创建英语元组
dictionary=('Meanwhile','coal ','mine','operation','after',
            'heavy','local','rain','river','project','spot',
            'suspend','yellow','people','province','district')
#游戏开始
print('欢迎参加猜单词游戏\n把字母组合成一个正确的单词')
#
#游戏开始默认选择’y‘(yes)
choose='y'
#
#仅当choose选择 ’n‘(no)时可以结束循环
while choose !='n':
#      随机选择一个单词
    temp_word=word=random.choice(dictionary)
#     初始化乱序后单词为空’‘
    after_word=''

#   随机选择单词索引范围内的一个数字，将单词从该位置裁剪成两片，后半截拼接在前半截上，一共进行五次相同拼接操作得到乱序单词
    for i in range(0,5):
        position=random.randint(1,len(word)-1)
        word=word[position:]+word[:position]

    after_word=word
    print('乱序后单词: ',after_word)

#提示游戏输入猜测答案，有三次机会猜猜测
    for i in range(1,4):
#第一次提示
        if i==1:
            answer=input('请你猜:')
        else:
#若猜测不正确，进行再一次猜测
            answer=input('继续猜:')

#验证猜测结果是否正确

        if answer==temp_word:
            print('真棒，你猜对了!')
            break;
#猜错，提示剩余猜测机会

        else:print('对不起不正确,您还有{}次机会'.format(3-i))
#询问是否继续游戏

    choose=input('是否继续？y/n')
    if choose=='n':break;

#总结:1.randon.choice()可以填入集合作为随机范围
#2.字符串切片可以使用  str[开始,结束],同时含头不含尾
#3.访问字符串内容可以使用 str[索引]形式