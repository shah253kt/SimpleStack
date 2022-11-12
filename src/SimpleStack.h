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
    uint8_t mMaxSize, mCurrentSize;

  public:
    SimpleStack(uint8_t size) :
      mCurrentSize(0),
      mMaxSize(size)
    {
      stack = new T[size];
    }

    ~SimpleStack() {
      delete [] stack;
    }

    bool push(T obj) {
      if (mCurrentSize >= mMaxSize) {
        return false;
      }

      stack[mCurrentSize++] = obj;
      return true;
    }

    bool pop(T *obj) {
      if (isEmpty()) {
        return false;
      }

      *obj = stack[--mCurrentSize];
      return true;
    }

    bool peek(T *obj) {
      if (isEmpty()) {
        return false;
      }

      *obj = stack[mCurrentSize - 1];
      return true;
    }

    bool get(uint8_t index, T *obj) {
      if (index >= mCurrentSize) {
        return false;
      }

      *obj =  stack[index];
      return true;
    }

    uint8_t getSize() {
      return mCurrentSize;
    }

    bool isEmpty() {
      return mCurrentSize == 0;
    }

    bool isFull() {
      return mCurrentSize == mMaxSize;
    }
};