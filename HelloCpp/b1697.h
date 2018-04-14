//
//  b1697.h
//  HelloCpp
//
//  Created by Legnon on 2018. 4. 10..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b1697_h
#define b1697_h


#endif /* b1697_h */


int visited[140001];

int answer() {
    int x, y, z;
    cin >> x >> y >> z;
    
    queue<int> q;
    q.push(x);
    
    visited[x] = 1;
    
    while (!q.empty()) {
        
        int k = q.front();
        q.pop();
        
        if (k == y){
            cout << visited[k] - 1;
            return 0;
        }
        
        if (k-1 > 0 && visited[k-1] == 0) {
            q.push(k-1);
            visited[k-1] = visited[k] + 1;
        }
        if (k+1 <= z && visited[k+1] == 0) {
            q.push(k+1);
            visited[k+1] = visited[k] + 1;
        }
        if (2*k <= z && visited[k*2] == 0) {
            q.push(2*k);
            visited[k*2] = visited[k] + 1;
        }
        
    }
    return 0;
}
