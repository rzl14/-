# 栈
## 后进先出
    
   ## 用数组模拟，要记录栈顶
    
   ## 常用操作：向栈顶插入一个数，从栈顶弹出，判断栈顶是否为空
    
   ## int stk[N], tt = -1;
    
   ## 插入一个数：stk[++ tt] = x;
   ## 弹出：tt --;
    
   ## 判断栈是否为空：
   ###  if (tt > 0) ;// not empty;
   ###  else ;// empty;
   ## 栈顶：stk[tt];
   ## 题目：acwing 3302. 表达式求值：给定一个表达式，其中运算符仅包含 +,-,*,/（加 减 乘 整除），可能包含括号，请你求出表达式的最终值。
   ###  核心思想：利用栈转化为后缀表达式，之后再次利用栈计算出结果（逆波兰算法）
   ###  转化为后缀表达式：
            1.所有的数字直接输出
            2.运算符优先级高于栈内的要入栈（或栈空）。否则，从堆栈中弹出所有优先级更高或一样的运算符（或直到括号），再将当前的入栈
            3.所有左括号都要入栈
            4.若是右括号，则不断出栈，直到碰到左括号

   ###  计算后缀表达式：
            1.从左到右扫描表达式，如果当前字符为数字，则入栈
            2.如果当前字符为运算符，则将栈顶两个元素出栈，作相应运算，结果再入栈
            3.最后当表达式扫描完后，栈里的就是计算结果了

   ###   计算1+2*(3+4)-5


# 普通队列

   ## 先进先出
   ## 用数组模拟，要记录队头和队尾
    
   ## 常用操作：向队尾插入一个数，从队头弹出，判断队列是否为空
    
   ## int q[N], hh, tt = -1;
    
   ## 插入：q[++ tt] = x;
   ## 弹出：hh ++;
    
   ## 判断是否为空
     if (hh <= tt);// not empty;
     else ;// empty;

   ## 队头：stk[hh];
   ## 队尾：stk[tt];

# 单调栈

   ## 常见模型：找出每个数左边离它最近的比它大/小的数
    
   ## 单调递增栈：在保持栈内元素单调递增的前提下（如果栈顶元素大于要入栈的元素，将将其弹出），此时栈顶元素就是数组中左侧第一个比自己小的元素，将新元素入栈
    
   ## 单调递减栈：在保持栈内元素单调递减的前提下（如果栈顶元素小于要入栈的元素，则将其弹出），此时栈顶元素就是数组中左侧第一个比自己大的元素，将新元素入栈
