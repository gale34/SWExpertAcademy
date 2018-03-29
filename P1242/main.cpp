#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

#define PASSWORD_SIZE 56

using namespace std;

vector<string> extractPassword(char** barcode, int width, int height);
int verifyPassword(vector<string> codes);
void convertHexToBinPassword(vector<string>& codes);
int convertPassword(string code);
const char* hexToBin(char c);

int main()
{
    freopen("sample_input.txt","r",stdin);

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

        vector<string> codes = extractPassword(barcode, width, height);
        convertHexToBinPassword(codes);

        //for(int k = 0; k < codes.size(); k++)
            //cout << codes[k] <<endl;

        //int result = verifyPassword(barcode, width, height);

//        cout << "#" << i+1 << " " << result << endl;
        for(int j = 0; j < height; j++)
            delete barcode[j];
        delete barcode;
    }

    return 0;
}

vector<string> extractPassword(char** barcode, int width, int height)
{
    bool isFind = false;
    vector<string> codes;

    for(int i = 0; i < height; i++)
    {
        string temp = "";
        for(int j = width-1; j >= 0; j--)
        {
            if(barcode[i][j] != '0')
            {
                isFind = true;
                temp.insert(temp.begin(),barcode[i][j]);
            }
            else if(isFind == true && barcode[i][j] == '0' && temp.size() >= 14)
            {
                if(codes.empty())
                    codes.push_back(temp);
                else
                {
                    bool isAlreadyFind = false;
                    for(int k = 0; k < codes.size(); k++)
                    {
                        if(codes[k].find(temp) != string::npos)
                        {
                            isAlreadyFind = true;
                            break;
                        }
                    }
                    if(!isAlreadyFind)
                        codes.push_back(temp);
                }
                isFind = false;
                temp.clear();
            }
        }

        if(!temp.empty())
        {
            codes.back().insert(codes.back().begin(),temp);
            isFind = false;
            temp
        }

    }

    return codes;
}

int verifyPassword(vector<string> codes)
{
    vector<int> password;
    string passwordCode = "";

   /* for(int i = 0; i < PASSWORD_SIZE; i++)
    {
        int target = lastPt.second - PASSWORD_SIZE + i + 1;

        passwordCode.append(1,barcode[lastPt.first][target]);

        if(passwordCode.size() == 7)
        {
            password.push_back(convertPassword(passwordCode));
            passwordCode.clear();
        }
    }*/

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

void convertHexToBinPassword(vector<string>& codes)
{
    for(int i = 0; i < codes.size(); i++)
    {

        string binaryCode = "";
        string target = codes[i];
        cout << target << endl;
        for(int j = 0; j < target.size(); j++)
            binaryCode.append(hexToBin(target.at(j)));

        cout << "size : " <<binaryCode.size() << endl;
        cout << "before :" << binaryCode << endl;

        int erasePt = 0;
        for(int j = binaryCode.size()-1; j >= 0; j--)
        {
            if(binaryCode.at(j) == '0')
                erasePt = j;
            else
                break;
        }
        if(erasePt != 0)
            binaryCode.erase(binaryCode.begin() + erasePt, binaryCode.end());

        erasePt = 0;
        for(int j = 0; j < binaryCode.size(); j++)
        {
            if(binaryCode.at(j) == '0')
                erasePt = j;
            else
                break;
        }
        if(erasePt != 0)
            binaryCode.erase(binaryCode.begin(), binaryCode.begin() + erasePt);

        cout << "size : " <<binaryCode.size() << endl;
        if(binaryCode.size() % PASSWORD_SIZE != 0)
        {
            int missingZero = PASSWORD_SIZE - (binaryCode.size() % PASSWORD_SIZE);
            binaryCode.insert(binaryCode.begin(),missingZero,'0');
        }

        cout << "after :" << binaryCode << endl;
        codes[i] = binaryCode;
    }
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

const char* hexToBin(char c)
{
    switch(toupper(c))
    {
    case '0':
        return "0000";
    case '1':
        return "0001";
    case '2':
        return "0010";
    case '3':
        return "0011";
    case '4':
        return "0100";
    case '5':
        return "0101";
    case '6':
        return "0110";
    case '7':
        return "0111";
    case '8':
        return "1000";
    case '9':
        return "1001";
    case 'A':
        return "1010";
    case 'B':
        return "1011";
    case 'C':
        return "1100";
    case 'D':
        return "1101";
    case 'E':
        return "1110";
    case 'F':
        return "1111";
    }
}
