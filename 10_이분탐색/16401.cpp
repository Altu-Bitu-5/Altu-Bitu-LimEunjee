#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int n, int m, vector<int> &snackList)
{
    int left = 1;
    int right = snackList[m-1];
    int mid;
    int snack = 0;
    
    while(left <= right){
        int count = 0;
        mid = (left + right) / 2;
        
        for(int i = 0; i < m; i++){
            count += snackList[i] / mid;
        }
        
        if(count >= n){
            left = mid + 1;
            snack = mid;
        }
        else if (count < n) {
            right = mid - 1;
        }
    }
    return snack;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> snackList(m);

    for(int i = 0; i < m; i++){
        cin >> snackList[i];
    }
    
    sort(snackList.begin(), snackList.end());
    
    cout << binarySearch(n, m, snackList);
}