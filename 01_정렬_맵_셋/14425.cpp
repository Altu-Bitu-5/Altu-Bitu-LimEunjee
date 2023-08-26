#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N, M;
    int count = 0;
    string str;
    map<string, int> check_map;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        check_map.insert(pair<string, int>(str, 1));
    }

    for (int i = 0; i < M; i++)
    {
        cin >> str;
        if (check_map[str] == 1)
            count++;
    }

    cout << count;

    return 0;
}
