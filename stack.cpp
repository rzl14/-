// #include <iostream>

// using namespace std;

// const int N = 100010;

// int stk[N], tt = -1;

// int main()
// {
//     int x = 10;

//     // 插入一个数
//     stk[++ tt] = x;

//     // 弹出
//     tt --;

//     // 判断栈是否为空
//     if (tt > 0) ;// not empty;
//     else ;// empty;

//     // 栈顶
//     stk[tt];

//     // *************队列*************
//     int q[N], hh, tt = -1;
    
//     // 插入
//     q[++ tt] = x;
    
//     // 弹出
//     hh ++;

//     // 判断是否为空
//     if (hh <= tt);// not empty;
//     else ;// empty;
    
//     // 队头
//     stk[hh];
//     // 队尾
//     stk[tt];
// }

#include <iostream>

using namespace std;

const int N = 100010;

int stk[N], tt = -1;

int main()
{
    int M;
    cin >> M;
    while (M--) {
        string op;
        cin >> op;
        if (op == "push"){
            int x;
            cin >> x;
            stk[++ tt] = x;
        }
        else if (op == "pop") tt--;
        else if (op == "empty") {
            if (tt >= 0) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        else {
            cout << stk[tt] << endl;
        }
    }
}