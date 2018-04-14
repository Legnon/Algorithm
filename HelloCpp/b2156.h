//
//  b2156.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 24..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b2156_h
#define b2156_h


#endif /* b2156_h */

#define MAX 10001

int dp[MAX];
long d[MAX];

void answer() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        scanf("%d", &dp[i]);
    }
    d[1] = dp[1];
    if (n >= 2) d[2] = dp[1]+dp[2];
    if (n >= 3) d[3] = max(dp[1]+dp[2], max(dp[2]+dp[3], dp[1]+dp[3]));
    
//    cout << dp[3] << endl;
    
    for (int i=4; i<=n; i++) {
        d[i] = max(d[i-1], max(d[i-2]+dp[i], d[i-3]+dp[i]+dp[i-1]));
    }
    
    cout << d[n] << endl;
}
