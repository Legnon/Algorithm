//
//  b9466.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 22..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b9466_h
#define b9466_h


#endif /* b9466_h */

vector<vector<int>> adj;
vector<bool> visited;
vector<bool> finished;
int n, cnt=0;
int _cnt = 0;

void dfs(int s) {
    visited[s] = 1;
    int next = adj[s].front();
    if (visited[next]){
        if(!finished[next]){
            while (s != next && !finished[next]){
                finished[s] = 1;
                s = next;
                next = adj[next].front();
                _cnt++;
            }
//            if (next == adj[next].front()){
                _cnt++;
//            }
        }
    } else {
        dfs(next);
    }
    finished[s] = 1;
}

void dfs(){
    std::fill(visited.begin(), visited.end(), false);
    std::fill(finished.begin(), finished.end(), false);
    for (int i=0; i<n; i++){
        dfs(i);
    }
    cout << n-_cnt << endl;
}

void answer(int test_case){
    scanf("%d", &n);
    
    adj.resize(n);
    visited.resize(n);
    finished.resize(n);
    
    for (int i=0; i<n; i++){
        int j;
        scanf("%d", &j);
        adj[i].push_back(j-1);
    }
    
    dfs();
}
