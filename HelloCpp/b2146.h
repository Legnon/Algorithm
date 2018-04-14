//
//  b2146.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 25..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b2146_h
#define b2146_h


#endif /* b2146_h */

#define MAX 101

int dp[MAX][MAX];
int a[MAX][MAX];
int b[MAX][MAX];
int cnt, n;
int ans = 1000;
int mx[4] = {0,0,1,-1};
int my[4] = {1,-1,0,0};

queue<pair<int, int>> q;

void classification() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        for (int i=0; i<4; i++) {
            int nx = x + mx[i];
            int ny = y + my[i];
            
            if (nx >= 1 && ny >= 1 && nx <= n && ny <=n) {
                if (dp[nx][ny] == 1 && a[nx][ny] == -1) {
                    q.push(make_pair(nx, ny));
                    a[nx][ny] = cnt;
                }
            }
        }
    }
    cnt++;
}

void bfs() {
    int max_num = 0;
    bool end = false;
    
    while (!q.empty() && !end) {
        unsigned long qs = q.size();
        
        for (int i=0; i<qs; i++){
            int x = q.front().first;
            int y = q.front().second;
			printf("시작!! %d %d -> 0\n", x, y);
			
            q.pop();
            
            for (int i=0; i<4; i++) {
				printf("상하좌우 탐색\n");
                int nx = x + mx[i];
                int ny = y + my[i];
				printf("%d %d\n", nx, ny);
				
                if (nx >= 1 && ny >= 1 && nx <= n && ny <=n) {
                    if (dp[nx][ny] == 0 && b[nx][ny] == -1) {
						printf("%d %d -> 물\n", nx, ny);
                        b[nx][ny] = 0;
                        q.push(make_pair(nx, ny));
                    }
                    if (dp[nx][ny] == 1 && a[nx][ny] != cnt && b[nx][ny] == -1) {
                        printf("%d %d -> 땅인데 내 섬이 아님\n", nx, ny);
                        b[nx][ny] = 0;
                        end = true;
                        ans = min(ans, max_num);
						printf("지금 답은 %d\n", ans);
                        break;
                    }
                }
            }
            if (end) break;
        }
        if (end) break;
        printf("맥스 넘 더함\n");
        max_num++;
    }
	while(!q.empty()) q.pop();
}

void init() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            b[i][j] = -1;
        }
    }
}

void answer() {
    scanf("%d", &n);
    
    // 그래프화
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            scanf("%1d", &dp[i][j]);
            a[i][j] = -1;
            b[i][j] = -1;
        }
    }
    
    // 섬 별 분류
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (dp[i][j] == 1 && a[i][j] == -1) {
                q.push(make_pair(i, j));
                a[i][j] = cnt;
                classification();
            }
        }
    }
	
	// show table
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			printf("%d", dp[i][j]);
		}
		printf("\n");
	}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			printf("%d", a[i][j]);
		}
		printf("\n");
	}

    
    // 최단 경로 찾기
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (dp[i][j] == 1) {
                printf("%d %d -> bfs 시작\n", i, j);
                cnt = a[i][j];
                q.push(make_pair(i,j));
                bfs();
                init();
            }
        }
    }
	
	printf("%d\n", (ans==101) ? 0:ans);
    
	
}
