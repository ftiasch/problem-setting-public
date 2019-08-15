#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using Double = double;

const Double EPSILON = 1e-9;

int signum(Double x)
{
    return x < -EPSILON ? -1 : x > EPSILON;
}

struct Point
{
    Point(Double x, Double y) : x(x), y(y) {}

    Double x, y;
};

Point operator - (const Point& a, const Point& b)
{
    return Point(a.x - b.x, a.y - b.y);
}

Double det(const Point& a, const Point& b)
{
    return a.x * b.y - a.y * b.x;
}

Double area(const std::vector<Point>& polygon)
{
    int n = polygon.size();
    if (n < 3) {
        return 0.;
    }
    Double result = 0.;
    for (int i = 0; i < n; ++ i) {
        result += det(polygon.at(i), polygon.at((i + 1) % n));
    }
    return result;
}

std::vector<Point> normalize(std::vector<Point> polygon)
{
    if (signum(area(polygon)) < 0) {
        std::reverse(polygon.begin(), polygon.end());
    }
    return polygon;
}

std::vector<Point> cut(const std::vector<Point>& intersection, const Point& a, const Point& b)
{
    int n = intersection.size();
    std::vector<Point> new_intersection;
    for (int i = 0; i < n; ++ i) {
        auto&& p = intersection.at(i);
        auto&& q = intersection.at((i + 1) % n);
        auto k1 = det(b - a, p - a);
        auto k2 = det(b - a, q - a);
        /*
         k1   x-p
         -- = --- => k1(x-q)=k2(x-p) => (k1-k2)x=k1*q-k2p
         k2   x-q
         */
        if (signum(k1) * signum(k2) < 0) {
            new_intersection.emplace_back
            ( (q.x * k1 - p.x * k2) / (k1 - k2)
            , (q.y * k1 - p.y * k2) / (k1 - k2) );
        }
        if (signum(det(b - a, q - a)) >= 0) {
            new_intersection.push_back(q);
        }
    }
    return new_intersection;
}

int main()
{
    int x[4], y[4];
    while (scanf("%d%d", x, y) == 2) {
        for (int i = 1; i < 4; ++ i) {
            scanf("%d%d", x + i, y + i);
        }
        std::vector<Point> intersection;
        intersection.emplace_back(x[0], y[0]);
        intersection.emplace_back(x[0], y[1]);
        intersection.emplace_back(x[1], y[0]);
        intersection = normalize(intersection);
        std::vector<Point> rectangle;
        rectangle.emplace_back(x[2], y[2]);
        rectangle.emplace_back(x[2], y[3]);
        rectangle.emplace_back(x[3], y[3]);
        rectangle.emplace_back(x[3], y[2]);
        rectangle = normalize(rectangle);
        for (int i = 0; i < 4; ++ i) {
            intersection = cut(intersection, rectangle.at(i), rectangle.at(i + 1 & 3));
        }
        printf("%.8f\n", .5 * area(intersection));
    }
}
