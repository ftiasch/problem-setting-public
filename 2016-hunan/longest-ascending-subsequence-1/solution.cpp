#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

#define ALL(v) (v).begin(), (v).end()

int find_first(const std::vector<int>& v, int a)
{
    return *std::lower_bound(v.begin(), v.end(), a);
}

int find_last(const std::vector<int>& v, int a)
{
    std::vector<int>::const_iterator iterator = std::upper_bound(v.begin(), v.end(), a);
    iterator --;
    return *iterator;
}

int match(int p, int x)
{
    if (~p) {
        return p == x;
    }
    return true;
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        std::vector<int> p(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &p.at(i));
            p.at(i) --;
        }
        std::vector<std::vector<int> > positions(5);
        for (int j = 0; j < 5; ++ j) {
            positions.at(j).push_back(-1);
        }
        for (int i = 0; i < n; ++ i) {
            if (~p.at(i)) {
                for (int j = 0; j < 5; ++ j) {
                    if (p.at(i) != i - 2 + j) {
                        positions.at(j).push_back(i);
                    }
                }
            }
        }
        for (int j = 0; j < 5; ++ j) {
            positions.at(j).push_back(n);
        }
        long long result = 0;
        for (int i = 0; i < n; ++ i) {
            int first = find_first(positions.at(2), 0);
            if (first >= i) {
                first = find_first(positions.at(1), i + 1) - 1;
            }
            int last = find_last(positions.at(2), n - 1) - 1;
            if (last <= i - 1) {
                last = find_last(positions.at(3), i - 1);
            }
//printf("%d %d %d\n", i, last, first);
            if (~p.at(i)) {
                result += p.at(i) != i && last < p.at(i) && p.at(i) <= first;
            } else if (last < first) {
                result += first - last;
                if (last < i && i <= first) {
                    result --;
                }
            }
//printf("=> %d\n", result);
        }
        for (int i = 1; i < n; ++ i) {
            int first = find_first(positions.at(2), 0);
            if (first >= i - 1) {
                first = find_first(positions.at(0), i + 1) - 2;
            }
            int last = find_last(positions.at(2), n - 1) - 2;
            if (last <= i - 2) {
                last = find_last(positions.at(4), i - 2);
            }
            int x = i - 1;
            if (match(p.at(i - 1), x + 1) && match(p.at(i), x) && last < x && x <= first) {
                result --;
            }
        }
        std::cout << result << std::endl;
    }
}
