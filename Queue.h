//Queue.h

#include <stdexcept>
#include <iostream>

template <class Q>
class Queue {
public:
     Queue(int cap);
     void enqueue(Q element);
     Q dequeue();
     Q peek();
     bool isEmpty();
     bool isFull();
private:
     Q * const array;
     size_t H;
     size_t T;
     size_t capacity;
     size_t nextIndex(size_t i);
};

template <class Q>
Queue<Q>::Queue(int cap) : array(new Q[cap + 1]){
     capacity = cap + 1;
     H = T = 0;
}

template<class Q>
void Queue<Q>::enqueue(Q element) {
     if(isFull()) {
          throw std::runtime_error("Queue<Q>.enqueue(): Full queue");
     }
     array[T] = element;
     T = nextIndex(T);
}

template<class Q>
Q Queue<Q>::dequeue() {
     if(isEmpty()) {
          throw std::runtime_error("Queue<Q>.dequeue(): Empty queue");
     }
     Q data = array[H];
     H = nextIndex(H);
     return data;
}

template<class Q>
Q Queue<Q>::peek() {
     if(isEmpty()) {
          return nullptr;
     }
     return array[H];
}

template<class Q>
bool Queue<Q>::isEmpty() {
     return (H == T);
}

template<class Q>
bool Queue<Q>::isFull() {
     return (H == nextIndex(T));
}

template<class Q>
size_t Queue<Q>::nextIndex(size_t i) {
     if(++i == capacity) {
          return 0;
     }
     return i;
}
