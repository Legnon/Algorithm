//
//  b1463.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 21..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b1463_h
#define b1463_h


#endif /* b1463_h */

#define MAX 1000001

int dp[MAX];
void answer(){
    int n;
    cin >> n;
    dp[1] = 0;
    for (int i=2; i<=n; i++){
        dp[i] = dp[i-1] + 1;
        if (i%2 == 0 && dp[i/2]+1 < dp[i])
            dp[i] = dp[i/2] + 1;
        if (i%3 == 0 && dp[i/3]+1 < dp[i])
            dp[i] = dp[i/3] + 1;
    }
    cout << dp[n];
}
