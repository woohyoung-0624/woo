#include <stdio.h>      // printf, scanf를 사용하기 위해 필요한 헤더 파일
#include <stdlib.h>     // rand, srand 함수를 사용하기 위한 헤더 파일
#include <time.h>       // time 함수를 사용하기 위한 헤더 파일

int main(void)          // 프로그램의 시작점인 main 함수
{                       // main 함수 시작
    int ball[3];        // 3개의 서로 다른 난수를 저장할 배열
    srand(time(NULL));  // 현재 시간을 기준으로 난수 생성기 초기화

    // 중복 없는 3자리 난수 생성 (각 자리는 0~9)
    do {
        ball[0] = rand() % 10;  // 첫 번째 난수 생성
        ball[1] = rand() % 10;  // 두 번째 난수 생성
        ball[2] = rand() % 10;  // 세 번째 난수 생성
    } while (ball[0] == ball[1] || ball[0] == ball[2] || ball[1] == ball[2]); 
    // 세 수 중 하나라도 중복되면 다시 난수 생성

    // printf("baseball : %d %d %d\n", ball[0], ball[1], ball[2]); // 정답 확인용(테스트시만 사용)

    int input[3];               // 사용자가 입력한 숫자 3개 저장 배열
    int strike_count = 0;       // strike 개수 저장 변수
    int ball_count = 0;         // ball 개수 저장 변수
    int out_count = 0;          // out 개수 저장 변수
    int try_count = 0;          // 시도 횟수 저장 변수

    clock_t start, end;         // 게임 시간 측정을 위한 clock 변수
    start = clock();            // 게임 시작 시간 기록

    while (1) {                 // 정답을 맞출 때까지 무한 반복
        printf("\n숫자 3개를 입력하세요 (공백으로 구분): ");
        scanf("%d %d %d", &input[0], &input[1], &input[2]);  
        // 사용자로부터 숫자 3개 입력 받기

        strike_count = 0;       // 이번 판정용 strike 초기화
        ball_count = 0;         // 이번 판정용 ball 초기화

        // strike, ball 판단
        for (int i = 0; i < 3; i++) {  // input의 각 자리 비교
            if (input[i] == ball[i]) { 
                strike_count++;         // 숫자와 위치 모두 같으면 strike
            } else if (input[i] == ball[(i+1)%3] || input[i] == ball[(i+2)%3]) {
                ball_count++;           // 숫자는 같으나 위치 다르면 ball
            }
        }

        out_count = 3 - (strike_count + ball_count);  // 남은 수는 out 계산
        
        try_count++;               // 시도 횟수 증가

        if (strike_count == 3) {   // 모든 자리가 맞으면 게임 종료
            end = clock();         // 게임 종료 시간 기록            
            double elapsed_sec = (double)(end - start) / CLOCKS_PER_SEC;  
            // 경과 시간 계산 (초 단위)

            printf("Home Run! %d번 만에 맞췄습니다!\n", try_count);
            printf("%f 초 시간이 걸렸습니다.\n", elapsed_sec);
            break;                 // 반복문 종료 → 프로그램 종료
        } else {
            printf("%d Strike, %d Ball, %d Out\n", strike_count, ball_count, out_count);
            // 현재 판정 결과 출력
        }
    }

    return 0;   // 프로그램 정상 종료
}               // main 함수 끝
