#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <queue>

int n;
int cards[14];

int get_num(char *str) {
    int sum = 0;
    for (int i = 0;str[i + 1];i++) {
        if (str[i] == 'A') {
            return 1;
        } else if (str[i] == 'J') {
            return 11;
        } else if (str[i] == 'Q') {
            return 12;
        } else if (str[i] == 'K') {
            return 13;
        }
        sum = sum * 10 + str[i] - '0';
    }
    return sum;
}

int main() {
    while(scanf("%d", &n) == 1) {
        memset(cards, 0, sizeof(cards));
        char line[105];
        for (int i = 0;i < n;i++) {
            scanf("%s", line);
            cards[get_num(line)]++;
            // printf("%d\n", get_num(line));
        }

        cards[0] = 0x3f3f3f3f;
        std::sort(cards, cards + 13);
        // std::cout << cards[0] << '\n';
        printf("%.15lf\n",  (4 - cards[0]) * 1.0 / (52 - n));
    }
}