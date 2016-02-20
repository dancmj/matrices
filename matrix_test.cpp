#include <cgreen/cgreen.h>
#include "matrix.h"
using namespace cgreen;


Describe(Matrix);
BeforeEach(Matrix) {}
AfterEach(Matrix) {}

Ensure(Matrix, has_correct_rows_and_columns) {
  Matrix dan(2,2);
  assert_that(dan.m, is_equal_to(2));
  assert_that(dan.n, is_equal_to(2));
}

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_test_with_context(suite, Matrix, has_correct_rows_and_columns);

  return run_test_suite(suite, create_text_reporter());
}
