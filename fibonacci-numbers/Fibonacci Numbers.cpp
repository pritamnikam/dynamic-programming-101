/*
Fibonacci Numbers

Write a function to calculate the nth Fibonacci number.

Fibonacci numbers are a series of numbers in which each number is the sum of the two preceding numbers. First few Fibonacci numbers are: 0, 1, 1, 2, 3, 5, 8, …

Mathematically we can define the Fibonacci numbers as:

    Fib(n) = Fib(n-1) + Fib(n-2), for n > 1

    Given that: Fib(0) = 0, and Fib(1) = 1

*/

using namespace std;

#include <iostream>
#include <vector>


namespace {
    class Fibonacci {

    public:
        int CalculateFibonacci(int n) {
            if (n <= 2) return n;

            int fib1 = 1, fib2 = 2;
            for (int i = 2; i <= n; ++i) {
                int temp = fib1 + fib2;
                fib1 = fib2;
                fib2 = temp;
            }

            return fib2;
        }
    };

}  // namespace

