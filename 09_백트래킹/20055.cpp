#include <deque>
#include <iostream>

using namespace std;

struct info { // 내구도와 로봇 존재 여부
    int power;  // int형 power 변수 선언
    bool is_on; // boolean형 is_on 변수 선언
};

// 벨트를 한 칸 회전
void rotateBelt(deque<info> &belt, int n) {
    belt.push_front(belt.back());   // 제일 뒤 칸을 제일 칸으로 이동
    belt.pop_back();    // 제일 뒤 칸을 사용했기 때문에 해당 데이터를 pop
    belt[n - 1].is_on = false; // 로봇이 내리는 위치
}

// 로봇을 움직일 수 있으면 한 칸 이동
void moveRobot(deque<info> &belt, int n) {
    for (int i = n - 2; i >= 0; i--) {  // 반복문
        if (!belt[i].is_on) {   // 로봇이 있는 칸의 값이 false인경우
            continue;   // 계속 진행
        }
        
        if (!belt[i + 1].is_on && (belt[i + 1].power >= 1)) {
            // 다음 칸에 로봇이 없으면서 다음 칸에 내구도가 남아있을 때
            belt[i].is_on = false;  // 현재 로봇이 있는 칸을 반납
            belt[i + 1].is_on = true;   // 다음 칸으로 이동
            belt[i + 1].power--;    // 다음 칸의 내구도 1 감소
        }
        
        belt[n - 1].is_on = false; // 로봇이 내리는 위치
    }
}

// 올리는 칸에 로봇을 올릴 수 있으면 올림
void putRobot(deque<info> &belt) {
    if (!belt[0].is_on && belt[0].power >= 1) {
        // 올리는 칸에 로봇이 존재하지 않고, 내구도가 남아있으면
        belt[0].is_on = true;   // 해당 칸에 로봇이 올라감
        belt[0].power--;    // 해당 칸에 내구도 1 감소
    }
}

// 벨트의 내구도 체크
bool checkFinish(deque<info> &belt, int n, int k) {
    int count = 0;  // int형 count 변수 0으로 초기화
    
    for (int i = 0; i < 2 * n; i++) {   // 반복문
        if (belt[i].power == 0) {   // 해당 칸의 내구도가 남아있지 않은 경우
            count++;    // count 변수 1 증가
        }
    }

    return count >= k;  // count가 k값보다 크거나 같을 때 true값 반환
}

// 위 함수를 활용한 문제 해결을 위한 함수
int solution(deque<info> &belt, int n, int k) {
    int step = 1;   // int형 step 변수 1로 초기화
    while (true) {
        // 회전
        rotateBelt(belt, n);
        // 이동
        moveRobot(belt, n);
        // 로봇 올리기
        putRobot(belt);

        // 내구도 체크하기
        if (checkFinish(belt, n, k)) {  // checkFinish 함수에서 true 값이 반환되는 경우
            return step;    // step값 반환
        }
        step++; // step 1 증가
    }
}

int main() {
    // 입력
    int n, k;   // int형 변수 n,k 선언
    cin >> n >> k;  // 사용자의 입력으로부터 n,k 값 받음
    deque<info> belt(2 * n); // 컨베이어 벨트의 내구도와 로봇 존재 여부 저장
    for (int i = 0; i < 2 * n; i++) {   // 반복문
        cin >> belt[i].power;   // 사용자의 입력으로부터 각 칸의 내구도 값 받음
        belt[i].is_on = false;  // 아직 어느칸에도 로봇이 안 올라갔으니까 모든 칸은 false
    }
    
    // 연산
    int answer = solution(belt, n, k);
    
    // 출력
    cout << answer;
}