//
//  b10819.h
//  HelloCpp
//
//  Created by Legnon on 2018. 4. 10..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b10819_h
#define b10819_h


#endif /* b10819_h */

void answer() {
    int x=0, highest=0;
    cin >> x;
    vector<int> a(x);
    
    for (int i=0; i<x; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int sum = 0;
    do {
        for (int i=0; i<x; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i=1; i<x; i++) {
            sum += abs(a[i-1]-a[i]);
        }
        if (sum > highest) highest = sum;
        sum = 0;
    } while(next_permutation(a.begin(), a.end()));
    cout << highest;
}
