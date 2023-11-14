#include <iostream>
#include <vector>

using namespace std;
const int max_n = 50;
const int max_m = 50;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int cleanRoom(int n, int m, int robotr, int robotc, int robotf, int room[max_n][max_m])
{
    int count = 0;
    
    while (true) {
        if (room[robotr][robotc] == 0) {
            room[robotr][robotc] = -1;
            count++;
        }

        if (room[robotr - 1][robotc] != 0 && room[robotr][robotc + 1] != 0 &&
            room[robotr + 1][robotc] != 0 && room[robotr][robotc - 1] != 0) {
            int backr = robotr - dx[robotf];
            int backc = robotc - dy[robotf];
            if (room[backr][backc] == 1) {
                break;
            }
            robotr = backr;
            robotc = backc;
        } else {
            robotf = (robotf + 3) % 4;
            int nextr = robotr + dx[robotf];
            int nextc = robotc + dy[robotf];
            
            if (room[nextr][nextc] == 0) {
                robotr = nextr;
                robotc = nextc;
            }
        }
    }

    return count;
}


int main()
{
    int n, m, result, robot_r, robot_c, robot_f;
    int room[max_n][max_m];
    cin >> n >> m;
    cin >> robot_r >> robot_c >> robot_f;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> room[i][j];
        }
    }
    
    result = cleanRoom(n, m, robot_r, robot_c, robot_f, room);
    cout << result;

    return 0;
}