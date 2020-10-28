#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

    
    int a = 10;
     const  int b = 12;
    printf("%o\n", a);
    printf("%o\n", b);
    printf("-----\n");
    printf("%o\n", a | b);


    return 0;

}
 
    /*    산술 연산자 부분
    int int_val1,int_val2;

    int result_val1;
    float f_val3;

    printf("==========\n");
    printf("산술 연산자 \n");
    printf("정수1: ");
        scanf("%d", &int_val1);
    printf("정수2: ");
        scanf("%d", &int_val2);

        result_val1 = int_val1 + int_val2;
    printf("val1 + val2 = %d\n",result_val1);
        result_val1 = int_val1 - int_val2;
    printf("val1 - val2 = %d\n",result_val1);
        result_val1 = int_val1 * int_val2;
    printf("val1 * val2 = %d\n",result_val1);
        result_val1 = int_val1 / int_val2;
    printf("val1 / val2 = %d\n",result_val1);
        result_val1 = int_val1 % int_val2;
    printf("val1 %% val2 = %d %%\n",result_val1);

    printf("-result value  = %d\n",-int_val1);
        printf("-result value  = %d\n",-int_val2);

            f_val3 = (float)int_val1 + int_val2;
    printf("----자료형 변환-----\n");
    printf("%f\n", f_val3);
 */

 /* 대입 연산자
    int int_a = 100;
    int int_b = 3;
    int int_c = 50; // 4로 3번 나누게 코드
    int int_val1,int_val2;
    int result_1;
    int avg;
    result_1 = int_b;


    int_c %= 4;
    printf("int_c %%=4 = %d \t",int_c);
    int_c %= 4;
    printf("int_c %%=4 = %d \t",int_c);
    int_c %= 4;
    printf("int_c %%=4 = %d \t \n",int_c);


    printf(" result = b : %d , %d\n", result_1,int_b);

    result_1 = int_a + int_b;
    printf("result_1 = int_a + int_b =  %d\n", result_1);

    result_1 += int_b;
    printf("result_1 += int_b =  %d\n", result_1);

    result_1 -= int_b;
    printf("result_1 -= int_b = %d\n", result_1);

    int_a /= 2;
    printf("int_a /= 2 = %d\t", int_a);
        int_a /= 2;
        printf("int_a /= 2 = %d\t", int_a);
            int_a /= 2;
            printf("int_a /= 2 = %d\n", int_a);

    --int_a;
    printf(" --int_a 증감연산 = %d\n", int_a);
    ++int_a;
    printf(" ++int_a 증감연산 = %d\n", int_a);
    int_a-=4;
    printf(" int_a-=4 = %d\n", int_a);

    int_a*=7;
    printf(" int_a*=7 = %d\n", int_a);

    printf("==============\n 두 정수를 입력 : ");
    scanf("%d %d", &int_val1, &int_val2);

    printf("입력된 두 수의 합 =  %d \n", int_val1+int_val2);
    printf("%d * %d = %d\n", int_val1,int_val2,int_val1*int_val2);

    printf("%d", ++int_a);
    */
    /* 논리 연산
printf("========and========\n");
printf("0 and 0 %d\t", 0 && 0);
printf("0 and 1 %d\t", 0 && 1);
printf("1 and 0 %d\t", 1 && 0);
printf("1 and 1 %d\t", 1 && 1);

printf("\n========OR========\n");
printf("0 OR 0 %d\t", 0 || 0);
printf("0 OR 1 %d\t", 0 || 1);
printf("1 OR 0 %d\t", 1 || 0);
printf("1 OR 1 %d\n", 1 || 1);

printf("\n========Not========\n");
printf("not 0 %d \t", !0);
printf("not 1 %d \n", !1);
*/

/*    int a,b,c;

    printf("세 정수를 입력하세요 : ");
    scanf("%d %d %d", &a,&b,&c);
    if(a > b && a > c){
        printf ("a(%d)가 제일 큽니다.\n",a);
        printf("b(%d) c(%d)", b,c);
    } else if (b > a && b > c){
        printf ("b(%d)가 제일 큽니다.\n",b);
        printf("a(%d) c(%d)", a,c);
    } else if (c > a && c > b) {
        printf ("c(%d)가 제일 큽니다.\n",c);
        printf("a(%d) b(%d)", a,b);
    }
    int i1=100;
    int i2=50;
    printf("\n");
    printf("%d\t", i1 == i2);
    printf("%d\t", i1 < i2);
    printf("%d\t", i1 > i2);
    printf("%d\t", i1 <= i2);
    printf("%d\t", i1 >= i2);
    printf("%d\t", i1 != i2);

    printf("\n");
    char c1='a';
    char c2='b';

    printf("%d\t", c1 == c2); // 0
    printf("%d\t", c1 < c2); // 1
    printf("%d\t", c1 > c2); // 0
    printf("%d\t", c1 <= c2); // 1
    printf("%d\t", c1 >= c2); // 0
    printf("%d\t", c1 != c2); // 1


    */

    /*
    int a = 300;

    printf("10진수 %d\t ", a);
    printf("8진수 %o\t", a);
    printf("16진수 %x\t", a);

    // 2진수 :  100001
    // 8 진수 :  41
    // 16진수 : 21
    */

    /*
        //문제1 : 급여와 근무한 기간을 입력하면 보너스가 계산되는 프로그램
        // 단 , 보너스는 급여의 60%에 근무한 기간을 곱한 값. (근무기간 * 급여의 60% )

        int pay; // 일급
        int day;
        int bonus;
        int sum; // 월급

        printf("급여(일급)와 근무 기간을 입력하세요 : ");
        scanf("%d %d", &pay,&day);

        printf("급여 : %d , 근무 일수 : %d\n",pay,day);
        sum = pay*day;
        printf("총 받을 금액 : %d원\n",sum);
        bonus = pay%60 * day;
        printf("이번 보너스 금액은 %d 원 지급 됩니다.\n", bonus);


        //문제 2 : 원의 반지름을 입력 받아서 면적을 계산하여 출력
        // 원의 면적은 반지름*반지름*3.14 (3.14 상수처리)
        int radius;
        const float pi=3.14;
        float circle; // 면적
        printf("원의 반지름을 입력하세요. ");
        scanf("%d", &radius);
        printf("반지름 값 : %d\n",radius);

        circle = (float)radius*(float)radius*pi;
        printf("면적 값 : %f\n",circle);

        //Q3
        int a = 10;
        printf("Q3 : %d", 5+2 || a+1 && -2);
        */
        /*
            int a = 10;
            int b,c,d;

            b = ++a; // 1개 증가 1단계 a=a+1 2단계 b=a;
            c = a++; // 1단계 c=a; 2단계 a=a+1;
            printf("%d\n", a); // 12
             // 12의 a 값에서  (++a)13 +  (a++)14 + (++a)15
            d = ++a + a++ + ++a;
            printf("%d\n", d);
            printf("%d\n", a);
            printf("%d\n", b);
            printf("%d\n", c);
            */
