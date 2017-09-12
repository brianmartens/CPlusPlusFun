#include <iostream>
#include <fstream>
using namespace std;

bool modtest(long long number)
{
    bool condition = true;
    for(size_t i=20 ; i>0 ; i--)
    {
        if(number%i != 0)
        {
            condition = false;
            return condition;
        }
    }
    return condition;
}

int main()
{
    ofstream myfile;
    myfile.open("modtest.txt");
    long long mult;
    mult = 20;
    for(;;)
    {
        if(modtest(mult))
        {
            myfile << "The smallest multiple is equal to: " << mult;
            break;
        }
        else
        {
            mult+=20;
        }
    }
    return 0;
}
