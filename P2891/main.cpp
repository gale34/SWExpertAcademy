#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class Cell
{
public:
    bool isFraction;
    int numerator;
    int denominator;
    int number;

    Cell()
    {
        isFraction = true;
        numerator = 0;
        denominator = 0;
        number = 0;
    }
};

bool makeSudoku(Cell** sudoku, int x, int y,bool** visited);
bool makeSudoku4Way(Cell** sudoku, int x, int y, bool** visited);
vector<int> makeCandidate(Cell** sudoku, int x, int y);

int pX[4] = {0,1,0,-1};
int pY[4] = {1,0,-1,0};

int main()
{
    freopen("input.txt","r",stdin);

    int testSize;
    cin >> testSize;

    for(int t = 0; t < testSize; t++)
    {
        Cell** sudoku = new Cell*[6];
        for(int i = 0; i < 6; i++)
            sudoku[i] = new Cell[6];

        bool** visited = new bool*[6];
        for(int i = 0; i < 6; i++)
            visited[i] = new bool[6];

        for(int i = 0; i < 6; i++)
            for(int j = 0; j < 6; j++)
                visited[i][j] = false;

        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                string temp;
                cin >> temp;

                if(temp.find('/') !=  string::npos)
                {
                    sudoku[i][j].isFraction = true;
                    sudoku[i][j].number = -1;

                    for(int k = 0; k < temp.size(); k++)
                    {
                        if(temp.at(k) != '-' && temp.at(k) != '/')
                        {
                            if(k == 0)
                                sudoku[i][j].numerator = temp.at(k) - 48;
                            else if(k == 2)
                                sudoku[i][j].denominator = temp.at(k) - 48;
                        }
                    }
                }
                else
                {
                    if(temp.at(0) != '-')
                        sudoku[i][j].number = temp.at(0) - 48;

                    sudoku[i][j].isFraction = false;
                    sudoku[i][j].numerator = -1;
                    sudoku[i][j].denominator = -1;
                }
            }
        }

        makeSudoku(sudoku, 0, 0, visited);

        cout << "#" << t+1 << endl;
        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                if(sudoku[i][j].isFraction)
                    cout << sudoku[i][j].numerator << "/" << sudoku[i][j].denominator << " ";
                else
                    cout << sudoku[i][j].number << " ";
            }
            cout << endl;
        }


        for(int i = 0; i < 6; i++)
        {
            delete sudoku[i];
            delete visited[i];
        }
        delete sudoku;
        delete visited;
    }

    return 0;
}

bool makeSudoku4Way(Cell** sudoku, int x, int y, bool** visited)
{
    for(int i = 0; i < 4; i++)
    {
        int targetX = x + pX[i];
        int targetY = y + pY[i];

        if(!makeSudoku(sudoku,targetX,targetY,visited))
            return visited[x][y] = false;
    }
    return true;
}

bool makeSudoku(Cell** sudoku, int x, int y, bool** visited)
{
    if(x <0 || x == 6 || y < 0 || y == 6)
        return true;

    if(visited[x][y])
        return true;

    visited[x][y] = true;

    vector<int> candidates = makeCandidate(sudoku, x, y);


    if(sudoku[x][y].isFraction)
    {
        if(sudoku[x][y].numerator != 0 && sudoku[x][y].denominator != 0)
            return makeSudoku4Way(sudoku, x, y, visited);
        else if(sudoku[x][y].numerator != 0 && sudoku[x][y].denominator == 0)
        {
            for(int i = 0; i < candidates.size(); i++)
            {
                if(candidates[i] <= sudoku[x][y].numerator)
                    continue;

                sudoku[x][y].denominator = candidates[i];
                if(makeSudoku4Way(sudoku, x, y, visited))
                    return true;
                sudoku[x][y].denominator = 0;
            }
        }
        else if(sudoku[x][y].numerator == 0 && sudoku[x][y].denominator != 0)
        {
            for(int i = 0; i < candidates.size(); i++)
            {
                if(candidates[i] >= sudoku[x][y].denominator)
                    continue;
                sudoku[x][y].numerator = candidates[i];
                if(makeSudoku4Way(sudoku, x, y, visited))
                    return true;
                sudoku[x][y].numerator = 0;
            }
        }
        else
        {
            for(int i = 0; i < candidates.size(); i++)
            {
                for(int j = i+1; j < candidates.size(); j++)
                {

                    sudoku[x][y].numerator = candidates[i];
                    sudoku[x][y].denominator = candidates[j];
                    if(makeSudoku4Way(sudoku, x, y, visited))
                        return true;
                    sudoku[x][y].numerator = 0;
                    sudoku[x][y].denominator = 0;
                }
            }
        }
    }
    else
    {
        if(sudoku[x][y].number != 0)
        {
            return makeSudoku4Way(sudoku, x, y, visited);
        }
        else
        {
            for(int i = 0; i < candidates.size(); i++)
            {

                sudoku[x][y].number = candidates[i];
                if(makeSudoku4Way(sudoku, x, y, visited))
                    return true;
                sudoku[x][y].number = 0;
            }
        }
    }

    return visited[x][y] = false;
}

vector<int> makeCandidate(Cell** sudoku, int x, int y)
{
    vector<int> candidates(10,0);
    vector<int> answer;

    for(int i = 0; i < 6; i++)
    {
        if(sudoku[i][y].isFraction)
        {
            if(sudoku[i][y].numerator != 0)
                candidates[sudoku[i][y].numerator] = -1;
            if(sudoku[i][y].denominator != 0)
                candidates[sudoku[i][y].denominator] = -1;
        }
        else
        {
            if(sudoku[i][y].number != 0)
                candidates[sudoku[i][y].number] = -1;
        }

        if(sudoku[x][i].isFraction)
        {
            if(sudoku[x][i].numerator != 0)
                candidates[sudoku[x][i].numerator] = -1;
            if(sudoku[x][i].denominator != 0)
                candidates[sudoku[x][i].denominator] = -1;
        }
        else
        {
            if(sudoku[x][i].number != 0)
                candidates[sudoku[x][i].number] = -1;
        }
    }

    if(x % 2 == 0)
    {
        for(int i = 0; i < 3; i++)
        {
            int target = (int)(y/3)*3 + i;
            if(sudoku[x+1][target].isFraction)
            {
                if(sudoku[x+1][target].numerator != 0)
                    candidates[sudoku[x+1][target].numerator] = -1;
                if(sudoku[x+1][target].denominator != 0)
                    candidates[sudoku[x+1][target].denominator] = -1;
            }
            else
            {
                if(sudoku[x+1][target].number != 0)
                    candidates[sudoku[x+1][target].number] = -1;
            }
        }
    }
    else
    {
        for(int i = 0; i < 3; i++)
        {
            int target = (int)(y/3)*3 + i;
            if(sudoku[x-1][target].isFraction)
            {
                if(sudoku[x-1][target].numerator != 0)
                    candidates[sudoku[x-1][target].numerator] = -1;
                if(sudoku[x-1][target].denominator != 0)
                    candidates[sudoku[x-1][target].denominator] = -1;
            }
            else
            {
                if(sudoku[x-1][target].number != 0)
                    candidates[sudoku[x-1][target].number] = -1;
            }
        }
    }

    for(int i = 1; i < 10; i++)
    {
        if(candidates[i] != -1)
            answer.push_back(i);
    }

    return answer;
}
