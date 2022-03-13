/* 
BowlingScorekeeping.cpp : A complete record of a 10 frame bowling game can be given as an array of the number of pins knocked down by each ball in sequence from the beginning to the end of the game.
                          Create a function whose argument is such an array. The function should return the final score.
*/

#include <iostream>
#include <vector>

using namespace std;

int bowling(vector<int> pins)
{
    int x = 0, sum = 0;
    for (int i = 0; i < pins.size(); i++)
    {
        if (i >= (pins.size() - 3) && (pins[i] == 10 || (pins[i] + pins[i + 1]) == 10))
        {
            sum += pins[i];
        }
        else if (pins[i] == 10)
            sum += pins[i] + pins[i + 1] + pins[i + 2];
        else if ((pins[i] + pins[i + 1]) == 10)
        {
            sum += 10 + pins[i + 2];
            i++;
        }
        else
            sum += pins[i];
    }

    return sum;
}

int main()
{
    int x;
    vector<int> pins;
    while (cin >> x)
    {
        if (x == -1)
            break;
        pins.push_back(x);
    }
    cout << bowling(pins);
}


