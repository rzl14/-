#include <iostream>

using namespace std;

const int N = 100010;

int stk[N], l[N], tt = -1, idx = 0, ttt = -1;
char c[N];
bool op[N], op2[N];

bool cmpop(int A, int B)
{
    int a = A, b = B;
    if (a == '*' || a == '/') a = 1;
    else a = 0;
    if (b == '*' || b == '/') b = 1;
    else b = 0;
    return (a - b) >= 0;
}

int main()
{
    cin >> c;
    for (int i = 0; c[i]; i ++){
        if (c[i] >= '0') {
            l[idx] = l[idx] * 10 + c[i] - '0';
            if (c[i + 1] < '0' || c[i + 1] == 0) idx ++;
        }
        else {
            l[idx] = c[i];
            op[idx] = true;
            idx ++;
        }
    }

    for (int i = 0; i < idx; i ++) {
        if (!op[i]) l[++ ttt] = l[i];
        else {
            if(tt < 0)
                stk[++ tt] = l[i];
            else if(l[i] == '(')
                stk[++ tt] = '(';
            else if(l[i] == ')'){
                while (stk[tt] != '(') l[++ ttt] = stk[tt --], op2[ttt] = true;
                tt --;
            }
            else if(stk[tt] == '(')
                stk[++ tt] = l[i];
            else {
                while (cmpop(stk[tt], l[i]) && tt >= 0 && stk[tt] !='(')
                    l[++ ttt] = stk[tt --], op2[ttt] = true;
                stk[++ tt] = l[i];
            }
        }
    }
    while (tt >= 0) l[++ ttt] = stk[tt --], op2[ttt] = true;
    //  for(int i = 0; i <= ttt; i ++) cout << l[i] << ' ';
    //  cout << endl ;

    tt = -1;
    for (int i = 0; i <= ttt; i ++) {
        if(!op2[i])stk[++ tt] = l[i];
        else {
            if (l[i] == '+') tt -= 1, stk[tt] += stk[tt + 1];
            else if (l[i] == '-') tt -= 1, stk[tt] -= stk[tt + 1];
            else if (l[i] == '*') tt -= 1, stk[tt] *= stk[tt + 1];
            else tt -= 1, stk[tt] /= stk[tt + 1];
        }
        //  for(int k = 0; k <= tt; k ++) cout << stk[k] << ' ';
        //  cout << endl;
    }
    cout << stk[tt];
}