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
};

int pX[4] = {0,1,0,-1};
int pY[4] = {1,0,-1,0};

void inputData(vector<vector<int> >& wholeMatrix, vector<vector<int> >& visited);
vector<matrix> findMatrixes(vector<vector<int> >& wholeMatrix, vector<vector<int> >& visited);
void getSubMatrix(vector<vector<int> >& wholeMatrix, vector<vector<int> >& visited, int x, int y, matrix& subMatrix);
void makeGraph(vector<matrix>& subMatrixes, vector<vector<int> >& matrixGraph);
int minMultiplyMatrixes(vector<matrix>& subMatrixes, vector<vector<int> >& matrixGraph);
int multiplyTry(vector<matrix>& subMatrixes, vector<int>& link);
vector<int> dfs(vector<vector<int> >& matrixGraph, vector<int> link, vector<bool>& visited, int target);

int main()
{
    freopen("input.txt","r",stdin);

    int testCase;
    cin >> testCase;

    for(int t = 0; t < testCase; t++)
    {
        vector<vector<int> > wholeMatrix, visited;
        inputData(wholeMatrix, visited);
        vector<matrix> subMatrixes;

        subMatrixes = findMatrixes(wholeMatrix, visited);
        vector<vector<int> > matrixGraph(subMatrixes.size());
        makeGraph(subMatrixes,matrixGraph);

        int result = minMultiplyMatrixes(subMatrixes, matrixGraph);

        cout << "#" << t+1 << " " << result << endl;
    }

    return 0;
}

void inputData(vector<vector<int> >& wholeMatrix, vector<vector<int> >& visited)
{
    int matrixSize;
    cin >> matrixSize;

    wholeMatrix.resize(matrixSize);
    for(int i = 0; i < matrixSize; i++)
    {
        vector<int> temp(matrixSize,0);
        wholeMatrix[i] = temp;
    }

    visited = wholeMatrix;

    for(int i = 0; i < matrixSize; i++)
        for(int j = 0; j < matrixSize; j++)
            cin >> wholeMatrix[i][j];
}

vector<matrix> findMatrixes(vector<vector<int> >& wholeMatrix, vector<vector<int> >& visited)
{
    vector<matrix> subMatrixes;
    int matrixSize = wholeMatrix.size();

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

                subMatrixes.push_back(tempPoint);
            }
        }
    }

    return subMatrixes;
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

void makeGraph(vector<matrix>& subMatrixes, vector<vector<int> >& matrixGraph)
{
    // height = x, width = y
    int matrixSize = matrixGraph.size();
    for(int i = 0; i < subMatrixes.size(); i++)
    {
        int target = subMatrixes[i].width;
        for(int j = 0; j < matrixSize; j++)
        {
            if(i == j)
                continue;

            if(target == subMatrixes[j].height)
                matrixGraph[i].push_back(j);
        }
    }
}

int minMultiplyMatrixes(vector<matrix>& subMatrixes, vector<vector<int> >& matrixGraph)
{
    int matrixSize = matrixGraph.size();
    int result = 9999999;

    for(int i = 0; i < matrixSize; i++)
    {
        vector<int> link;
        vector<bool> visited = vector<bool>(matrixSize, false);

        link = dfs(matrixGraph, link, visited, i);

        for(int i = 0; i < link.size(); i++)
        {
            int target = link[i];
            cout << subMatrixes[target].height << " " << subMatrixes[target].width << " ";
        }
        cout << endl;
        if(link.size() == matrixSize)
            result = min(result,multiplyTry(subMatrixes,link));
    }

    return result;
}

int multiplyTry(vector<matrix>& subMatrixes, vector<int>& link)
{
    int resultHeight = 0;
    int resultWidth = 0;
    int result = 0;

    for(int i = 0; i < link.size(); i++)
    {
        int target = link[i];
        if(i != 0)
        {
            int semiResult = resultHeight * resultWidth * subMatrixes[target].width;
            result += semiResult;
        }
        resultHeight = subMatrixes[target].height;
        resultWidth = subMatrixes[target].width;
    }

    return result;
}

vector<int> dfs(vector<vector<int> >& matrixGraph, vector<int> link, vector<bool>& visited, int target)
{
    link.push_back(target);
    visited[target] = true;
    vector<int> result(link);

    for(int i = 0; i < matrixGraph[target].size(); i++)
    {
        vector<int> tempLink;
        int subTarget= matrixGraph[target][i];
        if(!visited[subTarget])
            tempLink = dfs(matrixGraph, link, visited, subTarget);

        if(result.size() < tempLink.size())
            result = tempLink;
    }

    visited[target] = false;
    return result;
}
