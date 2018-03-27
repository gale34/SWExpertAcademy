#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void insertPassword(vector<int>& password);
void deletePassword(vector<int>& password);
void appendPassword(vector<int>& password);

int main()
{
    freopen("input.txt","r",stdin);

    for(int i = 0; i < 10; i++)
    {
        vector<int> password;
        int originSize;
        cin >> originSize;

        for(int j = 0; j < originSize; j++)
        {
            int temp;
            cin >> temp;
            password.push_back(temp);
        }

        int numOfcommand;
        cin >> numOfcommand;

        for(int j = 0; j < numOfcommand; j++)
        {
            char temp;
            cin >> temp;

            if(temp == 'I')
                insertPassword(password);
            else if(temp == 'D')
                deletePassword(password);
            else if(temp == 'A')
                appendPassword(password);
        }

        cout << "#" << i+1 << " ";

        for(int j = 0; j < 10; j++)
            cout << password[j] << " ";
        cout << endl;

    }

    return 0;
}

void insertPassword(vector<int>& password)
{
    int pt;
    int numSize;

    cin >> pt >> numSize;

    vector<int> target;

    for(int k = 0; k < numSize; k++)
    {
        int temp;
        cin >> temp;

        target.push_back(temp);
    }

    password.insert(password.begin()+pt,target.begin(),target.end());
}

void deletePassword(vector<int>& password)
{
    int pt;
    int numSize;

    cin >> pt >> numSize;

    password.erase(password.begin()+pt,password.begin()+pt+numSize);
}

void appendPassword(vector<int>& password)
{
    int numSize;

    cin >> numSize;

    for(int k = 0; k < numSize; k++)
    {
        int temp;
        cin >> temp;

        password.push_back(temp);
    }
}
