#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
using namespace std;

bool ptest(long long num)
{
    bool result = true;
    if(num <= 1) result = false;
    else if(num%2==0) result = false;
    else
    {
        for(long long k=3 ; k<sqrt(num) ; k+=2)
        {
            if(num%k==0)
                result = false;
        }
    }
    return result;
}

int main()
{
    ofstream myfile;
    myfile.open("factors.txt");
    long long n = 600851475143;
    for(long long a=3 ; a<sqrt(n) ; a+=2)
    {
        if((ptest(a)) && (n%a==0))
            myfile << a << endl;
    }
    return 0;
}
