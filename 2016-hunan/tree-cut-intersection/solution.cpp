#include <cstdio>
#include <vector>

std::vector<int> color, head, to, next, result, parent, delta, depth;
std::vector<std::vector<int> > stack;

int find(int u)
{
    if (parent.at(u) != u) {
        parent.at(u) = find(parent.at(u));
    }
    return parent.at(u);
}

void prepare(int p, int u)
{
    parent.at(u) = u;
    depth.at(u) = ~p ? depth.at(p) + 1 : 0;
    std::vector<int>& s = stack.at(color.at(u));
    if (!s.empty()) {
        int w = find(s.back());
        delta.at(u) ++;
        delta.at(w) --;
        if (depth.at(w) < depth.at(s.front())) {
            delta.at(s.front()) ++;
            delta.at(w) --;
        }
        while (!s.empty() && depth.at(s.back()) >= depth.at(w)) {
            s.pop_back();
        }
        s.push_back(w);
    }
    s.push_back(u);
    for (int iterator = head.at(u); ~iterator; iterator = next.at(iterator)) {
        int v = to.at(iterator);
        if (v != p) {
            prepare(u, v);
            parent.at(v) = u;
        }
    }
}

int dfs(int p, int u)
{
    int sum = delta.at(u);
    for (int iterator = head.at(u); ~iterator; iterator = next.at(iterator)) {
        int v = to.at(iterator);
        if (v != p) {
            sum += (result[iterator >> 1] = dfs(u, v));
        }
    }
    return sum;
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        color = std::vector<int>(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &color.at(i));
            color.at(i) --;
        }
        head = std::vector<int>(n, -1);
        to = std::vector<int>(n - 1 << 1);
        next = std::vector<int>(n - 1 << 1);
        for (int i = 0; i < n - 1 << 1; ++ i) {
            scanf("%d", &to.at(i));
            to.at(i) --;
        }
        for (int i = 0; i < n - 1 << 1; ++ i) {
            int& ref = head.at(to.at(i ^ 1));
            next.at(i) = ref;
            ref = i;
        }
        result = std::vector<int>(n - 1);
        parent = std::vector<int>(n);
        delta = std::vector<int>(n);
        depth = std::vector<int>(n);
        stack = std::vector<std::vector<int> >(n);
        prepare(-1, 0);
        dfs(-1, 0);
        for (int i = 0; i < n - 1; ++ i) {
            printf("%d\n", result.at(i));
        }
    }
}
