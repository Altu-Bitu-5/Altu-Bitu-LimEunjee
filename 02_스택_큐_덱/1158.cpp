#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    queue<int>q;
    for(int i = 1; i < N+1; i++)
        q.push(i);
        
    cout << "<";
        
    while(q.size() > 0)
    {
        if(q.size() == 1)
        {
            cout << q.front() << ">\n";
            q.pop();
            break;
        }
        
        for(int i = 1; i < K; i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }
    
    return 0;
}
