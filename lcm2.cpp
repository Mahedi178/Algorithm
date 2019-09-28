#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int longest_sequence(vector<int> &input, int length)
{
    vector<int> T(length), R(length, -1);
    T[0] = 0;
    int len = 0;
    for (int i = 1; i < length; i++)
    {
        if (T[0] > input[i])
            T[0] = i;
        else if (T[len] < input[i])
        {
            len++;
            T[len] = i;
            R[len] = T[len - 1];
        }
        else
        {
        }
    }
}
int main()
{
    vector<int> input{3, 4, -1, 5, 8, 2, 3, 12, 7, 9, 10};

    cout << longest_sequence(input, input.size()) << endl;
    return 0;
}