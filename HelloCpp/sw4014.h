//
//  sw4014.h
//  HelloCpp
//
//  Created by Legnon on 2018. 4. 13..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef sw4014_h
#define sw4014_h


#endif /* sw4014_h */
int check(int x, int n, vector<int> v, int j) {
    for (int i = j; i < x-1; i++) {
//        printf("i=%d, v[i]=%d, v[i+1]=%d\n", i, v[i], v[i+1]);
        if ( abs(v[i] - v[i+1]) > 1 ) { // 차이 2이상
            return 0; // 안 더함
        }
        else if (v[i]+1 == v[i+1]) { // up
            for (int k=0; k<n; k++) {
                if (i-k >= j && v[i] == v[i-k]) {
                    
                }
                else {
                    return 0;
                }
            }
            if (i+1 == x-1) return 1; // 올라가는 거----- 마지막까지 가면 리턴 1
            return check(x, n, v, i+1); // 올라가
        }
        else if (v[i] == v[i+1]+1) { // down
//            printf("??안떨어짐?\n");
            for (int k=1; k<n; k++) {
                if (i+k+1 < x && v[i+1] == v[i+k+1]) {
//                    printf("down, %d\n", i+k+1);
                }
                else {
                    return 0;
                }
            }
            if (i+n == x-1) // 떨어지는거 ---- 마지막인 경우 리턴 1
            {
//                printf("return 1");
                return 1;
            }
            else if (v[i+n] == v[i+n+1])  // 평지인 경우 다음부터 check
                return check(x, n, v, i+n+1);
            else if (v[i+n] == v[i+n+1]+1)  // 경사 떨어지면 현재 자리부터
                return check(x, n, v, i+n);
            else  // 2이상 떨어지거나 올라가는 경우 리턴 0
                return 0;
        }
    }
    return 1;
}

void answer(int T) {
    int ans=0, x, y;
    
    scanf("%d %d", &x, &y);
    vector<vector<int>> v(x, vector<int>(x));
    vector<vector<int>> v2(x, vector<int>(x));
    
    for (int i=0; i<x; i++) {
        for (int j=0; j<x; j++) {
            int k;
            scanf("%d", &k);
            v[i][j] = v2[j][i] = k;
        }
    }
    
    
    for (int i=0; i<x; i++) {
//        printf("i = %d\n", i);
        ans += check(x, y, v[i], 0);
        ans += check(x, y, v2[i], 0);
    }
    
    printf("#%d %d\n", T, ans);
}
