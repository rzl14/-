#include <iostream>

using namespace std;

const int N = 100010;

// head 表示头节点的下标
// e[i] 表示节点i的值
// ne[i] 表示节点i的next指针
// idx 相当于一个指针，表示当前已经用到了哪个点
int head, e[N], ne[N], idx;

// 初始化
void init()
{
    head = -1;
    idx = 0;
}

void add_to_head(int x)
{
    e[idx] = x, ne[idx] = head, head = idx ++;
}

void add(int k, int x)
{
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx ++;
}

void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    init();
    int M;
    cin >> M;
    while (M --) {
        char c;
        int x, k;
        cin >> c;
        if (c == 'H') cin >> x, add_to_head(x);
        if (c == 'D') {
            cin >> k;
            if (k) remove(k - 1);
            else  head = ne[head];
        }
        if (c == 'I') cin >> k >> x, add(k - 1, x);
    }
    for (int i = head; i != -1; i = ne[i]) printf("%d ", e[i]);
    system("pause");
    return 0;
}