//
//  b1261.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 24..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b1261_h
#define b1261_h


#endif /* b1261_h */

#define MAX 101

int d[MAX][MAX]; // 총 비용
int a[MAX][MAX]; // 그래프

int mx[4] = {0,0,1,-1};
int my[4] = {1,-1,0,0};

void answer() {
    int m, n;
    scanf("%d %d", &n, &m);
    
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            scanf("%1d", &a[i][j]);
            d[i][j] = -1;
        }
    }
    
    deque<pair<int, int>> q;
    q.push_back(make_pair(1,1));
    d[1][1] = 0;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        
        for (int i=0; i<4; i++) {
            int nx = x + mx[i];
            int ny = y + my[i];
            
            if (nx >= 1 && ny >=1 && nx <= m && ny <=n) {
                if (d[nx][ny] == -1) { // 아직 안간경우에
                    if (a[nx][ny] == 0) {  // 갈수 있다면 푸시 프론트
                        d[nx][ny] = d[x][y];
                        q.push_front(make_pair(nx,ny));
                    }
                    else { // 벽이라면 푸시 백
                        d[nx][ny] = d[x][y] + 1;
                        q.push_back(make_pair(nx,ny));
                    }
                }
            }
        }
    }
    
    printf("%d\n", d[m][n]);
    
}

