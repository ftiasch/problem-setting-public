#include <bits/stdc++.h>
using namespace std;
const int K(23), N(505);
const int mod(1e9 + 7);
void inc(int & x, int y) {
    if((x += y) >= mod)
        x -= mod;
}
struct Sgt {
    int a[N * 4];
    int get(int k, int le, int ri, int posi) {
        if(le == ri)
            return a[k];
        else {
            int mid((le + ri) / 2);
            if(posi <= mid) return (a[k] + get(k * 2, le, mid, posi)) % mod;
            else return (a[k] + get(k * 2 + 1, mid + 1, ri, posi)) % mod;
        }
    }
    void clear(int k, int le, int ri) {
        a[k] = 0;
        if(le != ri) {
            int mid((le + ri) / 2);
            clear(k * 2, le, mid);
            clear(k * 2 + 1, mid + 1, ri);
        }
    }
    void edit(int k, int le, int ri, int ql, int qr, int delta) {
        if(ql > qr) return;
        //printf("%d %d %d %d %d %d\n", k, le, ri, ql, qr, delta);
        if(ql <= le && ri <= qr) {
            inc(a[k], delta);
        }else {
            int mid((le + ri) / 2);
            if(ql <= mid) edit(k * 2, le, mid, ql, qr, delta);
            if(qr >= mid + 1) edit(k * 2 + 1, mid + 1, ri, ql, qr, delta);
        }
    }
} sgt[N][K];
int dp[N][N][K];
int a[K], b[N];
int main() {
    int n, m;
    while(2 == scanf("%d%d", &n, &m)) {
        for(int i(1); i <= n; i++)
            scanf("%d", &a[i]);
        for(int i(1); i <= m; i++)
            scanf("%d", &b[i]);
        for(int i(1); i <= m; i++)
            for(int j(1); j <= n; j++)
                sgt[i][j].clear(1, 1, m);
        for(int i(1); i <= m; i++) {
            sgt[i][n].edit(1, 1, m, b[i], b[i], 1);
        }
        for(int i(m); i >= 1; i--) {
            for(int j(i); j <= m; j++) {
                for(int k(1); k <= n; k++) {
                    dp[i][j][k] = sgt[j][k].get(1, 1, m, b[i]);
                    if(dp[i][j][k] == 0 || k == 1) continue;
                    if(a[k - 1] == 0) {
                        //printf("%d\n", a[k] == 1 ? i : j);
                        sgt[a[k] == 1 ? i : j][k - 1].edit(1, 1, m, 1, min(b[i], b[j]) - 1, dp[i][j][k]);
                    }else {
                        sgt[a[k] == 0 ? i : j][k - 1].edit(1, 1, m, max(b[i], b[j]) + 1, m, dp[i][j][k]);
                    }
                }
            }
        }
        int ans(0);
        for(int i(1); i <= m; i++)
            for(int j(i); j <= m; j++)
                inc(ans, dp[i][j][1]);
        printf("%d\n", ans);
    }
}
