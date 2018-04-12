#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define VISITED 1
#define NOT_VISITED 0

using namespace std;

struct matrix
{
    int width;
    int height;
    int matrixSize;
};

int pX[4] = {0,1,0,-1};
int pY[4] = {1,0,-1,0};

bool cmp(const matrix &a, const matrix &b)
{

    if(a.matrixSize != b.matrixSize)
        return a.matrixSize < b.matrixSize;
    else
        return a.width < b.width;
};

void getSubMatrix(vector<vector<int> >& wholeMatrix, vector<vector<int> >& visited, int x, int y, matrix& subMatrix);

int main()
{
    freopen("input.txt","r",stdin);

    int testCase;
    cin >> testCase;

    for(int t = 0; t < testCase; t++)
    {
        int matrixSize;
        cin >> matrixSize;

        vector<vector<int> > wholeMatrix(matrixSize);

        for(int i = 0; i < matrixSize; i++)
        {
            vector<int> temp(matrixSize,0);
            wholeMatrix[i] = temp;
        }
        vector<vector<int> > visited(wholeMatrix);

        for(int i = 0; i < matrixSize; i++)
            for(int j = 0; j < matrixSize; j++)
                cin >> wholeMatrix[i][j];

        vector<matrix> subMatrixes;

        for(int i = 0; i < matrixSize; i++)
        {
            for(int j = 0; j < matrixSize; j++)
            {
                if(wholeMatrix[i][j] != 0 && visited[i][j] == NOT_VISITED)
                {
                    matrix tempPoint;
                    tempPoint.width = i;
                    tempPoint.height = j;

                    getSubMatrix(wholeMatrix, visited, i, j, tempPoint);
                    tempPoint.width = tempPoint.width - i + 1;
                    tempPoint.height = tempPoint.height - j + 1;
                    tempPoint.matrixSize = tempPoint.width * tempPoint.height;

                    subMatrixes.push_back(tempPoint);
                }
            }
        }
        sort(subMatrixes.begin(), subMatrixes.end(), cmp);

        cout << "#" << t+1 << " " << subMatrixes.size() << " ";
        for(int i = 0; i < subMatrixes.size(); i++)
            cout << subMatrixes[i].width << " " << subMatrixes[i].height << " ";
        cout << endl;
    }

    return 0;
}

void getSubMatrix(vector<vector<int> >& wholeMatrix, vector<vector<int> >& visited, int x, int y, matrix& subMatrix)
{
    int matrixSize = wholeMatrix.size();

    visited[x][y] = VISITED;

    if(x > subMatrix.width)
        subMatrix.width = x;
    if(y > subMatrix.height)
        subMatrix.height = y;

    for(int i = 0; i < 4; i++)
    {
        int targetX = x+pX[i];
        int targetY = y+pY[i];

        if(targetX >= 0 && targetX < matrixSize && targetY >= 0 && targetY < matrixSize && visited[targetX][targetY] == NOT_VISITED && wholeMatrix[targetX][targetY] != 0)
            getSubMatrix(wholeMatrix, visited, targetX, targetY, subMatrix);
    }
}
