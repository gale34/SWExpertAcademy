#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int minDifHeight(vector<int>& jumpBoard);

int main()
{
    freopen("input.txt","r",stdin);

    int testSize;
    cin >> testSize;

    for(int t = 0; t < testSize; t++)
    {
        int n;
        cin >> n;

        vector<int> jumpBoard(n,0);
        for(int i = 0; i < n; i++)
            cin >> jumpBoard[i];

        sort(jumpBoard.begin(), jumpBoard.end());
        int answer = minDifHeight(jumpBoard);

        cout << "#" << t+1 << " " << answer << endl;
    }

    return 0;
}

int minDifHeight(vector<int>& jumpBoard)
{
    int boardSize = jumpBoard.size();

    int left = 1, right = 2;

    int answer = 0;

    while(left < boardSize && right < boardSize)
    {
        if(left < boardSize)
        {
            if(left == 1)
                answer = max(answer, jumpBoard[left] - jumpBoard[0]);
            else
                answer = max(answer, jumpBoard[left] - jumpBoard[left - 2]);
        }

        if(right < boardSize)
        {
            if(right == 2)
                answer = max(answer, jumpBoard[right] - jumpBoard[0]);
            else
                answer = max(answer, jumpBoard[right] - jumpBoard[right - 2]);
        }

        answer = max(answer, abs(jumpBoard[right] - jumpBoard[left]));

        left += 2;
        right += 2;
    }

    return answer;
}
