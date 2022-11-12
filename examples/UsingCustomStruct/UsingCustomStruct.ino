/*
 * Description: This example illustrates the usage of SimpleStack with a custom structure.
 *
 * Output:
 * 382
 * 472
 * 150
 */

#include <SimpleStack.h>

struct Book
{
  uint16_t pages;
};

SimpleStack<Book> bookStack(3); // Create a stack with maximum size of 3.

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Book book1, book2, book3;
  book1.pages = 150;
  book2.pages = 472;
  book3.pages = 382;

  bookStack.push(book1);
  bookStack.push(book2);
  bookStack.push(book3);

  // Note that the order of pages is inverted. 382, 472, 150
  Book tempBook;
  bookStack.pop(&tempBook);
  Serial.println(tempBook.pages);
  bookStack.pop(&tempBook);
  Serial.println(tempBook.pages);
  bookStack.pop(&tempBook);
  Serial.println(tempBook.pages);

  delay(3000);
}
