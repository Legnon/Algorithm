//
//  b9663.h
//  HelloCpp
//
//  Created by Legnon on 2018. 4. 10..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b9663_h
#define b9663_h


#endif /* b9663_h */

int v[16], cnt, n;

bool promising(int r, int c) {
    for (int i=1; i<r; i++) {
        if (v[i] == c) return false;
        if (abs(v[i] - c) == abs(r - i)) return false;
    }
    return true;
}

void dfs(int r, int c) {
    v[r] = c;
    if (r == n) cnt++;
    else {
        for (int i=1; i<=n; i++) {
            if (promising(r+1,i))
                dfs(r+1, i);
        }
    }
}

void answer() {
    cin >> n;
    
    for (int i=1; i<=n; i++) {
        dfs(1, i);
    }
    cout << cnt << endl;
}
