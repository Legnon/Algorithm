//
//  b2178.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 21..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b2178_h
#define b2178_h


#endif /* b2178_h */

#define MAX 101

int m,n,depth;
queue<pair<int,int>> q;

int mx[4] = {0,0,1,-1};
int my[4] = {1,-1,0,0};

int graph[MAX][MAX];
bool visited[MAX][MAX];

void answer() {
    cin >> m >> n;
    
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            visited[i][j] = false;
            scanf("%1d", &graph[i][j]);
        }
    }
    
    // bfs
    q.push(make_pair(1, 1));
    visited[1][1] = true;
    bool end = false;
    
    while (!q.empty()) {
        int x, y;
        unsigned long qs = q.size();
        
        for (int k=0; k<qs; k++){
            x = q.front().first;
            y = q.front().second;
            
            q.pop();
            
            for (int i=0; i<4; i++) {
                int nx = x + mx[i];
                int ny = y + my[i];
                
                if (nx >= 1 && ny >= 1 && nx <= m && ny <= n && !visited[nx][ny] && graph[nx][ny] == 1) {
                    if (nx == m && ny == n) {
                        end = true;
                        break;
                    }
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
            if (end) break;
        }
        depth++;
        if (end) break;
    }
    cout << depth+1 << endl;
}
