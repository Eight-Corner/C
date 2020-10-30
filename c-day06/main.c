#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <process.h>

#define  _FILE_   "ADDRBOOK.dat" // 파일명 선언 

//구조체 선언  
 
struct data {
   char cName[8];
   char cTel[16];
   char cAddr[32];
};

//함수 선언 
void SelOne(unsigned, struct data *);//자료 입력 
void SelTwo(unsigned, struct data *);//자료 검색  
void SelThree(unsigned, struct data *);//자료 수정 
void SelFour(unsigned, struct data *);//자료 삭제 
void SelFive(unsigned, struct data *);//자료 조회 

int Cnt_data(unsigned); //레코드 인원수를 세어주는 함수  
 
int main(int argc, char *argv[]) {
    char cBtn;
   int Lec;
   unsigned rsize = sizeof(struct data);//56 byte
   
   struct data *Book1;//구조체에 접근하기 위해서 필요한 변수 Book1입니다. 그런데 이것을 포인터 변수로 쓴 것  
   struct data *Book2;
    
    
   while(1){
      //데이터 갯수 세기, 파일에 들어 있는 레코드 갯수 세기
      
      Lec=Cnt_data(rsize); //56
   //   Lec = 10;//임시로 반복문 멈추게 하기 위해서 조금 있다 지워야 함 
       Book1 = (struct data *)malloc(1*sizeof(struct data));//1개 레코드 넣을 메모리 확보 
       // 레코드 = 필드 + 필드 + 필드 / 레코드 = Book1에 저장  
       Book2 = (struct data *)malloc(Lec*sizeof(struct data));//파일안에 여러개의 레코드를 넣을 메모리 확보
	   //   
      system("cls");//커멘드 명령(윈도우 명령) 화면을 크리어하는 함수
      printf("구조체 크기 : %d\n", rsize);
      printf("데이터 갯수 : %d\n\n", Lec);
      
      if(Lec != 0 ){ //파일에 데이터가 이미 있는 경우  
         printf("1. 자료 입력 \n");
         printf("2. 자료 검색 \n");
         printf("3. 자료 수정  \n");
         printf("4. 자료 삭제 \n");
         printf("5. 자료 조회 \n");
         printf("0. 종     료 \n");
         printf("선택하세요 : ");
         scanf("%c", &cBtn);
      } else {  //제일 처음에 파일에 아무것도 없는 상태 
         cBtn='1'; 
      }
       if(cBtn == '1'){
          system("cls");
          SelOne(rsize, Book1);
      }else if(cBtn == '2'){
         if(Lec == 0 ){
            printf("검색할 데이터가 없습니다 \n");
            system("pause");
         }else{
            system("cls");
            SelTwo(rsize,Book2);
         }
      }else if(cBtn=='3'){
         if(Lec == 0) {
            printf("수정할 데이터가 없습니다 \n");
            system("pause");
         }else{
            system("cls");
            SelThree(rsize, Book2);
         }
      }else if(cBtn=='4'){
         if(Lec == 0){
            printf("삭제할 데이터가 없습니다 \n");
            system("pause");
         }else{
            system("cls");
            SelFour(rsize, Book2);
         }
      }else if(cBtn == '5'){
         if(Lec == 0 ){
            printf("조회할 데이터가 없습니다 \n");
            system("pause");
         }else{
            system("cls");
            SelFive(rsize, Book2);
         }
         
      }else if(cBtn == '0'){
         break;
      } 
   }
   
      
   return 0;

}

//레코드 갯수 세어 주는 함수  
int Cnt_data(unsigned  rsize){ //56
   int Cnt;
   FILE *fload;//fload라는 변수는 FILE의 포인터 변수이다. 
   
   fload = fopen(_FILE_, "r");
   if(fload == NULL) {
      Cnt = 0;
   }else{
      fseek(fload, -1, SEEK_END);//fseek(파일포인터, 이동할 크기, 기준점); 성공하면 0 실패하면 -1를 반환함 
    // 
      
      Cnt = (ftell(fload)/rsize)+1;//ftell(파일포인터) 파일포인터의 현재 위치를 반환한다. 실패하면 -1를 반환한다.   
      fclose(fload);
   }
   return Cnt;
}

void SelOne(unsigned rsize, struct data *Book1){
    FILE  *fsave;
    
    fflush(stdin);
    printf("\n 이  름[8자] :  ");
    gets(Book1->cName);
    printf("\n 전화번호[16자] :  ");
    gets(Book1->cTel);
    printf("\n 주   소[24자] :  ");
    gets(Book1->cAddr);
    
    if(strlen(Book1->cName) < 1 || strlen(Book1->cTel) < 1 || strlen(Book1 -> cAddr) < 1){
       printf("아무런 입력이 없어 주소록에 저장되지 않습니다 \n");
   }else{
     fsave = fopen(_FILE_, "a+");//append 추가    
     fwrite(Book1, rsize, 1, fsave);
     fclose(fsave);  
   }
   system("pause");
  }//자료 입력 
  
void SelTwo(unsigned rsize, struct data *Book2){
   
   int nNum,i;
   FILE *fload;
   int Cnt = Cnt_data(rsize);//데이터(레코드) 개수 세주는 함수 호출  
   printf("총 %d개의 데이터가 있습니다.\n ", Cnt);//ex) 3
   printf("몇 번째 데이터를 조회하시겠습니까? ");//ex) 5번 조회  
   scanf("%d", &nNum);//2
   
   fload = fopen(_FILE_, "r+"); 
   fread(Book2, rsize, Cnt, fload);
   for(i=0;i<Cnt;i++){ //i=0, 1
       if(nNum-1 == i){ //2-1 == 0 2-1 == 1
            printf("\n %d번째 데이터 \n", i+1);
            printf("이    름 : %s\n", (Book2+i)->cName);
            printf("전화번호 : %s \n", (Book2+i)->cTel);
            printf("주    소 : %s \n", (Book2+i)->cAddr);
      }
   }
   fclose(fload);
   system("pause");
 }//자료 검색  
 
void SelThree(unsigned rsize, struct data *Book2){
   
   int i, temp = 0;
   int Cnt;
   int nNum;
   FILE *fsave;
   FILE *fload;
   
   Cnt = Cnt_data(rsize);
   
   printf("총 %d개의 데이터가 있습니다. \n", Cnt);
   printf("몇 번째 데이터를 수정하시겠습니까? " );
   scanf("%d", &nNum);
   
   fload = fopen(_FILE_, "r+");
   fread(Book2, rsize, Cnt, fload);
   for(i=0;i<Cnt;i++){
       if(nNum-1 == i){
           printf("\n%d번째 데이터 \n", i+1);
           fflush(stdin);
           printf("이 름 : ");
           gets((Book2+i)->cName);
           printf("전화번호 : ");
           gets((Book2+i)->cTel);
           printf("주   소 : ");
           gets((Book2+i)->cAddr);
           if(strlen((Book2+i)->cName) <  1 || strlen((Book2+i)->cTel) < 1 || strlen((Book2+i)->cAddr) < 1) {
             temp++;               
       } 
          
      }
     
   }//end for
   
   if(temp > 0 ) {
        printf("아무런 입력이 없어 주소록를 수정 하지 않았습니다.\n");
   }else {
       fsave = fopen(_FILE_, "w+");
       fwrite(Book2, rsize*Cnt, 1, fsave);
       fclose(fsave);
   } 
   
   fclose(fload);
   system("pause");
   
 }//자료 수정 
void SelFour(unsigned rsize, struct data *Book2){
   int i, j=0;
   int nNum;
   char cYN;
   int Cnt = Cnt_data(rsize);
   FILE *fsave;//쓰기용  
   FILE *fload;//읽기용 
   
   printf("총 %d개의 데이터가 있습니다 \n", Cnt);
   
   if(Cnt == 1) {
      printf("1개의 데이터만 존재하므로 삭제가 불가능합니다 \n");
      fflush(stdin);
      printf("모두 삭제하시겠습니까?(Y/N)");
      cYN = getchar(); //scanf("%c", &cYN);
      if(cYN == 'Y' || cYN == 'y'){
         _unlink(_FILE_);
    }else{
     printf("취소되었습니다. ") ;    
    }
   } else {
       while(1) {
            printf("몇번째 데이터를 삭제하시겠습니까? ");
            scanf("%d", &nNum);
            if(nNum <= Cnt) break;   // 2 <= 3           
     } 
      fload = fopen(_FILE_, "r+");
      fread(Book2, rsize, Cnt, fload);
      for(i=0;i<Cnt;i++){
         if( i != nNum-1) { // 0 != 1
               if(j==0) fsave = fopen(_FILE_,"w+");
               else fsave = fopen(_FILE_, "a+");
               fwrite(Book2 + i, rsize, 1, fsave);
               fclose(fsave);
               j++;
         }
      }
         
         printf("선택하신 레코드가 삭제되었습니다.\n");
         fclose(fload);
      
   } 
      
   system("pause");

}//자료 삭제 
void SelFive(unsigned rsize, struct data *Book2){
  int i;
  int Cnt = Cnt_data(rsize);
  FILE *fload;
  
  printf("총 %d개의 데이터가 있습니다. ", Cnt);
  fload = fopen(_FILE_, "r+");
  fread(Book2, rsize, Cnt, fload);
  for(i=0;i<Cnt; i++){
     printf("\n %d번째 데이터 \n", i+1);
     printf("이   름 : %s \n ", (Book2+i)->cName);
     printf("전화번호: %s \n ", (Book2+i)->cTel);
     printf("주   소 : %s \n ", (Book2+i)->cAddr);
  }
  fclose(fload);
  system("pause");
}

//자료 조회 
