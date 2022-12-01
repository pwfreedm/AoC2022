#include <iostream>
#include <fstream>
#include <string>
#include <set>


using std::string;
using std::isdigit;

int main(int argc, char const *argv[])
{
    std::ifstream i ("d1_input.txt");
    int sum = 0;
    int max = 0;
    std::set<int> o;
    string line;
    while(i.peek() != EOF) {
       getline(i,line);
       if(line.length() == 0) {
            o.insert(sum);
            sum = 0;
       } else {
            sum += stoi(line);
         }
       }
       auto it = o.end();
       std::cout << *--it + *--it + *--it << std::endl;
       return 0; 
    }
