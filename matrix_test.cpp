#include <cgreen/cgreen.h>
using namespace cgreen;

Describe(Matrix);
BeforeEach(Matrix) {}
AfterEach(Matrix) {}

Ensure(Matrix, passes_this_test) {
    assert_that(1 == 1);
}

Ensure(Matrix, fails_this_test) {
    assert_that(0 == 1);
}

int main(int argc, char **argv) {
    TestSuite *suite = create_test_suite();
    add_test_with_context(suite, Matrix, passes_this_test);
    add_test_with_context(suite, Matrix, fails_this_test);
    return run_test_suite(suite, create_text_reporter());
}

// g++ -Wall -I /usr/local/include -L /usr/local/lib matrix_test.cpp -lcgreen++ -o matrix_test; ./matrix_test
