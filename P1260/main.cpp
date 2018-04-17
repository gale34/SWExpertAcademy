#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define VISITED 1
#define NOT_VISITED 0
#define INF 9999999

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
int multiplyTry(vector<int>& matrixSides, vector<vector<int> >& multiSums, int start, int finish);
vector<matrix> dfs(vector<matrix>& subMatrixes, vector<vector<int> >& matrixGraph, vector<matrix> link, vector<bool>& visited, int target);

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
        vector<matrix> link;
        vector<bool> visited = vector<bool>(matrixSize, false);

        link = dfs(subMatrixes, matrixGraph, link, visited, i);

        /*for(int i = 0; i < link.size(); i++)
        {
            cout << link[i].height << " " << link[i].width << " ";
        }
        cout << endl;*/
        if(link.size() == matrixSize)
        {
            vector<int> matrixSides(matrixSize+1);
            for(int j = 0; j <= matrixSize; j++)
            {
                if(j == 0)
                    matrixSides[j] = link[j].height;
                else
                    matrixSides[j] = link[j-1].width;
            }
            vector<vector<int> > multiSums(matrixSize+1);

            for(int j = 0; j <= matrixSize; j++)
            {
                vector<int> temp(matrixSize+1, INF);
                multiSums[j] = temp;
            }

            result = min(result,multiplyTry(matrixSides,multiSums,1,matrixSize));
        }

    }

    return result;
}

int multiplyTry(vector<int>& matrixSides, vector<vector<int> >& multiSums, int start, int finish)
{
    int& result = multiSums[start][finish];
    if(start == finish)
        return result = 0;

    if(result != INF)
        return result;

    for(int i = start; i < finish; i++)
    {
        result = min(result, multiplyTry(matrixSides, multiSums, start,i)
                     + multiplyTry(matrixSides, multiSums, i+1,finish)
                     + matrixSides[start-1]*matrixSides[i]*matrixSides[finish]);
    }

    return result;
}

vector<matrix> dfs(vector<matrix>& subMatrixes, vector<vector<int> >& matrixGraph, vector<matrix> link, vector<bool>& visited, int target)
{
    link.push_back(subMatrixes[target]);
    visited[target] = true;
    vector<matrix> result(link);

    for(int i = 0; i < matrixGraph[target].size(); i++)
    {
        vector<matrix> tempLink;
        int subTarget= matrixGraph[target][i];
        if(!visited[subTarget])
            tempLink = dfs(subMatrixes, matrixGraph, link, visited, subTarget);

        if(result.size() < tempLink.size())
            result = tempLink;
    }

    visited[target] = false;
    return result;
}
