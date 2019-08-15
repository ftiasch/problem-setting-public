#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

const int N = 100000;
const int M = 100000;

using Long = long long;

int ends[M << 1], color[M], length[M];
bool visited[M << 1];
Long distance[M << 1];
std::vector<int> graph[N];

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < n; ++ i) {
            graph[i].clear();
        }
        for (int i = 0; i < m; ++ i) {
            scanf("%d%d%d%d", ends + (i << 1), ends + (i << 1 | 1), color + i, length + i);
        }
        for (int i = 0; i < m << 1; ++ i) {
            ends[i] --;
        }
        for (int i = 0; i < m << 1; ++ i) {
            graph[ends[i]].push_back(i);
        }
        std::fill(distance, distance + (m << 1), std::numeric_limits<Long>::max());
        std::queue<int> queue;
        memset(visited, 0, sizeof(*visited) * (m << 1));
        Long result = std::numeric_limits<Long>::max();
        for (int i = 0; i < m << 1; ++ i) {
            if (!ends[i]) {
                visited[i] = true;
                distance[i] = length[i >> 1];
                queue.push(i);
                if (ends[i ^ 1] == n - 1) {
                    result = std::min(result, distance[i]);
                }
            }
        }
        while (!queue.empty()) {
            auto e = queue.front();
            queue.pop();
            visited[e] = false;
            if (distance[e] >= result) {
                continue;
            }
            for (auto&& f : graph[ends[e ^ 1]]) {
                int cost = std::abs(color[e >> 1] - color[f >> 1]) + length[f >> 1];
                if (distance[f] > distance[e] + cost) {
                    distance[f] = distance[e] + cost;
                    if (ends[f ^ 1] == n - 1) {
                        result = std::min(result, distance[f]);
                    }
                    if (!visited[f]) {
                        visited[f] = true;
                        queue.push(f);
                    }
                }
            }
        }
        std::cout << result << std::endl;
    }
}
