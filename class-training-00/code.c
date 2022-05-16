#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// class definiton
typedef struct t_person {
    char *name;
    int age;
} person;

void __init__person_class(person *p, char *name, int age) {
    p->name = name;
    p->age = age;
}

void __call__person_class(person *p, char *name, int age) {
	p->name = name;
	p->age = age;
}

void myfunc(person *p) {
    printf("%s is %d years old\n", p->name, p->age);
}

void free_array(void **ptr, int size){
	int i = 0;
	for (; i < size; i++)
		free(ptr[i]);
	free(ptr);
}

person *copy_class_person(person *ptr)
{
	person *p = malloc(sizeof(person));
	p->name = ptr->name;
	p->age = ptr->age;
	return p;
}

int main()
{
    person *p = NULL;
	p = malloc(sizeof(person));
    __init__person_class(p, "Ophen", 19);
    myfunc(p);

    p->age = 20;
    myfunc(p);

    person *p2 = NULL;
	p2 = malloc(sizeof(person));
    __init__person_class(p2, "Saad", 22);
    printf("the combined age of %s and %s is %d\n", p->name, p2->name, p->age + p2->age);

    if (p->age > p2->age)
        printf("%s is older than %s\n", p->name, p2->name);
    else
        printf("%s is older than %s\n", p2->name, p->name);

    person **persons = NULL;
    int __size_of_persons = 0;
    person *person_tmp = NULL;

    __size_of_persons += 1;
    persons = realloc(persons ,(__size_of_persons) * sizeof(person *));
	person_tmp = malloc(sizeof(person));
    __init__person_class(person_tmp, "Jawad", 99);
    persons[0] = copy_class_person(person_tmp);
	free(person_tmp);
    myfunc(persons[0]);

    __size_of_persons += 1;
    persons = realloc(persons ,(__size_of_persons) * sizeof(person *));
	person_tmp = malloc(sizeof(person));
    __init__person_class(person_tmp, "rida", 55);
    persons[1] = copy_class_person(person_tmp);
	free(person_tmp);
    myfunc(persons[1]);

    __size_of_persons += 1;
    persons = realloc(persons ,(__size_of_persons) * sizeof(person *));
    persons[2] = copy_class_person(p);
    myfunc(persons[2]);
    
    for (int i = 1;i < __size_of_persons - 1;i++)
	{
		free(persons[i]);
        persons[i] = persons[i + 1];
    }
	__size_of_persons -= 1;
    persons = realloc(persons ,(__size_of_persons) * sizeof(person *));
    myfunc(persons[1]);

	__call__person_class(persons[0], "Rina", 18);
	myfunc(persons[0]);

	free_array((void **)persons, __size_of_persons);
    free(p);
    free(p2);
	return 0;
}