#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    printf("Hello world \n");
    std::cout << "Hello world\n" << endl;

    vector<int> vtr (4, 100);

    for(int i = 0; i< (int)vtr.size(); i++) std::cout << vtr[i]<<endl;
    return 0;
}