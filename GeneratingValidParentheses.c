#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Windows ve Linux üzerinde bulunan sleep fonksiyonları için önişlemci direktifleri
#ifdef _WIN32
    #include <windows.h>
    #define delay(milliseconds) Sleep(milliseconds)
#elif defined(__linux__)
    #include <unistd.h>
    #define delay(milliseconds) usleep(milliseconds * 1000)
#else
    #error "Unsupported OS"
#endif

/* İstenilen uzunlukta kurallı rastgele parantez dizisi oluşturur.
 * Kurallar:
 * 1) Oluşturulan stringteki açık ve kapalı parantez sayısı aynı olmalı
 * 2) Kapalı parantez kullanılacaksa mutlaka ona denk açık bir parantez olmalı
*/
char *generateParentheses(size_t length){
    
    // Eğer uzunluk ikiden küçükse hata mesajı ver ve NULL döndür
    if (length < 2) {
        fprintf(stderr, "String length must be greater than two.\n");
        return NULL;
    }

    // Eğer uzunluk ikiye tam bölünmüyorsa uzunluğu bir arttır
    if (length % 2 != 0)
        length++;

    // Parantez dizisi için bellek tahsisi
    char *str = malloc(sizeof(char) * length + 1); // '\0' karakteri için uzunluk + 1
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }

    int index, max = length / 2;
    int openCount = 0, closeCount = 0;

    srand(time(NULL));
    
    // Parantezleri oluşturma işlemi
    for (index = 0; index < length; index++) {
        if (openCount <= closeCount) {
            str[index] = '(';
            openCount++;
        }
        else if (openCount == max && closeCount < max) {
                str[index] = ')';
                closeCount++;
        }
        else {
            str[index] = (rand() % 2) ? '(' : ')';
            str[index] == '(' ? openCount++ : closeCount++;
        }
    }
    str[index] = '\0';

    return str;
}

int main(void){
    
    int i;

    for (i = 0; i < 20; i++) {
        char *str = generateParentheses(20);
        if (str != NULL) {
            printf("[%02d] --> %s\n", (i + 1), str);
            free(str);
            delay(1000);
        }
    }
    
    return 0;
}