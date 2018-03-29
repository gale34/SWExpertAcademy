#include <iostream>
#include <cstdio>
#include <vector>

#define PASSWORD_SIZE 56

using namespace std;

int verifyPassword(char** barcode, int width, int height);
int convertPassword(string code);

int main()
{
    freopen("input.txt","r",stdin);

    int numTest;
    cin >> numTest;

    for(int i = 0; i < numTest; i++)
    {
        int width, height;

        cin >> height >> width;

        char** barcode;
        barcode = new char*[height];
        for(int j = 0; j < height; j++)
            barcode[j] = new char[width];

        for(int j = 0; j < height; j++ )
            for(int k = 0; k < width; k++)
                cin >> barcode[j][k];

        int result = verifyPassword(barcode, width, height);

        cout << "#" << i+1 << " " << result << endl;
        for(int j = 0; j < height; j++)
            delete barcode[j];
        delete barcode;
    }

    return 0;
}


int verifyPassword(char** barcode, int width, int height)
{
    pair<int, int> lastPt;

    for(int i = 0; i < height; i++)
    {
        for(int j = width-1; j >= width - PASSWORD_SIZE; j--)
        {
            if(barcode[i][j] == '1')
            {
                lastPt.first = i;
                lastPt.second = j;
                break;
            }
        }
    }

    vector<int> password;
    string passwordCode = "";

    for(int i = 0; i < PASSWORD_SIZE; i++)
    {
        int target = lastPt.second - PASSWORD_SIZE + i + 1;

        passwordCode.append(1,barcode[lastPt.first][target]);

        if(passwordCode.size() == 7)
        {
             password.push_back(convertPassword(passwordCode));
             passwordCode.clear();
        }
    }

    int odd = 0;
    int even = 0;
    for(int i = 0; i < password.size()-1; i++)
    {
        if((i+1)%2 != 0)
            odd += password[i];
        else
            even += password[i];
    }

    if((odd*3 + even + password[7]) % 10 == 0)
        return odd + even + password[7];
    else
        return 0;

}

int convertPassword(string code)
{
    if(code.find("0001101") != string::npos)
        return 0;
    else if(code.find("0011001") != string::npos)
        return 1;
    else if(code.find("0010011") != string::npos)
        return 2;
    else if(code.find("0111101") != string::npos)
        return 3;
    else if(code.find("0100011") != string::npos)
        return 4;
    else if(code.find("0110001") != string::npos)
        return 5;
    else if(code.find("0101111") != string::npos)
        return 6;
    else if(code.find("0111011") != string::npos)
        return 7;
    else if(code.find("0110111") != string::npos)
        return 8;
    else if(code.find("0001011") != string::npos)
        return 9;

    return -1;
}
