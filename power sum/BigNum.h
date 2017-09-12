#ifndef BIGNUM_H
#define BIGNUM_H
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class number
{
private:
    int power;
    size_t digit;
public:
    number(int p, size_t d);
    number();
    void setPower(int p);
    void setDigit(size_t d);
    int getPower();
    size_t getDigit();
};

class BigNum
{
private:
    const char *str;
    vector<number> NumVec;
public:
    BigNum(const char *numberstr); // build bignum from a long string of chars
    BigNum(long long product1, long long product2); // build a bignum from the product of two long longs
    BigNum(size_t base, size_t exponent); // build a big num from an exponential number
    BigNum();
    BigNum operator+(const BigNum &BN);
    BigNum operator-(const BigNum &BN);
    BigNum operator*(const BigNum &BN);
    BigNum operator/(const BigNum &BN);
    void printDetails();
};

#endif // BIGNUM_H
