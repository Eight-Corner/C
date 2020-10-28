

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
//    문자열을 사용할 때는 char 포인터에 " "(큰따옴표)로 묶은 문자열만 할당하면 된다는 점만 기억
//    그리고 printf로 문자열을 출력할 때는 서식 지정자로 %s를 사용.
    /*
     포인터 변수 : 데이터형의 하나로 데이터 값이 데이터가 저장되어 있는 메모리 어드레스
     
     메모리 address : 메모리 위치에 대한 식별자로, 컴퓨터 프로그램이나 하드웨어 장치가 데이터를 저장하고 나중에 이를 가져오는 장소이다.
     (이진 형태의 숫자로 되어 있다.)
     
     프로그램 제어용 변수 : 프로그램 제어용 데이터를 값으로 사용할 수 있는 변수를 일컫는 말로서 포인터 변수가 대표적인 프로그램 제어용 변수
     
     포인터 배열 : 여러개의 포인터를 하나의 배열로 구성한 것으로 배열의 특징과 포인터의 특징을 모두 활용
     
     배열 포인터 : 배열을 가리키는 포인터 변수
     
    --------------------
     포인터의 사용 이유
     
     메모리 주소를 직접 이용하여 접근 할 수 있는 프로그램을 작성
     메모리 어드레스를 c언어에 포인터라고 함
     메모리 어드레스를 저장하고 있는 변수를 포인터 변수라고 함
     
     - 포인터 배열을 사용하면 메모리가 절약됨
     - 기억장소의 남아 있는 공간을 최대한 활용할 수 있다.
     - 포인터를 이용하여 함수의 반환 값을 전달하면 하나의 값이 아닌 여러개의 값을 전달 할 수 있다.
     
     -------------------------
     
     포인터변수
     */
    int int_val = 10;
    double dou_val = 3.14;
    char ch_val = 'a';
    
    int arr[5] = {1,2,3,4,5};
    printf("-----1---------\n");
    printf("%d\n", &int_val); // & 변수의 주소를 찍기위함
    printf("%d\n", &dou_val);
    printf("%d\n", &ch_val); // 결과 값은 컴퓨터마다 다르기 때문에 주소가 다르게 나올 수 있다.
    
    printf("\n-arr 배열의 주소-\n");
    printf("%d[0번]\n", &arr[0]);
    printf("%d[1번]\n", &arr[1]);
    printf("%d[2번]\n", &arr[2]);
    printf("%d[3번]\n", &arr[3]);
    printf("%d[4번]\n", &arr[4]);
    // 결과 값
//    -배열의 주소-
//    -272632528
//    -272632524
//    -272632520
//    -272632516
//    -272632512
//   배열안에 있는 데이터 값이 4씩 줄어든 규칙을 알 수 있다.
//    배열의 특징 : 같은 자료형을 저장하고, 연속해서 저장한다.
//    4칸씩 차이가 나는 이유 : int 자료형은 4byte이기 때문이다.
    printf("arr의 배열명 주소 : %d\n", arr); // 배열 명은 배열의 0열의 주소값
//    arr == arr[0]의 주소와 같다. ||| 배열명 == 배열명[0]
    
// 배열을 저장하고 싶다면 변수에 담으면 된다.
    
    // 주소가 들어갈 변수 : 포인터 변수 == 주소를 담을 변수
    int *p_int_val; // * 은 포인터 변수라는 뜻
    // 주소가 정수라는 뜻 보다는, 이 변수의 주소 값이 정수라는 숫자가 들어가있다.
    double *p_dou_val; //
    char *p_ch_val; //
    
    // 변수에 값을 넣기
    p_int_val = &int_val; // &int_val 주소를 포인터 변수에 넣겠다.
    p_dou_val = &dou_val;
    p_ch_val = &ch_val;
    printf("---2--\n");
    printf("%d %d\n", &int_val, p_int_val); //
    printf("%d %d\n", &dou_val, p_dou_val);
    printf("%d %d\n", &ch_val, p_ch_val); //  .
    
    
    // 일반 변수에 포인터 주소를 넣어보기
    printf("일반 변수에 포인터 주소를 넣어보기\n");
    int int_val2; // 일반 변수를 선언
    int_val2 = &int_val; // 일반 변수에  &포인터 넣기
    printf("%d \n", int_val2); // 원래는 안된다는데,,, 컴파일하고 실행하는데 오류or문제발생이 되지않는다면 괜찮은거 아닌가?..
    
    // 크기 찍어보기
    printf("2번의 크기 찍어보기 ----\n");
    printf("%d %d\n", sizeof(&int_val), sizeof(p_int_val)); //
    printf("%d %d\n", sizeof(&dou_val), sizeof(p_dou_val));
    printf("%d %d\n", sizeof(&ch_val), sizeof(p_ch_val)); //
    // 결과 : 8  ==> 64bit 운영체제를 쓰기 때문에 8byte가 나온다.
    // 주소의 크기는 같다. (size) 주소는 무엇을 담든 상관없이 주소의 크기는 8byte로 세팅 되어 있다.
    // 어떤 자료형을 갖고 있던 주소의 크기는 8byte.
    
}