#include <iostream>
#include <vector>

using namespace std;
const int max_num = 100001;

int maxLength(int n, int k, vector<int>& list)
{
    vector<int> count(max_num, 0);
    int max_length = 0;
    int left = 0;
    
    for(int right = 0; right < n; right++){
        count[list[right]] += 1;
        
        while(count[list[right]] > k){
            count[list[left]] -= 1;
            left++;
        }
        max_length = max(max_length, right-left+1);
    }
    return max_length;
}


int main()
{
    int n, k, result;
    cin >> n >> k;
    
    vector<int> list(n);
    for(int i = 0; i < n; i++){s
        cin >> list[i];
    }
    
    result = maxLength(n, k, list);
    cout << result;

    return 0;
}