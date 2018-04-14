//
//  dfs.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 22..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef dfs_h
#define dfs_h


#endif /* dfs_h */


vector<vector<int>> adj;
vector<bool> visited;

int n;

void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void sortList(){
    for (int i=0; i<n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
}

void dfs(int s){
    visited[s] = true;
    cout << "current node " << s << " visited" << endl;
    for (int next: adj[s]) if(!visited[next]) dfs(next);
}

void dfs(){
    fill(visited.begin(), visited.end(), false);
    dfs(0);
}

void answer(){
    scanf("%d", &n);
    adj.resize(n);
    visited.resize(n);
    
    for (int i=0; i<n; i++){
        int u,v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
        
    dfs();
    
}
