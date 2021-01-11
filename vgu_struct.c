#include <stdio.h>
#include <string.h>

struct person
{
    char name[50]; 
    int id; 
    int year_of_birth;
};

int main()
{
    //create a struct 
    struct  person a_person; 

    //set value
    strcpy(a_person.name, "Peter"); 
    a_person.id = 123456;
    a_person.year_of_birth = 1998;

    //print the value
    printf("Person name: %s\n", a_person.name); 
    printf("Person id: %d\n", a_person.id); 
    printf("Person year of birth: %d\n", a_person.year_of_birth);
    
    return 0; 
}