#include <iostream>

using namespace std;
const int MAX = 256;

int main()
{
    int width, length, inventory, min_time, max_heihgt = 0;
    cin >> length >> width >> inventory;
    
    int minecraft[length][width];
    for(int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            cin >> minecraft[i][j];
        }
    }
    
    int times[MAX+1];
    for(int i = 0; i <= MAX; i++){
        times[i] = -1;
    }
    
    for(int h = 0; h <= MAX; h++){
        int add = 0;
        int sub = 0;
        for(int i = 0; i < length; i++){
            for(int j = 0; j < width; j++){
                int temp = minecraft[i][j] - h;
                if(temp >= 0){
                    sub += temp;
                }
                else{
                    add -= temp;
                }
            }
        }
        if(sub + inventory >= add){
            times[h] = sub * 2 + add;
        }
    }
    
    min_time = times[0];
    for(int i = 1; i <= MAX; i++){
        if(times[i] != -1 && min_time >= times[i]){
            min_time = times[i];
            max_heihgt = i;
        }
    }
    
    cout << min_time << " " << max_heihgt;

    return 0;
}