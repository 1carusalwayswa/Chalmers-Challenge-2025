#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <limits>

const int N = 6005;

struct node {
    long long x, y;
    double dis1, dis2;
    int min_idx1, min_idx2;
} R[N], G[N], B[N];

double cal_dis(long long x1, long long y1, long long x2, long long y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2)*(y1 - y2));
}

int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        long long x, y;
        char ch;
        getchar();
        int r_cnt, g_cnt, b_cnt;
        r_cnt = g_cnt = b_cnt = 0;
        for (int i = 0;i < n;i++) {
            scanf("%lld %lld %c", &x, &y, &ch);
            getchar();
            if(ch == 'R') {
                R[r_cnt].x = x;
                R[r_cnt].y = y;
                R[r_cnt].dis1 = std::numeric_limits<double>::max();
                R[r_cnt].dis2 = std::numeric_limits<double>::max();
                r_cnt++;
            } else if (ch == 'G') {
                G[g_cnt].x = x;
                G[g_cnt].y = y; 
                G[g_cnt].dis1 = std::numeric_limits<double>::max();
                G[g_cnt].dis2 = std::numeric_limits<double>::max();
                g_cnt++;
            } else {
                B[b_cnt].x = x;
                B[b_cnt].y = y;
                B[b_cnt].dis1 = std::numeric_limits<double>::max();
                B[b_cnt].dis2 = std::numeric_limits<double>::max();
                b_cnt++;
            }
        }

        // 1 R
        for (int i = 0;i < r_cnt;i++) {
            for (int j = 0;j < g_cnt;j++) {
                double new_dis = cal_dis(R[i].x, R[i].y, G[j].x, G[j].y) + cal_dis(0, 0, G[j].x, G[j].y); 
                if (new_dis - R[i].dis1 < 0.000001) {
                    R[i].dis1 = new_dis;
                } 
            }
        }
        for (int i = 0;i < r_cnt;i++) {
            for (int j = 0;j < b_cnt;j++) {
                double new_dis = cal_dis(R[i].x, R[i].y, B[j].x, B[j].y) + cal_dis(0, 0, B[j].x, B[j].y); 
                if (new_dis - R[i].dis2 < 0.000001) {
                    R[i].dis2 = new_dis;
                } 
            }
        }

        // 2 G
        for (int i = 0;i < g_cnt;i++) {
            for (int j = 0;j < r_cnt;j++) {
                double new_dis = cal_dis(R[j].x, R[j].y, G[i].x, G[i].y) + cal_dis(0, 0, R[j].x, R[j].y); 
                if (new_dis - G[i].dis1 < 0.000001) {
                    G[i].dis1 = new_dis;
                } 
            }
        }
        for (int i = 0;i < g_cnt;i++) {
            for (int j = 0;j < b_cnt;j++) {
                double new_dis = cal_dis(G[i].x, G[i].y, B[j].x, B[j].y) + cal_dis(0, 0, B[j].x, B[j].y); 
                if (new_dis - G[i].dis2 < 0.000001) {
                    G[i].dis2 = new_dis;
                } 
            }
        }

        // 3 B
        for (int i = 0;i < b_cnt;i++) {
            for (int j = 0;j < r_cnt;j++) {
                double new_dis = cal_dis(R[j].x, R[j].y, B[i].x, B[i].y) + cal_dis(0, 0, R[j].x, R[j].y); 
                if (new_dis - B[i].dis1 < 0.000001) {
                    B[i].dis1 = new_dis;
                } 
            }
        }
        for (int i = 0;i < b_cnt;i++) {
            for (int j = 0;j < g_cnt;j++) {
                double new_dis = cal_dis(G[j].x, G[j].y, B[i].x, B[i].y) + cal_dis(0, 0, G[j].x, G[j].y); 
                if (new_dis - B[i].dis2 < 0.000001) {
                    B[i].dis2 = new_dis;
                } 
            }
        }

        double ans = std::numeric_limits<double>::max();
        for (int i = 0;i < r_cnt;i++) {
            double dis = R[i].dis1 + R[i].dis2;
            // std::cout << "R " << i << ": " << R[i].dis1 << " " << R[i].dis2 << '\n';
            ans = std::min(dis, ans);
        }
        for (int i = 0;i < g_cnt;i++) {
            double dis = G[i].dis1 + G[i].dis2;
            // std::cout << "G " << i << ": " << G[i].dis1 << " " << G[i].dis2 << '\n';
            ans = std::min(dis, ans);
        }
        for (int i = 0;i < b_cnt;i++) {
            double dis = B[i].dis1 + B[i].dis2;
            // std::cout << "B " << i << ": " << B[i].dis1 << " " << B[i].dis2 << '\n';
            ans = std::min(dis, ans);
        }

        // std::cout << '\n';
        // for (int i = 0;i < r_cnt;i++) {
        //     std::cout << R[i].dis1 << " " << R[i].dis2 << '\n';
        // }
        // std::cout << '\n';
        // for (int i = 0;i < b_cnt;i++) {
        //     std::cout << B[i].dis1 << " " << B[i].dis2 << '\n';
        // }
        // std::cout << '\n';
        // for (int i = 0;i < g_cnt;i++) {
        //     std::cout << G[i].dis1 << " " << G[i].dis2 << '\n';
        // }
        printf("%lf\n", ans);
        // std::cout << cal_dis(G[0].x, G[0].y, B[0].x, B[0].y) << '\n';
        // std::cout << G[0].x << " " << G[0].y << '\n';
        // std::cout << B[0].x << " " << B[0].y << '\n';
    }
}