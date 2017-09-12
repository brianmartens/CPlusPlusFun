#include <iostream>

using namespace std;

size_t sqr(size_t x)
{
    return x*x;
}

int main()
{
    long SumOfSquare = 0;
    long SquareOfSum = 0;
    for(size_t i=1 ; i<=100 ; i++)
    {
        SumOfSquare += sqr(i);
        SquareOfSum += i;
    }
    SquareOfSum = sqr(SquareOfSum);
    cout << SquareOfSum - SumOfSquare;
}
