#include <iostream>
#include "hangman_func.h"
#include <vector>
#include <fstream>
#include <random>
#include <string>
using namespace std;

int main()
{
    // Lời chào
    greet();  

    // Mở file txt và lấy ngẫu nhiên một từ
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
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, words.size() - 1);
    // Lấy vị trí ngẫu nhiên trong vector
    int index = dist(gen);

    // Chọn từ ngẫu nhiên
    string codeword = words[index];
    // Chuyển đổi ký tự sang dạng '_'
    string answer;
    for (int i = 0; i < codeword.size(); ++i) {
        answer[i] = '_';
    }
    // Các biến
    int misses = 0;
    vector<char> incorrect;
    bool guess = false;
    char letter;

    // Logic trò chơi
    while(answer!=codeword && misses < 6)
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