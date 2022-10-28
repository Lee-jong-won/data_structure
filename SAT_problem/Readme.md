## 221023일 문제상황
![image](https://user-images.githubusercontent.com/78682445/197346806-7b1318e0-2f4c-4f51-ab08-9d78b3b97df3.png)   
--> 위 파일들을 빌드하여, test 파일을 실행하게 되면, postfix에 저장된 논리연산자들이 ?로 출력되는 문제가 발생한다. 배열에 실제로 논리연산자 대신 ?가 저장된 것인지   
아니면 출력만 ?로 되는 것인지 확인이 필요하다.


## 해결방법

main.cpp를 다음과 같은 코드로 수정하여 실제로 배열에 어떤 값이 저장되어 있는지 hex값으로 데이터를 나타내보자


    #include "SAT.h"
    #include "string.h"
    #include <iostream>

    using std::wcout;

    int main()
    {
      SAT_problem my_sat;
      my_sat.to_postfix(L"(a∧b)∨(c∧d)");

      wcout << my_sat.postfix;


      /*
      int index = 0;
    
      for(index = 0; index < wcslen(my_sat.postfix); index++)
      {
        if(index % 16 == 0) printf("\n");
        printf("0x%02X ", my_sat.postfix[index]);
      }
      */
    }
    
 ![image](https://user-images.githubusercontent.com/78682445/197347097-f93fc8cd-5a4d-4c3b-acc4-b3b7ba47f8d7.png)   
 위 사진과 같이 실제로 hex값으로 데이터를 나타내보면, 배열에 내가 입력한 명제가 잘 저장되어 있는 것을 알 수 있다.
 
 #221028일 문제상황
 
 infix에서 postfix로 문장의 형태를 바꾼 후, 객체 내의 postfix 포인터를 통해, postfix 문자열의 첫번째 요소에 접근하려고 하면, segment fault가 뜬다.
