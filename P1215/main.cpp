#include <iostream>
#include <cstdio>
#include <cstring>

#define MAP_SIZE 8

using namespace std;

int countPalindrome(char words[][MAP_SIZE], int wordSize);
int isPalindrome(string word);

int main()
{
    freopen("input.txt","r",stdin);

    for(int i = 0; i < 10; i++)
    {
        int palindromeSize;
        char words[MAP_SIZE][MAP_SIZE];

        cin >> palindromeSize;

        for(int j = 0; j < MAP_SIZE; j++)
        {
            for(int k = 0; k < MAP_SIZE; k++)
            {
                cin >> words[j][k];
            }
        }

        int result = countPalindrome(words,palindromeSize);

        cout << "#" << i+1 << " " << result << endl;
    }

    return 0;
}


int countPalindrome(char words[][MAP_SIZE], int wordSize)
{
    int result = 0;
    for(int i = 0; i < MAP_SIZE; i++)
    {
        for(int j = 0; j <= MAP_SIZE - wordSize; j++)
        {
            string word = "";
            for(int k = j; k < j+wordSize; k++)
                word += words[i][k];
            result += isPalindrome(word);
        }
    }

    for(int i = 0; i < MAP_SIZE; i++)
    {
        for(int j = 0; j <= MAP_SIZE - wordSize; j++)
        {
            string word = "";
            for(int k = j; k < j+wordSize; k++)
                word += words[k][i];
            result += isPalindrome(word);
        }
    }

    return result;
}

int isPalindrome(string word)
{
    for(int i = 0; i < word.size(); i++)
    {
        if(word[word.size()-1-i] != word[i])
            return 0;
    }

    return 1;
}

