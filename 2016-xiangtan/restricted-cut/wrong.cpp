#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#include <limits>
#include <queue>
#include <vector>
#include <algorithm>

template<typename Type>
class Network
{
public:
    Network(int n) : n(n), head(n, -1)
    {
    }

    void add_edge(int u, int v, Type w)
    {
        add_edge_(u, v, w);
        add_edge_(v, u, 0);
    }

    Type max_flow(int source, int target)
    {
        Type result = 0;
        while (true) {
            std::vector<int> level(n, -1);
            level.at(target) = 0;
            std::queue<int> queue;
            queue.push(target);
            while (!queue.empty() && !~level.at(source)) {
                int v = queue.front();
                queue.pop();
                for (int iterator = head.at(v); ~iterator; ) {
                    auto&& edge = edges.at(iterator);
                    int u = edges.at(iterator).to;
                    if (edges.at(iterator ^ 1).capacity > 0 && !~level.at(u)) {
                        level.at(u) = level.at(v) + 1;
                        queue.push(u);
                    }
                    iterator = edge.next;
                }
            }
            if (!~level.at(source)) {
                break;
            }
            std::vector<int> current_head(head);
            result += dfs(level, current_head, source, target, std::numeric_limits<Type>::max());
        }
        return result;
    }

private:
    struct Edge
    {
        Edge(int to, Type capacity, int next) : to(to), capacity(capacity), next(next) {}

        int to;
        Type capacity;
        int next;
    };

    void add_edge_(int u, int v, Type w)
    {
        edges.emplace_back(v, w, head.at(u));
        head.at(u) = static_cast<int>(edges.size()) - 1;
    }

    Type dfs(const std::vector<int>& level, std::vector<int>& head, int u, int target, Type delta)
    {
        if (u == target) {
            return delta;
        }
        Type left = delta;
        for (int& iterator = head.at(u); ~iterator; ) {
            auto& edge = edges.at(iterator);
            int v = edge.to;
            if (edge.capacity > 0 && level.at(u) == level.at(v) + 1) {
                auto ret = dfs(level, head, v, target, std::min(left, edge.capacity));
                edge.capacity -= ret;
                edges.at(iterator ^ 1).capacity += ret;
                left -= ret;
                if (!left) {
                    return delta;
                }
            }
            iterator = edge.next;
        }
        return delta - left;
    }

    int n;
    std::vector<int> head;
    std::vector<Edge> edges;
};

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<int> a(m), b(m), c(m);
        int inf = 1;
        for (int i = 0; i < m; ++ i) {
            scanf("%d%d%d", &a.at(i), &b.at(i), &c.at(i));
            a.at(i) --;
            b.at(i) --;
            inf += c.at(i);
        }
        Network<int> network(n);
        for (int i = 0; i < m; ++ i) {
            network.add_edge(a.at(i), b.at(i), c.at(i));
        }
        printf("%d\n", network.max_flow(0, n - 1));
    }
}
