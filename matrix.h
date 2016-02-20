#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
public:
  const int m, n;
  Matrix(int, int);
  ~Matrix();

private:
  float **p;
};

#endif
