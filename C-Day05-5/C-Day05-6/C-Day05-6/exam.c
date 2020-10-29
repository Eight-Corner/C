
#include "exam.h"

int main(int argc, const char * argv[]) {
    char *month[] = {"January", "Freburary", "March"};
    char ch = 'A';// 문자형
    
    char *pch, **ppch;
    
    pch = &ch;
    ppch = &pch;
    
    printf("ch : %c \t *pch : %c \t**ppch : %c \n", ch, *pch, **ppch);
    // ch 문자형을 pch ppch에 넣은 것
    
    
    ppch = month; // month 배열을 ppch 변수에 대입
    
    printf("*(pch+0) : %s\n", *(ppch+0)); // 변수값이 올라갈 수록 담겨있는 데이터(인덱스)를 보여준다.
    printf("*(pch+1) : %s\n", *(ppch+1));
    printf("*(pch+2) : %s\n", *(ppch+2));
//    printf("*(pch+3) : %s\n", *(ppch+3)); // 만약 벗어난 수를 입력하면 error
    
}
