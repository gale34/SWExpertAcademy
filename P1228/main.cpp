#include <iostream>
#include <vector>
#include <cstdio>


using namespace std;

void insertPassword(vector<int>& password, int pt, vector<int>& target);

int main()
{
    freopen("input.txt","r",stdin);

    for(int i = 0; i < 10; i++)
    {
        vector<int> passwords;
        int originSize;
        cin >> originSize;

        for(int j = 0; j < originSize; j++)
        {
            int temp;
            cin >> temp;
            passwords.push_back(temp);
        }

        int numOfcommand;
        cin >> numOfcommand;

        for(int j = 0; j < numOfcommand; j++)
        {
            char temp;
            cin >> temp;

            if(temp != 'I')
                cout << "ERROR!" << endl;

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

            insertPassword(passwords,pt,target);
        }

        cout << "#" << i+1 << " ";

        for(int j = 0; j < 10; j++)
            cout << passwords[j] << " ";
        cout << endl;

    }

    return 0;
}

void insertPassword(vector<int>& password, int pt, vector<int>& target)
{
    password.insert(password.begin()+pt,target.begin(),target.end());
}
