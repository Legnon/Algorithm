//
//  b1799.h
//  HelloCpp
//
//  Created by Legnon on 2018. 4. 12..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b1799_h
#define b1799_h


#endif /* b1799_h */

int n;
vector<pair<int, pair<int, int>>> v1, v2;
int highest, sum;

bool promising(int num, vector<pair<int, pair<int, int>>> v) {
    for (int i=0; i<num; i++) {
        if (v[i].first == 0) continue;
        if (abs(v[i].second.first-v[num].second.first) == abs(v[i].second.second-v[num].second.second))
            return false;
    }
    return true;
}

void dfs(int num, vector<pair<int, pair<int, int>>> v) {
    v[num].first = 1;
    sum++;
    
    if (sum > highest) {
        highest = sum;
    }
    
    for (int i=num+1; i<(INT_MAX&v.size()); i++) {
        if (promising(i, v)) {
            dfs(i, v);
            v[num].first = 0;
            sum--;
        }
    }
    
    v[num].first = 0;
}

void answer() {
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int k;
            scanf("%d", &k);
            if (k == 1 && ((i+j)%2 == 0)) v1.push_back({0,{i,j}});
            if (k == 1 && ((i+j)%2 == 1)) v2.push_back({0,{i,j}});
        }
    }
    for (int i=0; i<(INT_MAX&v1.size()); i++) {
        dfs(i, v1);
        sum--;
    }
    int highest1 = highest;
    highest = 0;
    sum = 0;
    for (int i=0; i<(INT_MAX&v2.size()); i++) {
        dfs(i, v2);
        sum--;
    }
    
    printf("%d", highest+highest1-1);
}
