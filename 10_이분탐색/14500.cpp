#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<vector<int>>board;   //게임 보드를 저장할 전역 변수 2차원 벡터 board 선언

int ans;    //최대 점수를 저장할 전역 변수 ans 선언

void dfs(int x, int y, int depth, int sum) {    //깊이 우선 탐색

	vector<int> dx = { -1,0,1,0 };  //움직임 방향을 나타내는 벡터
	vector<int> dy = { 0,1,0,-1 };  //움직임 방향을 나타내는 벡터

	if (depth == 4) {   //칸 4개 선택했으면 ans 최대값 갱신
		ans = max(ans, sum);    //최대값으로 ans 값 업데이트
		return; // 함수 반환
	}

	for (int i = 0; i < 4; i++) {   //반복문 시작
		int nx = x + dx[i];     //이동 할 수 있는 4가지 방향 확인
		int ny = y + dy[i];     //이동 할 수 있는 4가지 방향 확인

		if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || !board[nx][ny]) { // 범위를 벗어났거나 이미 방문한 블록이라면 넘어가기
			continue;   //유효한 이동이 아니기 때문에 다음 방향으로 이동
		}

		int temp = board[nx][ny]; // 방문 처리하기 전 해당 칸 가치 저장
		board[nx][ny] = 0; // 방문 처리 : 4개를 선택함에 있어서 똑같은 블록을 선택하지 않기 위해

		// 다음 탐색 -> depth 1 증가 && sum값에 현재 칸 가치 더하기
		if (depth == 2) { // ㅜ 모양은 현재 위치에서 다시 탐색!
			dfs(x, y, depth + 1, sum + temp);
		}
		dfs(nx, ny, depth + 1, sum + temp); // 선택한 칸으로 이동

		board[nx][ny] = temp; // 이후의 케이스에서 재방문할 수 있으므로 원래대로 돌려줌

	}
}

int main() {

	// 입력
	int n, m;   //int형 변수 n과 m 선언
	cin >> n >> m;      //n과 m에 값 입력 받음
	board.assign(n, vector<int>(m, 0));    //게임의 보드 크기 입력


	for (int i = 0; i < n; i++) {   //반복문 시작
		for (int j = 0; j < m; j++) {      //이중 반복문 시작
			cin >> board[i][j];     //보드 각 셀의 값을 입력
		}
	}

	// 연산
	for (int i = 0; i < n; i++) {   //반복문 시작 
		for (int j = 0; j < m; j++) {   //이중 반복문 시작
			int temp = board[i][j];     //값을 일시적으로 제거하기 전에 temp에 저장
			board[i][j] = 0;    //값을 일시적으로 제거
			dfs(i, j, 1, temp);     //함수 호출해가능한 테트로미노 조합 확인
			board[i][j] = temp;     // 값 복원
		}
	}

	// 출력 
	cout << ans;    //dfs 탐색 결과 중 최대 점수를 출력
	return 0;
}