#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

template <class T>
class Array {
private:
  T *values;
  int maxSize;
  int currentSize;

  bool isIndexValid(int index);
  void resize();
public:
  //friend std::ostream& operator<<(std::ostream& stream, const Array& obj);

  Array(int size=0);
  
  ~Array();
  Array(const Array & obj);
  Array operator= (const Array & obj);

  int size();
  void add(T value);
  T get(int index, bool & ok);
  void set(int index, T value, bool & ok);
  void remove(int index, bool & ok);
};

template <class T>
Array<T>::Array(int size) {
  if (size <= 10) {
    maxSize = 10;
  } else {
    maxSize = size;
  }
  currentSize = size;
  values = new T[maxSize];
}

template <class T>  
Array<T>::~Array() {
  delete [] values;
}

template <class T>
Array<T>::Array(const Array & obj) {
  maxSize = obj.maxSize;
  currentSize = obj.currentSize;

  values = new T[maxSize];

  for (int i = 0; i < currentSize; ++i) {
    values[i] = obj.values[i];
  }
}

template <class T>
Array<T> Array<T>::operator= (const Array<T> & obj) {
  delete [] values;
  maxSize = obj.maxSize;
  currentSize = obj.currentSize;

  values = new T[maxSize];

  for (int i = 0; i < currentSize; ++i) {
    values[i] = obj.values[i];
  }
  return *this;
}

template <class T>
int Array<T>::size() {
  return currentSize;
}

template <class T>
void Array<T>::add(T value) {
  resize();
  values[currentSize] = value;
  currentSize++;
}

template <class T>
T Array<T>::get(int index, bool & ok) {
  if (isIndexValid(index)) {
    ok = true;
    return values[index];
  } else {
    ok = false;
  }
}

template <class T>
void Array<T>::set(int index, T value, bool & ok) {
  if (isIndexValid(index)) {
    ok = true;
    values[index] = value;
  } else {
    ok = false;
  }
}

template <class T>
void Array<T>::remove(int index, bool & ok) {
  if (isIndexValid(index)) {
    resize();
    for (int i=index; i<currentSize-1; i++) {
      values[i] = values[i+1];
    }
    currentSize -= 1;
  } else {
    ok = false;
  }
}

template <class T>
bool Array<T>::isIndexValid(int index) {
  return index >= 0 && index < currentSize;
}

template <class T>
void Array<T>::resize() {
  int newSize;
  bool performResize = false;

  if (currentSize >= maxSize) {
    newSize = maxSize*2;
    performResize = true;
  } else if (currentSize <= maxSize/4 && maxSize >= 10) {
    newSize = maxSize/2;
    performResize = true;
  }

  if (performResize) {
    T *tmp = new T[newSize];
    for (int i=0; i<currentSize; i++) {
      tmp[i] = values[i];
    }
    maxSize = newSize;
    delete [] values;
    values = tmp;
  }
}

/*
std::ostream& operator<<(std::ostream& stream, const Array& obj) {
  stream << "****" << endl;
  stream << "maxSize = " << obj.maxSize << ", currentSize = " << obj.currentSize << endl;
  for (int i=0; i<obj.currentSize; i++) {
    stream << obj.values[i] << ",";
  }
  stream << endl;
  stream << "****";
}
*/


#endif
