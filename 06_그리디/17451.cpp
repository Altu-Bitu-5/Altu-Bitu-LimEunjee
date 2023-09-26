#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    double speed;
    cin >> n;
    vector<double> spaceshuttle;
    
    for(int i = 0; i < n; i++){
        cin >> speed;
        spaceshuttle.push_back(speed);
    }
    
    speed = spaceshuttle[n-1];
    for(int i = n-1; i > 0; i--){
        speed = ceil(speed/spaceshuttle[i-1]) * spaceshuttle[i-1];
    }
    
    cout << (ll)speed;
    
    return 0;
}