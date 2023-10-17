#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 8;

int n, m;
int sequence[MAX];
vector<int> nums;

void printSequence() {
    for(int i = 0; i < m; i++){
        cout << sequence[i] << " ";
    }
    cout << "\n";
}

void backtrack(int cnt) {
    // 재귀 호출 종료 조건: M개의 숫자를 다 뽑은 경우
    if (cnt == m) {
        printSequence();
        return;
    }
    
    else{
        for(int i = 1; i < nums.size(); i++){
            sequence[cnt] = nums[i-1];
            backtrack(cnt+1);
        }
    }
}


int main() {
    // 입력
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }

    // 연산
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end()-1);
    
    backtrack(0);
    
    return 0;
}