//
//  main.c
//  C-Day04-2
//
//  Created by 지금인 이유 on 2020/10/27.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    int age[2][3]={10,3,5,15,25,35};
    
//    for(int i=0; i<2; i++){
//        for (int j=0; j<3; j++){
//            scanf("%d", &age[i][j]);
//        }
//    }
    for(int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            printf("%d \t", age[i][j]);
        }
        printf("\n");
    }
 
    
    return 0;
}
