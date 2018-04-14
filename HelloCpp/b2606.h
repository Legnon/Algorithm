//
//  b2606.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 21..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b2606_h
#define b2606_h


#endif /* b2606_h */

#define MAX 101
queue<int> q;
int graph[MAX][MAX];
int visited[MAX];
int node, edge;

void bfs() {
    q.push(1);
    visited[1] = 1;
    
    while (!q.empty())
    {
        cout << q.front() << endl;
        int current = q.front();
        q.pop();
        visited[1] = 1;
        
        
        for (int next = 0; next < node; next++)
        {
            if (graph[current][next] == 1 && !visited[next])
            {
                q.push(next);
                visited[next] = 1;
            }
        }
    }
    
    int num = 0;
    for (int i = 2; i <= node; i++)
    {
        if (visited[i])
            num++;
    }
    cout << num;
}

void answer() {
    cin >> node >> edge;
    
    for (int i = 0; i < edge; i++) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    
    bfs();
}
