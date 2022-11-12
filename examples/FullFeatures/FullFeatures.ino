/*
 * Description: This example utilizes all features of the SimpleStack.
 *
 * Output:
 * Stack is full
 * Current content of the stack:
 * 1
 * 2
 * 3
 * 4
 * 5
 * Popped data: 5
 * Top-most data now: 4
 * Current content of the stack:
 * 1
 * 2
 * 3
 * 4
 * Resetting the stack...Failed to pop the stack. The stack is empty.
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

    // Push data
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    // Error checking
    if (!myStack.push(6))
    {
        Serial.println("Stack is full");
    }

    printStack(); // Print content of the stack

    myStack.pop(&myInt); // Remove the top-most object
    Serial.print("Popped data: ");
    Serial.println(myInt);

    myStack.peek(&myInt);
    Serial.print("Top-most data now: ");
    Serial.println(myInt);

    printStack(); // Print content of the stack

    Serial.print("Resetting the stack...");
    myStack.empty(); // Empty the stack

    if (!myStack.pop(&myInt))
    {
        Serial.println("Failed to pop the stack. The stack is empty.");
    }

    delay(3000);
}

void printStack()
{
    int myInt;
    Serial.println("Current content of the stack:");

    for (uint16_t i = 0; i < myStack.getSize(); i++)
    {
        myStack.get(i, &myInt);
        Serial.println(myInt);
    }
}
