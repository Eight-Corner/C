//
//  main.c
//  C-Day04-2
//
//  Created by 지금인 이유 on 2020/10/27.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    int age[7] = {10,20,30,40,50,60,70,80};
     
    for(int i=0; i<sizeof(age)/sizeof(int); i++){
        printf("age[%d] = %d\t", i, age[i]);
    }
    printf("\n오류가 나지 않고 80이라는 data는 없는 상태, 소멸 되어있다.\n");
    
    return 0;
}
