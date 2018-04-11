#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<string> splitWord(string word);
int main()
{
    freopen("input.txt","r",stdin);

    int testCase;
    cin >> testCase;

    for(int t = 0; t < testCase; t++)
    {
        int order;
        cin >> order;

        string word;
        cin >> word;

        vector<string> result = splitWord(word);
        cout << "#" << t+1 << " " << result[order-1] << endl;
    }

    return 0;
}

vector<string> splitWord(string word)
{
    vector<string> splitWord;

    int wordSize = word.size();
    for(int i = 0; i < wordSize; i++)
        splitWord.push_back(word.substr(i,wordSize-i));

    sort(splitWord.begin(), splitWord.end());
    return splitWord;
}
