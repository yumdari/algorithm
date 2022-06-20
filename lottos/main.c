#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.


    int* answer = (int*)malloc(1);
    return answer;
}

int test(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    int flag = 0;
    for (int idx = 0; idx < lottos_len; idx++) {
        if (lottos[idx] == 0) {
            flag++;
            printf("0이라 올라감\n");
        }
        for (int jdx = 0; jdx < lottos_len; jdx++) {
            if (lottos[idx] == win_nums[jdx]) {
                flag++;
                printf("숫자 맞음\n");
            }
        }
    }
    //printf("%d", flag);
    return flag;
}

int main() {
    int match = 0;
    int matchPlus = 0;
    int lottos[6] = {0};
    int win_nums[] = { 17, 45, 23, 22, 19, 6 };
    int cntZero = 0;
    int prizeMax = 0;
    int prizeMin = 0;

    printf("번호 6개 입력 해주세요.\n");
    for (int idx = 0; idx < 6; idx++) {
        int* pi = &idx;
        printf("%d번째 입력 : ", idx);
        scanf_s("%d", &lottos[idx]);
        if (lottos[idx] > 45) {
            printf("다시 입력하세요.\n");
            (*pi)--;
        }
        else if (lottos[idx] == 0) {
            cntZero++;
        }
    }
    printf("0의 갯수는 : %d\n", cntZero);
    //solution(lottos, sizeof(lottos)/sizeof(int), win_nums, sizeof(win_nums)/sizeof(int));
    match = test(lottos, sizeof(lottos) / sizeof(int), win_nums, sizeof(win_nums) / sizeof(int));
    matchPlus = match + cntZero;

    switch (match) {
    case 6 :
        prizeMax = 1;
        break;
    case 5:
        prizeMax = 2;
        break;
    case 4:
        prizeMax = 3;
        break;
    case 3:
        prizeMax = 4;
        break;
    case 2:
        prizeMax = 5;
        break;
    default :
        prizeMax = 6;
        break;
    }

    switch (matchPlus) {
    case 6:
        prizeMin = 1;
        break;
    case 5:
        prizeMin = 2;
        break;
    case 4:
        prizeMin = 3;
        break;
    case 3:
        prizeMin = 4;
        break;
    case 2:
        prizeMin = 5;
        break;
    default:
        prizeMin = 6;
        break;
    }
    printf("[%d, %d]", prizeMax, prizeMin);

    return 0;
}