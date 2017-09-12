#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

bool ptest(long long num)
{
    bool result = true;
    if(num <= 1) result = false;
    else if((num%2==0) && (num>2)) result = false;
    else
    {
        for(long long k=3 ; k<=sqrt(num) ; k+=2)
        {
            if(num%k==0)
            {
                result = false;
            }
        }
    }
    return result;
}

int main()
{
    ofstream myfile;
    myfile.open("primeget.txt");
    long long i=7;
    size_t j=4;
    myfile << "Prime number(1): 2" << endl;
    myfile << "Prime number(2): 3" << endl;
    myfile << "Prime number(3): 5" << endl;
    while(j<=10001)
    {
        if(ptest(i))
        {
            myfile << "Prime number(" << j << "): " << i << endl;
            j++;
        }
        i+=2;
    }
    return 0;
}
