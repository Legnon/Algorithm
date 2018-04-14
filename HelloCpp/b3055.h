//
//  b3055.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 22..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef b3055_h
#define b3055_h


#endif /* b3055_h */

#define DEST 1000

int x,y;
int **graph;
int finish = 0;

queue<pair<int, int >> d;
queue<pair<int, int >> w;
queue<pair<int, int >> d1;
queue<pair<int, int >> w1;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int water_bfs();
int dochi_bfs();
int max_num = 999;

int bfs() {
    while( ( !w.empty() || !d.empty() ) && finish == 0 ){
        
        // 물과 고슴도치 이동을 한번씩 돌아가면서 하기 위해서 두개의 큐 사용
        // 새로 저장되는 것은 d1,w1에 하고 꺼내서 확인하는 것은 d,w로 함
        // 한번 BFS가 실행될때마다 d1에 있는것을 꺼내와 d에 넣고 d1는 비움
        swap(d1, d);
        while (!d1.empty()) d1.pop();
        
        swap(w1, w);
        while (!w1.empty()) w1.pop();
        
        // 물 BFS
        water_bfs();
        // 고슴도치 BFS
        dochi_bfs();
    }
    
    // 종료시 결과 값 출력
    if (finish == 0){
        cout << "KAKTUS" << endl;
        return 0;
    }
    else {
        cout << finish-1 << endl;
        return 0;
    }
}

// 물 BFS
int water_bfs(){
    
    while (!w.empty()) {
        int curr[2] = {w.front().first, w.front().second};
        w.pop();
        
        // 인접한 땅 동서남북 4방향 체크
        for (int i=0; i<4; i++) {
            int _x = curr[0]+dx[i];
            int _y = curr[1]+dy[i];
            
            // 인덱스 초과하는 경우 continue
            if ( _x<0 || _x>=x || _y<0 || _y>=y ) {
                continue;
            }
            
            // 목적지가 아닌 빈 땅인 경우 물로 채움
            if (graph[_x][_y] > 1 && graph[_x][_y] < DEST) {
                graph[_x][_y] = 1;
                w1.push({_x, _y});
            }
        }
    }
    
    return 0;
}

// 고슴도치 BFS
int dochi_bfs(){
    
    if (finish == 0){
        while (!d.empty()) {
            int curr[2] = {d.front().first, d.front().second};
            d.pop();
            
            // 원래 땅이었는데 물로 채워진 경우 continue
            if (graph[curr[0]][curr[1]] == 1) continue;
            
            // 인접한 땅 동서남북 4방향 체크
            for (int i=0; i<4; i++) {
                int _x = curr[0]+dx[i];
                int _y = curr[1]+dy[i];
                
                if ( _x<0 || _x>=x || _y<0 || _y>=y ) {
                    continue;
                }
                
                if (graph[_x][_y] == 2) { // 빈 땅인 경우
                    // 빈 땅인 경우 그 땅이 물이랑 붙어 있는지 확인
                    for (int i=0; i<4; i++) {
                        int next_x = _x+dx[i];
                        int next_y = _y+dy[i];
                        
                        if ( next_x<0 || next_x>=x || next_y<0 || next_y>=y ) {
                            continue;
                        }
                        // 물이랑 붙어있지 않으면 전진
                        if ( graph[next_x][next_y] != 1 && graph[next_x][next_y] != DEST ) {
                            graph[_x][_y] = graph[curr[0]][curr[1]] + 1;
                            d1.push({_x, _y});
                        }
                        // 빈땅 앞에 목적지 찾으면 종료
                        if ( graph[next_x][next_y] == DEST ) {
                            finish = graph[curr[0]][curr[1]];
                            
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}
void answer() {
    // 가로 세로 받음
    scanf("%d %d", &x, &y);
    graph = new int*[x];
    for (int i=0; i<x; i++)
        graph[i] = new int[y];
    
    // 그래프화
    for (int i=0; i<x; i++){
        string s;
        cin >> s;
        char* c = new char[y];
        s.copy(c, y);
        for (int j=0; j<y; j++) {
            if (c[j] == 'X') graph[i][j] = 0;  // blocked
            if (c[j] == '*') graph[i][j] = 1;  // water
            if (c[j] == '.') graph[i][j] = 2;  // empty
            if (c[j] == 'S') graph[i][j] = 3;  // departure
            if (c[j] == 'D') graph[i][j] = DEST;  // destination
        }
        delete [] c;
    }
    
    // 초기화
    for (int i=0; i<x; i++)
        for (int j=0; j<y; j++) {
            if (graph[i][j] == 3){
                d1.push({i,j});
            }
            if (graph[i][j] == 1){
                w1.push({i,j});
            }
            
        }
    
    bfs();
    
}
