#ifndef MATRIX_H
#define MATRIX_H

#include "proxy.h"

class Matrix {
  friend Matrix operator*(float scalar, const Matrix &M){
		return M * scalar;
	}
public:
  int rows, columns;
  Matrix(int, int);
  Matrix(int, int, float**);
  ~Matrix();
  Matrix & operator=(const Matrix&);
  Matrix operator+(const Matrix) const;
  Matrix operator-(const Matrix) const;
  Matrix operator*(const Matrix&) const;
  Matrix operator*(const float) const;

  Proxy operator[](int index) const {
    return Proxy(p[index]);
  }

private:
  float **p;
};

#endif
