#include "BigNum.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

number::number(int p, size_t d) // this is our number class constructor in which numbers have a digit and a power
{
    power = p;
    digit = d;
}
number::number() // this is our default constructor with an initial digit and power equal to 0
{
    power = 0;
    digit = 0;
}
void number::setDigit(size_t d)
{
    digit = d;
}
void number::setPower(int p)
{
    power = p;
}
size_t number::getDigit()
{
    return digit;
}
int number::getPower()
{
    return power;
}

BigNum::BigNum() // our default constructor for a bignum is a number object with digit and power equal to 0 as well as a string "0"
{
    number n(0,0);
    NumVec.push_back(n);
    str = "0";
}
BigNum::BigNum(const char *numstr)
{
    str = numstr;
    size_t it = 0;
    while(*(str + it)!='\0') // it will be the length of our string
    {
        ++it;
    }
    it--;
    stringstream ss;
    ss.clear();
    for(size_t i=0 ; i<=it ; i++)
    {
        ss << *(str + i);
        size_t temp;
        ss >> temp;
        ss.clear();
        number n((it - i),temp);
        NumVec.push_back(n);
    }
}
BigNum::BigNum(size_t base, size_t exponent) // the exponential BigNum constructor
{
    stringstream ss;
    ss << base;
    string basestr;
    ss >> basestr;
    size_t allocatelength = basestr.size(); // we will need to pro-actively allocate digits equal to the size of the base integer
    ss.clear();
    NumVec.push_back(number(0,1));
    for(size_t i=exponent ; i>0 ; --i)
    {
        for(vector<number>::iterator it=NumVec.end() ; it!=NumVec.begin() ; --it) // initial multiplication phase
        {
            it->setDigit(it->getDigit() * base);
        }
        for(size_t i=0 ; i<allocatelength ; ++i)
        {
            NumVec.insert(NumVec.begin(), number(NumVec.size(),0)); // insert the maximum required new digits
        }
        for(vector<number>::iterator it=NumVec.end() ; it!=NumVec.begin() ; --it)
        {
            if(it->getDigit()>=10) // if we need to reallocate the digits of it
            {
                size_t tempint = it->getDigit()/10; // store the carryover digit
                it->setDigit(it->getDigit()%10); // leave the remainder
                (it - 1)->setDigit((it - 1)->getDigit() + tempint); // add the carryover
            }
        }
    }

}
void BigNum::printDetails()
{
    for(vector<number>::iterator it=NumVec.begin() ; it!=NumVec.end() ; ++it)
    {
        cout << (*it).getDigit() << "\t" << (*it).getPower() << endl;
    }
}
