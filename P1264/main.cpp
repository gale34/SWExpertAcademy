#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int matchBarcodes(string a, string b, int** cache);

int main()
{
    freopen("input.txt","r",stdin);
    int testCase;
    cin >> testCase;

    cout << fixed;
    cout.precision(2);

    for(int t = 0; t < testCase; t++)
    {
        int stringSize;
        cin >> stringSize;

        string a,b;
        cin >> a;
        cin >> b;

        int** cache = new int*[stringSize+1];
        for(int i = 0; i < stringSize+1; i++)
        {
            cache[i] = new int[stringSize+1];
            for(int j = 0; j < stringSize+1; j++)
                cache[i][j] = -1;
        }
        int result = matchBarcodes(a,b,cache);

        cout << "#" << t+1 << " " << (double)result/stringSize*100 << endl;
    }
    return 0;
}

int matchBarcodes(string a, string b, int** cache)
{
    //cout << a.size() << " " << a << " " << b.size() << " " << b << endl;
    if(a.size() == 0 || b.size() == 0)
        return 0;

    int& result = cache[a.size()][b.size()];

    if(result != -1)
        return result;

    if(a.at(0) == b.at(0))
        return result = matchBarcodes(a.substr(1,a.size()-1),b.substr(1,b.size()-1),cache)+1;
    else
        return result = max(matchBarcodes(a,b.substr(1,b.size()-1),cache),
                   matchBarcodes(a.substr(1,a.size()-1),b,cache));
}
