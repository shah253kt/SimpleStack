/*
 * Description: This example illustrates the basic usage of the library by creating a stack of size 5
 * and filling the stack with 3 integer values and popping them back out.
 *
 * Output:
 * Pushing data onto the stack...
 * Popping data from the stack...
 * 3
 * 2
 * 1
 */

#include <SimpleStack.h>

SimpleStack<int> myStack(5); // Create a stack with maximum size of 5.

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int myInt;

  Serial.println("Pushing data onto the stack...");
  myStack.push(1);
  myStack.push(2);
  myStack.push(3);

  // The output will be in inverted order from when the data were pushed.
  // This is the concept of a stack, which is FILO (First In, Last Out).

  Serial.println("Popping data from the stack...");
  myStack.pop(&myInt); // Pass the address of the variable. myStack.pop() returns a boolean. You can check if you have successfully popped a value by checking the returned value.
  Serial.println(myInt);

  myStack.pop(&myInt);
  Serial.println(myInt);

  myStack.pop(&myInt);
  Serial.println(myInt);

  delay(3000);
}
