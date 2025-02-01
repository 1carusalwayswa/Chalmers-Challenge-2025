#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <queue>

std::priority_queue<int, std::vector<int>, std::greater<int>> que;
int main() {
    int n, x;
    while(scanf("%d %d", &n, &x) == 2) {
        char str[105];
        int flag = 1;
        for (int i = 1;i <= n;i++) {
            scanf("%s", str);
            if (strcmp(str, "ADD") == 0) {
                que.push(i);
            } else if (strcmp(str, "EAT") == 0) {
                if (que.empty()) {
                    flag = 0;
                } else {
                    int cur = que.top();
                    que.pop();
                    if (i - cur > x) {
                        flag = 0;
                    }
                }
            } else {
                continue;
            }

            if (flag == 0) break;
        }

        if (flag) {
            printf("%s\n", "yay!");
        } else {
            printf("%s\n", "ono..");
        }
    }
}