//
//  b11726.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 23..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b11726_h
#define b11726_h


#endif /* b11726_h */

#define MAX 1001

int dp[MAX];

void answer(){
    int n;
    cin >> n;
    dp[1] = 1; dp[2] = 2;
    for (int i=3; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    cout << dp[n];
}
