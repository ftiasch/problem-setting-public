#include <cassert>
#include <cstdio>
#include <vector>

const int MOD = 1e9 + 7;

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

template<typename T>
std::vector<std::vector<T> > rotate(const std::vector<std::vector<T> >& a)
{
    int n = a.size();
    int m = a.at(0).size();
    std::vector<std::vector<T> > result(m, std::vector<T>(n));
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            result.at(m - 1 - j).at(i) = a.at(i).at(j);
        }
    }
    return result;
}

bool is_valid(char c)
{
    return c == '0';
}

std::vector<std::vector<int> > process(const std::vector<std::vector<char> >& board)
{
    int n = board.size();
    int m = board.at(0).size();
    std::vector<std::vector<int> > result(n, std::vector<int>(m));
    std::vector<int> up(m + 1);
    up.at(0) = -1;
    for (int i = 0; i < n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            up.at(j) ++;
            if (!is_valid(board.at(i).at(j - 1))) {
                up.at(j) = 0;
            }
        }
        std::vector<int> stack;
        stack.push_back(0);
        int sum = 0;
        for (int j = 1; j <= m; ++ j) {
            while (up.at(stack.back()) >= up.at(j)) {
                update(sum, MOD - (long long)(stack.back() - stack.at(static_cast<int>(stack.size()) - 2)) * up.at(stack.back()) % MOD);
                stack.pop_back();
            }
            update(sum, (long long)(j - stack.back()) * up.at(j) % MOD);
            stack.push_back(j);
            result.at(i).at(j - 1) = sum;
        }
    }
    return result;
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<std::vector<char> > board(n, std::vector<char>(m));
        for (int i = 0; i < n; ++ i) {
            std::vector<char> buffer(m + 1);
            scanf("%s", buffer.data());
            buffer.resize(m);
            board[i] = buffer;
        }
        int result = 0;
        for (int _ = 0; _ < 2; ++ _) {
            std::vector<std::vector<int> > count[2];
            for (int i = 0; i < 2; ++ i) {
                count[i] = process(board);
                board = rotate(rotate(board));
            }
            std::vector<std::vector<int> > sum(n, std::vector<int>(m));
            for (int i = 0; i < n; ++ i) {
                for (int j = 0; j < m; ++ j) {
                    int& ref = sum.at(i).at(j);
                    ref = count[0].at(i).at(j);
                    if (i) {
                        update(ref, sum.at(i - 1).at(j));
                    }
                    if (j) {
                        update(ref, sum.at(i).at(j - 1));
                    }
                    if (i && j) {
                        update(ref, MOD - sum.at(i - 1).at(j - 1));
                    }
                }
            }
            for (int i = 0; i < n - 1; ++ i) {
                for (int j = 0; j < m; ++ j) {
                    update(result, (long long)sum.at(i).at(m - 1) * count[1].at(n - 2 - i).at(m - 1 - j) % MOD);
                    if (j < m - 1) {
                        update(result, MOD - (long long)sum.at(i).at(j) * count[1].at(n - 2 - i).at(m - 2 - j) % MOD);
                    }
                }
            }
            board = rotate(board);
            std::swap(n, m);
        }
        printf("%d\n", result);
    }
}
