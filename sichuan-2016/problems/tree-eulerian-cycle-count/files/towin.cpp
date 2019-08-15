#include <cstdio>
#include <cstring>

const int LENGTH = 1 << 10;

char buffer[LENGTH];

int main(int argc, char* argv[]) {
    bool flag = false;
    for (int i = 1; i < argc; ++ i) {
        FILE* f = fopen(argv[i], "r");
        while (fgets(buffer, LENGTH, f)) {
            if (buffer[strlen(buffer) - 1] == 13) {
                for (int j = strlen(buffer) - 1; j >= 0; -- j) {
                    if (buffer[j] <= 32) {
                        buffer[j] = 0;
                    } else {
                        break;
                    }
                }
                printf("%s", buffer);
                flag = true;
                continue;
            } else {
                if (buffer[strlen(buffer) - 1] != 10) {
                    printf("%s", buffer);
                    flag = true;
                    continue;
                }
            }
            flag = false;
            for (int j = strlen(buffer) - 1; j >= 0; -- j) {
                if (buffer[j] <= 32) {
                    buffer[j] = 0;
                } else {
                    break;
                }
            }
            puts(buffer);
        }
        fclose(f);
    }
    if (flag) {
        puts("");
    }
    return 0;
}
