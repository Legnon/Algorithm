//
//  b1208.h
//  HelloCpp
//
//  Created by Legnon on 2018. 4. 13..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b1208_h
#define b1208_h


#endif /* b1208_h */


void answer() {
    int x, ans=0;
    long y;
    scanf("%d %ld", &x, &y);
    vector<int> v(x);
    
    for (int i=0; i<x; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    
    for (int i=1; i<=x; i++) {
        vector<bool> b(x, false);
        b.clear();
        fill_n(b.begin(), i, true);
        vector<int> vb;
        do {
            long sum = 0;
            
            for (int j=0 ;j<x; j++) {
                if (b[j]) {
//                    sum += v[j];
                    vb.push_back(v[j]);
                }
            }
            
            for (int j=0; j<(INT_MAX&vb.size()); i++) {
                printf("%d ", vb[i]);
            }
            printf("\n");
            
//            if (sum == y) ans++;
        } while(prev_permutation(b.begin(), b.end()));
    }
    
    
    printf("%d", ans);
}
