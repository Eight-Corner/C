 
#include <stdio.h>

// 함수선언
void swap(int *sw_pnum1, int *sw_pnum2);
int sum(int num1, int num2);

int main(int argc, const char * argv[]) {
  /*
    int a = 10;
    int *pa;
    int **ppa;
    
    pa = &a;
    ppa = &pa;
    
    //10을 출력
    printf("%d %d %d \n", a, *pa, **ppa);
    //같은 결과 10을 보여준다.
    
    //주소를 출력하기
    printf("%d %d %d \n", &a,&pa,&ppa);
    printf("%d %d \n", &a,*ppa);// 값 출력
    // 다른 결과를 보여준다.
    */
    
    
//
    //    int num1 = 10, num2=20;
    //    int *ptr1 = &num1, *ptr2 = &num2;
//
    //    int **dptr1 = &ptr1, **dptr2 = &ptr2;
    //
    //    int sum;
    //
    //    sum = num1 + num2;
    //    printf("%d \t", sum);
    //    sum = *ptr1 + num2;
    //    printf("%d \t",sum);
    //    sum = num1 + *ptr2;
    //    printf("%d \t", sum);
    //    sum = *ptr1 + ptr2;
    //    printf("%d \t", sum);
    //    sum = **dptr1 + **dptr2;
    //    printf("\n%d \t", sum);
    //
    
    
        int num1 = 10, num2=20;
        int *ptr1 = &num1, *ptr2 = &num2;
    int total = 0;
    
    swap(ptr1,ptr2);
    printf(" %d %d ",num1,num2);
    
    total = sum(num1,num2);
    printf("\n %d", total);
    
    printf("\n");
    return 0;
}
// 합수 정의
void swap (int *sw_pnum1, int *sw_pnum2){
    printf("주소 : %d | %d \n", sw_pnum1, sw_pnum2); // call by address
    printf("값 : %d | %d \n", *sw_pnum1, *sw_pnum2); // call by value
    
}
int sum(int num1, int num2){
    return num1+num2;
}
