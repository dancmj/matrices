#ifndef PROXY_H
#define PROXY_H

class Proxy {
public:
  Proxy(float* _array) : _array(_array) { }
  float operator[](int index) const {
    return _array[index];
  }
  float & operator[](int index) {
    return _array[index];
  }
private:
  float* _array;
};

#endif
