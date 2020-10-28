
#include <stdio.h>

int main(int argc, const char * argv[]) {
  
    /*
    char id[14] = "9011032683231";
    printf("%c%c년도에 태어난 ", id[0],id[1]);
     
    if(id[2]=='1') // id 인덱스 안에 n번째 '항'에 있는 수가 그 수와 같은지,
        printf("남자\n");
    else
        printf("여자\n");
    
     */
    
    
    /* 주석
    // char형 2차원 배열을 이용한 여러개의 문자열 처리
    char city[4][6] = {"Seoul","Busan","Daegu","Ulsan"};
    char city_kor[4][5];
    int row_size, col_size;
    row_size = sizeof(city)/sizeof(city[6]);
    col_size = sizeof(city[6]);
    printf("%d   %d \n", row_size,col_size);
    
    for (int i = 0; i < row_size; i++){
        for(int j = 0; j<col_size; j++){
        printf("%c",city[i][j]); // %c format은 한글자 출력
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < row_size; i++){
        printf("%s\n", city[i]);
    }
    
    // 2차원 배열에서
    // 0행 1행으로 생각하지만 메모리는 실제로
//       0 1 2
//       1 2 4
    // 길게 뒤로 이어진 타입
//         [0 1 2] [1 2 4] [5 7 9]
     */
//    문자열을 사용할 때는 char 포인터에 " "(큰따옴표)로 묶은 문자열만 할당하면 된다는 점만 기억
//    그리고 printf로 문자열을 출력할 때는 서식 지정자로 %s를 사용.
    
    
    
}

