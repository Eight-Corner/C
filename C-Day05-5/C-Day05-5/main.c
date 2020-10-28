// 포인터와 배열의 관계 , 포인터 배열 (여러개의 포인터를 하나의 배열로 구성)
#include <stdio.h>

int main(int argc, const char * argv[]) {
 
    int a[5]={10,20,30,40,50};
    int *pa = a;
    printf("%d %d \n", a[2], *(pa+2) ); // *pa+1 = pa는 10값에 +1 그러므로 *(pa+1) 괄호를 이용해 연산을 먼저 시켜줘야한다.
    
    for (int i = 0; i<5; i++){ // 배열을 보기 위한 반복문
        printf("%d \t", a[i]);
    }printf("\n");

    //10부터 50까지 포인터 변수로 출력
    for (int i = 0; i<sizeof(a)/sizeof(int); i++){ // 시작 주소 a를 *pa에 넣기 때문에 같다.
        printf("%d %d\t", a[i], *(pa+i));
    }
    printf("\n");
    
    //C언어는 배열을 구성하는 배열요소의 자료형에 제한이 없다, int나 char과 같은 기본 자료형 뿐 만 아니라 배열도 배열요소로 사용할 수 있다.
    // 포인터 배열은 배열요소가 포인터인 배열
    char *name[5] = {"memory","cpu","main board","hdd","mouse"};
    int age[5] = {10,5,2,1,12};
    printf("name[0] = %d\n", name[0]); // 202  memory는 6이지만 끝에 null 값에 의해
    printf("name[1] = %d\n", name[1]); // 209  7이 차이나는것을 알 수 있다.
    printf("name[2] = %d\n", name[2]); // 213  cpu는 3이지만 끝에 null 값에 의해 2번 인덱스와 4차이가 난다.
    printf("name[3] = %d\n", name[3]); // main board는 10이지만 끝에 null 값에 의해 11차이
    printf("name[4] = %d\n", name[4]); // hdd는 마찬가지로 null값을 포함해 +1 하여 4 차이
    printf("\n");
    
    printf("%s \t",name[0]);
    printf("%s \t",name[1]);
    printf("%s \t",name[2]);
    printf("%s \t",name[3]);
    printf("%s \t",name[4]);
    printf("\n");
}
