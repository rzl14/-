#include <iostream>

using namespace std;

const int N = 100010;

int stk[N], tt = -1, n;

int main()
{
    cin >> n;
    while (n --) {
        int x;
        cin >> x;
        if(tt < 0) {
            cout << -1 << ' ';
            stk[++ tt] = x;
            continue;
        }
        while(stk[tt] >= x && tt >= 0) tt --;
        if(tt < 0) cout << -1 << ' ';
        else cout << stk[tt] << ' ';
        stk[++ tt] = x;
        // cout << endl << "****************" << endl;
        // for(int i = 0; i <= tt; i ++) cout << stk[i] << endl;
    }
    cin >> n;
}