#include <stdlib.h>
#include <cgreen/cgreen.h>
#include <string>
#include <iostream>
#include "matrix.h"
using namespace cgreen;
using namespace std;

#define HI 100
#define LO -100

Describe(Matrix);
BeforeEach(Matrix) {}
AfterEach(Matrix) {}

Ensure(Matrix, is_initialized_correctly_with_2_params) {
  int m = rand() % 10 + 1;
  int n = rand() % 10 + 1;
  bool end_test = false;

  Matrix dan(m, n);

  assert_that(dan.rows, is_equal_to(m));
  assert_that(dan.columns, is_equal_to(n));

  for(int i = 0; i < m && !end_test ; ++i ) {
    for(int j = 0; j < n ; ++j ) {
      if(dan[i][j] != 0) {
        end_test = true;
        break;
      }
    }
  }

  assert_that(end_test, is_false);
}

Ensure(Matrix, is_initialized_correctly_with_3_params) {

  const int m = rand() % 10 + 1;;
  const int n = rand() % 10 + 1;;
  float **test_array;
  bool end_test = false;

  test_array = new float*[m];

  for(int i = 0; i < m ; ++i ) {
    test_array[i] = new float[n];
    for(int j = 0; j < n ; ++j ) {
      test_array[i][j] = ((HI-LO)*((float)rand()/RAND_MAX))+LO;
    }
  }

  Matrix dan(m, n, test_array);

  assert_that(dan.rows, is_equal_to(m));
  assert_that(dan.columns, is_equal_to(n));

  for(int i = 0; i < m && !end_test ; ++i ) {
    for(int j = 0; j < n ; ++j ) {
      if(dan[i][j] != test_array[i][j]) {
        end_test = true;
        break;
      }
    }
  }

  assert_that(end_test, is_false);
}

Ensure(Matrix, sum_is_done_correctly) {
  const int m = 3;
  const int n = 3;
  float **test_array;
  bool end_test = false;


  test_array = new float*[m];

  for(int i = 0; i < m ; ++i ) {
    test_array[i] = new float[n];
    for(int j = 0; j < n ; ++j ) {
      test_array[i][j] = 1 + i;
    }
  }

  Matrix augend(m, n);
  Matrix addend(m, n, test_array);
  Matrix sum(m, n);

  sum = augend + addend;

  for(int i = 0; i < m && !end_test ; ++i ) {
    for(int j = 0; j < n ; ++j ) {
      if(sum[i][j] !=  1 + i) {
        end_test = true;
        break;
      }
    }
  }

  assert_that(end_test, is_false);
}

Ensure(Matrix, substraction_is_done_correctly) {
  const int m = 3;
  const int n = 3;
  float **test_array_1;
  float **test_array_2;
  bool end_test = false;


  test_array_1 = new float*[m];
  test_array_2 = new float*[m];

  for(int i = 0; i < m ; ++i ) {
    test_array_1[i] = new float[n];
    test_array_2[i] = new float[n];
    for(int j = 0; j < n ; ++j ) {
      test_array_1[i][j] = i;
      test_array_2[i][j] = 20;
    }
  }

  Matrix minuend(m, n, test_array_2);
  Matrix subtrahend(m, n, test_array_1);
  Matrix difference(m, n);

  difference = minuend - subtrahend;

  for(int i = 0; i < m && !end_test ; ++i ) {
    for(int j = 0; j < n ; ++j ) {
      if(difference[i][j] !=  20 - i) {
        end_test = true;
        break;
      }
    }
  }

  assert_that(end_test, is_false);
}

Ensure(Matrix, multiplication_is_done_correctly) {
  const int m = 3;
  const int n = 4;
  int counter = 0;
  float **test_array_1;
  float **test_array_2;
  float answer[3][3] = {{12, 12, 12},
                        {44, 44, 44},
                        {76, 76, 76}};
  bool end_test = false;


  test_array_1 = new float*[m];
  test_array_2 = new float*[n];

  for(int i = 0; i < m ; ++i ) {
    test_array_1[i] = new float[n];
    for(int j = 0; j < n ; ++j ) {
      test_array_1[i][j] = counter;
      counter++;
    }
  }

  for(int i = 0; i < n ; ++i ) {
    test_array_2[i] = new float[m];
    for(int j = 0; j < m ; ++j ) {
      test_array_2[i][j] = 2;
    }
  }

  Matrix multiplicand(m, n, test_array_1);
  Matrix multiplier(n, m, test_array_2);
  Matrix product(multiplicand.rows, multiplier.columns);

  product = multiplicand * multiplier;

  for(int i = 0; i < multiplicand.rows && !end_test ; ++i ) {
    for(int j = 0; j < multiplier.columns; ++j ) {
      if(product[i][j] != answer[i][j]) {
        end_test = true;
        break;
      }
    }
  }

  assert_that(end_test, is_false);
}

Ensure(Matrix, multiplication_by_scalar_is_done_correctly) {
  const int m = 3;
  const int n = 3;
  int counter = 0;
  float **test_array_1;
  float answer[3][3] = {{0, 2, 4},
                        {6, 8, 10},
                        {12, 14, 16}};
  bool end_test = false;

  test_array_1 = new float*[m];

  for(int i = 0; i < m ; ++i ) {
    test_array_1[i] = new float[n];
    for(int j = 0; j < n ; ++j ) {
      test_array_1[i][j] = counter;
      counter++;
    }
  }

  Matrix multiplicand(m, n, test_array_1);
  Matrix product(m, n);
  Matrix product_2(m, n);

  product = multiplicand * 2;
  product_2 = 2 * multiplicand;

  for(int i = 0; i < m && !end_test ; ++i ) {
    for(int j = 0; j < n; ++j ) {
      if(product[i][j] != answer[i][j] || product_2[i][j] != answer[i][j]) {
        end_test = true;
        break;
      }
    }
  }

  assert_that(end_test, is_false);
}


int main(int argc, char **argv) {
  srand (time(NULL));

  TestSuite *suite = create_test_suite();
  add_test_with_context(suite, Matrix, is_initialized_correctly_with_2_params);
  add_test_with_context(suite, Matrix, is_initialized_correctly_with_3_params);
  add_test_with_context(suite, Matrix, sum_is_done_correctly);
  add_test_with_context(suite, Matrix, substraction_is_done_correctly);
  add_test_with_context(suite, Matrix, multiplication_is_done_correctly);
  add_test_with_context(suite, Matrix, multiplication_by_scalar_is_done_correctly);

  return run_test_suite(suite, create_text_reporter());
}
