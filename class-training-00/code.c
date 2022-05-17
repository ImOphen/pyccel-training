#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// class definiton
typedef struct t_person {
    char *name;
    int age;
    void (*myfunc)(struct t_person *self);
} person;

// method
void myfunc_person_class(person *p) {
    printf("%s is %d years old\n", p->name, p->age);
}

// __init__ magic method
void *__init__person_class(char *name, int age) {
    person *p = malloc(sizeof(person));
    p->name = name;
    p->age = age;
    p->myfunc = myfunc_person_class;
    return p;
}

// __call__ magic method
void __call__person_class(person *p, char *name, int age) {
	p->name = name;
	p->age = age;
    p->myfunc = myfunc_person_class;
}

// free array of pointers
void free_array(void **ptr, int size){
	int i = 0;
	for (; i < size; i++)
		free(ptr[i]);
	free(ptr);
}

// copy an object and return the new allocated copy
person *copy_class_person(person *ptr)
{
	person *p = (person *)__init__person_class(ptr->name, ptr->age);
	p->name = ptr->name;
	p->age = ptr->age;
	return p;
}

int main()
{
	// p = person("Ophen",19)
    person *p = NULL;
	p = (person *)__init__person_class("Ophen", 19);

	// p.myfunc_person_class()
    p->myfunc(p);
    // p.age = 20;
    p->age = 20;

	// p.myfunc_person_class()
    p->myfunc(p);

	// p2 = person("Saad",22)
    person *p2 = NULL;
	p2 = (person *)__init__person_class("Saad", 22);
	
	// print(f"the combined age of {p.name} and {p2.name} is {p.age + p2.age}")
    printf("the combined age of %s and %s is %d\n", p->name, p2->name, p->age + p2->age);

	// if p.age > p2.age:
    if (p->age > p2->age)
		// print(f"{p.name} is older than {p2.name}")
        printf("%s is older than %s\n", p->name, p2->name);
    else
		// print(f"{p2.name} is older than {p.name}")
        printf("%s is older than %s\n", p2->name, p->name);

	// persons = []
    person **persons = NULL;
    int __size_of_persons = 0;
    person *person_tmp = NULL;

	// persons.append(person("Jawad",99))
    __size_of_persons += 1;
    persons = realloc(persons ,(__size_of_persons) * sizeof(person *));
	person_tmp = (person *)__init__person_class("Jawad", 99);
    persons[0] = copy_class_person(person_tmp);
	free(person_tmp);

	// persons[0].myfunc_person_class();
    persons[0]->myfunc(persons[0]);

	// persons.append(person("rida",55))
    __size_of_persons += 1;
    persons = realloc(persons ,(__size_of_persons) * sizeof(person *));
	person_tmp = (person *)__init__person_class("rida", 55);
    persons[1] = copy_class_person(person_tmp);
	free(person_tmp);

	// persons[1].myfunc_person_class();
    persons[1]->myfunc(persons[1]);

	// persons.append(p)
    __size_of_persons += 1;
    persons = realloc(persons ,(__size_of_persons) * sizeof(person *));
    persons[2] = copy_class_person(p);

	// persons[2].myfunc_person_class();
    persons[2]->myfunc(persons[2]);

    // del persons[1]
    for (int i = 1;i < __size_of_persons - 1;i++)
	{
		free(persons[i]);
        persons[i] = persons[i + 1];
    }
	__size_of_persons -= 1;
    persons = realloc(persons ,(__size_of_persons) * sizeof(person *));
	// persons[1].myfunc_person_class();
   persons[1]->myfunc(persons[1]);

	// persons[0]("Rina", 18);
	__call__person_class(persons[0], "Rina", 18);

	// persons[0].myfunc_person_class();
    persons[0]->myfunc(persons[0]);

	// freeing all allocated memory
	free_array((void **)persons, __size_of_persons);
    free(p);
    free(p2);

	return (0);
}