//
//  b9019.h
//  HelloCpp
//
//  Created by Legnon on 2018. 4. 9..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b9019_h
#define b9019_h


#endif /* b9019_h */

bool visited[10001]={false,};
queue<pair<int,string>> q;

void bfs(int output) {
    while (!q.empty()) {
        int num = q.front().first;
        string s = q.front().second;
        
        if (num == output) break;
        
//        cout << num << endl << s << endl;
        
        q.pop();
        
        if (visited[num]) continue;
        
        visited[num] = true;
            
        for (int i=0; i<4; i++) {
            if (i == 0) { // D
                int k = (num * 2) % 10000;
                q.push(make_pair(k, s+"D"));
            }
            else if (i == 1) { // S
                int k = num - 1;
                if (num == 0) k += 10000;
                q.push(make_pair(k, s+"S"));
            }
            else if (i == 2) { // L
                int k = num * 10;
                k += k / 10000;
                k %= 10000;
                q.push(make_pair(k, s+"L"));
            }
            else if (i == 2) { // R
                int l = num % 10;
                int k = num / 10;
                k += l * 1000;
                q.push(make_pair(k, s+"R"));
            }
        }
    }
    cout << q.front().second << endl;
}

void answer() {
    int x,y;
    cin >> x >> y;
    
//    cout << x << endl << y << endl;
    
    q.push(make_pair(x,""));
    bfs(y);
}
