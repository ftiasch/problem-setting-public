#include <algorithm>
#include <cassert>
#include <cstdio>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define ALL(v) (v).begin(), (v).end()
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)

typedef std::vector<std::vector<std::pair<int, int> > > Graph;

const long long MAX_VALUE = 1e18;

struct Edge
{
    Edge(int a, int b, int c, int l) : a(a), b(b), c(c), l(l) {}

    int a, b, c, l;
};

void add_edge(Graph& graph, int a, int b, int c)
{
//printf("%d--%d [label=\"%d\"]\n", a, b, c);
    graph.at(a).push_back(std::make_pair(b, c));
    graph.at(b).push_back(std::make_pair(a, c));
}

int find_vertex(const Graph& ends, int a, int c)
{
    return std::lower_bound(ALL(ends.at(a)), std::make_pair(c, 0))->second;
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<Edge> edges;
        Graph ends(n);
        for (int i = 0; i < m; ++ i) {
            int a, b, c, l;
            scanf("%d%d%d%d", &a, &b, &c, &l);
            a --;
            b --;
            edges.push_back(Edge(a, b, c, l));
            ends.at(a).push_back(std::make_pair(c, 0));
            ends.at(b).push_back(std::make_pair(c, 0));
        }
        int v = 0;
        for (int i = 0; i < n; ++ i) {
            std::vector<std::pair<int, int> > &e = ends.at(i);
            std::sort(ALL(e));
            e.erase(std::unique(ALL(e)), e.end());
            foreach (iterator, e) {
                iterator->second = v ++;
            }
        }
        Graph graph(v);
        for (int i = 0; i < n; ++ i) {
            std::vector<std::pair<int, int> > &e = ends.at(i);
            for (int j = 1; j < static_cast<int>(e.size()); ++ j) {
                add_edge(graph, e.at(j - 1).second, e.at(j).second, e.at(j).first - e.at(j - 1).first);
            }
        }
        for (int i = 0; i < m; ++ i) {
            Edge& e = edges.at(i);
            int a = find_vertex(ends, e.a, e.c);
            int b = find_vertex(ends, e.b, e.c);
            add_edge(graph, a, b, e.l);
        }
        std::vector<long long> distance(v, MAX_VALUE);
        std::priority_queue<std::pair<long long, int> > queue;
        foreach (iterator, ends.at(0)) {
            int v = iterator->second;
            distance.at(v) = 0;
            queue.push(std::make_pair(0, v));
        }
        while (!queue.empty()) {
            std::pair<long long, int> t = queue.top();
            queue.pop();
            int u = t.second;
            if (-t.first == distance.at(u)) {
                foreach (iterator, graph.at(u)) {
                    int v = iterator->first;
                    if (distance.at(v) > distance.at(u) + iterator->second) {
                        distance.at(v) = distance.at(u) + iterator->second;
                        queue.push(std::make_pair(-distance.at(v), v));
                    }
                }
            }
        }
// for (int i = 0; i < v; ++ i) {
//     printf("%d: %lld\n", i, distance.at(i));
// }
        long long result = MAX_VALUE;
        foreach (iterator, ends.at(n - 1)) {
            result = std::min(result, distance.at(iterator->second));
        }
        assert(result < MAX_VALUE);
        std::cout << result << std::endl;
    }
}
