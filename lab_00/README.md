
# Work Report

## Name: <ins> Eva Sangwan </ins>

## Features:

- Not Implemented:
  - Some of the features that have been implemented _array_init, _append, _find, _at, and _print_array in array_functions.cpp. Basically, all the functions that are used in basic_test.cpp have been implemented.

<br><br>

- Implemented:
  - Some things that were implemented include _append which appends an integer value append_me to the end of an integer array a. It also increments the size parameter to indicate the new size of the array after appending. Also _array_init, which initializes an integer array a of a given size to a specified value x. It iterates through the array and sets each element to x. Also _at, which returns a reference to an element of an integer array a at a specified position pos. It first checks if pos is within the valid range (less than size) using the assert function from the <assert.h> header.

<br><br>

- Partly implemented:
  - Some things that weren't implemented include the function basic_test and int main. 

<br><br>

- Bugs
  - Known bugs

<br><br>

# Reflections:

- This lab really helped me get familiar with VS Code and how to git commit and push.

# **output**
<pre>
<br/><br/><br/><br/>
----------running basic_test.cpp---------


[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from BASIC_TEST
[ RUN      ] BASIC_TEST.BasicTest


after init: [-1|-1|-1|-1|-1|]
[-1|-1|-1|-1|-1|50|]
[-1|-1|-1|-1|-1|50|60|]
[-1|-1|-1|-1|-1|50|60|70|]
[-1|-1|-1|-1|-1|50|60|70|80|]
[-1|-1|-1|-1|-1|50|60|70|80|90|]
found 70 at: -1
changing 70 to 700:
[700|-1|-1|-1|-1|50|60|70|80|90|]


[       OK ] BASIC_TEST.BasicTest (18 ms)
[----------] 1 test from BASIC_TEST (26 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (46 ms total)
[  PASSED  ] 1 test.
</pre>


<br/><br/>

# basic_test.cpp output:
<pre>
<br/><br/><br/><br/>
----------running basic_test.cpp---------


[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from BASIC_TEST
[ RUN      ] BASIC_TEST.BasicTest


after init: [-1|-1|-1|-1|-1|]
[-1|-1|-1|-1|-1|50|]
[-1|-1|-1|-1|-1|50|60|]
[-1|-1|-1|-1|-1|50|60|70|]
[-1|-1|-1|-1|-1|50|60|70|80|]
[-1|-1|-1|-1|-1|50|60|70|80|90|]
found 70 at: -1
changing 70 to 700:
[700|-1|-1|-1|-1|50|60|70|80|90|]


[       OK ] BASIC_TEST.BasicTest (18 ms)
[----------] 1 test from BASIC_TEST (26 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (46 ms total)
[  PASSED  ] 1 test.
</pre>

# testB.cpp output:
<pre>
<br/><br/><br/><br/>
----------running testB.cpp---------


[==========] Running 3 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 1 test from TEST_STUB
[ RUN      ] TEST_STUB.TestStub
[       OK ] TEST_STUB.TestStub (0 ms)
[----------] 1 test from TEST_STUB (6 ms total)

[----------] 2 tests from TEST_ARRAY
[ RUN      ] TEST_ARRAY.TestInitArray
[       OK ] TEST_ARRAY.TestInitArray (0 ms)
[ RUN      ] TEST_ARRAY.TestAppend
[       OK ] TEST_ARRAY.TestAppend (0 ms)
[----------] 2 tests from TEST_ARRAY (12 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 2 test suites ran. (40 ms total)
[  PASSED  ] 3 tests.
</pre>



