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
void open(struct banking *popen, struct banking *prcv);//계좌 등록 함수  prcv = 수신계좌  
void input(struct banking *pinput);//입금 함수 
void withdrawal(struct banking *pwithdrawal);//출금 함수 
void transfer(struct banking *ptransfer,struct banking *prcv);//계좌 이체 함수 
void balance(struct banking *pbalance,struct banking *prcv);//잔액 조회 함수 


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
         case 9 : exit(0); // 종료하기 
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
//함수 정의  해둘 것
void input(struct banking *pinput) { //입금 함수
	char temp_acct_no[10];
	int result, money; 
	printf("입/출금은 발신 계좌에서만 가능합니다. \n");
	printf("계좌번호 [10자 이내]");
	scanf("%s", temp_acct_no);
	result = strcmp(pinput->acct_no, temp_acct_no); 
	// 스트링 컴페어가 발신계좌 등록 계좌번호와 지금 입력 계좌번호가 같은지 비교 
	 // 비교해서 같으면 0을 리턴하고 같지 않다면 0이 아닌수를 리턴  
	if (result == 0 ){
		printf("입금 할 금액 : ");
		scanf("%d", &money); 
		pinput->balance = pinput -> balance + money; 
		// 기존에 들어있는 금액에다 넣기s
	} else {
		printf("\n일치하는 계좌번호가 없습니다");
		FLUSH;
		printf("\n... 계속하려면 아무키를 입력하세요. ");
		getchar();
	}
} 
void withdrawal(struct banking *pwithdrawal){ //출금 함수
	char temp_acct_no[10];
	int result, money;
	printf("출금하시려는 계좌번호를 입력하세요.\n");
	printf("계좌번호 [10자 이내] : ");
	scanf("%s", temp_acct_no);
	
	result = strcmp(pwithdrawal->acct_no, temp_acct_no);
	
	if (result == 0 ){
		printf("출금 할 금액 : ");
		scanf("%d", &money);
		if( money > pwithdrawal->balance){ // 포인트가 balnace를 가르키는 돈이 money보다 크다면 
			printf("잔액이 부족합니다.\n");
			FLUSH;
			printf("...진행하려면 아무키를 입력하세요..");
			getchar(); 
		} else {  
	    pwithdrawal->balance = pwithdrawal->balance - money;
	    // 원래 잔액에서 money값을 빼서 코드(원래잔액)에 대입 
		}  
	} else {
		printf("일치하는 계좌번호가 없습니다. \n");
		FLUSH;
		printf("...진행하려면 아무키를 입력하세요. ");
		getchar();
	}
 

} 
void transfer(struct banking *ptransfer,struct banking *prcv){ //계좌 이체 함수 
		char temp_acct_no[10];
		int result1,result2,money;
		
		printf("보낼사람의 계좌번호를 입력하세요. : ");
		scanf("%s", temp_acct_no);
		
		result1 = strcmp(ptransfer->acct_no,temp_acct_no);  //내가 입력한 값(temp_acct_no)와 계좌번호가 같는지
		
		if(result1 == 0 ){
			printf("잔 액 : %d \n", ptransfer->balance);	
			printf("받을사람의 계좌번호를 입력하세요. : ");
			scanf("%s",temp_acct_no);
				result2 = strcmp(prcv->acct_no, temp_acct_no); //수신 계좌(prcv)랑 비교 
		
			if(result2 == 0){ 
				printf("이체할 금액을 입력하세요 : ");
				scanf("%d", &money);
			
				if(money > ptransfer->balance ) {  // 보낼 사람의 금액이 money보다 크다면 
					printf("이체할 금액이 부족합니다.\n");
					printf("잔액을 다시 확인하세요. ");
					FLUSH;
					printf("계속 진행하려면 아무키를 입력하세요. ");
					getchar();
			} else { // 보낼 사람의 금액이 충분하므로 이체 구문작성 
				ptransfer->balance -= money;  //보낼사람의 계좌의 금액에서 money를 뺀다.
				printf("계좌번호 : %s 로 %d 원이 송금 되었습니다. ", prcv->acct_no, money);
				prcv->balance += money; // 수신계좌의 잔액에 금액을 추가시킴
				printf("발신 계좌번호: %s의 잔액은 %d 원 있습니다.", ptransfer->acct_no, ptransfer->balance);
				printf("수신 계좌번호: %s의 잔액은 %d 원 있습니다.", prcv->acct_no, prcv->balance);
				FLUSH;
				printf("계속 진행하려면 아무키를 입력하세요. ");
					getchar();
			}
		}  else {
			printf("일치하는 계좌번호가 없습니다. \n");
			FLUSH;
			printf("...진행하려면 아무키를 입력하세요. ");
			getchar();
		}
	}  else {
			printf("일치하는 계좌번호가 없습니다. \n");
			FLUSH;
			printf("...진행하려면 아무키를 입력하세요. ");
			getchar();
		}

}
void balance(struct banking *pbalance,struct banking *prcv){ //잔액 조회 함수 
	char temp_acct_no[10];
   int result, match=0;
   printf("계좌 번호 : ");
   scanf("%s", temp_acct_no);
   // 발신계좌 검색  
   result = strcmp(pbalance->acct_no, temp_acct_no) ;
   
   // 발신 계좌를 조회했을때 match를 1로 변경
   if(result == 0) { 
     printf("계좌 번호 : %s",pbalance->acct_no );
     printf("계좌 성명 : %s", pbalance->acct_name );
     printf("금    액 : %d", pbalance->balance );
     match=1; 
   }
   
   result = strcmp(prcv->acct_no, temp_acct_no) ;  // 수신계좌 검색
  
   // 발신 계좌를 조회했을때 match를 1로 변경  
   if(result == 0) {		
     printf("계좌 번호 : %s",prcv->acct_no );
     printf("계좌 성명 : %s", prcv->acct_name );
     printf("금     액 : %d", prcv->balance );
     match=1; 
   }
   
   if(match==0) 
      printf("계좌번호 오류 입니다 .");
   FLUSH;
   printf("...Press any key to continue... ");
   getchar();
	
	}
 




