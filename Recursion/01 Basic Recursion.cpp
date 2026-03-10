// Find Factorial using Simple Recursion
class Solution{
public:
    int factorial(int n) {
        if (n <= 1)
            return 1;            // Base case
        else
            return n * factorial(n - 1);  // Recursive call
    }
};


// Find Factorial using Tail Recursion 
class Solution{
public:
    int factorialHelper(int n, int product) {
        if (n <= 1)
            return product;                
        else
            return factorialHelper(n - 1, n * product);   
    }

    int factorial(int n) {
        return factorialHelper(n, 1);
    }
};


// Find Fibonacci Number 
class Solution{
public:
    int fibonacci(int n) {
        if (n <= 1)
            return n;           
        else
            return fibonacci(n - 1) + fibonacci(n - 2);  
    }
};

