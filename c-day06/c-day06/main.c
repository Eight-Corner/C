/*
 // 주소 project

 
 // 구조체 : 다른 자료형을 갖는 변수의 집합
 struct {
     // 자료형 변수명1;
     // 자료형 변수명2;
 }  //구조체 명;

 // 배열 : 같은 자료형의 연속적인 메모리 할당
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <process.h>

#define _FILE_ "ADDRBOOK.dat"

// 구조체 = 자바로 치면 클래스 생성자 선언
struct data { //구조체 구조체명
    char cName[8]; // 8byte라고 변수 선언
    char cTel[16]; // 전화번호 16byte의 자리 값 변수
    char cAddr[32]; // 주소의 32byte의 자리 값 변수
};
// 함수 선언
void SelOne(unsigned, struct data *); // 1개는 unsigned 정수 , 구조체 포인터 변수(참조변수)를 입력 (자료입력)
void SelTwo(unsigned, struct data *); // 자료 검색
void SelThree(unsigned, struct data *); // 자료 수정
void SelFour(unsigned, struct data *); // 자료 삭제
void SelFive(unsigned, struct data *); // 자료 조회

int Cnt_data(unsigned); // 정보의 한줄 => 레코드 ADDRBOOK.dat에 save할 예정, 레코드 인원수를 카운팅하기 위한 함수.

int main(int argc, const char * argv[]) {
    
    char cBtn; // c Button 콘솔 입력을 받기위한 변수 선언;
    int Lec; //
    unsigned rsize = sizeof(struct data); // 56byte
    
    struct data *Book1; //포인터변수 Book1선언-> 구조체에 접근할 수 있기 위함
    struct data *Book2;
    
    while(1){
        // 데이터 갯수 세기, 파일에 들어 있는 레코드 갯수 세기
        Lec = Cnt_data(rsize);
        printf("%d", Lec);
    }
    return 0;
    
}

// ㄹ[ㅔ코드 갯수 세어주는 함수
int Cnt_data(unsigned rsize) { // 양수만
    int Cnt; // 갯수 세기
    FILE *fload; // FILE에 주소를 담기위한 변수, 파일을 쓰기 위한 예약어
    
    fload = fopen(_FILE_, "r"); // r - 읽기 w - 쓰기
    //파일을 불러온다 = 파을 열어준다 (_파일명_, 읽기 전용으로);
    if (fload == NULL ) { // NULL == 파일이 없다면
        Cnt = 0;
    } else {
        fseek(fload, -1, SEEK_END); // 자료를 찾아주는 함수 -> SEEK_END 끝날때까지
        Cnt =(ftell(fload)/rsize)+1; //
        fclose(fload);
    }
    return Cnt;
}
