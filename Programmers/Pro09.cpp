#include <vector>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<vector<int>> pictureDFS;
int width, height;
    
int dfs(int y, int x, int tempVal) {
    if(pictureDFS[y][x] == 0 || pictureDFS[y][x] != tempVal) {
        return 0;
    }
    
    pictureDFS[y][x] = 0;
    int result = 1;
    
    for(int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
            
        if(next_x < 0 || next_x > width-1 || next_y < 0 || next_y > height-1) {
            continue;
        } else {
            result += dfs(next_y, next_x, tempVal);
        }
    }
    
    return result;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2);
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int tempSize = 0;
    
    //init
    pictureDFS = picture;
    max_size_of_one_area = 0;
    width = n;
    height = m;
    
    //dfs
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(pictureDFS[i][j] != 0) {
                number_of_area += 1;
                tempSize = dfs(i, j, pictureDFS[i][j]);
                
                if(max_size_of_one_area < tempSize) {
                    max_size_of_one_area = tempSize;
                }
            }
        }
    }
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}
