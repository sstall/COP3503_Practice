//Queue.cpp

#include "Queue.h"
#include <iostream>


int main() {
     std::cout << "Enter capacity of Queue: ";
     int capacity;
     std::cin >> capacity;

     Queue<char> q1 = Queue<char>(capacity);
     char c = 'a';
     for(int i = 0; i < capacity; i++, c++) {
          q1.enqueue(c);
     }
     q1.dequeue();
     q1.enqueue('J');

     for(;!q1.isEmpty();) {
          std::cout << q1.dequeue() << std::endl;
     }

     return 0;
}
