#include <stdio.h>

void fun1(void){ printf("fun1()\n"); }
void fun2(void){ printf("fun2()\n"); }

int main(void){
    
    void (*fPtr1)(void) = &fun1;
    (*fPtr1)();

    void (*fPtr2)(void) = fun2;
    fPtr2();

    return 0;
}