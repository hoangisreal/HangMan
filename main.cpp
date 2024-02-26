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
    // Mở file txt
    ifstream infile("data.txt");

    // Tạo vector lưu trữ các từ
    vector<string> words;
    string word;

    // Đọc từng từ trong file và thêm vào vector
    while (infile >> word) {
        words.push_back(word);
    }
    infile.close();

    // Tạo random number generator
    srand(time(0));
    int index = rand() % words.size();

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
    
    do{
        system("cls");
        greet();
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
        if(guess==false)
        {
        incorrect.push_back(letter);
        misses++;
        }
        guess = false;
    }while(answer!=codeword && misses < 7);
    system("cls");
    display_misses(misses);
    end_game(answer, codeword);
    return 0;
}