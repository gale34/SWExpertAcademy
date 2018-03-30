#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

double findBalancePt(vector<int> magBodyPt, vector<int> magBodyMass, int balancePt);
int main()
{
    freopen("input.txt","r",stdin);

    int testCase;
    cin >> testCase;

    for(int i = 0; i < testCase; i++)
    {
        int magneticBody;
        cin >> magneticBody;

        vector<int> magBodyPt;
        vector<int> magBodyMass;

        for(int j = 0; j < magneticBody; j++)
        {
            int temp;
            cin >> temp;
            magBodyPt.push_back(temp);
        }

        for(int j = 0; j < magneticBody; j++)
        {
            int temp;
            cin >> temp;
            magBodyMass.push_back(temp);
        }

        cout << "#" << i+1 << " ";

        for(int j = 0; j < magneticBody; j++)
        {

        }

    }
    cout << "Hello world!" << endl;
    return 0;
}

double findBalancePt(vector<int> magBodyPt, vector<int> magBodyMass, int balancePt)
{
    double leftForce = 0;
    double rightForce = 0;
    double x;


}

double attractiveForce(vector<int> magBodyPt, vector<int> magBodyMass)
{
    double target;
    int numMagBody = magBodyPt.size();
    for(int i = 0; i < numMagBody; i++)
    {
        magBodyPt[i]
    }

}
