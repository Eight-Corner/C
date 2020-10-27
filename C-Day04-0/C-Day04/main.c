//
//  main.c
//  C-Day04
//
//  Created by 지금인 이유 on 2020/10/27.
//

#include <stdio.h>
#include <math.h>
#define PI 3.141592


int compute_sum (int i, int n,int sum);// 함수 선언
int pass (int number); // 결석시간에 따른 통과 함수 선언

int main(int argc, const char * argv[]) {
    // 표준 함수 사용
//    사인 삼각 함수 이용하기
    // 문제 1 ) 0도부터 180도 까지 30도 단위마다 사인 함수의 값을 출력하기
    // 사인 삼각함수의 값은 c라이브러리 함수 sin을 호출해 구한다.
    // sin 함수를 이용하려면 #include <math.h>가 필요하다.
//  sin함수의 인수는 단위가 각도가 아닌 라디안이므로 각도 변수 degree를 라디안 변수 radian으로 변환한 후 sin(radian)으로 호출한다.
//    180도는 라디안으로 파이에 해당하므로 각도를 라디안 단위로 변환하는 식은 ( PI * 각도 ) / 180
    
    int degree;
    double radian;
    
    for (degree = 0; degree <= 180; degree += 30 ){
        radian = (PI*degree)/180;
        printf("sin(%d) = %.5lf\n", degree,sin(radian) );
    }
               
    
    // 문제 2 ) 1 ~ n 까지의 합을 구하는 프로그램을 작성하여라. (함수 사용할 것)

    // 힌트 : n을 입력받아서 매개변수(인수)로 전달하여 처리할 것
    // n 값 전달 받기 -> compute_sum 함수 --> sum 반환
    //                  1~n의 합 sum 구하기
    int i,n,sum;
    printf("문제 2 ) 1 ~ n 까지의 합을 구하는 프로그램 (함수 사용) ---\n");
    printf("n값을 입력하세요 :");
    scanf("%d",&n);
    
    i = 1;
    
    
    sum = compute_sum(i,n,sum); // 덧셈 함수호출
    printf("%d + %d = 합산 %d\n",i,n,sum);
    
    // 문제 3 ) 결석시간에 근거하여 출석 통과 여부를 출력하는 프로그램을 작성
    // 결석시간을 number로 전달 받기 --> 함수원형 int pass(int number) ---> 1 (통과) or 반환
        // 결석시간 number에 따른 과락 여부 반환, 결석 시간이 6시간 미만이어야 통과함
    
    int number; // 결석시간 변수 선언
    int pa; // 통과 변수
    printf("문제 3 ) 결석시간에 근거하여 출석 통과 여부를 출력하는 프로그램을 작성---\n");
    printf("결석 시간을 입력하세요. :");
    scanf("%d", &number);
    
    printf("결과 : ", pa);
    pa = pass(number);
    printf("\n");
    
    
}

int compute_sum(int i, int n,int sum){
    for (i = 1; i <= n; i++) {
            sum += i;
    }
    return sum;
}

int pass (int number){ // 결석시간에 따른 통과 함수
    if ( 5 < number && number < 0 ){
        printf("non-pass");
    } else {
        printf("pass");
    }
    return number;
}

/*
// * C언어는 절차적 지향 언어이기 때문에 함수 선언을 해야한다.
// 함수
int sum(int i, int j,int k); // 함수의 구조 선언하는 부분
double  avg(double i, double j, double k, double h);


int main(int argc, const char * argv[]) {
  
    
    int number1, number2, total;
    double average;
    printf("정수 1 입력 : "); // ex ) 100
    scanf("%d", &number1);
    printf("정수 2 입력 : "); // ex ) 200
    scanf("%d", &number2);
    
    total = sum(number1, number2,50); // 함수호출
    printf("%d + %d + %d = 합계 : %d\n", number1,number2,50,total);
    
    average = avg(number1,number2,78.25,532.1);
    printf("(%d + %d + %lf + %lf ) / 4 = 평균 : %lf\n", number1,number2,78.25,532.1,average);
    return 0;
    
}

int sum(int i, int j, int k){
    return i+j+k;
}
double avg(double i, double j, double k, double h){
    return (i+j+k+h)/4;
}
*/

/*
 변수의 생명주기
 변수를 선언하면 태어남
            int sum( ) {
            int a=10; //지역 변수 
 
            a=a+10;
        return a;
 변수의 생명 죽기, 함수 밖으로 나오면 변수 사용 못함.
 */





//for문에서 1부터 100까지 합 구하기
/*
int sum=0;
for (int i=1; i<=100; i++){
    for(int j=1; j<10;j++){
        printf("i = %d, j = %d", i,j);
    }
    sum+=i;
} printf("합 = %d\n", sum);
*/

// 예제1 별찍기 31p
/*
printf("예제1 별찍기 31p ==== \n");
printf("자연수 n값을 입력하세요.\n");

int n;
scanf("%d",&n);

for(int i=0; i<n; i++){
    for(int j=0; j<=i; j++){
        printf("*");
    }
    printf("\n");
}
*/

// 예제2 별찍기2 32p
/*
int i, j, k;        // i= n만큼 반복  j=공백 k=별
    int n;          // 정수 입력받기
printf("예제2 별찍기2 32p ==== \n");
printf("자연수 n값을 입력하세요.\n");
scanf("%d",&n);
 
    for (i = 0; i < n; i++) {
        for (j = 0; j < n-i; j++) {  // 공백의 수 계산 (공백은 줄어간다 n-i)
            printf(" ");
        }
        for (k = 0; k <=i; k++) {   // 별 계산 (별은 늘어난다)
            printf("*");
        }
        printf("\n");
    }

//예제3 별찍기3 33p

int x,y; // x = num 만큼 반복  y=별;
int num;
printf("예제3 별찍기3 33p ==== \n");
printf("자연수 num 값을 입력하세요 : ");
scanf("%d",&num);

for(x = 0; x < num; x++){
    for (y = 0; y < num-x; y++){
        printf("*");
    }
    printf("\n");
}
 
 
 
int x2,y2,z2;
int num2;
 
 
printf("예제4 별찍기4 34p ==== \n");
printf("자연수 num2 값을 입력하세요 : ");
scanf("%d",&num2);
for (x2=0; x2 < num2; x2++){
    for (y2 = 0; y2 < x2+1; y2++){
        printf(" ");
    }
    for (z2 = 0; z2< num2-x2; z2++){
        printf("*");
    }
    printf("\n");
}

printf("예제5 별찍기5 피라미드 찍기 35p -------- \n ");
int a,b,c; // a=반복 b=공백 c=별
int num3;
printf("자연수 num3 값을 입력하세요 : ");
scanf("%d",&num3);

for(a = 0; a<num3; a++){
    for(b = num3-1; b > a; b--){
        printf(" ");
    }
    for(c = 0; c<2*a+1;c++) {
    printf("*");
    }
    printf("\n");
}
*/
