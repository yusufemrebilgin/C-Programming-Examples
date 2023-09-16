#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
} User;

int cmpUserID(const void *a, const void *b){
    if (((const User *)a)->id > ((const User *)b)->id)
        return 1;
    else if (((const User *)a)->id < ((const User *)b)->id)
        return -1;
    else 
        return 0;
}

int cmpUserName(const void *a, const void *b){
    return strcmp(((const User *)a)->name, ((const User *)b)->name);
}

int main(void){

    User users[] = {{23,"Yusuf"}, {34,"Mustafa"}, {2,"Murat"}, {5,"Mehmet"}, {28,"Ali"}};
    int size = sizeof(users) / sizeof(User);

    qsort(users, size, sizeof(User), cmpUserID);

    printf("Sorted by ID:\n");
    for (int i = 0; i < size; i++)
        printf("%d\t%s\n", users[i].id, users[i].name);

    qsort(users, size, sizeof(User), cmpUserName);

    printf("\nSorted by name:\n");
    for (int i = 0; i < size; i++)
        printf("%d\t%s\n", users[i].id, users[i].name);

    return 0;
}