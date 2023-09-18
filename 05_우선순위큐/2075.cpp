#include <iostream>
#include <queue>

using namespace std;

struct cmp{
    bool operator() (int x1, int x2){
        return x1 > x2;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int n, num;
    cin >> n;
    
    priority_queue<int, vector<int>, cmp> heap;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> num;
            heap.push(num);
        }
        while(heap.size() > n){
            heap.pop();
        }
    }
    
    cout << heap.top();

    return 0;
}