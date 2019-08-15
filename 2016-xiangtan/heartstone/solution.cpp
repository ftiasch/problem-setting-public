#include <cstdio>
#include <queue>
#include <utility>
#include <vector>

const int MOD = (int)1e9 + 7;

void update(int &x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int cost3(int n)
{
    return n % 3 == 0 ? 0 : 1;
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<int> a(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a.at(i));
        }
        int current = 0;
        for (int i = 0; i < n; ++ i) {
            current += (a.at(i) + 2) / 3;
        }
        int result = current % MOD;
        int start = 0;
        std::priority_queue<std::pair<int, int>> queue;
        for (int i = 0; i < n; ++ i) {
            if (a.at(i) > 0) {
                queue.emplace(cost3(a.at(i)), a.at(i));
            }
        }
        while (start < m && !queue.empty()) {
            current -= queue.top().first;
            update(result, current);
            start ++;
            int a = queue.top().second - 2;
            queue.pop();
            if (a > 0) {
                queue.emplace(cost3(a), a);
            }
        }
        update(result, (long long)(m - start) * current % MOD);
        printf("%d\n", result);
    }
}
