#include <iostream>
#include "hangman_func.h"
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

int main()
{
    // Lời chào
    greet();  

    vector<string> words = {"balloon", "hair", "computer", "orange", "clock", "mailman", "lemon", "spine", "sunlight", "fang"};

    // Tạo random number generator
    srand(time(0));
    int index = rand() % 10;
    // Chọn từ ngẫu nhiên
    string codeword = words[index];
    // Chuyển đổi ký tự sang dạng '_'
    string answer = codeword;
    for (int i = 0; i < codeword.size(); ++i) {
        answer[i] = '_';
    }
    // Các biến
    int misses = 0;
    vector<char> incorrect;
    bool guess = false;
    char letter;

    // Logic trò chơi
    while(answer!=codeword && misses < 7)
    {
        display_misses(misses);
        display_status(incorrect, answer);

        cout<<"\n\nMoi ban nhap mot chu: ";
        cin>>letter;

        for(int i = 0; i<codeword.length(); i++)
        {
        if(letter==codeword[i])
        {
            answer[i] = letter;
            guess = true;
        }
        }
        if(guess)
        {
        cout<<"\nDung roi\n";
        }
        else
        {
        cout<<"\nSai roi, ban da mat mot luot.\n";
        incorrect.push_back(letter);
        misses++;
        }
        guess = false;
    }

    end_game(answer, codeword);
    return 0;
}