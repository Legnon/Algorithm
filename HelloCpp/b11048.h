//
//  b11048.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 24..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b11048_h
#define b11048_h
#define MAX 1001

#endif /* b11048_h */

int dp[MAX][MAX];
int d[MAX][MAX];

void answer() {
    int m, n;
    cin >> m >> n;
    
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            scanf("%d", &dp[i][j]);
        }
    }
    d[1][1] = dp[1][1];
    
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (j == 1) d[i][j] = d[i-1][j] + dp[i][j];
            else if (i == 1) d[i][j] = d[i][j-1] + dp[i][j];
            else d[i][j] = max(d[i-1][j], d[i][j-1]) + dp[i][j];
        }
    }
    
    cout << d[m][n];
}
