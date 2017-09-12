#ifndef BIGNUM_H
#define BIGNUM_H
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

class number
{
private:
    int power;
    int digit;
public:
    number(int p, int d);
    number();
    void setPower(int p);
    void setDigit(int d);
    int getPower();
    int getDigit();
    bool operator==(const number &n);
    bool operator!=(const number &n);
    bool operator<(const number &n);
    bool operator<=(const number &n);
    bool operator>(const number &n);
    bool operator>=(const number &n);
    number operator+(const number &n);
    number operator-(const number &n);
    number operator*(const number &n);
    number operator+=(size_t n);
    number operator-=(size_t n);
};
ostream& operator<<(ostream &os, number &n);
class BigNum
{
private:
    const char *str;
    vector<number> NumVec;
public:
    BigNum(const char *numberstr); // build bignum from a long string of chars
    BigNum(const string &StrRef);
    BigNum(size_t base, size_t exponent); // build a big num from an exponential number
    BigNum(long long InitialNumber);
    BigNum();
    BigNum operator+(const BigNum &BN);
    BigNum operator-(const BigNum &BN);
    BigNum operator*(const BigNum &BN);
    bool operator==(const BigNum &BN);
    bool operator!=(const BigNum &BN);
    bool operator>(const BigNum &BN);
    bool operator<(const BigNum &BN);
    bool operator<=(const BigNum &BN);
    bool operator>=(const BigNum &BN);
    void printDetails();
    void printText();
    size_t getLength();
    long long DigitSum();
    const number& getNumber(size_t index);
};

#endif // BIGNUM_H
