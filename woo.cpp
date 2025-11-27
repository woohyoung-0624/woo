#include <stdio.h>      // printf, scanf 함수를 사용하기 위한 헤더
#include <stdlib.h>     // rand, srand 함수 사용을 위한 헤더
#include <time.h>       // time 함수 사용을 위한 헤더

int main(void) 
{
    int ball[3];                 // 컴퓨터가 생성할 정답 숫자 3개 저장 배열
    srand(time(NULL));           // 난수 생성기 초기화(현재 시간을 기반으로 시드 설정)

    // 중복 없는 3자리 숫자 생성 반복문
    do {
        ball[0] = rand() % 10;   // 첫 번째 난수 생성(0~9)
        ball[1] = rand() % 10;   // 두 번째 난수 생성(0~9)
        ball[2] = rand() % 10;   // 세 번째 난수 생성(0~9)
    } while (ball[0] == ball[1] || ball[0] == ball[2] || ball[1] == ball[2]);
                                 // 숫자 3개 중 하나라도 같으면 다시 생성

    printf("baseball : %d %d %d\n", ball[0], ball[1], ball[2]);  
                                 // 정답 출력 (테스트용)

    int input[3];                // 사용자가 입력한 숫자 저장용 배열
    int strike_count = 0;        // 스트라이크 개수 저장
    int ball_count = 0;          // 볼 개수 저장
    int out_count = 3;           // 아웃 개수 (총 3개에서 strike/ball만큼 감소)

    while (1)                    // strike가 나올 때까지 무한 반복
    {
        // 입력 받기
        printf("Enter the first number: ");
        scanf("%d", &input[0]);  // 첫 번째 자리 입력

        printf("Enter the second number: ");
        scanf("%d", &input[1]);  // 두 번째 자리 입력

        printf("Enter the third number: ");
        scanf("%d", &input[2]);  // 세 번째 자리 입력

        printf("input : %d %d %d\n", input[0], input[1], input[2]);  
                                    // 입력한 값 출력

        // strike / ball / out 개수 초기화
        strike_count = 0;
        ball_count = 0;
        out_count = 3;

        // strike / ball 계산
        for (int i = 0; i < 3; i++)   // 정답 숫자 3개 반복 검사
        {
            if (ball[i] == input[i])  // 위치도 같고 숫자도 같으면 strike
            {
                strike_count++;       // strike 증가
                out_count--;          // out 감소
            }
            else if (ball[i] == input[(i+1)%3] || ball[i] == input[(i+2)%3])
                                     // 위치는 다르지만 숫자가 존재하면 ball
            {
                ball_count++;         // ball 증가
                out_count--;          // out 감소
            }
        }

        // strike 3개면 게임 종료(정답)
        if (strike_count == 3)
        {
            printf("Home Run~\n");    // 홈런 메시지
            break;                    // 반복 종료
        }

        // strike/ball/out 결과 출력
        printf("%d Strike, %d Ball, %d Out\n", 
               strike_count, ball_count, out_count);

        // strike가 없을 경우 안내 메시지
        if (strike_count == 0)
        {
            printf("Strike가 없으니 다시 입력하세요!\n\n");
        }
        else                         // strike가 1~2개 있으면
        {
            printf("Strike가 있으니 일단 계속 진행합니다.\n\n");
        }
    }

    return 0;                        // 프로그램 정상 종료
}
