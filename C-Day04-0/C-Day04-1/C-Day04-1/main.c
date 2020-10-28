
#include <stdio.h>

int main(int argc, const char * argv[]) {
    int age[5];
    double jumsu[5];
    char ch[5];
    int i;
    int age_size; double jumsu_size; char ch_size;
    
    age_size = sizeof(age)/sizeof(int);
    jumsu_size = sizeof(jumsu)/sizeof(double);
    ch_size = sizeof(ch)/sizeof(char);
    printf("%d\n", age_size);
    
    
    
    //
    for(i = 0; i < 5; i++){
        printf("나이 : ");
        scanf("%d", &age[i]);
    }
    for(i = 0; i < 5; i++){
        printf("점수 : ");
        scanf("%lf", &jumsu[i]);
    }
    for(i = 0; i < 5; i++){
        printf("문자 : ");
        scanf("%c", &ch[i]);
        
    }
    for(i = 0; i < 5; i++){
        printf("나이 : %d \t 점수 : %lf \t 문자 : %c\n",age[i],jumsu[i],ch[i]);
    }
    
    
    return 0;
}
