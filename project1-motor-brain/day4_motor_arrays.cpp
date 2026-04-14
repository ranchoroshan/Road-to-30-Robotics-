#include <iostream>
#include <string>
using namespace std;

class Motor {
    public:
    string name;
    int speed;
    bool isRunning;

    void start() {
        isRunning = true;
        cout << name << " started at speed " << speed << endl;
    }

    void stop() {
        isRunning = false;
        cout << name << " stopped." << endl;
    }
};

int main() {
    // Array of 4 motors
    Motor motors[4];

    // Set up each motor
    motors[0].name = "Front Left";
    motors[1].name = "Front Right";
    motors[2].name = "Back Left";
    motors[3].name = "Back Right";

    // Set speeds using a loop
    int speeds[4] = {100,150,200,255};

    for (int i=0; i<4; i++) {
        motors[i].speed = speeds[i];
        motors[i].isRunning = false;
    }

    // Start all motors
    cout << "\n--- Stopping all motor ---" << endl;
    for (int i=0; i<4; i++) {
        motors[i].stop();
    }

    return 0;
}