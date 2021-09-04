//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2020_CSP20200902_H
#define CSP2020_CSP20200902_H
namespace CSP20200902{
    typedef struct Node{
        int x,y;
        int through,danger,k;
    }Node;
    void testCSP20200902() {
        int t, k, n, x1, y1, x2, y2;
        int through = 0, danger = 0;
        cin >> t >> k >> n >> x1 >> y1 >> x2 >> y2;
        for (int i = 0; i < t; i++) {
            Node node;
            node.through = 0;
            node.danger = 0;
            node.k = 0;
            for (int j = 0; j < n; j++) {
                int x, y;
                cin >> x >> y;
                if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
                    node.through = 1;
                    node.k += 1;
                    if (node.k == k) {
                        node.danger = 1;
                    }
                }//连续k个或更多坐标均位于矩形内（含边界），
                    //则认为该居民曾在高危区域逗留。
                else node.k = 0;
            }
            through += node.through;
            danger += node.danger;
        }
        cout << through << endl << danger;
    }
}
#endif //CSP2020_CSP20200902_H
