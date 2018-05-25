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

int cnt;

bool makeSudoku(Cell** sudoku, int x, int y);
vector<int> makeCandidate(Cell** sudoku, int x, int y);

int main()
{
    freopen("input.txt","r",stdin);

    int testSize;
    cin >> testSize;

    for(int t = 0; t < 1; t++)
    {
        Cell** sudoku = new Cell*[6];
        for(int i = 0; i < 6; i++)
            sudoku[i] = new Cell[6];

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

        cnt = 0;

        makeSudoku(sudoku, 0, 0);

        cout <<endl;
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
    }

    return 0;
}

bool makeSudoku(Cell** sudoku, int x, int y)
{
    if(x == 6 || y == 6)
        return true;

    vector<int> candidates = makeCandidate(sudoku, x, y);

    cout << "Test  "  << x << " " << y << endl;
    cout << "CANDIDATE : ";
    for(int i = 0; i < candidates.size(); i++)
        cout << candidates[i] << " ";
    cout << endl;
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

    if(sudoku[x][y].isFraction)
    {
        if(sudoku[x][y].numerator != 0 && sudoku[x][y].denominator != 0)
        {
            if(makeSudoku(sudoku,x,y+1))
                return makeSudoku(sudoku,x+1,y);
        }
        else if(sudoku[x][y].numerator != 0 && sudoku[x][y].denominator == 0)
        {
            for(int i = 0; i < candidates.size(); i++)
            {
                if(candidates[i] <= sudoku[x][y].numerator)
                    continue;

                sudoku[x][y].denominator = candidates[i];
                if(makeSudoku(sudoku,x,y+1))
                    if(makeSudoku(sudoku,x+1,y))
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
                if(makeSudoku(sudoku,x,y+1))
                    if(makeSudoku(sudoku,x+1,y))
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
                    if(makeSudoku(sudoku,x,y+1))
                        if(makeSudoku(sudoku,x+1,y))
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
            if(makeSudoku(sudoku,x,y+1))
                return makeSudoku(sudoku,x+1,y);
        }
        else
        {

            for(int i = 0; i < candidates.size(); i++)
            {
                sudoku[x][y].number = candidates[i];
                if(makeSudoku(sudoku,x,y+1))
                    if(makeSudoku(sudoku,x+1,y))
                        return true;
                sudoku[x][y].number = 0;
            }
        }
    }

    return false;
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
