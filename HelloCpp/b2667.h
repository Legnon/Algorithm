//
//  b2667.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 21..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b2667_h
#define b2667_h


#endif /* b2667_h */

#define MAX 25

int node;
int graph[MAX][MAX];
bool visited[MAX][MAX];

queue<pair<int, int>> q;
vector<int> c;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void find() {
    int sum = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i=0; i<4; i++) {
            int x_new = x+dx[i];
            int y_new = y+dy[i];
            
            if (x_new < 0 || x_new >= node || y_new < 0 || y_new >= node) continue;
                
            if (visited[x_new][y_new] == 0 && graph[x_new][y_new] == 1) {
                q.push(make_pair(x_new,y_new));
                visited[x_new][y_new] = 1;
                sum++;
            }
        }
    }
    c.push_back(sum);
    
}

void bfs() {
    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            if (visited[i][j] == 0 && graph[i][j] == 1){
                visited[i][j] = 1;
                q.push(make_pair(i,j));
                find();
            }
        }
    }
    
    sort(c.begin(), c.end());
    
    c.insert(c.begin(), INT_MAX & c.size());
    
    for (int i: c) {
        cout << i << endl;
    }
}

void answer() {
    cin >> node;
    
    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }
    
    bfs();
}
