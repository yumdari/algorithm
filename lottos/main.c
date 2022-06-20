#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len�� �迭 lottos�� �����Դϴ�.
// win_nums_len�� �迭 win_nums�� �����Դϴ�.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.


    int* answer = (int*)malloc(1);
    return answer;
}

int test(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    int flag = 0;
    for (int idx = 0; idx < lottos_len; idx++) {
        if (lottos[idx] == 0) {
            flag++;
            printf("0�̶� �ö�\n");
        }
        for (int jdx = 0; jdx < lottos_len; jdx++) {
            if (lottos[idx] == win_nums[jdx]) {
                flag++;
                printf("���� ����\n");
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

    printf("��ȣ 6�� �Է� ���ּ���.\n");
    for (int idx = 0; idx < 6; idx++) {
        int* pi = &idx;
        printf("%d��° �Է� : ", idx);
        scanf_s("%d", &lottos[idx]);
        if (lottos[idx] > 45) {
            printf("�ٽ� �Է��ϼ���.\n");
            (*pi)--;
        }
        else if (lottos[idx] == 0) {
            cntZero++;
        }
    }
    printf("0�� ������ : %d\n", cntZero);
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