//
//  b11057.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 24..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b11057_h
#define b11057_h


#endif /* b11057_h */

int dp[1001][10];
void answer() {
    int n;
    cin >> n;
    for (int i=0; i<=9; i++) {
        dp[1][i] = 1;
    }
    for (int i=2; i<=n; i++) {
        for (int j=0; j<=9; j++) {
            for (int k=0 ;k<=j; k++) {
                dp[i][j] = ( dp[i][j] + dp[i-1][j-k] ) % 10007;
            }
        }
    }
    int d = 0;
    for (int i=0; i<=9; i++){
        d += dp[n][i];
    }
    cout << d % 10007;
}
