#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    // const :   상수 명시, final :   상수 명시
    const float pi=3.14f;
    // const (항상 유지를 해야함, 변수를 상수로 명시)
    // pi = pi * 100; 변수는 상수 값을 새로 선언 할 수 없음.
    printf("%f\n", pi * 100 );  // 출력할 때 바꾸는 것은  괜찮다.
    
    int integer_number;        //변수선언
    integer_number = 50;     //변수 값을 넣는다(할당한다) 초기값
    integer_number = integer_number-10;
    
    float float_number = 3.14;
    char char_character = 'a';
    double double_number = 3.25784;
    short short_number = 32767; // 2byte 16bit 최대 숫자 32767
    short short_number1 = 5;
    short short_number2 = 32767 + 5;
    unsigned short unsignedshort_number = 65535;
    unsigned int unsignedint_number = 1234;
    unsigned long unsignedlong_number = 12345789;
        
    printf("%d\n",integer_number);        //정수
    printf("%f\n",float_number);    //실수
    printf("%lf\n",double_number);
    printf("short_number %d\n",short_number + short_number1 ); // 출력이 되면서 + 더하기 연산으로 인해 자료형 타입이 4byte로 형변환 됨.
        printf("short_number %d\n",short_number2 );
    printf("unsignedshort_number %d\n",unsignedshort_number);
    printf("%u\n",unsignedint_number);
    printf("%ld\n",unsignedlong_number);
    printf("문자형으로 출력 %c 숫자형으로 출력 %d\n",char_character,char_character);        //문자
    printf("%s\n","korea"); //문자열
    printf("%d %f %c %s \n",100,12.54,'b',"corner"); //제어문자를 한꺼번에 쓸 수도 있다.
    
    return 0;

}

/*
 signed
 signed는 C/C++ 프로그램 언어에서 정수형 변수 중 부호를 갖는 변수를 선언 한다. 정수형 중 음수는 2의 보수 체계를 사용하므로 이 키워드에 의해 부호를 사용할 수 있도록 변수 선언할 수 있다. 그러나 정수형의 변수에서 unsigned가 없으면 음수를 사용할 수 있는 부호를 갖는 정수형이 된다. 따라서 프로그램에서는 이 키워드는 많이 사용은 하지 않는다.

 unsigned
 unsigned는 C/C++ 언어에서 사용되는 지정자로 정수형과 같이 사용되어 부호 비트를 제거해 저장 가능한 양수 범위를 두배로 늘이는 역할을 한다. char와 int의 signed 정수형 변수에서 MSB가 부호 비트이다. 1이면 음수이고 0이면 양수이다. 그러나 unsigned을 사용하면 음수를 사용하지 않겠다는 의미 이므로 부호 비트가 필요 없다. 따라서 이진수와 같은 십진수가 된다.

 unsigned char
 8비트 정수형 변수 선언 char와 결합하여 선언하면 부호 비트가 필요 없으므로 0 ~ 255 범위를 갖는다.
 */
