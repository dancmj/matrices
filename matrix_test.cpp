#include <stdlib.h>
#include <cgreen/cgreen.h>
#include <string>
#include "matrix.h"
using namespace cgreen;

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
      test_array[i][j] = 1 + m;
    }
  }

  Matrix augend(m, n);
  Matrix addend(m, n, test_array);
  Matrix sum(m, n);

  sum = augend + addend;

  for(int i = 0; i < m && !end_test ; ++i ) {
    for(int j = 0; j < n ; ++j ) {
      if(sum[i][j] !=  m) {
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

  return run_test_suite(suite, create_text_reporter());
}
