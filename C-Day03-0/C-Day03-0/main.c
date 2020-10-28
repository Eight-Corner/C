#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
/*

        // 1+2+4+7+11+16
    int n=1;
    int sum=0;
    int cnt=0;
    while(n<=46){
        n+=cnt;
        cnt++;
        sum+=n;
        printf("n:%d\tcnt:%d\n",n,cnt);
        if(n==46)break;
    }
    printf("합계:%d    \t",sum);r
*/
/*
// 1+3+6+10+15+=....
    int i = 1, sum=0, cnt=1;
    while ( i <= 15){
        cnt++; // 2
        sum+=i;
        i+=cnt;
        printf("i:%d cnt: %d sum: %d\n",i,cnt,sum);
        if(i==15) {
        break;
        }
        }
    printf("총 합 : %d\n",sum);
*/
/*
 // 1x2x3x4x5x 100
 //  2 6 24 120
 
 // i  j   j
 // 1  2 = 2
 // 2  2 = 4
 // 3  4 = 12
 // 4  12 = 48
 int i = 0;
 int j;
 while ( i < 4 ){ // 100까지 곱하기 제어
     i++; // i는 1씩 증가
     j = j*i;
     j*i; // j는 증가한 i만큼 곱하여 계산한다.
     
    printf("i: %d j: %d\n", i,j);
     }
      printf("j: %d\n", j);
     */
     // 피보나치 수열
     // 1+1+2+3+5+8+13 ... + 의 순서로 나열되는 피보나치수열의 10번째 항까지의 합계를
     // 구하는 순서도
    int a = 1, b =1; //첫번째항, 두번≳항
    int c; //세번째항
    int sum = 2, cnt = 2; //합계 sum, 항의갯수 cnt
    int num; // 몇번재 항을 입력 할 건지
        printf("\n 피보나치 수 입력 : \n");
      scanf("%d" , &num) ;
    while(cnt<num){ //조건
        c = a + b;
        sum += c; //sum에 c값을 누적
        cnt++; //cnt 1증가
        // 계산할 항을 한칸씩 뒤로 밀기
        a=b;
        b=c;
    }
    printf("%d번째항까지의 피보나치수열의 합 = %d",cnt,sum); //출력
  /*1
          int i ;
        int num;
        int head = 0;
        int mid = 0;
        int rear = 1;
        printf("\n 피보나치 수 입력 : \n");
        scanf("%d" , &num) ;
        for(i = 0 ; i < num ; i++){
                printf("%d " , head) ;
                mid = head+rear;
                head = rear;
                rear = mid;
        }
        printf("\n\n"); */
 return 0;
}
/*
// 1-2+3-4+5-6.....+99-100
    int a = 0;
    int sum = 0;
    int sw=1; // 1 -1  1 -1
    
    while( a <= 100 ){
        a++;
        sw *= -1;
        sum = sum + a*sw;
            printf("%d \t %d \t %d\n",a,sw,sum);
    }
    printf("%d",sum);
*/
/*
    //1부터 100까지의 홀수 제곱의 합
    int a = 1;
    int n = 0;
    while ( a <= 100){
        n += a*a;
        a+=2;
    }
    printf("%d\n",n);*/
/*
// 1부터 100까지 홀수의 합
    int b = 1;
    int sum = 0;
    while(b <= 100){
        sum += b;
        b+=2;
    } printf("%d\n",sum);

// 1부터 100까지 짝수의 합

    int a = 2;
    int s = 0;
    while( a <= 100){
        s += a;
        a+=2;
    }
    printf("%d",s);
    */
 /*    // 1~100 까지 합 구하기 while문
    
     int a = 1;
     int s = 0;
    while ( a <= 100 ){
        s+=a;
        a++;
    }
        printf("%d",s);
 */
/*
    int a = 100;
     
     do{ // do while = 일단 1회는 무조건 실행.
     // 조건이 참이면 반복 실행
         printf("a는 100이 아닙니다!.(%d)+10을 더합니다. \n", a);
         a+=10;
    } while(a != 100); // a가 100이면 무한반복,-> 첫회는 무조건 실행하기 때문에
    // a 가 110이 되므로 a는 100이 다르다라는 것이 '맞다'(참) 그러므로 반복문 실행
    */
 /*
 
     char ch;

     while(1){
     printf("문자 입력 :  ");
     scanf("%c", &ch);
     switch(ch){
         case 'A':
         case 'a':
             printf("a 입니다.\n");
             break;
         case 'B':
         case 'b':
             printf("b 입니다.\n");
             break;
         case 'C':
         case 'c':
             printf("c 입니다.\n");
             break;
         default:
             printf("\nNothing\n");
             break;
     }
 }*/
 
 /*
 
 // 정수 2개 입력
 // 합계가 180 이상이면 * 10% 할인해서 출력
 // ex) 합계 - 합계 * 10% = 출력
 
  int a,b,result;
  float sum;
  float res;
     printf ("정수 2개를 입력하세요----\n");
     printf ("정수1: (100이하)\n");
     scanf ("%d",&a);
     printf ("정수2: (100이하) \n");
     scanf ("%d",&b);
    printf("a = %d, b =  %d 값을 입력했습니다.\n", a,b);
     sum=a+b;
     
     //  200 -> 20 정수
     // 191 ~ 199 -> 19.1 ~19.9 --> 정수
//     18.1 ~ 18.9 ==> 정수 부분만 취하기
//   17.1~17.9 ==> 17
     result = a+b;
     result = result * 0.1;
     printf("result : %d\n", result);
     
     switch(result){
     case 20:
     case 19:
     case 18:
         printf ("1. 10%% 할인= %f ",sum-(sum*0.1)); // 180 이상 18
         break;
    case 17:
    case 16:
        printf ("2. 8%% 할인 = %f ",sum-(sum*0.08)); //
         break;
    case 15:
    case 14:
        printf ("3. 5%% 할인 = %f ",sum-(sum*0.05)); //
         break;
    default:
        printf ("4. 할인X = %f ",sum-(sum*0.0)); //
         break;
     }
     */
     /*
 switch(a+b){
     case 180:
             res = sum-(sum*0.1);
        printf("현재 합계 : %f\n", sum);
        printf("180이상 할인 : %f\n", res);
        printf(" %f-(%f*0.1)\n", sum,sum);
        printf(" 할인된 수 : %f\n", sum*0.1);
     case 160:
             res = sum-(sum*0.08);
        printf("현재 합계 : %f\n", sum);
        printf("160이상 할인 : %f\n", res);
        printf(" 할인된 수 : %f\n", sum*0.08);
     case 140:
             res = sum-(sum*0.05);
        printf("현재 합계 : %d\n", sum);
        printf("160이상 할인 : %f\n", res);
        printf(" 할인된 수 : %f\n", sum*0.05);
     default:
         printf(" : %d");
 }
 */
 
 /*
 while(1){
 int a,b,sum,res;
     printf ("정수 2개를 입력하세요 : ");
     scanf ("%d %d",&a,&b);
    printf("a = %d, b =  %d 값을 입력했습니다.\n", a,b);
 sum=a+b;
    if( sum >= 180 ) {
        res = sum-(sum*0.1);
        printf("현재 합계 : %d\n", sum);
        printf("180이상 할인 : %d\n", res);
        
    } else if ( sum>= 160 ){
        res = sum-(sum*0.08);
        printf("현재 합계 : %d\n", sum);
        printf("160이상 할인 : %d\n", res);
    }
    else if ( sum>= 140 ){
        res = sum-(sum*0.05);
        printf("현재 합계 : %d\n", sum);
        printf("160이상 할인 : %d\n", res);
    } else {
        printf(" : %d");
    }

    
 
 }
*/


/*
    int a;
    int i=10;
    while(1) {
    printf("점수입력 : ");
    scanf("%d",&a);
        if ( a >= 90 ) {
        printf(" A 점= %d\n",a);
    } else if(a>=80) {
        printf(" B 점= %d\n",a);
    } else if ( a>=70){
        printf(" C 점 = %d\n",a);
    } else if ( a>=60){
         printf(" D 점= %d\n",a);
    } else if ( a>= 0 && a<60){
        printf(" F 점 = %d\n",a);
    } else {
        printf("0점 이상인 숫자를 입력하세요.\n");
        continue;
    }
}
 */
 
//
//        for (int i = 1; i<=9; i++) {
//            for (int j=1; j<=9; j++){
//                printf("%d * %d = %d\n",i,j,i*j);
//            }
//        }
        


/*
    char char1 = 'a';
    short val1 = 10;
    long long1 = 10L;
    int val2=20;
    float float1 = 3.14f;
    double val3 = 3.15;
 /*
      val1 = (short)val2; //(형변환-> int타입이 byte타입으로)
      // 명시적 형변환 -> 즉 down-casting 해야할 때
      // up-casting 할때는 묵시적 형변환 (명시하지 않아도 암묵적으로 가능)
      // 즉 - 64bit에서 32bit 호환이 어렵지만
      // 32bit에서 64bit 호환이 자유롭다.
    val3 = val2;
    printf("%lf \t ", val3); // up - casting
    
    val2 = (int)val3; // down-casting
    printf("%d \n", val2);
     
    
    printf("%d byte \n", sizeof(char1)); // sizeof()변수의 메모리 할당 크기를 리턴해준다.
    printf("%d byte \n", sizeof(val1));
    printf("%d byte \n", sizeof(long1));
    printf("%d byte \n", sizeof(val2));
    printf("%d byte \n", sizeof(float1));
    printf("%d byte \n", sizeof(val3));
    // c언어는 unix 계열 (Linux) work source 기반이기 때문에 8바이트
    */
    
    
    
    
    /*
      // 전위 증감 // 후위 증감
      // 최적화가 이루어질 경우 전위증가가 기능적 유리
      int i=0;
      i++; // 자신이 증가(or감소)
      printf("%d\t",i);// 1
      ++i; //   자신을 복사->증가(반환)
      printf("%d\t",i); // 2
      i++;
      printf("%d\t",i); // 3
      int i2 = i++; // 후위증가 -> 자신이 복사되고(대입된상태) ->증가함
      printf("%d\t",i2); // 3
      printf("%d\t",i); // 4
      */

/*
    // 3항 연산 == 조건부 연산  [?]
    int a1=20;
    int sa = 0 ;
    int sas = 0 ;
    //sa가 1000 이상 될 때까지 누적하여서 sa를 출력
    sa+=a1;
    while( sa >= 1000 ) {
        if ( sa < 1000 ){
            sa+=a1;
            
        } else if (sa){
        printf("%d", sa);
        }
        
    }
    int a=1;
    printf("%d\n", a);
    int b=++a;
    printf("%d\n", b); // 2
    int c=a++;
    printf("%d\n", c); // 2
    int d=b++ + ++c;  // b++ = 3 + ++c = 2  = 5
        // 다음줄  여기서 c = 3   후위증가
    printf("%d\n", d);// 5
    printf("%d %d %d %d\n", a,b,c,d);
    //printf("%d", (sa>=1000) ? sa : sa+=a ); // 만약에~~ 참 : 거짓
    
    
    // 1항 ?  2항   :   3항
    printf("%s", (a>50) ? "합격" : "불합격");
    // 조건이 참이면 합격 - 그렇지 않으면 불합격
     */
    
    
    
    /* 시프트 연산
    int num=100,num2 = 200;
    
    printf("%o\t %x\n", num,num);
    printf("%d\t", num << 2);
    printf("%d\t\n", num >> 3);
*/



/* 진수 계산기
   int select, num;
    int bin, sum = 0;
    int i = 1; // 1의 자리 숫자 표현
    
    printf("===변환할 진수 번호를 입력====\n");
    printf("1. 2진수 \n");
    printf("2. 8진수 \n");
    printf("3. 16진수 \n");
    scanf_s("%d", &select);

    printf("값 입력 : ");
    scanf_s("%d", &num);
    
    switch (select) {
        case 1:  // 2진수 변환
            while (num > 0) {
                bin = num % 2;
                sum += bin * i;
                num = num / 2;
                i *= 10;  //10의 자리씩 곱함
            }
            printf("변환한 값은 %d(2진수) \n", sum);
            break;
        case 2:  // 8진수 변환
            printf("변환한 값은 %#o(8진수) \n", num);
            break;
        case 3:  // 16진수 변환
            printf("변환한 값은 %#x(16진수) \n", num);
            break;
        default :
            printf("잘못 입력하셨습니다. \n");
            break;
    }         */


/* 쉬프트 연산
    int val1;
    int val2;

    printf("정수1 : ");
    scanf("%d", &val1);
    printf("정수2 : ");
    scanf("%d", &val2);

    printf("왼쪽 쉬프트 연산 %d\n", val1 << val2); // 10 * 3^2(2제곱)
     printf("오른쪽  쉬프트 연산 %d\n", val1 >> val2); // 10 / 3^2
    
*/

