# SimpleStack
As the name suggest, this library allows you to create simple stack of arbitrary datatypes on Arduino.
Checkout `FullFeatures.ino` example to see all of the main features in use.

# API
## `SimpleStack<T>(uint16_t size)`
**Description:** The constructor to create SimpleStack object.

**Parameters**:

`T`: Datatype of the object.

`size`: Maximum number of objects to fill the stack with.
```cpp
// Example of creating a stack of integers with maximum size of 5:
SimpleStack<int> myStack(5);
```
---
## `bool push(T obj)`
**Description:** Insert object onto the top of the stack.

**Parameters**:

`obj`: The object to be pushed onto the stack.

**Returns**: `true` if stack is not yet full and successfully added the object onto the stack, `false` otherwise.
```cpp
if (myStack.push(1)) {
    // Your code here
}
```
---
## `bool pop(T *obj)`
**Description:** Take out the top-most object.

**Parameters**:

`obj`: The object just removed, if stack is not empty.

**Returns**: `true` if stack is not empty, `false` otherwise.
```cpp
int myInt;

if (myStack.pop(&myInt)) {
    // Your code here
}
```
---
## `bool peek(T *obj)`
**Description:** Get the object at the top of the stack without removing it from the stack.

**Parameters**:

`obj`: The object on top of the stack, if stack is not empty.

**Returns**: `true` if stack is not empty, `false` otherwise.
```cpp
int myInt;

if (myStack.peek(&myInt)) {
    // Your code here
}
```
---
## `bool get(uint16_t index, T *obj)`
**Description:** Retrieve object at a specific index.

**Parameters**:

`index`: Index of object to be retrieved.
`obj`: The object at the specified index.

**Returns**: `true` if index is within the boundary, `false` otherwise.
```cpp
int myInt;

if (myStack.get(2, &myInt)) { // Get object at index 2.
    // Your code here
}
```
---
## `uint16_t getSize()`
**Description:** Get the current object count in the stack.

**Returns**: The current object count.
```cpp
int currentStackSize = mystack.getSize();
```
---
## `void setMaxSize(uint16_t size)`
**Description:** Get the current object count in the stack.

**Parameters**:

`size`: Maximum number of objects to fill the stack with.

**Returns**: The current object count.
```cpp
int currentStackSize = mystack.getSize();
```
---
## `uint16_t getMaxSize()`
**Description:** Get the maximum size of the stack.

**Returns**: The maximum size of the stack.
```cpp
int maxStackSize = mystack.getMaxSize();
```
---
## `uint16_t isEmpty()`
**Description:** Check if the stack is empty.

**Returns**: `true` if the stack is empty, `false` otherwise.
```cpp
if (mystack.isEmpty()) {
    // Your code here
}
```
---
## `uint16_t isFull()`
**Description:** Check if the stack is full.

**Returns**: `true` if the stack is full, `false` otherwise.
```cpp
if (mystack.isFull()) {
    // Your code here
}
```
---
## `void empty()`
**Description:** Empty the stack.
```cpp
mystack.empty();
```