#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

bool pcheck(size_t x, size_t y)
{
    size_t product = x*y;
    string g;
    string h;
    ostringstream convert;
    convert << product;
    g = convert.str();
    h = g;
    reverse(h.begin(), h.end());
    stringstream nconvert(h);
    size_t revproduct;
    nconvert >> revproduct;
    if(revproduct==product) return true;
    else
    return false;
}
int main()
{
    ofstream myfile;
    myfile.open("palindrome.txt");
    vector<size_t> v = {1};
    for(size_t i=999 ; i>=900 ; i--)
    {
        for(size_t j=999 ; j>=900 ; j--)
        {
            if((pcheck(i,j)) && ((i*j)>v.back())) // if we have a new palindrome that is greater than the last one we found
            {
                v.push_back(i*j);
                myfile << "The product of:" << i << " & " << j << ": " << i*j << " is a palindrome";
                break;
            }
        }
    }
    return 0;
}
