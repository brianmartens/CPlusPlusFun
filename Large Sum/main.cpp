#include "BigNum.h"
using namespace std;


int main()
{
    ifstream myfile;
    myfile.open("Numbers.txt");
    BigNum Total;
    string line;
    while(getline(myfile,line))
    {
        BigNum temp(line);
        Total = Total + temp;
    }
    for(size_t i=0 ; i<10 ; ++i)
    {
        number tempnum = Total.getNumber(i);
        cout << tempnum;
    }
    return 0;
}
