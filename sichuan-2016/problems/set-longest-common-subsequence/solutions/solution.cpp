#include <algorithm>
#include <cstdio>
#include <list>
#include <vector>

int main()
{
    int n, m, l;
    scanf("%d%d%d", &n, &m, &l);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", &a[i]);
        a[i] --;
    }
    std::vector<int> dp(n + 1);
    while (m --) {
        std::list<int> queue;
        std::vector<int> count(l), new_dp(dp), tmp_count(l), timestamp(l, -1);
        {
            int k;
            scanf("%d", &k);
            while (k --) {
                int b;
                scanf("%d", &b);
                count.at(b - 1) ++;
            }
        }
        for (int i = 0; i < n; ++ i) {
            queue.push_front(i);
            int profit = 0;
            for (auto iterator = queue.begin(); iterator != queue.end(); ) {
                auto backup = iterator;
                iterator ++;
                int value = a[*backup];
                if (timestamp[value] != i) {
                    tmp_count[value] = 0;
                    timestamp[value] = i;
                }
                if (tmp_count[value] < count[value]) {
                    profit ++;
                    tmp_count[value] ++;
                    new_dp[i + 1] = std::max(new_dp[i + 1], dp[*backup] + profit);
                } else {
                    queue.erase(backup);
                }
            }
        }
        dp = new_dp;
    }
    printf("%d\n", *std::max_element(dp.begin(), dp.end()));
    return 0;
}
