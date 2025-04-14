#include <cs50.h>
#include <stdio.h>

int main(void)
{
  // set variable with initial question
  string yourName = get_string("What's your name? ");
  // Print response with the value yourName
  printf("hello, %s\n", yourName);
}