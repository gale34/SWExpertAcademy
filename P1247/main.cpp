#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);

    int testCase;
    cin >> testCase;

    for(int i = 0; i < testCase; i++)
    {
        int numOfcustomer;
        cin >> numOfcustomer;

        pair<int, int> company;
        cin >> company.first >> company.second;

        pair<int, int> home;
        cin >> home.first >> home.second;

        vector<pair<int,int> > customers;
        for(int j = 0; j < numOfcustomer; j++)
        {
            pair<int, int> temp;

            cin >> temp.first >> temp.second;

            customers.push_back(temp);
        }

        sort(customers.begin(), customers.end());

    }
    cout << "Hello world!" << endl;
    return 0;
}
