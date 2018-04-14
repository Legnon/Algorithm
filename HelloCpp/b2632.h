//
//  b2632.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 27..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b2632_h
#define b2632_h


#endif /* b2632_h */

int dA[1000][1000];
int dB[1000][1000];

void answer() {
    int size;
    int m, n;
    cin >> size;
    cin >> m >> n;
    
    vector<int> A(m), B(n);
    for(int i = 0; i < m; ++i) {
        cin >> A[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> B[i];
    }
    
    vector<int> first, second;
    // A 피자
    for(int i = 0; i < A.size(); ++i) {
        dA[0][i] = A[i];
        first.push_back(dA[0][i]);
    }
    for(int i = 1; i < A.size()-1; ++i) {
        for(int j = 0; j < A.size(); ++j) {
            dA[i][j] = dA[i-1][j] + A[(i+j)%m];
            first.push_back(dA[i][j]);
        }
    }
    first.push_back(0);
    first.push_back(std::accumulate(A.begin(), A.end(), 0));
    
    // B 피자
    for(int i = 0; i < B.size(); ++i) {
        dB[0][i] = B[i];
        second.push_back(dB[0][i]);
    }
    for(int i = 1; i < B.size()-1; ++i) {
        for(int j = 0; j < B.size(); ++j) {
            dB[i][j] = dB[i-1][j] + B[(i+j)%n];
            second.push_back(dB[i][j]);
        }
    }
    second.push_back(0);
    second.push_back(accumulate(B.begin(), B.end(), 0));
    
    sort(second.begin(), second.end());
    int ans = 0;
    for(int i: first) {
//        auto range = equal_range(second.begin(), second.end(), size-i);
//        ans += range.second - range.first;
        for (int j: second) {
            if (i+j == size) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    
}
