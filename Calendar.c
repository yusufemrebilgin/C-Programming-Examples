#include <stdio.h>
#include <time.h>

int main(void){

    const char *days[] = {"Pt","Sa","Ca","Pe","Cu","Ct","Pa"};

    const char *months[] = {"Ocak","Subat","Mart","Nisan","Mayis","Haziran",
                        "Temmuz","Agustos","Eylul","Ekim","Kasim","Aralik"};
    

    //time() fonksiyonu, 1 Ocak 1970'den itibaren geçen zamanı döndürür.
    time_t t = time(NULL);

    /*
    time() fonksiyonundan dönen değeri kullanabilmemiz için time_t değişkenini localtime()
    fonksiyonuna parametre olarak gönderip dönen adresi 'struct tm' yapısınında tutarız.
    */
   
    struct tm *tm = localtime(&t);
    
    printf("--------------------------------------\n");
    printf("%d %s %d\t\t\t %02d:%02d\n\n", tm->tm_mday, months[tm->tm_mon], tm->tm_year + 1900, tm->tm_hour, tm->tm_min);
    
    int i;
    for (i = 0; i < 7; i++)
        printf("%-6s", days[i]);
    printf("\n\n");

    int firstDayOfMonth = 1;
    int lastDayOfMonth;
    {
        int mon = tm->tm_mon + 1;
        if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 ||mon == 10 || mon == 12)
            lastDayOfMonth = 31;
        else if (mon == 2) {
            int year = tm->tm_year + 1900;
            lastDayOfMonth = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28;
        }
        else
            lastDayOfMonth = 30;
    }
    
    int dayOfTheWeek = (tm->tm_wday == 0) ? 7 : tm->tm_wday;

    //Ayın ilk gününe kadar olan boşlukları ayarlar.
    int leadingSpaces = (dayOfTheWeek - (tm->tm_mday % 7) + 7) % 7;
    for (i = 0; i < leadingSpaces; i++)
        printf("      ");
    
    for (i = leadingSpaces + 1; firstDayOfMonth <= lastDayOfMonth; firstDayOfMonth++) {
        printf("%02d    ", firstDayOfMonth);
        if (i++ % 7 == 0) printf("\n\n");
    }
    
    return 0;
}