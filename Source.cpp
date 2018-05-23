#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

#define PI 3.14156265
using namespace std;

class Player
{
public:
    int x;
    int y;
    int nextCheckpointX;
    int nextCheckpointY;
    int nextCheckpointDist;
    int nextCheckpointAngle;
    int opponentX;
    int opponentY;
    int beforeX;
    int beforeY;
    bool isAfterPeak = false;
    bool hasBoost = true;
    int destinationX;
    int destinationY;
    int force;
    string thrust;

    void move()
    {
        beforeX = x;
        beforeY = y;

        cout << destinationX << " " << destinationY << " " << thrust << endl;
    }

    void desisionNextMove()
    {
        destinationX = nextCheckpointX;
        destinationY = nextCheckpointY;
        force = 100;

        double rad = ((nextCheckpointAngle * PI) / 180);

        //normal moving
        if (nextCheckpointAngle < 90)
        {
            double perfectForce = nextCheckpointDist * cos(rad) * 0.15;
            if (perfectForce > 100)
            {
                force = 100;
            }
            else if (perfectForce < 0)
            {
                force = 0;
            }
            else
            {
                force = (int)perfectForce;
            }
        }
        else
        {
            force = 0;
        }
        thrust = to_string(force);
        if (hasBoost && nextCheckpointDist > 3000 && nextCheckpointAngle == 0)
        {
            thrust = "BOOST";
            hasBoost = false;
        }
        //The goal is to make kinda method for shield and future prediction
    }
};
int main()
{
    while(1){
    Player valialble;
    cin >> valialble.x >> valialble.y >> valialble.nextCheckpointX >> valialble.nextCheckpointY >> valialble.nextCheckpointDist >> valialble.nextCheckpointAngle;
    cin.ignore();
    cin >> valialble.opponentX >> valialble.opponentY;
    cin.ignore();
    valialble.desisionNextMove();
    valialble.move();
    }
}


