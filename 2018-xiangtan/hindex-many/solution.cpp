#include <cstdio>
#include <vector>

struct Node;

std::vector<Node*> alloc;

Node* null;

struct Node
{
    Node(int count, Node* left, Node* right)
        : count(count), left(left), right(right)
    {
        alloc.push_back(this);
    }

    Node* insert(int l, int r, int k)
    {
        if (k < l || r < k) {
            return this;
        }
        if (l == r) {
            return new Node(count + 1, null, null);
        }
        int m = l + r >> 1;
        return new Node(count + 1, left->insert(l, m, k), right->insert(m + 1, r, k));
    }

    int count;
    Node* left, *right;
};

const int N = 100000;

Node* tree[N + 1];

int main()
{
    int n, q;
    while (scanf("%d%d", &n, &q) == 2) {
        null = new Node(0, nullptr, nullptr);
        null->left = null->right = null;
        tree[0] = null;
        for (int i = 0, a; i < n; ++ i) {
            scanf("%d", &a);
            tree[i + 1] = tree[i]->insert(1, n, a);
        }
        while (q --) {
            int l, r;
            scanf("%d%d", &l, &r);
            l --;
            Node *p = tree[l], *q = tree[r];
            int low = 1;
            int high = n;
            int cnt = 0;
            while (low < high) {
                int mid = low + high >> 1;
                int tmp = q->right->count - p->right->count;
                if (cnt + tmp >= mid + 1) {
                    low = mid + 1;
                    p = p->right, q = q->right;
                } else {
                    high = mid;
                    cnt += tmp;
                    p = p->left, q = q->left;
                }
            }
            printf("%d\n", high);
        }
        for (auto& a : alloc) {
            delete a;
        }
        alloc.clear();
    }
}
