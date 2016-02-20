#include "matrix.h"

Matrix::Matrix(int rows, int columns): n(rows), m(columns), p(new float*[m])
{
  for(int i = 0; i < m ; ++i ) {
    p[i] = new float[n];

    for(int j = 0; j < n ; ++j ) {
      p[i][j] = 0;
    }
  }
}
