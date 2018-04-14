//
//  b2579.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 28..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b2579_h
#define b2579_h


#endif /* b2579_h */


int dp[300];
int a[300][2];
int n;

void answer() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &dp[i]);
    
    a[0][0] = 0;
    a[0][1] = dp[0];
    a[1][0] = dp[0];
    a[1][1] = dp[0]+dp[1];
    a[2][0] = a[1][1];
    a[2][1] = max(dp[0], dp[1]) + dp[2];
    
    for (int i=3; i<n; i++) {
        a[i][0] = a[i-1][1];
        a[i][1] = max(a[i-3][1]+dp[i-1], a[i-2][1]) + dp[i];
    }
//
//    for (int i=0; i<n; i++) {
//        cout << i << "0: " << a[i][0] << endl;
//        cout << i << "1: " << a[i][1] << endl;
//    }
    
    printf("%d", a[n-1][1]);
}
