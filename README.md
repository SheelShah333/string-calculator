# String Calculator - TDD Kata (C++)

A TDD-based solution to the classic string calculator problem.

## Features
- [x] Empty string returns 0
- [x] Supports multiple delimiters
- [x] Supports newline separators
- [x] Custom delimiters like //;\n
- [x] Multi-character delimiters like //[***]\n
- [x] Ignores numbers > 1000
- [x] Throws exception for negative numbers

## Run Tests

```bash
g++ src/string_calculator.cpp tests/test_add.cpp -o test
./test