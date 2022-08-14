#include <iostream>

using namespace std;

const int N = 100010;

int e[N], l[N], r[N], idx;

// 初始化
void init()
{
    // 0表示左端点，1表示右端点
    r[0] = 1, l[1] = 0;
    idx = 2;
}

// 下标是k的点的右边插入x：add(k,x);
// 在最左侧插入：add(0, x);
// 在最右侧插入：add(l[1], x);
// 在第k个插入的数的右侧插入：add(k + 1, x);
// 在第k个插入的数的左侧插入：add(l[k + 1], x);
void add(int k, int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx ++;
}

// 删除下标是k的点：remove(k);
// 删除第k个插入的数：remove(k + 1);
// 删除最左边的点：remove(r[0]);
// 删除最右边的点：remove(l[1]);
void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{
    init();
    int M;
    cin >> M;
    while (M--) {
        string s;
        int k, x;
        cin >> s;
        if (s == "L") cin >> x, add(0, x);
        else if (s == "R") cin >> x, add(l[1], x);
        else if (s == "D") cin >> k, remove(k + 1);
        else if (s == "IL") cin >> k >> x, add(l[k + 1], x);
        else if (s == "IR") cin >> k >> x, add(k + 1, x);
    }

    for(int i = r[0]; i != 1; i = r[i]) printf("%d ", e[i]);
}