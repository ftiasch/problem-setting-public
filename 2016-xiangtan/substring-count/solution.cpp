#include <cstdio>
#include <cstring>

typedef unsigned long long Long;

const int N = 50000;
const int L = N + 63 >> 6;

char s[N + 1], buffer[N + 1];
Long mask[26][L], result[L], shifted[L];

int main()
{
    int n, q;
    while (scanf("%d%d", &n, &q) == 2) {
        scanf("%s", s);
        memset(mask, 0, sizeof(mask));
        for (int i = 0; i < n; ++ i) {
            mask[s[i] - 'a'][i >> 6] |= 1ULL << (i & 63);
        }
        while (q --) {
            int index;
            scanf("%d%s", &index, buffer);
            if (index --) {
                mask[s[index] - 'a'][index >> 6] &= ~(1ULL << (index & 63));
                s[index] = *buffer;
                mask[s[index] - 'a'][index >> 6] |= 1ULL << (index & 63);
            } else {
                memcpy(result, mask[*buffer - 'a'], sizeof(result));
                for (int i = 1; buffer[i]; ++ i) {
                    Long* src = mask[buffer[i] - 'a'];
                    int big_offset = i >> 6;
                    int small_offset = i & 63;
                    for (int j = big_offset; j < L; ++ j) {
                        Long tmp = 0;
                        tmp |= src[j] >> small_offset;
                        if (small_offset && j + 1 < L) {
                            tmp |= src[j + 1] << 64 - small_offset;
                        }
                        result[j - big_offset] &= tmp;
                    }
                }
                int count = 0;
                for (int i = 0; i < L; ++ i) {
                    count += __builtin_popcountll(result[i]);
                }
                printf("%d\n", count);
            }
        }
    }
    return 0;
}
