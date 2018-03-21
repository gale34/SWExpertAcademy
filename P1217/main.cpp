#include <iostream>
#include <cstdio>

using namespace std;

int getPow(int base, int power);

int main()
{
    freopen("input.txt","r",stdin);

    for(int i = 0; i < 10; i++)
    {
        int testCase;
        int base;
        int power;
        int result = 0;
        cin >> testCase;
        cin >> base >> power;

        result = getPow(base,power);

        cout << "#" << testCase << " " << result << endl;
    }

    return 0;
}

int getPow(int base, int power)
{
    if(power == 0)
        return 1;
    return base * getPow(base,power-1);
}
