//Bit Düzeyi(& ve |) ve Mantıksal(&& ve ||) Operatörler Arasındaki Farklar
#include <stdio.h>

int fun1(void){
    printf("fun1()\n");
    return 1;
}
int fun2(void){
    printf("fun2()\n");
    return 2;
}

void main(void){

    /*
    İlk ifade 'false' olduğu için sağ taraftaki ifade değerlendirilmez. Sağ taraftaki ifadenin 
    değerlendirilmesi için sol taraftaki ifadenin 'true' olması gerekir. 
    */
    if ((fun1() == 2) && (fun2() == 1))
        printf("true\n\n");
    else
        printf("false\n\n");
    
    /*
    Burada ikinci ifade de değerlendirilir çünkü '&' operatörü her zaman her iki ifadeyi de
    değerlendirir.
    */
    if ((fun1() == 2) & (fun2() == 1))
        printf("true\n\n");
    else
        printf("false\n\n");
    
    /*
    Sol taraftaki ifade 'true' olduğundan dolayı sağ taraftaki ifadenin değerlendirilmesine 
    gerek duyulmaz.
    */
    if ((fun1() == 1) || (fun2() == 2))
        printf("true\n\n");
    else
        printf("false\n\n");

    /*
    Bit düzeyinde '|' operatörü kullandığımız için her iki tarafta değerlendirilir.
    */
    if ((fun1() == 1) | (fun2() == 2))
        printf("true\n\n");
    else
        printf("false\n\n");

}