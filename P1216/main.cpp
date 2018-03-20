#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

#define MAP_SIZE 100

using namespace std;

int getMaxPalindrome(char words[][MAP_SIZE]);
int getMaxPalindromeWithWord(string word, int cache[][MAP_SIZE], int start, int last);
int isPalindrome(string word);

int main()
{
    freopen("input.txt","r",stdin);

    for(int i = 0; i < 10; i++)
    {
        int testCase;
        char words[MAP_SIZE][MAP_SIZE];

        cin >> testCase;

        for(int j = 0; j < MAP_SIZE; j++)
        {
            for(int k = 0; k < MAP_SIZE; k++)
            {
                cin >> words[j][k];
            }
        }

        int result = getMaxPalindrome(words);

        cout << "#" << i+1 << " " << result << endl;
    }

    return 0;
}


int getMaxPalindrome(char words[][MAP_SIZE])
{
    int result = 0;
    for(int i = 0; i < MAP_SIZE; i++)
    {
        string word(words[i]);

        int cache[MAP_SIZE][MAP_SIZE] = {};

        result = max(result, getMaxPalindromeWithWord(word,cache,0,MAP_SIZE-1));
    }

    for(int i = 0; i < MAP_SIZE; i++)
    {
        string word = "";
        for(int j = 0; j < MAP_SIZE; j++)
            word += words[j][i];

        int cache[MAP_SIZE][MAP_SIZE] = {};

        result = max(result, getMaxPalindromeWithWord(word,cache,0,MAP_SIZE-1));
    }

    return result;
}

int isPalindrome(string word)
{
    for(int i = 0; i <= word.size()/2; i++)
    {
        if(word[word.size()-1-i] != word[i])
            return 0;
    }

    return 1;
}

int getMaxPalindromeWithWord(string word, int cache[][MAP_SIZE], int start, int last)
{
    //cout << start << " " << last << endl;

    queue<pair<int,int> > strQueue;
    int result = 0;

    strQueue.push(make_pair(start, last));

    while(!strQueue.empty())
    {
        pair<int, int> targetIdx = strQueue.front();
        strQueue.pop();

        if(targetIdx.first == targetIdx.second)
            return 1;
        int& target = cache[targetIdx.first][targetIdx.second];
        if(target != 0)
            continue;

        target = 1;

        if(isPalindrome(word.substr(targetIdx.first,targetIdx.second-targetIdx.first+1)))
            return result = targetIdx.second-targetIdx.first+1;

        strQueue.push(make_pair(targetIdx.first+1, targetIdx.second));
        strQueue.push(make_pair(targetIdx.first, targetIdx.second-1));
    }
}
