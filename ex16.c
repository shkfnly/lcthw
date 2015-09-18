#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// define the the data types of the struct
struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

// This is creating a function that will create a struct.
struct Person *Person_create(char *name, int age, int height, int weight)
{
  /*  this creates a struct from person using the name passed so in the syntax
   *  struct Person *ashoka , ashoka becomes the *who. I am not sure why this works liek this.
   *  */
  struct Person *who = malloc(sizeof(struct Person));
  // assert that bad input not given
  assert(who != NULL);

  //assign properties of struct
  who->name = strdup(name);
  who->age = age;
  who->height = height;
  who->weight = weight;

  // return the instance of the sruct
  return who;
}

void Person_destroy(struct Person *who)
{
  assert(who != NULL);

  free(who->name);
  free(who);
}

void Person_print(struct Person *who)
{
  printf("Name: %s\n", who->name);
  printf("\tAge: %d\n", who->age);
  printf("\tHeight: %d\n", who->height);
  printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
  // make two people structures
  struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
  struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

  // print them out and where they are in memory
  printf("Joe is at memory location %p:\n", joe);
  Person_print(joe);

  printf("Frank is at memory location %p:\n", frank);
  Person_print(frank);

  // make everyone age 20 years and print this again
  joe->age += 20;
  joe->height -= 2;
  joe->weight += 40;
  Person_print(joe);

  frank->age += 20;
  frank->weight += 20;
  Person_print(frank);

  // destroy them both so we clean up
  Person_destroy(joe);
  Person_destroy(frank);

  return 0;

}
