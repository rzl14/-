#include <iostream>

using namespace std;

const int M = 100010;

int q[M], hh, tt = -1;

int main()
{
    int m;
    cin >> m;

    while (m --) {
        string s;
        cin >> s;
        if (s == "push") {
            int x;
            cin >> x;
            q[++ tt] = x;
        }
        else if (s == "pop") hh ++;
        else if (s == "empty") {
            if (hh <= tt) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        else cout << q[hh] << endl;
    }
}