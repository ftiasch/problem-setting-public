#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        long long result = 0;
        std::vector<std::pair<int, int>> segments;
        for (int i = 0; i < n; ++ i) {
            char buffer[2];
            int length, cost;
            scanf("%d%s%d", &length, buffer, &cost);
            if (*buffer == '(') {
                result += (long long)length * cost;
                segments.emplace_back(length, -cost);
            } else {
                segments.emplace_back(length, cost);
            }
        }
        std::priority_queue<std::pair<int, int>> queue;
        int length = 0;
        for (auto&& segment : segments) {
            queue.emplace(-segment.second, segment.first);
            int new_length = length + segment.first;
            int need = (new_length + 1 >> 1) - (length + 1 >> 1);
            while (need > 0) {
                auto top = queue.top();
                queue.pop();
                int delta = std::min(need, top.second);
                need -= delta;
                top.second -= delta;
                result -= (long long)delta * top.first;
                if (top.second > 0) {
                    queue.push(top);
                }
            }
            length = new_length;
        }
        std::cout << result << std::endl;
    }
}
