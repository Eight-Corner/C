#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    int a,b,c,sum;
    
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    sum = a+b+c;
    printf("sum 값 = %d\n", sum);
    sum--;
    printf("sum 값 = %d\n", sum);
    printf("sum이 10보다 큰가?%d\n", sum>10);

    /*
    int kor,eng,math;
    int sum = 0;
    double avg;
    printf("국어 점수:");
    scanf("%d", &kor);
 
    printf("영어 점수:");
    scanf("%d", &eng);

    printf("수학 점수:");
    scanf("%d", &math);

    printf("국어 점수: %d점 입니다.\n", kor);
    printf("영어 점수: %d점 입니다.\n", eng);
    printf("수학 점수: %d점 입니다.\n", math);
    
    sum = kor + eng + math;
    printf("총합 : %d점\n",sum);
    
    avg = sum / 3.0; //평균
    printf("평균 : %lf점\n",avg);
    
    if (avg <= 40) {
        printf("최하");
    } else if (avg <= 50){
        printf ("6등급");
    } else if (avg <= 60){
        printf ("5등급");
    } else if (avg <= 70){
        printf ("4등급");
    } else if (avg <= 80){
        printf("3등급");
    } else if (avg <= 90){
        printf (" 2등급 ");
    } else if (avg <= 100){
        printf (" 1등급 ");
    }
     
    */
    return 0;
}
