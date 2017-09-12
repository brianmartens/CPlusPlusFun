#include "BigNum.h"

using namespace std;

number::number(int p, int d) // this is our number class constructor in which numbers have a digit and a power
{
    power = p;
    digit = d;
}
number::number() // this is our default constructor with an initial digit and power equal to 0
{
    power = 0;
    digit = 0;
}
void number::setDigit(int d)
{
    digit = d;
}
void number::setPower(int p)
{
    power = p;
}
int number::getDigit()
{
    return digit;
}
int number::getPower()
{
    return power;
}
bool number::operator==(const number &n)
{
    if((n.digit==this->digit) && (n.power==this->power))
       return true;
    else
        return false;
}
bool number::operator!=(const number &n)
{
    if((n.digit!=this->digit) || (n.power!=this->power))
       return true;
    else
        return false;
}
bool number::operator<(const number &n)
{
    if(n.power>this->power)
       return true;
    else if((n.power==this->power) && (n.digit>this->digit))
        return true;
    else if(n.power<this->power)
        return false;
    else
        return false;
}
bool number::operator>(const number &n)
{
    if(n.power<this->power)
        return true;
    else if((n.power==this->power)&&(n.digit<this->digit))
        return true;
    else if(n.power>this->power)
        return false;
    else
        return false;
}
bool number::operator<=(const number &n)
{
    if(n.power>this->power)
        return true;
    else if((n.power==this->power)&&(n.digit>=this->digit))
        return true;
    else
        return false;
}
bool number::operator>=(const number &n)
{
    if(n.power<this->power)
        return true;
    else if((n.power==this->power)&&(n.digit<=this->digit))
        return true;
    else
        return false;
}
number number::operator+(const number &n)
{
    this->digit+=n.digit;
    return *this;
}
number number::operator-(const number &n)
{
    this->digit-=n.digit;
    return *this;
}
number number::operator*(const number &n)
{
    this->setDigit(this->digit * n.digit);
    this->setPower(this->power + n.power);
    return *this;
}
number number::operator+=(size_t n)
{
    this->digit = this->digit + n;
    return *this;
}
number number::operator-=(size_t n)
{
    this->digit = this->digit - n;
    return *this;
}

ostream& operator<<(ostream &os, number &n)
{
    os << "This number has a power of " << n.getPower() << " and a digit of " << n.getDigit() << endl;
    return os;
}

BigNum::BigNum() // our default constructor for a bignum is a number object with digit and power equal to 0 as well as a string "0"
{
    NumVec.push_back(number(0,0));
    str = "0";
}
BigNum::BigNum(const string &StrRef)
{
    const char *c;
    c = StrRef.c_str();
    str = c;
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
    for(size_t i=1 ; i<=exponent ; ++i)
    {
        for(vector<number>::iterator j=(NumVec.end()-1) ; j>=NumVec.begin() ; --j)
        {
            j->setDigit(j->getDigit()*base);
        }
        for(size_t j=0 ; j<allocatelength ; j++)
            NumVec.insert(NumVec.begin(),number(NumVec.size(),0));

        for(vector<number>::iterator k=(NumVec.end()-1) ; k>=NumVec.begin() ; --k)
        {
            if(k->getDigit()>=10)
            {
                size_t temp = k->getDigit()/10;
                k->setDigit(k->getDigit()%10);
                (k-1)->setDigit((k-1)->getDigit()+temp);
            }
        }
    }
    for(;;)
    {
        vector<number>::iterator check=NumVec.begin();
        if(check->getDigit()==0)
            NumVec.erase(check);
        else if(check->getDigit()>0)
            break;
    }
}
BigNum::BigNum(long long InitialNumber)
{
    stringstream iss;
    iss << InitialNumber;
    string tempstr = iss.str();
    const char* c = tempstr.c_str();
    this->str = c;
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
const number& BigNum::getNumber(size_t index)
{
    const number temp = NumVec.at(index);
    return temp;
}
size_t BigNum::getLength()
{
    size_t len = NumVec.size();
    return len;
}
void BigNum::printDetails()
{
    cout << "-----------Details-----------" << endl;
    for(vector<number>::iterator l=NumVec.begin() ; l!=NumVec.end() ; ++l)
            cout << "Power: " << l->getPower() << " Digit : " << l->getDigit() << endl;
}
void BigNum::printText()
{
    ofstream myfile;
    myfile.open("BigNumber.txt");
    myfile << "-----------Details-----------" << endl;
    for(vector<number>::iterator l=NumVec.begin() ; l!=NumVec.end() ; ++l)
            myfile << "Power: " << l->getPower() << " Digit : " << l->getDigit() << endl;
}
long long BigNum::DigitSum()
{
    long long sum = 0;
    for(vector<number>::iterator it=NumVec.begin() ; it!=NumVec.end() ; ++it)
    {
        sum+=it->getDigit();
    }
    return sum;
}
bool BigNum::operator==(const BigNum &BN)
{
    bool cond = true;
    if(BN.NumVec.size()!=this->NumVec.size())
        cond = false;
    else
    {
        vector<number>::iterator it = this->NumVec.begin();
        for(size_t i=0 ; i<BN.NumVec.size() ; ++i)
        {
            if((*it)!=BN.NumVec.at(i))
            {
                cond = false;
                break;
            }
            ++it;
        }
    }
    return cond;
}
bool BigNum::operator>(const BigNum &BN)
{
    BigNum bncopy = BN;
    bool cond = false;
    if(this->NumVec.size()>BN.NumVec.size())
        cond = true;
    else if(BN.NumVec.size()>this->NumVec.size())
        cond = false;
    else
    {
        vector<number>::iterator it=this->NumVec.begin();
        for(vector<number>::iterator bnit=bncopy.NumVec.begin() ; bnit!=bncopy.NumVec.end() ; ++bnit)
        {
            if(*it>*bnit)
            {
                cond = true;
                break;
            }
            else if(*it<*bnit)
            {
                cond = false;
                break;
            }
            else
                ++it;
        }
    }
    return cond;
}
bool BigNum::operator<(const BigNum &BN)
{
    BigNum bncopy = BN;
    bool cond = false;
    if(this->NumVec.size()<BN.NumVec.size())
        cond = true;
    else if(this->NumVec.size()>BN.NumVec.size())
        cond = false;
    else
    {
        vector<number>::iterator it=this->NumVec.begin();
        for(vector<number>::iterator bnit=bncopy.NumVec.begin() ; bnit!=bncopy.NumVec.end() ; ++bnit)
        {
            if(*it>*bnit)
            {
                cond = false;
                break;
            }
            else if(*it<*bnit)
            {
                cond = true;
                break;
            }
            else
                ++it;
        }
    }
    return cond;
}
BigNum BigNum::operator+(const BigNum &BN)
{
    if(BN.NumVec.size()>=this->NumVec.size())
    {
        while(this->NumVec.size()!=BN.NumVec.size())
            this->NumVec.insert(this->NumVec.begin(),number(this->NumVec.size(),0)); // fill this-> numvec with numbers until it is equal in size to BN.numvec

        vector<number>::iterator it=this->NumVec.begin();
        for(size_t i=0 ; i<BN.NumVec.size() ; ++i)
        {
            (*it) = (*it) + BN.NumVec.at(i); // use our overloaded number operator+ to add digits
            ++it;
        }
    }
    else
    {
        size_t diff = this->NumVec.size() - BN.NumVec.size();
        vector<number>::iterator it=this->NumVec.begin();
        for(size_t i=0 ; i<diff ; ++i) // move iterator into alignment with begin of BN numvec
            ++it;
        for(size_t i=0 ; i<BN.NumVec.size() ; ++i)
        {
            (*it) = (*it) + BN.NumVec.at(i);
            ++it;
        }
    }
    this->NumVec.insert(this->NumVec.begin(),number(this->NumVec.size(),0)); // insert carryover digit
    for(vector<number>::iterator k=(this->NumVec.end()-1) ; k>=this->NumVec.begin() ; --k) // carry over numbers
    {
        if(k->getDigit()>=10)
        {
            size_t temp = k->getDigit()/10;
            k->setDigit(k->getDigit()%10);
            (k-1)->setDigit((k-1)->getDigit()+temp);
        }
    }
    if(this->NumVec.begin()->getDigit()==0){this->NumVec.erase(this->NumVec.begin());} // remove carryover digit if we didn't use it

    return *this;
}
BigNum BigNum::operator-(const BigNum &BN)
{
    BigNum bncopy = BN; // copy BN
    if(bncopy>*this) // if BN is larger than *this we will subtract *this from BN and then invert the answer once we are done
    {
        size_t diff = bncopy.NumVec.size() - this->NumVec.size(); // alignment measure
        vector<number>::iterator bnit = bncopy.NumVec.begin();
        for(size_t i=0 ; i<diff ; ++i) // align vectors
            ++bnit;
        for(vector<number>::iterator thisit=this->NumVec.begin() ; thisit!=this->NumVec.end() ; ++thisit)
        {
            *bnit = *bnit - *thisit; // perform subtraction
            if(bnit->getDigit()<0)
            {
                (bnit-1)->setDigit((bnit-1)->getDigit() - 1); // carry digits if necessary
                bnit->setDigit(10 + bnit->getDigit());
            }
            ++bnit;
        }
        for(vector<number>::iterator bnit=bncopy.NumVec.begin() ; bnit!=bncopy.NumVec.end() ; ++bnit)
            bnit->setDigit(bnit->getDigit() * -1); // invert final answer
        return bncopy;
    }
    else if(bncopy<*this)
    {
        vector<number>::iterator thisit=this->NumVec.begin();
        size_t diff = this->NumVec.size() - bncopy.NumVec.size(); // alignment measure
        for(size_t i=0 ; i<diff ; ++i) // align vectors
            ++thisit;
        for(vector<number>::iterator bnit=bncopy.NumVec.begin() ; bnit!=bncopy.NumVec.end() ; ++bnit)
        {
            *thisit = *thisit - *bnit; // perform subtraction
            if(thisit->getDigit()<0)
            {
                (thisit - 1)->setDigit((thisit-1)->getDigit() - 1); // carry digits when necessary
                thisit->setDigit(10 + thisit->getDigit());
            }
            ++thisit;
        }
        return *this; // no inversion necessary since *this was larger than BN
    }
    return BigNum(); // return the default constructor of 0,0 if numbers are equal
}
