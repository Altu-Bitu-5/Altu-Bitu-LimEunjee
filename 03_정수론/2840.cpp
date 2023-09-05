#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 입력
    int n, k, s, check, result;
    char letter;
    cin >> n >> k;

    char luckywheel[25];
    fill_n(luckywheel, 25, '?');
    check = n - 1;
    // 연산
    while(k--)
    {
        cin >> s >> letter;
        
        s %= n;
        if (check - s >= 0) {
            check -= s;
        }
        else {
            check = (check - s) + n;
        }

        if (luckywheel[check] == '?' || luckywheel[check] == letter) {
            luckywheel[check] = letter;
        }
        else {
            cout << "!\n";
            return 0;
        }
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (luckywheel[i] == '?') {
                continue;
            }
            if (luckywheel[i] == luckywheel[j]) {
                cout << "!\n";
                return 0;
            }
        }
    }

    // 출력
    for (int i = 0; i < n; i++)
    {
        if (check + i >= n) {
            check -= n;
        }
        cout << luckywheel[check+i];
    }

    return 0;
}