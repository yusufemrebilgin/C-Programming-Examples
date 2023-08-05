#include <stdio.h>

int main(void){

    // Kaynak dosyasının ismini verir
    printf("%s\n", __FILE__);

    // Bulunduğu satır numarasını verir
    printf("%d\n", __LINE__);

    // Tarihi belirtir
    printf("%s\n", __DATE__);

    // Saati belirtir
    printf("%s\n", __TIME__);

    // Hangi fonksiyonun içinde olduğunu belirtir
    printf("%s\n", __func__);
    
    return 0;
}