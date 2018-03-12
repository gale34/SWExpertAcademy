#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int getViewHouses(vector<int> houses);

int main()
{
    freopen("input.txt","r",stdin);

    int num_test_cases = 10;

    for(int i = 0; i < num_test_cases; i++)
    {
        int width = 0;
        int result = 0;
        vector<int> houses;

        cin >> width;

        for(int j = 0; j < width; j++)
        {
            int temp = 0;

            cin >> temp;
            houses.push_back(temp);
        }

        result = getViewHouses(houses);

        cout << "#" << i+1 << " " << result << endl;
    }

    return 0;
}

int getViewHouses(vector<int> houses)
{
    if(houses.size() < 5)
        return 0;

    int maxNeighberHeight = 0;
    int sum = 0;

    for(int i = 2; i < houses.size()-2; i++)
    {
        int max_neighber = 0;

        max_neighber = max(max_neighber, houses[i-2]);
        max_neighber = max(max_neighber, houses[i-1]);

        max_neighber = max(max_neighber, houses[i+1]);
        max_neighber = max(max_neighber, houses[i+2]);

        int sub_result = houses[i] - max_neighber;
        if(sub_result > 0)
            sum += sub_result;
    }

    return sum;
}
