#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int getMaxPrice(int number, int num_swap);

int main()
{
    //freopen("input.txt","r",stdin);

    int num_test_cases = 0;

    cin >> num_test_cases;
    for(int i = 0; i < num_test_cases; i++)
    {
        int number;
        int num_swap;

        cin >>number;
        cin >> num_swap;

        int result = getMaxPrice(number, num_swap);
        cout << "#" << i+1 << " " << result << endl;
    }
    return 0;
}

int getMaxPrice(int number, int num_swap)
{
    if(number < 10)
        return number;

    vector<int> split_number;

    int numOfNumber[10];
    bool isMoreThanOne = false;
    for(int i = 0; i < 10; i++)
        numOfNumber[i] = 0;

    int target = number;
    vector<int>::iterator it;

    while(target > 0)
    {
        if(target == number)
            split_number.push_back(target % 10);
        else
        {
            it = split_number.begin();
            split_number.insert(it,target % 10);
        }
        target /= 10;
    }

    for(int i = 0; i < split_number.size(); i++)
        numOfNumber[split_number[i]]++;

    for(int i = 9; i >= 0; i--)
    {
        if(numOfNumber[i] > 1)
            isMoreThanOne = true;
        if(i != 9)
            numOfNumber[i] += numOfNumber[i+1];
    }

    for(int i = 0; i < split_number.size(); i++)
    {
        if(num_swap <= 0)
            break;

        int index_max = i;

        for(int j = split_number.size() - 1; j > i ; j--)
        {
            if(split_number[j] > split_number[index_max])
                index_max = j;
            else if(split_number[j] == split_number[index_max] && j == numOfNumber[split_number[i]] - 1)
                index_max = j;

        }

        if(index_max != i)
        {
            int temp = split_number[index_max];
            split_number[index_max] = split_number[i];
            split_number[i] = temp;
            num_swap--;
        }
    }

    if(num_swap > 0 && num_swap % 2 != 0 && isMoreThanOne == false)
    {
        int index_swap_1 = split_number.size()-1;
        int index_swap_2 = split_number.size()-2;

        int temp = split_number[index_swap_1];
        split_number[index_swap_1] = split_number[index_swap_2];
        split_number[index_swap_2] = temp;
    }

    int result = 0;

    for(int i = 0; i < split_number.size(); i++)
    {
        result *= 10;
        result += split_number[i];
    }

    return result;
}
