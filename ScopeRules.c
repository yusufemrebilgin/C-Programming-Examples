#include <stdio.h>

//Function prototypes
void useLocal(void);
void useStaticLocal(void);
void useGlobal(void);

int x = 5; //Global variable

int main(void){
    
    int x = 20; //Local variable to main

    printf("Local x in outer scope of main is %d\n", x);

    {//start new scope

        int x = 7;
        printf("Local x in inner scope of main is %d\n", x);

    }//end new scope

    printf("Local x in outer scope of main is %d\n", x);

    useLocal();             //useLocal has automatic local
    useStaticLocal();       //useStaticLocal has static local
    useGlobal();            //useGlobal uses global
    useLocal();             //useLocal reinitializes automatic local
    useStaticLocal();       //static local x retains its prior value
    useGlobal();            //global x also retains its value

    printf("Local x in main is %d\n", x);

    return 0;
}

//useLocal reinitializes local variable x during each call
void useLocal(void){
    int x = 25;

    printf("\nLocal x in useLocal is %d after entering useLocal\n", x);
    x++;
    printf("Local x in useLocal is %d before exiting useLocal\n", x);
}

//useStaticLocal initializes static local variable x only first time the function is called,
//value of x is saved between calls to this function
void useStaticLocal(void){
    static int x = 50; //initialized only first time useStaticLocal is called

    printf("\nLocal static x is %d on entering useStaticLocal\n", x);
    x++;
    printf("Local static x is %d on exiting useStaticLocal\n", x);
}

//Function useGlobal modifies global variable x during each call
void useGlobal(void){

    printf("\nGlobal x is %d on entering useGlobal\n", x);
    x *= 10;
    printf("Global x is %d on exiting useGlobal\n", x);
}