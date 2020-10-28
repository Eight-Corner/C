
#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    // 배열 선언
    int a[5] = {10,20,30,40,50};
    //포인터 변수의 선언
    int *ptr; // * 포인터 변수라는 의미 (주소를 담을 뜻)
    
    // 포인터 변수에 배열 대입
    ptr=&a[2]; // ptr = &a[0] || a의 0열에 주소를 ptr에 대입
    // 10출력, 40출력
    
    
    ptr = ptr-2; // 10
    printf("주소 : %d \n", ptr); //a=0이였다가 1이 증가해 1번 인덱스
    printf("주소 : %d \n", &a[0]);
    // 포인터 값을 증가
//    ptr++; // ptr = ptr+1
    printf("*ptr 값은  : %d \n", *ptr); //1이 한번 더 증가해서 2번 인덱스
    // 포인터 변수의 주소를 찾아 그 안에 들어있는 값을 선택,
    ptr = ptr+3; // 40
    printf("*ptr 값은  : %d \n", *ptr); //1이 한번 더 증가해서 2번 인덱스
    printf("\n=============\n");
    
    
}
