//
//  b10844.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 24..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b10844_h
#define b10844_h


#endif /* b10844_h */

long long mod = 1000000000;
long long dp[101][10];
void answer() {
    int n;
    cin >> n;
    for (int i=1; i<=9; i++) {
        dp[1][i] = 1;
    }
    for (int i=2; i<=n; i++) {
        for (int j=0; j<=9; j++) {
            if (j+1 <= 9) dp[i][j] += dp[i-1][j+1];
            if (j-1 >= 0) dp[i][j] += dp[i-1][j-1];
            dp[i][j] %= mod;
        }
    }
    unsigned long answer = 0;
    for (int i=0; i<=9; i++) answer += dp[n][i];
    
    cout << answer;
}
