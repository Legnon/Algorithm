//
//  sw3977.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 24..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef sw3977_h
#define sw3977_h


#endif /* sw3977_h */

int n;

void answer(int test_case){
    scanf("%d",&n);
    int *dp = new int[n+1];
    for (int i=0; i<=n; i++)
        dp[i] = 1000000000;
    dp[1] = 1;
    for (int i=1; i<n+1; i++){
        dp[i*2] = min(dp[i*2],dp[i]+1);
        dp[i*2+1] = min(dp[i*2+1],dp[i]+1);
    }
    string s = (dp[n]%2) ? "Alice" : "Bob";
    cout << "#" << test_case<< s <<endl;
}
