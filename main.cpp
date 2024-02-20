#include <iostream>
#include "hangman_func.h"
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    greet();  

    //lay ngau nhien mot tu
    // string myText;
    // ifstream readFile("data.txt");
    // getline(readFile, myText);
        random = rand() % 50;
    while(getline(File, line))
    {
        ++numOfLines;
        if(numOfLines == random)
        {
            cout << line;
        }
    }
    count++;
    //bien
    int misses = 0;
    vector<string> incorrect;
    bool guess = false;
    char letter;

    // 


    return 0;
}