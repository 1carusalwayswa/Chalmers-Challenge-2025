#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <cstdlib>

int boll[4];

int main() {
    int goal;
    int n, a, b;
    while(scanf("%d", &goal) == 1) {
        memset(boll, 0, sizeof(boll));
        boll[2] = 1;
        scanf("%d", &n);
        for (int i = 0;i < n;i++) {
            scanf("%d %d", &a, &b);
            std::swap(boll[a], boll[b]);
        }

        if (boll[goal]) {
            int flag = 1;
            for (int i = 1;i <= 3;i++) {
                if (i == goal)continue;
                if (!flag) {
                    printf(" ");
                }
                flag = 0;
                printf("%d", i);
            }
            putchar('\n');
        } else {
            printf("%d", goal);
            for (int i = 1;i <= 3;i++){
                if (i == goal)continue;
                if (boll[i] == 0) continue;
                printf(" %d", i);
                break;
            }
            putchar('\n');
        }
    }
}