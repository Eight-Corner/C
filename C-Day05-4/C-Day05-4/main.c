 
#include <stdio.h>

int main(int argc, const char * argv[]) {
  
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
    
    
    
    return 0;
}
