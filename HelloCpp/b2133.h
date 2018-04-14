//
//  b2133.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 24..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b2133_h
#define b2133_h


#endif /* b2133_h */

#define MAX 31

int dp[MAX];

void answer() {
    int n;
    cin >> n;
    
    dp[2] = 3;
    dp[4] = 8;
    
    for (int i=6; i<=n; i++) {
        dp[i] = dp[i-2]*6 + dp[i-4]*4;
    }
    
    cout << dp[n];
}
