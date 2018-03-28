#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void convertPassword(vector<char>& password);

int main()
{
    freopen("input.txt","r",stdin);

    for(int i = 0; i < 10; i++)
    {
        int passwordSize;
        cin >> passwordSize;
        vector<char> password;

        for(int i = 0; i < passwordSize; i++)
        {
            char temp;
            cin >> temp;
            password.push_back(temp);
        }


        convertPassword(password);

        cout << "#" << i+1 << " ";
        for(int i = 0; i < password.size(); i++)
            cout << password[i];
        cout << endl;
    }

    return 0;
}

void convertPassword(vector<char>& password)
{
    bool isEraseble = false;
    for(vector<char>::iterator it = password.begin(); it != password.end();)
    {
        vector<char>::iterator nextIt = it+1;
        isEraseble = false;

        while(1)
        {
            if(nextIt != password.end() && *it == *nextIt)
            {
                isEraseble = true;
                if(it == password.begin())
                    break;
                it--;
                nextIt++;
            }
            else
            {
                if(isEraseble)
                {
                    it++;
                    nextIt--;
                }
                break;
            }
        }

        if(isEraseble)
            password.erase(it,nextIt+1);
        else
            it++;
    }
}
