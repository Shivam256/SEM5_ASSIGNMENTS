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
bool isEvenParity(vector<int> v)
{
    int c = 0;
    for (auto i : v)
    {
        if (i == 1)
        {
            c++;
        }
    }
    return c % 2 == 0;
}
vector<int> generateError(vector<int> &bits)
{
    vector<int> result;
    int x = rand() % bits.size();
    for (int i = 0; i < bits.size(); i++)
    {
        if (i == x)
        {
            if (bits[i] == 1)
            {
                result.push_back(0);
            }
            else
            {
                result.push_back(1);
            }
        }
        else
        {
            result.push_back(bits[i]);
        }
    }
    return result;
}
int getRandomBit(vector<int> v, int k)
{
    vector<int> temp;
    int i = k - 1;
    int ctr = 0;
    while (i < v.size())
    {
        if (ctr == k)
        {
            i += k;
            ctr = 0;
            continue;
        }
        temp.push_back(v[i]);
        i++;
        ctr++;
    }
    if (isEvenParity(temp))
    {
        return 0;
    }
    return 1;
}
int main()
{
    string message;
    cout << "Enter the message string:";
    cin >> message;
    int r = randomBitLen(message.size());
    int totalLen = r + message.size();
    vector<int> bits(totalLen, 0);
    int i = 0;
    while (pow(2, i) <= totalLen)
    {
        bits[pow(2, i) - 1] = -1;
        i++;
    }
    int j = 0; // for(int i=totalLen-1;i>=0;i--){ // if(bits[i] != -1){ // bits[i] = message[j] - '0'; // j++; // } // } for(int i=0;i<totalLen;i++){ if(bits[i] != -1){ bits[i] = message[j] - '0'; j++; } } for(auto i:bits){ cout<<i<<" "; } cout<<endl; // int x = getRandomBit(bits,8); // cout<<x<<endl; for(int i=0;i<bits.size();i++){ if(bits[i] == -1){ bits[i] = getRandomBit(bits,i+1); } } for(auto i:bits){ cout<<i<<" "; } cout<<endl; vector<int> erroredBits = generateError(bits); for(auto i:erroredBits){ cout<<i<<" "; } cout<<endl; return 0; }