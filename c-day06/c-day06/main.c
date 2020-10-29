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
#include <term.h> //
#include <curses.h> //
//#include <process.h>
#include <unistd.h> // procees.h의 역할



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
//        Lec = 10;
        Book1 = (struct data *) malloc(1*sizeof(struct data)); // malloc = 동적할당 함수   [ struct data의 주소 = 일반주소 // 구체화 = ( ) 범용적인 자료 downcasting ]
        Book2 = (struct data *)malloc(Lec*sizeof(struct data)); // 형변환
        // Book1 == 하나도 없을 때 (처음일 때) 레코드 넣을 메모리 확보 , // Book2 => 파일안에 여러개의 레코드를 넣을 메모리 확보
        system("clear"); // 윈도우에서는 "cls", 맥에선 "clear"
        printf("구조체 크기 : %d\n", rsize);
        printf("데이터 갯수 : %d\n\n", Lec);
        system("clear");

        if(Lec != 0 ) {//파일에 데이터가 이미있는 경우
            printf("1. 자료 입력 \n");
            printf("2. 자료 검색 \n");
            printf("3. 자료 수정 \n");
            printf("4. 자료 삭제 \n");
            printf("5. 자료 조회 \n");
            printf("0. 종    료 \n");
            printf("번호를 입력하여 선택하세요 : ");
            scanf("%c",&cBtn);

        } else { // 제일 처음에 파일에 아무것도 없는 상태
            cBtn='1'; // char 자료형이니 싱글 따옴표
            }
        if (cBtn == '1') { //입력하는 코드
            system("clear");
            SelOne(rsize, Book1);
        } else if (cBtn == '2') { // 2라면 검색 하지만 Lec이 있는지 없는지 유효성 검사 판별 추가
            if ( Lec == 0 ){
                printf("검색할 데이터가 존재하지 않습니다. 데이터를 넣어주세요. \n");
                system("read"); // pause 대신 read
            } else {
                system("clear");
                SelTwo(rsize, Book2);
            }
        } else if (cBtn == '3') { // 자료 수정
            if ( Lec == 0 ){
                printf("수정할 데이터가 존재하지 않습니다. \n");
                system("read");
            } else {
                system("clear");
                SelThree(rsize, Book2);
            }
        } else if (cBtn == '4') {
            if (Lec == 0 ){
                printf("삭제할 데이터가 없습니다. \n");
                system("read");
            } else {
                system("clear");
                SelFour(rsize, Book2);
            }
        } else if ( cBtn == '5') {
            if (Lec == 0 ){
                printf("조회할 데이터가 없습니다. \n");
                system("read");
            } else {
                system("clear");
                SelFive(rsize, Book2);
            }
        } else if ( cBtn == '0' ){
            printf("프로그램을 종료합니다.");
            break;
        }
        
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

void SelOne(unsigned rsize, struct data *Book1){
    FILE *fsave;
    
    fflush(stdin);
    printf("\n 이    름[8자] : ");
    gets(Book1->cName); // 입력한 문자열을 book1이라는 포인트변수가 가리키는 cName에 넣어달라는 함수
    printf("\n 전화번호[16자] : ");
    gets(Book1->cTel);
    printf("\n 주    소[24자] : ");
    gets(Book1->cAddr);
    
    if (strlen(Book1->cName) < 1 || strlen(Book1->cTel) < 1 || strlen(Book1->cAddr) < 1 ) { // String length 의미 , 입력을 안했을 경우
        printf("제대로 다시 입력하세요! ");
    } else { //입력하는 구문
        fsave = fopen(_FILE_, "a+");
        fwrite(Book1, rsize, 1, fsave);
        fclose(fsave);
    }
    system("read");
}
void SelTwo(unsigned rsize, struct data *Book2){
    
    int nNum; // =조회를 입력할 변수 선언 scan
    FILE *fload; // 파일을 로드할 변수 선언
    int Cnt = Cnt_data(rsize); // 데이터(레코드)개수 세주는 함수 호출
    printf("총 %d 개의 데이터가 있습니다.\n", Cnt);
    printf("몇 번째의 데이터를 조회하시겠습니까? ");
    scanf("%d", &nNum);
    
    fload = fopen(_FILE_, "r+"); //파일을 읽기모드로 오픈
    fread(Book2, rsize, Cnt, fload); // 파일 읽기 함수
    for (int i=0; i<Cnt; i++){
        if(nNum-1 == i ){ // -1이유 : 5번을 입력하면 4번인덱스 (0 1 2 3 4) , 0번 인덱스를 보고싶으면 1번을 입력 ( 0 1 2 3 4)
            printf("\n %d번째 데이터 \n",i+1);
            printf("이   름 : %s\n",(Book2+i)->cName);
            printf("전화번호 : %s \n",(Book2+i)->cTel);
            printf("주   소 : %s \n",(Book2+i)->cAddr);
        }
    }
    fclose(fload);// 열어둔 파일을 반환,
    system("read");
} // 자료 검색 함수
void SelThree(unsigned rsize, struct data *Book2){
    int i, temp = 0;
    int Cnt;
    int nNum;
    FILE *fsave;
    FILE *fload;
    
    Cnt = Cnt_data(rsize);
    
    printf("총 %d개의 데이터가 있습니다. \n", Cnt);
    printf("몇 번째의 데이터를 수정하시겠습니까? ");
    scanf("%d", &nNum); // 입력받아서 몇번째를 수정할 건지 작성
    
    fload = fopen(_FILE_, "r+"); //
    fread(Book2, rsize, Cnt, fload);
    for (i=0; i < Cnt ; i++) {
        if(nNum-1 == i){
        printf("\n%d번 데이터 \n", i+1);
        fflush(stdin);
        printf("이   름 : ");
        gets((Book2+i)->cName);
        printf("전화번호 : ");
        gets((Book2+i)->cTel);
        printf("주   소 : ");
        gets((Book2+i)->cAddr);
        if(strlen((Book2+i)->cName) < 1 || strlen((Book2+i)->cTel) < 1 || strlen((Book2+i)->cAddr) < 1){
            temp++; // 임시 저장변수
        }
        }
     } // end for
    if (temp > 0 ){
        printf("아무런 입력이 없었기 때문에 주소를 수정하지 않았습니다.\n");
    } else {
        fsave = fopen(_FILE_, "w+");// 쓰기 권한을 줌.
        fwrite(Book2, rsize*Cnt, 1, fsave);
        fclose(fsave);
        printf("주소록을 수정 하였습니다. 파일을 저장합니다. \n");
    }
    printf("수정을 마칩니다.\n");
    fclose(fload);
    system("read");
    
} // 자료 수정 함수 end
void SelFour(unsigned rsize, struct data *Book2) {
    int i, j=0;
    int nNum;
    char cyn;
    int Cnt = Cnt_data(rsize);
    FILE *fsave; // write
    FILE *fload; // read
    
    printf("총 %개의 데이터가 있습니다. \n", Cnt);
    
    if (Cnt == 1 ) { // data가 1개 밖에 없다면
        printf("1개의 데이터만 존재하므로 삭제가 불가능 합니다.");
        fflush(stdin);
        printf("모두 삭제 하시겠습니까? (Y/N)");
        cyn = getchar(); // 한글자의 문자를 입력받을땐 이 방법도 가능 ,한글자를 입력하는 함수를 사용 scanf("%c",&cyn);
        if ( cyn == 'Y' || cyn == 'y' ) {
            unlink(_FILE_); // file이 연결된 것을 소멸
        } else {
            printf("취소 되었습니다.\n");
        }
    } else {
        while (1) {
            printf("몇번째 데이터를 삭제하시겠습니까? ");
            scanf("%d", &nNum);
            if (nNum <= Cnt) break;
        }
        fopen(_FILE_, "r+");
        fread(Book2, rsize, Cnt, fload );
        for(i = 0; i< Cnt; i++ ){
            if ( i != nNum-1) { // 내가 삭제할 번호와 같지 않다면,
                if ( j == 0 ) fsave = fopen(_FILE_, "w+"); // j가 0이랑 같다면,(현재 아무 파일이 없기 때문에 0, ) 새로 생성파일을 만든다. w+
                else fsave = fopen(_FILE_, "a+");
                fwrite(Book2 + i, rsize, 1, fsave);
                fclose(fsave);
                j++;
            }
        }
        printf("선택하신 레코드가 삭제 되었습니다. \n");
        fclose(fload);
        printf("삭제를 끝냅니다. \n");
    }
    system("read");
}
void SelFive(unsigned rsize, struct data *Book1){
    
}
 
