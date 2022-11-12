/*
 * Description: This example shows how you can use pointer with SimpleStack.
 * 
 * Output:
 * 253
 */

#include <SimpleStack.h>

class MyClass {
  private:
    int myPrivateInt;

  public:
    MyClass(int privateInt) : myPrivateInt(privateInt) {}

    int getPrivateInt() {
      return myPrivateInt;
    }
};

SimpleStack<MyClass *> myStack(5); // Create a stack with maximum size of 5
MyClass myObject(253); // Create an object

void setup() {
  Serial.begin(9600);
  myStack.push(&myObject); // Push object onto the stack once
}

void loop() {
  MyClass *myTempObject; // Create a temporary object
  myStack.peek(&myTempObject); // Peek the object at the top of the stack
  Serial.println(myTempObject->getPrivateInt());
  delay(3000);
}
