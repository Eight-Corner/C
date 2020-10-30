#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>

#define FLUSH fflush(stdin)

struct banking {
   char acct_no[10]; //���¹�ȣ
   char acct_name[10]; //������ ���� 
   int balance; //�ݾ�
};

int menu_disp(); //�޴� �Լ� ���� 

void init(struct banking *init, struct banking *init_rcv);//�ʱ�ȭ �Լ� ���� 
void open(struct banking *popen, struct banking *prcv);//���� ��� �Լ�  prcv = ���Ű���  
void input(struct banking *pinput);//�Ա� �Լ� 
void withdrawal(struct banking *pwithdrawal);//��� �Լ� 
void transfer(struct banking *ptransfer,struct banking *prcv);//���� ��ü �Լ� 
void balance(struct banking *pbalance,struct banking *prcv);//�ܾ� ��ȸ �Լ� 
void pfree(struct banking *pfree);//���� �Լ�


void main() {
   
   int choice;
   struct banking *account;//�߽Ű��� 
   struct banking *rcv_acct;//���Ű��� 
   
   account = (struct banking *) malloc (sizeof(struct banking));
   rcv_acct = (struct banking *) malloc (sizeof(struct banking));
   
   init(account, rcv_acct); //�ʱ�ȭ �ϴ� �Լ� ���. (����� �Լ�) 
   //����ü�ȿ� ������ �ڷᰡ �ִٸ� ��� ����� ���̴�.  
   
   while(1) {
      choice = menu_disp();//�޴��� ���̰� �ϵ��� �ϴ� �Լ� 
      switch (choice) {
         case 1 : open(account, rcv_acct); // ���µ��
            break; 
         case 2 : input(account); // �Ա� 
            break;
         case 3 : withdrawal(account); // ��� 
            break;
         case 4 : transfer(account, rcv_acct); // ������ü 
            break;
         case 5 : balance (account, rcv_acct); // �ܾ���ȸ 
            break;
         case 9 : pfree(account); pfree(rcv_acct); exit(0); // �����ϱ� 
         default : break;
      }
   }
}
//�޴� 
int menu_disp(){
   int ch;
   system("cls") ;
   printf("1. ���� ���\n");
   printf("2. ��     ��\n");
   printf("3. ��     ��\n");
   printf("4. ���� ��ü\n");
   printf("5. �ܾ� ��ȸ\n");
   printf("9. ��     ��\n");
   printf("����[ ]\b\b");  //\b �齺���̽� : �齺���̽��� �Է��� ���� ���ü��ֵ��� ���ִ� ��. ��... 
   scanf("%d", &ch);
   return ch;
}
//
void init(struct banking *init, struct banking *init_rcv){
   strset(init -> acct_no, 0);
   //init�� ����Ű�� ����ü�� acct_no�� 0���� ������. ��� �ǹ���. 
   //strset�� string.h �� �ִ� �Լ���.  
   strset(init -> acct_name, 0);
   init->balance = 0;
   //acct_balance�� int Ÿ���̱� ������ strset�� ���ص� �ȴ�.  

   strset(init_rcv -> acct_no, 0);   
   strset(init_rcv -> acct_name, 0);
   init_rcv->balance = 0;   
}

void open(struct banking *popen, struct banking *prcv){
   int tx_rx;
   printf("1. �߽� ���� ��� \n");
   printf("2. ���� ���� ��� \n");
   printf("����[]\b\b");
   scanf("%d", &tx_rx);
   
   if (tx_rx == 1){
      printf("���� ��ȣ (10)�� �̳� : "); FLUSH; gets(popen -> acct_no);
      printf("���� ���� (10)�� �̳� : "); FLUSH; gets(popen -> acct_name);
   } else {
      printf("���� ��ȣ (10)�� �̳� : "); FLUSH; gets(prcv->acct_no);
      printf("���� ���� (10)�� �̳� : "); FLUSH; gets(prcv->acct_name);
   }
   
   printf("ù �ŷ� �����մϴ�"); FLUSH;
   printf("Press any key to continue ... ") ;
   getchar();
   //getchar ()�� ����Ű�� �Ծ���  
} 
//�Լ� ����  �ص� ��
void input(struct banking *pinput) { //�Ա� �Լ�
	char temp_acct_no[10];
	int result, money; 
	printf("��/����� �߽� ���¿����� �����մϴ�. \n");
	printf("���¹�ȣ [10�� �̳�]");
	scanf("%s", temp_acct_no);
	result = strcmp(pinput->acct_no, temp_acct_no); 
	// ��Ʈ�� ���� �߽Ű��� ��� ���¹�ȣ�� ���� �Է� ���¹�ȣ�� ������ �� 
	 // ���ؼ� ������ 0�� �����ϰ� ���� �ʴٸ� 0�� �ƴѼ��� ����  
	if (result == 0 ){
		printf("�Ա� �� �ݾ� : ");
		scanf("%d", &money); 
		pinput->balance = pinput -> balance + money; 
		// ������ ����ִ� �ݾ׿��� �ֱ�s
	} else {
		printf("\n��ġ�ϴ� ���¹�ȣ�� �����ϴ�");
		FLUSH;
		printf("\n... ����Ϸ��� �ƹ�Ű�� �Է��ϼ���. ");
		getchar();
	}
} 
void withdrawal(struct banking *pwithdrawal){ //��� �Լ�
} 
void transfer(struct banking *ptransfer,struct banking *prcv){ //���� ��ü �Լ� 
}
void balance(struct banking *pbalance,struct banking *prcv){ //�ܾ� ��ȸ �Լ� 
	char temp_acct_no[10];
   int result, match=0;
   printf("���� ��ȣ : ");
   scanf("%s", temp_acct_no);
   // �߽Ű��� �˻�  
   result = strcmp(pbalance->acct_no, temp_acct_no) ;
   
   // �߽� ���¸� ��ȸ������ match�� 1�� ����
   if(result == 0) { 
     printf("���� ��ȣ : %s",pbalance->acct_no );
     printf("���� ���� : %s", pbalance->acct_name );
     printf("��    �� : %d", pbalance->balance );
     match=1; 
   }
   
   result = strcmp(prcv->acct_no, temp_acct_no) ;  // ���Ű��� �˻�
  
   // �߽� ���¸� ��ȸ������ match�� 1�� ����  
   if(result == 0) {		
     printf("���� ��ȣ : %s",prcv->acct_no );
     printf("���� ���� : %s", prcv->acct_name );
     printf("��    �� : %d", prcv->balance );
     match=1; 
   }
   
   if(match==0) 
      printf("���¹�ȣ ���� �Դϴ� .");
   FLUSH;
   printf("...Press any key to continue... ");
   getchar();

  
	
	}
  

	
	
void pfree(struct banking *pfree){ //���� �Լ�
}




