#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

template <class T>
class SimpleStack {
  private:
    T *stack;
    uint16_t mMaxSize, mCurrentSize;

  public:
    /**
     * @brief Construct a new SimpleStack object
     * 
     * @param size Maximum number of objects to fill the stack with.
     */
    SimpleStack(uint16_t size) :
      mCurrentSize(0),
      mMaxSize(size)
    {
      stack = new T[size];
    }

    /**
     * @brief Destroy the SimpleStack object
     * 
     */
    ~SimpleStack() {
      delete [] stack;
    }

    /**
     * @brief Insert object onto the top of the stack.
     * 
     * @param obj The object to be pushed onto the stack.
     * @return true if stack is not yet full and successfully added the object onto the stack.
     * @return false if stack is full.
     */
    bool push(T obj) {
      if (isFull()) {
        return false;
      }

      stack[mCurrentSize++] = obj;
      return true;
    }

    /**
     * @brief Take out the top-most object.
     * 
     * @param obj The object just removed, if stack is not empty.
     * @return true if stack is not empty.
     * @return false if stack is empty.
     */
    bool pop(T *obj) {
      if (isEmpty()) {
        return false;
      }

      *obj = stack[--mCurrentSize];
      return true;
    }

    /**
     * @brief Get the object at the top of the stack without removing it from the stack.
     * 
     * @param obj The object on top of the stack, if stack is not empty.
     * @return true if stack is not empty.
     * @return false if stack is empty.
     */
    bool peek(T *obj) {
      if (isEmpty()) {
        return false;
      }

      *obj = stack[mCurrentSize - 1];
      return true;
    }

    /**
     * @brief Retrieve object at a specific index.
     * 
     * @param index Index of object to be retrieved.
     * @param obj The object at the specified index.
     * @return true if index is within the boundary.
     * @return false if index is out of bound.
     */
    bool get(uint16_t index, T *obj) {
      if (index >= mCurrentSize) {
        return false;
      }

      *obj = stack[index];
      return true;
    }

    /**
     * @brief Get the current object count in the stack.
     * 
     * @return uint16_t The current object count.
     */
    uint16_t getSize() {
      return mCurrentSize;
    }

    /**
     * @brief Check if the stack is empty.
     * 
     * @return true if the stack is empty.
     * @return false if the stack is not empty.
     */
    bool isEmpty() {
      return mCurrentSize == 0;
    }

    /**
     * @brief Check if the stack is full.
     * 
     * @return true if the stack is full.
     * @return false if the stack is not full.
     */
    bool isFull() {
      return mCurrentSize >= mMaxSize;
    }

    /**
     * @brief Empty the stack.
     * 
     */
    void empty() {
      mCurrentSize = 0;
    }
};