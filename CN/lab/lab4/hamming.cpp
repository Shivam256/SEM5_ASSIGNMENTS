#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int randomBitLen(int len)
{
    int i = 0;
    while (true)
    {
        if (pow(2, i) >= len + i + 1)
        {
            return i;
        }
        i++;
    }
}

int main()
{
    string message;
    cout << "Enter the message string:";
    cin >> message;

    int r = randomBitLen(message.size());
    int totalLen = r + message.size();

    vector<int> bits(totalLen,0);
    int i = 0;

    while(pow(2,i) <= totalLen){
        bits[pow(2,i) - 1] = -1;
        i++;
    }

    



    return 0;
}