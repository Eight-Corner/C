 

#include <stdio.h>
int main(int argc, const char * argv[]) {
 
    
    // 별찍기 마름모
    
    
    int a = 11;
    int b = a/2+1;
    int c = 0;
    printf("마름모 \n");
    
    for (int i=1; i<=a; ++i){
        if (i <= b){
            ++c;
        } else {
            --c;
        }
        for (int j=1; j<=b-c; ++j){
            printf(" "); // 공백 구문
        }
        for (int k=1; k<=c*2-1; ++k){
            printf("*"); // * 별 찍기
        }
        printf("\n");//줄바꿈
    }
    
}
