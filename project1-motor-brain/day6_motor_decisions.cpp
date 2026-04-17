#include <iostream>
#include <string>
using namespace std;

class Motor {
public:
    string name;
    int speed;
    bool isRunning;
    string mode;

    void start() {
        isRunning = true;
        cout << name << " started!" << endl;
    }

    void stop() {
        isRunning = false;
        cout << name << " stopped!" << endl;
    }

    // If/else - check battery level
    void checkBattery(int battery) {
        if (battery > 75) {
            cout << "Battery GOOD - running at full speed" << endl;
            speed = 255;
        } else if (battery > 50) {
            cout << "Battery OK - running at medium speed" << endl;
            speed = 180;
        } else if (battery > 25) {
            cout << "Battery LOW - running at slow speed" << endl;
            speed = 100;
        } else {
            cout << "Battery CRITICAL - stopping motor!" << endl;
            stop();
        }
        cout << name << " speed set to: " << speed << endl;
    }

    // Switch statement - driving modes
    void setMode(int modeNumber) {
        switch (modeNumber) {
            case 1:
                mode = "FORWARD";
                speed = 200;
                cout << name << " mode: FORWARD at speed 200" << endl;
                break;
            case 2:
                mode = "BACKWARD";
                speed = 200;
                cout << name << " mode: BACKWARD at speed 200" << endl;
                break;
            case 3:
                mode = "SLOW";
                speed = 80;
                cout << name << " mode: SLOW at speed 80" << endl;
                break;
            case 4:
                mode = "STOP";
                speed = 0;
                stop();
                break;
            default:
                cout << "Unknown mode!" << endl;
                break;
        }
    }
};

int main() {
    Motor m1;
    m1.name = "BO Motor 1";
    m1.speed = 0;
    m1.isRunning = false;

    m1.start();

    // Test battery levels
    cout << "--- Battery Tests ---" << endl;
    m1.checkBattery(90);
    m1.checkBattery(60);
    m1.checkBattery(30);
    m1.checkBattery(10);

    // Test driving modes
    cout << "\n--- Driving Modes ---" << endl;
    m1.start();
    m1.setMode(1);
    m1.setMode(2);
    m1.setMode(3);
    m1.setMode(4);
    m1.setMode(9);

    return 0;
}