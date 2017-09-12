#include <iostream>
#include "math.h"
#include <fstream>
using namespace std;

int main()
{
    ofstream myfile;
    myfile.open("lettercounts.txt");
    long TotalLetters = 0;
    long Teens[9] = {6,6,8,8,7,7,9,8,8};
    long Tens[9] = {3,6,6,5,5,5,7,6,6};
    long Singles[9] = {3,3,5,4,4,3,5,5,4};
    long Hundreds [9] = {10,10,12,11,11,10,12,12,11};
    for(size_t i = 1 ; i<1000 ; ++i)
    {
        myfile << "Prior to addition " << "Adding: " << i << endl;
        int hundred = i/100;
        int ten = (i%100)/10;
        int single = i%10;
        if(i>=100)
        {
            if((i%100>10)&&(i%100<20))
            {
                TotalLetters += Hundreds[hundred-1];
                TotalLetters += Teens[(i%10)-1];
                TotalLetters += 3;
                myfile << "Case: hundred within teens " << "Added: " << Hundreds[hundred - 1] + Teens[(i%10)-1] + 3 << " with result " << TotalLetters << endl;
            }
            else if(i%100==0)
            {
                TotalLetters += Hundreds[hundred-1];
                myfile << "Case: even hundred " << "Added: " << Hundreds[hundred-1] << " With result: " << TotalLetters << endl;
            }
            else if(ten==0)
            {
                TotalLetters += 3;
                TotalLetters += Hundreds[hundred-1];
                TotalLetters += Singles[single-1];\
                myfile << "case Hundred with no tens " << "Added: " << 3+Hundreds[hundred]+Singles[single-1] << " With result: " << TotalLetters << endl;
            }
            else if(single==0)
            {
                TotalLetters += 3;
                TotalLetters += Hundreds[hundred-1];
                TotalLetters += Tens[ten-1];
                myfile << "Case hundred with even ten " << "Added: " << 3+Hundreds[hundred-1]+Tens[ten-1] << " With result: " << TotalLetters << endl;
            }
            else
            {
                TotalLetters += 3;
                TotalLetters += Hundreds[hundred-1];
                TotalLetters += Tens[ten-1];
                TotalLetters += Singles[single-1];
                myfile << "case: composite hundred " << "Added: " << 3+Hundreds[hundred-1]+Tens[ten-1]+Singles[single-1] << " With result " << TotalLetters << endl;
            }
        }
        else if(i>=10)
        {
            if((i>10) && (i<20))
            {
                TotalLetters += Teens[(i%10)-1];
                myfile << "case: Only teens " << "added: " << Teens[(i%10)-1] << " With result " << TotalLetters << endl;
            }
            else if(i%10==0)
            {
                TotalLetters += Tens[ten - 1];
                myfile << "case: even ten " << "Added: " << Tens[ten - 1] << " with result " << TotalLetters << endl;
            }
            else
            {
                TotalLetters += Tens[ten - 1];
                TotalLetters += Singles[single - 1];
                myfile << "Case: composite ten " << "Added: " << Tens[ten - 1]+Singles[single - 1] << " With result " << TotalLetters << endl;
            }
        }
        else if(i<10)
        {
            TotalLetters += Singles[single - 1];
            myfile << "Case: single only " << "Added " << Singles[single] << " With result " << TotalLetters << endl;
        }
    }
    TotalLetters += 11; // one thousand
    myfile << endl << TotalLetters;
    return 0;
}
