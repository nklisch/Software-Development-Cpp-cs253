# CS253 HW6 grading

## Grading policy

4 pts

* 1.5 pts HW5 requirements
* 1 pt [] operator
* 1 pt == and != operators
* 0.5 pt bool operator

For each of the items, the grade is deduced from the percentage of tests that passed, rounded at a precision of 0.05 pt.

Please note that, in the HW5 test suite, test20 and test42 are supposed to fail due to the double call to free.
The percentage of tests passed have been manually changed to take this into account.

Also, a test that failed to compiled is considered in the exact same way as a failed test.



## Building and running the test suite

1. Untar and build your homework


2. Untar the tests

tar -zxvf hw6_grading.tar.gz


3. Build the tests

cd hw6_grading
mkdir build
cd build
cmake -DHOMEWORK_DIR=/path/to/homework6/library/and/header/files" ..
make --ignore-errors

Here, the ignore errors allow the command to try to build every tests
it can, instead of stopping at the first error.


4. Run the tests

To run all tests, run `make test` in the build directory created beforehand.

The tests are divided by label:

* "Tests HW5"
* "Tests samples" -> Those are not used for grading
* "Tests array subscript operator"
* "Tests boolean conversion operator"
* "Tests equality and non equality "

To run only one category, run `ctest -L "label name"`.
