## 문제상황

guest-rnm1eg@h21758:~/Desktop/data_structure/SAT_problem$ g++ main.o SAT.o -o test
guest-rnm1eg@h21758:~/Desktop/data_structure/SAT_problem$ ./test
guest-rnm1eg@h21758:~/Desktop/data_structure/SAT_problem$ ./test
ab?cd??guest-rnm1eg@h21758:~/Desktop/data_structure/SAT_problem$ 
--> 위 파일들을 빌드하여, test 파일을 실행하게 되면, postfix에 저장된 논리연산자들이 ?로 출력되는 문제가 발생한다. 배열에 실제로 논리연산자 대신 ?가 저장된 것인지
아니면 출력만 ?로 되는 것인지 확인이 필요하다.



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
