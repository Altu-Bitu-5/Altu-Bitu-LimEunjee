#include <iostream>
#include <vector>

using namespace std;

int maxSushi(int n, int d, int k, int c, vector<int>& belt)
{
    vector<int> count(d+1, 0);
    int plate = 0;
    int max_plate = 0;
    
    for(int i = 0; i < k; i++){
        if(count[belt[i]] == 0){
            plate += 1;
        }
        count[belt[i]] += 1;
    }

    for(int i = 0; i < n; i++){
        count[belt[i]] -= 1;
        if(count[belt[i]] == 0){
            plate -= 1;
        }
        
        int temp = (i+k) % n;
        count[belt[temp]] += 1;
        if(count[belt[temp]] == 1){
            plate += 1;
        }
        
        if(count[c] == 0){
            max_plate = max(max_plate, plate + 1);
        }
        else{
            max_plate = max(max_plate, plate);
        }
        
    }
    return max_plate;
}


int main()
{
    int n, d, k, c, result;
    cin >> n >> d >> k >> c;
    
    vector<int> belt(n);
    for(int i = 0; i < n; i++){
        cin >> belt[i];
    }
    
    result = maxSushi(n, d, k, c, belt);
    cout << result;

    return 0;
}