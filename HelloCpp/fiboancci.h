//
//  fiboancci.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 23..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef fiboancci_h
#define fiboancci_h


#endif /* fiboancci_h */

// DP없이 재귀로 구하는 피보나치
int fibonacci(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n == 0) {
        return 0;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// DP를 이용한 피보나치
int memo[100];
int fibonacci_topdown(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n == 0) {
        return 0;
    }
    else {
        if (memo[n] > 0)
            return memo[n];
        memo[n] = fibonacci(n-1) + fibonacci(n-2);
        return memo[n];
    }
}

int dp[100];
int fibonacci_bottomup(int n) {
    dp[0] = 0;
    dp[1] = 1;
    for (int i=0; i<n; i++) {
        dp[n] = dp[i-2] + dp[i-1];
    }
    return dp[n];
}
