#include "testlib.h"
#include <cassert>
#include <cmath>
#include <functional>
#include <queue>
#include <vector>

using i64 = long long;

namespace gen {
namespace util {
// Random distribute $n$ undistinguishable item into $T$ different boxes.
std::vector<int> distribute(int n, int T) {
  std::vector<int> cuts, result;
  cuts.push_back(0);
  for (auto i = 0; i < T - 1; ++i) {
    cuts.push_back(rnd.next(0, n - T));
  }
  cuts.push_back(n - T);
  std::sort(cuts.begin(), cuts.end());
  for (auto i = 1; i <= T; ++i) {
    result.push_back(cuts.at(i) - cuts.at(i - 1) + 1);
  }
  return result;
}

// Random sample $k$ elements from $n$ elements with equal probability.
// Time Complexity: $O(k \log k)$
template <typename Int> std::vector<Int> random_subset(Int n, int k) {
  ensuref(n >= k, "random_subset failed: n >= k");
  std::set<Int> set;
  for (Int i = n - k; i < n; ++i) {
    Int p = rnd.next(static_cast<Int>(0), i);
    if (set.count(p)) {
      set.insert(i);
    } else {
      set.insert(p);
    }
  }
  std::vector<Int> result;
  for (auto elem : set) {
    result.push_back(elem);
  }
  return result;
}
} // namespace util
} // namespace gen

namespace gen {
namespace tree {

using edge_t = std::vector<std::pair<int, int>>;

// Copy from @ftiasch
// If $w = 1$, the expectation of diamater is $O(\sqrt{n})$.
// If $w = n$, the expectation of diamater may be $O(n)$.
edge_t rand_with_dsu(int n, int w) {
  std::vector<int> parent(n, -1);
  std::function<int(int)> find = [&](int u) {
    return ~parent[u] ? parent[u] = find(parent[u]) : u;
  };
  edge_t edges;
  for (auto _ = 0; _ < n - 1; ++_) {
    while (true) {
      auto a = rnd.next(0, n - 1);
      auto b = (a + rnd.wnext(1, n - 1, w)) % n;
      auto u = find(a);
      auto v = find(b);
      if (u != v) {
        if (rnd.next(0, 1)) {
          std::swap(a, b);
        }
        edges.emplace_back(a, b);
        parent[u] = v;
        break;
      }
    }
  }
  return edges;
}

// Generate a random tree with $n$ nodes using prufer sequence.
edge_t rand_with_prufer(int n) {
  if (n == 1)
    return {};
  if (n == 2)
    return {{0, 1}};
  std::vector<int> a(n - 2), deg(n, 1);
  for (int i = 0; i < n - 2; ++i)
    a[i] = rnd.next(n);
  for (auto &x : a)
    deg[x]++;
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  for (int i = 0; i < n; ++i) {
    if (deg[i] == 1)
      pq.push(i);
  }
  edge_t edges;
  for (auto &u : a)
    if (!pq.empty()) {
      int v = pq.top();
      pq.pop();
      --deg[v];
      --deg[u];
      edges.emplace_back(u, v);
      if (deg[u] == 1)
        pq.push(u);
    }
  int u = -1, v = -1;
  for (int i = 0; i < n && v == -1; ++i)
    if (deg[i] == 1) {
      if (u == -1)
        u = i;
      else
        v = i;
    }
  edges.emplace_back(u, v);
  return edges;
}

// Generate a random binary tree using: A random binary tree generator, by
// Martin, H. W., & Orr, B. J It will generate a binary tree with $n$ nodes such
// that
//   1. the root of the binary tree is $0$.
//   2. each node has at most two childrens.
//   3. for each edge $(u, v)$, if $label[u] == label[v]$, $v$ is right child of
//   $u$; otherwise $v$ is left child of $u$.
edge_t rand_binary_inversion_table(int n, std::vector<int> &label) {
  label.resize(n);
  label[0] = 0;
  for (int i = 1; i < n; ++i) {
    label[i] = rnd.next(0, label[i - 1] + 1);
  }
  std::vector<int> stack = {0};
  edge_t edges;
  for (int i = 1; i < n; ++i) {
    if (label[stack.back()] < label[i]) {
      edges.emplace_back(stack.back(), i);
      stack.push_back(i);
    } else {
      while (!stack.empty() && label[stack.back()] > label[i])
        stack.pop_back();
      ensuref(!stack.empty(), "rand_binary_inversion_table failed");
      edges.emplace_back(stack.back(), i);
      stack.push_back(i);
    }
  }
  return edges;
}

// Generate a random binary tree using: Fast Generation of Big Random Binary
// Trees, by W. B. Langdon It will generate a full binary tree with $n + 1$
// leaves and $n$ internal nodes. And the root is $0$. For each edge $(u, v)$,
// the first occurrence of $(u, \cdot)$ is the left edge and the second is right
// edge. The average height is $2 \sqrt{\pi n} + O(n^{1/4+\epsilon})$.
edge_t random_binary_dyck(int n) {
  std::vector<int> dyck(n * 2 + 1);
  for (int i = 0; i <= n * 2; ++i)
    dyck[i] = i % 2;
  shuffle(dyck.begin(), dyck.end());
  int x = 0, y = 0, best = 1, pos = -1;
  for (int i = 0; i <= n * 2; ++i) {
    if (dyck[i] == 0)
      ++x;
    else
      ++y;
    if (x - y <= best)
      best = x - y, pos = i;
  }
  ensuref(dyck[pos] == 1, "random_binary_dyck failed: invalid start position");
  std::vector<int> cnt(n * 2 + 1);
  std::vector<int> stack = {0};
  edge_t edges;
  for (int i = 1; i <= n * 2; ++i) {
    int o = dyck[(pos - i + n * 2 + 1) % (n * 2 + 1)];
    edges.emplace_back(stack.back(), i);
    cnt[stack.back()]++;
    if (o == 1)
      stack.push_back(i);
    while (!stack.empty() && cnt[stack.back()] == 2)
      stack.pop_back();
  }
  ensuref(stack.empty(), "random_binary_dyck failed: stack should be empty");
  return edges;
}

// Generate a random caterpillar with $n$ nodes, where $m$ is the number of
// nodes on the main chain. If $m = 3$, it is a star.
edge_t rand_caterpillar(int n, int m) {
  if (n == 1)
    return {};
  if (n == 2)
    return {{0, 1}};
  ensuref(m >= 3, "number of nodes on the main chain >= 3");
  edge_t edges;
  for (int i = 0; i + 1 < m; ++i)
    edges.emplace_back(i, i + 1);
  for (int i = m; i < n; ++i) {
    edges.emplace_back(i, rnd.next(1, m - 1));
  }
  return edges;
}

// Generate a random tree with $n$ vertices and a long path of $m$ vertices.
edge_t rand_skew_tree(int n, int m) {
  ensuref(1 <= m && m <= n, "rand_skew_tree failed: 1 <= m <= n");
  edge_t edges;
  for (int i = 1; i < m; ++i) {
    edges.emplace_back(i - 1, i);
  }
  for (int i = m; i < n; ++i) {
    edges.emplace_back(rnd.next(0, i - 1), i);
  }
  return edges;
}

// If `w = 1`, generate a path with $n$ vertices.
edge_t rand_path(int n, int w) {
  edge_t edges;
  for (int i = 1; i < n; ++i) {
    edges.emplace_back(rnd.next(std::max(0, i - w), i - 1), i);
  }
  return edges;
}

// Generate k-ary tree with $n$ vertices.
edge_t rand_kary(int n, int k) {
  ensuref(k >= 1, "rand_kary failed: k >= 2");
  edge_t edges;
  for (int i = 1; i < n; ++i) {
    edges.emplace_back(i, i / k);
  }
  return edges;
}

// Generate an $m$-wheel with $n$ vertices.
edge_t rand_wheel(int n, int m) {
  edge_t edges;
  for (int i = 1; i < n; ++i) {
    if (i <= m)
      edges.emplace_back(0, i);
    else
      edges.emplace_back(i - m, i);
  }
  return edges;
}

// Relabel the vertices
void relabel_vertices(int n, edge_t &edges) {
  std::vector<int> label(n);
  for (int i = 0; i < n; ++i)
    label[i] = i;
  shuffle(label.begin(), label.end());
  for (auto &e : edges) {
    e.first = label[e.first];
    e.second = label[e.second];
  }
}

// Convert an unrooted tree to a rooted tree
// If `relabel = 1`, the result `parent` array will satisfy: `parent[i] < i`.
// Otherwise, `parent[root]` will be `-1`.`
std::vector<int> convert_rooted(int n, const edge_t &edges, int root,
                                bool relabel = false) {
  std::vector<int> label(n);
  std::vector<std::vector<int>> adj(n);
  for (auto &e : edges) {
    adj[e.first].push_back(e.second);
    adj[e.second].push_back(e.first);
  }

  std::vector<int> parent(n, -1);
  int m = 0;
  std::function<void(int, int)> dfs = [&](int u, int p) {
    label[u] = m++;
    if (p != -1) {
      if (relabel)
        parent[label[u]] = label[p];
      else
        parent[u] = p;
    }
    for (auto &v : adj[u])
      if (v != p) {
        dfs(v, u);
      }
  };

  dfs(root, -1);

  return parent;
}
} // namespace tree
} // namespace gen

// Generate a tree with $n$ vertices by combining all the methods above.
gen::tree::edge_t combine(int n, int part) {
  auto ns = gen::util::distribute(n, part);
  gen::tree::edge_t edges;
  int offset = 0;
  for (auto &&n : ns) {
    int type = rnd.next(7);
    gen::tree::edge_t t_edges;
    if (type == 0) {
      t_edges =
          gen::tree::rand_with_dsu(n, std::min(n, std::min(n, rnd.next(1, 5))));
    } else if (type == 1) {
      t_edges = gen::tree::rand_with_prufer(n);
    } else if (type == 2) {
      std::vector<int> label;
      t_edges = gen::tree::rand_binary_inversion_table(n, label);
    } else if (type == 3) {
      t_edges = gen::tree::random_binary_dyck((n - 1) / 2);
    } else if (type == 4) {
      t_edges =
          gen::tree::rand_caterpillar(n, std::max(3, rnd.next(n / 4, n / 3)));
    } else if (type == 5) {
      t_edges =
          gen::tree::rand_skew_tree(n, std::max(1, rnd.next(n / 4, n / 2)));
    } else if (type == 6) {
      t_edges = gen::tree::rand_path(n, rnd.next(1, 4));
    } else if (type == 7) {
      t_edges = gen::tree::rand_kary(n, rnd.next(2, 4));
    } else {
      t_edges = gen::tree::rand_wheel(n, rnd.next((int)cbrt(n), (int)sqrt(n)));
    }
    n = t_edges.size() + 1;
    for (auto &e : t_edges) {
      edges.emplace_back(e.first + offset, e.second + offset);
    }
    if (offset) {
      edges.emplace_back(rnd.next(offset), rnd.next(n) + offset);
    }
    offset += n;
  }
  ensuref(offset <= n, "combine failed: wrong number of vertices");
  return edges;
}

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  auto N = 100000, M = 200000;
  auto min_n = std::atoi(argv[1]);
  auto max_n = std::atoi(argv[2]);
  auto type = std::atoi(argv[3]);
  auto w = std::atoi(argv[4]);
  auto D = std::atoi(argv[5]);
  std::vector<int> ns;
  while (N >= min_n) {
    int n = rnd.next(min_n, std::min(N, max_n));
    ns.push_back(n);
    N -= n;
  }
  auto ms = gen::util::distribute(M - (100000 - ns.size()), ns.size());
  for (size_t i = 0; i < ns.size(); ++i) {
    int n = ns[i], m = ms[i];
    gen::tree::edge_t edges;
    if (type == 0) {
      edges = gen::tree::rand_with_dsu(n, std::min(n, rnd.next(1, 5)));
    } else if (type == 1) {
      edges = gen::tree::rand_with_prufer(n);
    } else if (type == 2) {
      std::vector<int> label;
      edges = gen::tree::rand_binary_inversion_table(n, label);
    } else if (type == 3) {
      edges = gen::tree::random_binary_dyck((n - 1) / 2);
    } else if (type == 4) {
      edges =
          gen::tree::rand_caterpillar(n, std::max(3, rnd.next(n / 4, n / 3)));
    } else if (type == 5) {
      edges = gen::tree::rand_skew_tree(n, std::max(1, rnd.next(n / 4, n / 2)));
    } else if (type == 6) {
      edges = gen::tree::rand_path(n, rnd.next(1, 4));
    } else if (type == 7) {
      edges = gen::tree::rand_kary(n, rnd.next(2, 4));
    } else if (type == 8) {
      edges = gen::tree::rand_wheel(n, rnd.next((int)cbrt(n), (int)sqrt(n)));
    } else {
      edges = combine(n, rnd.next(20, 40));
    }
    n = edges.size() + 1;
    // m = std::min<i64>((i64)n * (n - 1) / 2 - (n - 1), m);
    std::vector<std::vector<int>> vs(n);
    for (auto &e : edges) {
      int u = e.first, v = e.second;
      if (u > v)
        std::swap(u, v);
      vs[u].push_back(v);
    }
    std::vector<i64> rest(n);
    for (int i = 0; i < n; ++i) {
      rest[i] = n - 1 - i - vs[i].size();
      vs[i].push_back(i);
      std::sort(vs[i].begin(), vs[i].end());
      for (size_t j = 0; j < vs[i].size(); ++j)
        vs[i][j] -= j;
      if (i)
        rest[i] += rest[i - 1];
    }
    for (int i = 0; i < m; ++i) {
      int u = rnd.next(0, n - 1);
      int v = (u + rnd.next(1, n - 1)) % n;
      edges.emplace_back(u, v);
    }
    shuffle(edges.begin(), edges.end());
    for (auto &e : edges) {
      if (rnd.next(2))
        std::swap(e.first, e.second);
    }
    int l = rnd.next(0, D);
    int r = rnd.next(0, D);
    if (l > r)
      std::swap(l, r);
    printf("%d %d %d %d\n", n, n - 1 + m, l, r);
    for (auto &e : edges) {
      printf("%d %d %d %d\n", e.first + 1, e.second + 1, rnd.next(1, w),
             rnd.next(-w, w));
    }
  }
  return 0;
}
