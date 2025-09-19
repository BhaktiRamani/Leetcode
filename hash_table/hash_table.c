#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10 


typedef struct {
    char name[MAX_NAME];
    int age; 
} person; 


person *hash_table[TABLE_SIZE];

unsigned int hash(char* name)
{
    int len = strlen(name);
    unsigned int hash_value = 0;
    for(int i = 0; i< len; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }

    return hash_value;
    
}

bool init_hash_table()
{
    for(int i = 0; i< TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
    return true;
}

void print_hash_table()
{
    printf("Start\n");
    for(int i = 0; i< TABLE_SIZE; i++)
    {
        if(hash_table[i] == NULL){
            printf("\t%i\t--\n", i);
        }
        else{
            printf("\t%i\t%s\n",i, hash_table[i]->name);
        }

    }
    printf("End\n");
    return;
}

bool hash_table_insert(person *p)
{
    if(p==NULL) return false;
    int index = hash(p->name);
    for(int i = 0; i< TABLE_SIZE; i++)
    {
        int try = (i + index)%TABLE_SIZE;
        if(hash_table[try] == NULL)
        {
            printf("Index %d : %s\n", try, p);
            hash_table[try] = p;
            return true; 
        }
    }
    return false;
}

person *hash_table_delete(char *name)
{
    int index = hash(name);
    for(int i = 0; i< TABLE_SIZE; i++)
    {
        int try = (i+index)%TABLE_SIZE;
        if(hash_table[try] != NULL && (strncmp(hash_table[try] -> name, name, TABLE_SIZE)) == 0)
        {
        person *tmp = hash_table[try];
        hash_table[try] = NULL;
        return tmp;
        }
    }
    return NULL;
}


person *hash_table_lookup(char* name)
{
    int index = hash(name);
    for(int i = 0; i< TABLE_SIZE; i++)
    {
        int try = (i+index)%TABLE_SIZE;
        if(hash_table[try] != NULL && (strncmp(hash_table[try] -> name, name, TABLE_SIZE)) == 0)
        {
            printf("hash_table_lookup index : %d\n", try);
            return hash_table[try];
        }
    }
    return NULL;
}

int main()
{
    init_hash_table();
    print_hash_table();

    person bhakti = {.name="Bhakti", .age=20};
    person kavya = {.name="Kavya", .age=12};
    person foram = {.name="Foram", .age=23};
    person Durvisha = {.name="Durvisha", .age=23};
    person Parth = {.name="Parth", .age=23};
    person Dhruvi = {.name="Dhruvi", .age=23};
    person Suhani = {.name="Suhani", .age=23};
    person Preksha = {.name="Preksha", .age=23};
    person Jenisha = {.name="Jenisha", .age=23};

    hash_table_insert(&bhakti);
    hash_table_insert(&kavya);
    hash_table_insert(&foram);
    hash_table_insert(&Durvisha);
    hash_table_insert(&Parth);
    hash_table_insert(&Dhruvi);
    hash_table_insert(&Suhani);
    hash_table_insert(&Preksha);
    hash_table_insert(&Jenisha);

    print_hash_table();
    
    person *tmp = hash_table_lookup("Bhakti");
    if(tmp == NULL)
    {
        printf("Not Found\n");
    }
    else{
        printf("Index value is : %s\n", tmp->name);
    }
    tmp = hash_table_lookup("Jenisha");
    if(tmp == NULL)
    {
        printf("Not Found\n");
    }
    else{
        printf("Index value is : %s\n", tmp->name);
    }

    tmp = hash_table_delete("Jenisha");
    if(tmp == NULL)
    {
        printf("Not Found\n");
    }
    else{
        printf("Index value is : %s\n", tmp->name);
    }
     print_hash_table();
    return 0;
}