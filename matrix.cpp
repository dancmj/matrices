#include "matrix.h"

Matrix::Matrix(int m, int n): rows(m), columns(n), p(new float*[rows])
{
  for(int i = 0; i < rows ; ++i ) {
    p[i] = new float[columns];

    for(int j = 0; j < columns ; ++j ) {
      p[i][j] = 0;
    }
  }
}

Matrix::Matrix(int m, int n, float **array): rows(m), columns(n), p(new float*[rows])
{
  for(int i = 0; i < rows ; ++i ) {
    p[i] = new float[columns];

    for(int j = 0; j < columns ; ++j ) {
      p[i][j] = array[i][j];
    }
  }
}

Matrix Matrix::operator+(const Matrix addend) const
{
  if(rows != addend.rows ||  columns != addend.columns) throw "Error, matrix sizes are not equivalent.";

  Matrix sum(rows, columns);
  for(int i = 0; i < rows ; ++i ) {
    for(int j = 0; j < columns ; ++j ) {
      sum[i][j] = p[i][j] + addend[i][j];
    }
  }

  return sum;
}

Matrix & Matrix::operator=(const Matrix &m)
{
  if(this != &m) {
    if(rows != m.rows || columns != m.columns){
      for(int i = 0; i < rows ; ++i ) if(p[i] != 0) delete [] p[i];
      if(p != 0) delete [] p;
      rows = m.rows;
      columns = m.columns;
      p = new float*[rows];
      for(int i = 0; i < rows ; ++i ) {
        p[i] = new float[columns];
      }
    }

    for(int i = 0; i < rows ; ++i ) {
      for(int j = 0; j < columns ; ++j ) {
        p[i][j] = m.p[i][j];
      }
    }
  }

  return *this;
}

Matrix::~Matrix()
{

}
