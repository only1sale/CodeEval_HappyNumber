#include <iostream>
#include <fstream>
#include <string>
#include <set>

int sumSquare(std::string num)
{
    //calculate sum of squares of digits
    //easier to leave it in string format and iterate over than divide by 10 several times
    int tmp = 0;
    for(size_t i = 0; i < num.length(); ++i)
        tmp += ((num[i] - '0') * (num[i] - '0')); //convert char to int
    return tmp;
}

int main(int argc, char *argv[])
{
    std::ifstream in(argv[1]);
    std::string num;
    int tmp;
    while(getline(in,num)) //read line, to avoid EOF problem
    {
        std::set<int> a;//set stores unique elements
        //better a for loop with some large number, than risk an infinite loop with while(1)
        for(int i = 0; i < 20; ++i)
        {
            tmp = sumSquare(num);
            if(tmp == 1)
            {
                //if sum of squares is 1 then the number is happy
                std::cout << "1" << std::endl;
                //end for loop
                break;
            }
            //if tmp!= 1 then add tmp to set "a"
            auto ret = a.emplace(tmp);
            //if ret==false, tmp is already in set, number is not happy
            if (!ret.second)
            {
                //number is not happy
                std::cout << "0" << std::endl;\
                //end for loop
                break;
            }
            //convert tmp to string because function sumSquares accepts a string
            num = std::to_string(tmp); //this could have been avoided
        }

    }
    return 0;
}
