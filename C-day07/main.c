#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>

#define FLUSH fflush(stdin)

struct banking {
   char acct_no[10]; //계좌번호
   char acct_name[10]; //계좌주 성명 
   int balance; //금액
};

int menu_disp(); //메뉴 함수 선언 

void init(struct banking *init, struct banking *init_rcv);//초기화 함수 선언 
void open(struct banking *popen, struct banking *prcv);//계좌 등록 함수 
void input(struct banking *pinput);//입금 함수 
void withdrawal(struct banking *pwithdrawal);//출금 함수 
void transfer(struct banking *ptransfer,struct banking *prcv);//계좌 이체 함수 
void balance(struct banking *pbalance,struct banking *prcv);//잔액 조회 함수 
void pfree(struct banking *pfree);//종료 함수


void main() {
   
   int choice;
   struct banking *account;//발신계좌 
   struct banking *rcv_acct;//수신계좌 
   
   account = (struct banking *) malloc (sizeof(struct banking));
   rcv_acct = (struct banking *) malloc (sizeof(struct banking));
   
   init(account, rcv_acct); //초기화 하는 함수 사용. (사용자 함수) 
   //구조체안에 기존의 자료가 있다면 모두 지우는 것이다.  
   
   while(1) {
      choice = menu_disp();//메뉴가 보이게 하도록 하는 함수 
      switch (choice) {
         case 1 : open(account, rcv_acct); // 계좌등록
            break; 
         case 2 : input(account); // 입금 
            break;
         case 3 : withdrawal(account); // 출금 
            break;
         case 4 : transfer(account, rcv_acct); // 계좌이체 
            break;
         case 5 : balance (account, rcv_acct); // 잔액조회 
            break;
         case 9 : pfree(account); pfree(rcv_acct); exit(0); // 종료하기 
         default : break;
      }
   }
}
//메뉴 
int menu_disp(){
   int ch;
   system("cls") ;
   printf("1. 계좌 등록\n");
   printf("2. 입     금\n");
   printf("3. 출     금\n");
   printf("4. 계좌 이체\n");
   printf("5. 잔액 조회\n");
   printf("9. 종     료\n");
   printf("선택[ ]\b\b");  //\b 백스페이스 : 백스페이스로 입력한 값이 들어올수있도록 해주는 것. 오... 
   scanf("%d", &ch);
   return ch;
}
//
void init(struct banking *init, struct banking *init_rcv){
   strset(init -> acct_no, 0);
   //init이 가르키는 구조체의 acct_no를 0으로 만들어라. 라는 의미임. 
   //strset은 string.h 에 있는 함수임.  
   strset(init -> acct_name, 0);
   init->balance = 0;
   //acct_balance는 int 타입이기 때문에 strset을 안해도 된다.  

   strset(init_rcv -> acct_no, 0);   
   strset(init_rcv -> acct_name, 0);
   init_rcv->balance = 0;   
}

void open(struct banking *popen, struct banking *prcv){
   int tx_rx;
   printf("1. 발신 계좌 등록 \n");
   printf("2. 수신 계좌 등록 \n");
   printf("선택[]\b\b");
   scanf("%d", &tx_rx);
   
   if (tx_rx == 1){
      printf("계좌 번호 (10)자 이내 : "); FLUSH; gets(popen -> acct_no);
      printf("계좌 성명 (10)자 이내 : "); FLUSH; gets(popen -> acct_name);
   } else {
      printf("계좌 번호 (10)자 이내 : "); FLUSH; gets(prcv->acct_no);
      printf("계좌 성명 (10)자 이내 : "); FLUSH; gets(prcv->acct_name);
   }
   
   printf("첫 거래 감사합니다"); FLUSH;
   printf("Press any key to continue ... ") ;
   getchar();
   //getchar ()는 엔터키를 먹어줌  
} 
//함수 저으이 해둘 것
void input(struct banking *pinput) {

} //입금 함수 
void withdrawal(struct banking *pwithdrawal){
}//출금 함수 
void transfer(struct banking *ptransfer,struct banking *prcv){
}//계좌 이체 함수 
void balance(struct banking *pbalance,struct banking *prcv){
}//잔액 조회 함수 
void pfree(struct banking *pfree){
}//종료 함수




