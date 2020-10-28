 
#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // 포인터 변수의 선언
    int *ptr, *ptr_a;
    //문자 배열 선언 후 초기화
    int a[5] = {10,20,30,40,50};
    int ptr_v,i;
    
    // 포인터 값 대입 후 출력
    ptr = a; // ptr = &a[0]  a포인트 변수 0열 ptr     // a = 0 == 10
    printf("*ptr : %d \t ptr : %p \t address : a : %p \n", *ptr,ptr,a);
    // %p 포맷은 16진수 출력
    //ptr++후 출력
    ptr_a = ptr++; // 1: ptr을 ptr_a에 대입을 먼저 -> 2: ptr=ptr+1  // a = 1 == 20
    printf("*ptr : %d \t ptr : %p \t ptr_a = ptr++ : %p \n", *ptr,ptr,ptr_a);
    
    //*ptr++후 출력
    ptr_v = *ptr++; // 1: ptr_v에 *ptr 포인터ptr 대입 -> 2: ptr=tr+1 // a = 2  == 30
    printf("*ptr : %d \t ptr : %p \t ptr_v = *ptr++ : %p \n", *ptr,ptr,ptr_v);
    // (*ptr)++;
    ptr_v = (*ptr)++; // 1: ptr_v에 ptr 대입  --> 2: ptr=ptr+1 // a = 2 + 1 == 31
    printf("*ptr : %d \t ptr : %p \t ptr_v = (*ptr)++ : %p \n", *ptr,ptr,ptr_v);
    
    
    /*
    // 포인터 연산에서 사용 가능한 연산
     
    ptr == ptr + 1;
    ptr = ptr + 2;
    ptr++;
    ++ptr;
    ptr--;
    --ptr;
    
     
     // 포인터 연산에서 사용할 수 없는 연산
     
     ptr = ptr * 2;
     ptr = ptr / 2;
     ptr = ptr + ptr2 ; 
    */
}
