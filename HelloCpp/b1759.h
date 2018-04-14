//
//  b1759.h
//  HelloCpp
//
//  Created by Legnon on 2018. 4. 11..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b1759_h
#define b1759_h


#endif /* b1759_h */


void answer() {
    int x, y;
    cin >> x >> y;
    
    vector<char> alphabet(y);
    vector<bool> v(y);
    vector<string> sv;
    fill_n(v.begin(), x, true);
    
    for (int i=0; i<y; i++) {
        cin >> alphabet[i];
    }
    
    sort(alphabet.begin(), alphabet.end());
    
    do {
        string s = "";
        int cnt = 0;
        for (int i=0; i<y; i++) {
            if (v[i]) {
                if (!(std::strncmp(&alphabet[i], "a", 1) && std::strncmp(&alphabet[i], "e", 1) && std::strncmp(&alphabet[i], "i", 1) && std::strncmp(&alphabet[i], "o", 1) && std::strncmp(&alphabet[i], "u", 1)))
                    cnt++;
                s += alphabet[i];
            }
        }
        
//        vector<string> :: iterator it;
//        it =  find(sv.begin(), sv.end(), s);
//        if (cnt > 0 && cnt < x-1 && !(it != sv.end())) {
//            sv.push_back(s);
//        }
        
        if (cnt > 0 && cnt < x-1)
            cout << s << endl;
    } while (prev_permutation(v.begin(), v.end()));
    
}

