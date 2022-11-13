/*
 * Description: This example utilizes all features of the SimpleStack.
 *
 * Output:
 * Current stack max size: 5
 * Stack is full. Unable to push new object. Resizing stack...
 * Now, we can push new object onto the stack
 * Current stack max size: 10
 * Current content of the stack:
 * 1
 * 2
 * 3
 * 4
 * 5
 * 6
 * Popped data: 6
 * Top-most data now: 5
 * Current content of the stack:
 * 1
 * 2
 * 3
 * 4
 * 5
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
		Serial.print("Current stack max size: ");
		Serial.println(myStack.getMaxSize());

		Serial.println("Stack is full. Unable to push new object. Resizing stack...");
		myStack.setMaxSize(myStack.getSize() * 2);

		if (myStack.push(6))
		{
			Serial.println("Now, we can push new object onto the stack");
		}

		Serial.print("Current stack max size: ");
		Serial.println(myStack.getMaxSize());
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
	myStack.empty();			 // Empty the stack
	myStack.setMaxSize(5); // Resize the stack back down to 5

	if (!myStack.pop(&myInt))
	{
		Serial.println("Failed to pop the stack. The stack is empty.");
	}

	Serial.println("--------------------------");

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
