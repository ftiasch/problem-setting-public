import java.io.*;
import java.util.*;

public class WrongSolution2 {
    public static void main(String[] args) {
        new WrongSolution2().run();
    }

    class Tree {
        Tree(int id, List<Integer> parent) {
            this.id = id;
            n = parent.size();
            k = 1;
            while (1 << k < n) {
                k ++;
            }
            depth = new int[n];
            jump = new int[k][n];
            for (int i = 1; i < n; ++ i) {
                depth[i] = depth[jump[0][i] = parent.get(i)] + 1;
            }
            for (int i = 1; i < k; ++ i) {
                for (int u = 0; u < n; ++ u) {
                    jump[i][u] = jump[i - 1][jump[i - 1][u]];
                }
            }
        }

        int distance(int u, int v) {
            if (depth[u] > depth[v]) {
                return distance(v, u);
            }
            int result = depth[u] + depth[v];
            for (int i = k - 1; i >= 0; -- i) {
                if ((depth[v] - depth[u] >> i & 1) > 0) {
                    v = jump[i][v];
                }
            }
            if (u == v) {
                return result - (depth[u] << 1);
            }
            for (int i = k - 1; i >= 0; -- i) {
                if (jump[i][u] != jump[i][v]) {
                    u = jump[i][u];
                    v = jump[i][v];
                }
            }
            return result - (depth[jump[0][u]] << 1);
        }

        int id, n, k;
        int[] depth;
        int[][] jump;
    }

    class Node {
        Node(Tree tree, int index) {
            this.tree = tree;
            this.index = index;
        }

        int id() {
            return tree.id;
        }

        int depth() {
            return tree.depth[index];
        }

        Tree tree;
        int index;
    }

    int[][] graph;
    int[] degree;
    int[] depth;

    void dfs(List<Integer> parent, List<Integer> queue, int i) {
        int u = queue.get(i);
        for (int v : graph[u]) {
            if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                if (degree[v] < 3) {
                    int j = parent.size();
                    parent.add(i);
                    queue.add(v);
                    dfs(parent, queue, j);
                }
            }
        }
    }

    public void run() {
        InputReader reader = new InputReader(System.in);
        PrintWriter writer = new PrintWriter(System.out);
        try {
            int n = reader.nextInt();
            int m = reader.nextInt();
            int q = reader.nextInt();
            degree = new int[n];
            graph = new int[n][];
            if (true) {
                int[] a = new int[m];
                int[] b = new int[m];
                for (int i = 0; i < m; ++ i) {
                    a[i] = reader.nextInt() - 1;
                    b[i] = reader.nextInt() - 1;
                    degree[a[i]] ++;
                    degree[b[i]] ++;
                }
                for (int i = 0; i < n; ++ i) {
                    graph[i] = new int[degree[i]];
                    degree[i] = 0;
                }
                for (int i = 0; i < m; ++ i) {
                    graph[a[i]][degree[a[i]] ++] = b[i];
                    graph[b[i]][degree[b[i]] ++] = a[i];
                }
            }
            if (true) {
                Queue<Integer> queue = new LinkedList<Integer>();
                for (int u = 0; u < n; ++ u) {
                    if (degree[u] == 1) {
                        queue.offer(u);
                    }
                }
                while (!queue.isEmpty()) {
                    int u = queue.poll();
                    for (int v : graph[u]) {
                        degree[v] --;
                        if (degree[v] == 1) {
                            queue.offer(v);
                        }
                    }
                }
            }
            int[] newId = new int[n];
            Arrays.fill(newId, -1);
            int n2 = 0;
            for (int r = 0; r < n; ++ r) {
                if (degree[r] >= 3) {
                    newId[r] = n2 ++;
                }
            }
            int[][] distance = new int[n2][n2];
            for (int i = 0; i < n2; ++ i) {
                Arrays.fill(distance[i], n);
                distance[i][i] = 0;
            }
            List<List<Node>> nodes = new ArrayList<List<Node>>();
            for (int u = 0; u < n; ++ u) {
                nodes.add(new ArrayList<Node>());
            }
            depth = new int[n];
            for (int r = 0; r < n; ++ r) {
                if (degree[r] >= 3) {
                    // for (int t = 0; t < 2; ++ t) {
                        Arrays.fill(depth, -1);
                        depth[r] = 0;
                        List<Integer> parent = new ArrayList<Integer>();
                        parent.add(0);
                        List<Integer> queue = new ArrayList<Integer>();
                        queue.add(r);
                        // if (t == 0) {
                             for (int i = 0; i < queue.size(); ++ i) {
                                 int u = queue.get(i);
                                 for (int v : graph[u]) {
                                     if (depth[v] == -1) {
                                         depth[v] = depth[u] + 1;
                                         if (degree[v] < 3) {
                                             parent.add(i);
                                             queue.add(v);
                                         } else {
                                             distance[newId[r]][newId[v]] = Math.min(distance[newId[r]][newId[v]], depth[v]);
                                         }
                                     }
                                 }
                             }
                        // } else {
                        //    dfs(parent, queue, 0);
                        // }
                        Tree tree = new Tree(newId[r], parent);
                        for (int i = 0; i < queue.size(); ++ i) {
                            nodes.get(queue.get(i)).add(new Node(tree, i));
                        }
                    // }
                }
            }
            for (int k = 0; k < n2; ++ k) {
                for (int i = 0; i < n2; ++ i) {
                    for (int j = 0; j < n2; ++ j) {
                        distance[i][j] = Math.min(distance[i][j], distance[i][k] + distance[k][j]);
                    }
                }
            }
            while (q > 0) {
                q --;
                int a = reader.nextInt() - 1;
                int b = reader.nextInt() - 1;
                int result = n;
                for (Node u : nodes.get(a)) {
                    for (Node v : nodes.get(b)) {
                        result = Math.min(result, u.depth() + distance[u.id()][v.id()] + v.depth());
                        if (u.tree == v.tree) {
                            result = Math.min(result, u.tree.distance(u.index, v.index));
                        }
                    }
                }
                writer.println(result);
            }
        } catch (IOException e) {
        } finally {
            writer.close();
        }
    }

    class InputReader {
        InputReader(InputStream in) {
            this.reader    = new BufferedReader(new InputStreamReader(in));
            this.tokenizer = new StringTokenizer("");
        }

        public String nextToken() throws IOException {
            while (!tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(nextToken());
        }

        private BufferedReader  reader;
        private StringTokenizer tokenizer;
    }

    private void debug(Object...o) {
        System.err.println(Arrays.deepToString(o));
    }
}
