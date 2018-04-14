//
//  sw3812.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 24..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef sw3812_h
#define sw3812_h


#endif /* sw3812_h */

void answer(int test_case){
    int k[8];
    int k2[1000]={0,};
    
    cin >> k[0] >> k[1] >> k[2] >> k[3] >> k[4] >> k[5] >> k[6];
    
    //        string s;
    //        cin.ignore();
    //        getline(cin, s);
    //
    //        istringstream iss(s);
    //        int j=0;
    //        while (iss) {
    //            string sub;
    //            iss >> sub;
    //            k[j] = atoi(sub.c_str());
    ////            cout << k[j] << endl;
    //            j++;
    //        }
    
    for (int a=0; a<k[0]; a++){
        for (int b=0; b<k[1]; b++){
            for (int c=0; c<k[2]; c++){
                int one,two,three,i;
                
                if (a >= k[3]) one = a-k[3];
                else one = k[3]-a;
                
                if (b >= k[4]) two = b-k[4];
                else two = k[4]-b;
                
                if (c >= k[5]) three = c-k[5];
                else three = k[5]-c;
                
                i = one + two + three;
                
                i %= k[6];
                
                k2[i] += 1;
            }
        }
    }
    cout << "#" << test_case << " ";
    
    for (int i = 0; i < k[6]; i++){
        cout << k2[i];
        if (i != k[6]) cout << " ";
    }
    cout<<endl;
}
