#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int n, int card, vector<int> &cardList)
{
    int left = 0;
    int right = n-1;
    int mid;
    
    while(left <= right){
        mid = (left + right) / 2;
        if(cardList[mid] == card){
            return 1;
        }
        else if(cardList[mid] > card){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return 0;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int n, m, card;
    cin >> n;
    vector<int> cardList(n);

    for(int i = 0; i < n; i++){
        cin >> cardList[i];
    }
    sort(cardList.begin(), cardList.end());
    
    cin >> m;
    while(m--){
        cin >> card;
        cout << binarySearch(n, card, cardList) << " ";
    }
}