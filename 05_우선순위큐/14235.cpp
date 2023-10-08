#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int n, a, present;
    cin >> n;
    
    priority_queue<int> heap;
    
    while(n--)
    {
        cin >> a;
        if(a == 0){
            if(heap.empty()){
                cout << "-1\n";
            }
            else{
                cout << heap.top() << "\n";
                heap.pop();
            }
        }
        else{
            for(int i = 0; i < a; i++){
                cin >> present;
                heap.push(present);
            }
        }
    }
    
    return 0;
}