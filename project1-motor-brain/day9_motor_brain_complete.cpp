#include <iostream>
#include <string>
using namespace std;

class Motor {
public:
    string name;
    int speed;
    bool isRunning;
    string direction;
    int batteryLevel;

    // Constructor
    Motor(string n, int bat) {
        name = n;
        speed = 0;
        isRunning = false;
        direction = "FORWARD";
        batteryLevel = bat;
        cout << name << " initialized!" << endl;
    }

    void start() {
        if (batteryLevel <= 0) {
            cout << "Cannot start - battery empty!" << endl;
            return;
        }
        isRunning = true;
        cout << name << " started!" << endl;
    }

    void stop() {
        isRunning = false;
        speed = 0;
        cout << name << " stopped!" << endl;
    }

    void setSpeed(int newSpeed) {
        if (newSpeed < 0 || newSpeed > 255) {
            cout << "Invalid speed! Enter 0-255" << endl;
            return;
        }
        speed = newSpeed;
        batteryLevel -= 5;
        cout << name << " speed: " << speed << endl;
    }

    void setDirection(int choice) {
        switch (choice) {
            case 1:
                direction = "FORWARD";
                break;
            case 2:
                direction = "BACKWARD";
                break;
            case 3:
                direction = "LEFT";
                break;
            case 4:
                direction = "RIGHT";
                break;
            default:
                cout << "Invalid direction!" << endl;
                return;
        }
        cout << name << " direction: " << direction << endl;
    }

    void checkBattery() {
        if (batteryLevel > 75) {
            cout << "Battery: GOOD (" << batteryLevel << "%)" << endl;
        } else if (batteryLevel > 50) {
            cout << "Battery: OK (" << batteryLevel << "%)" << endl;
        } else if (batteryLevel > 25) {
            cout << "Battery: LOW (" << batteryLevel << "%)" << endl;
        } else {
            cout << "Battery: CRITICAL (" << batteryLevel << "%)" << endl;
            if (isRunning) {
                cout << "Auto stopping motor!" << endl;
                stop();
            }
        }
    }

    void rampUp() {
        cout << "Ramping up..." << endl;
        while (speed < 255) {
            speed += 50;
            if (speed > 255) speed = 255;
            cout << "Speed: " << speed << endl;
        }
    }

    void rampDown() {
        cout << "Ramping down..." << endl;
        while (speed > 0) {
            speed -= 50;
            if (speed < 0) speed = 0;
            cout << "Speed: " << speed << endl;
        }
    }

    void getStatus() {
        cout << "\n====== Motor Status ======" << endl;
        cout << "Name:      " << name << endl;
        cout << "Speed:     " << speed << endl;
        cout << "Direction: " << direction << endl;
        cout << "Running:   " << (isRunning ? "YES" : "NO") << endl;
        checkBattery();
        cout << "==========================" << endl;
    }
};

// Function using pointer to reset motor
void emergencyStop(Motor *m) {
    m->speed = 0;
    m->isRunning = false;
    cout << "EMERGENCY STOP: " << m->name << endl;
}

int main() {
    // Array of 2 motors with constructor
    Motor motors[2] = {
        Motor("BO Motor 1", 100),
        Motor("N20 Gear Motor", 80)
    };

    int choice;
    int motorChoice;
    int speedInput;
    int dirChoice;

    cout << "\n==============================" << endl;
    cout << "   MOTOR BRAIN v1.0 - ROSHAN  " << endl;
    cout << "==============================" << endl;

    while (true) {
        cout << "\nSelect Motor:" << endl;
        cout << "1. " << motors[0].name << endl;
        cout << "2. " << motors[1].name << endl;
        cout << "3. Emergency Stop All" << endl;
        cout << "4. Exit" << endl;
        cout << "Choice: ";
        cin >> motorChoice;

        if (motorChoice == 4) {
            cout << "Shutting down Motor Brain..." << endl;
            emergencyStop(&motors[0]);
            emergencyStop(&motors[1]);
            break;
        }

        if (motorChoice == 3) {
            emergencyStop(&motors[0]);
            emergencyStop(&motors[1]);
            continue;
        }

        if (motorChoice < 1 || motorChoice > 2) {
            cout << "Invalid motor choice!" << endl;
            continue;
        }

        Motor &selected = motors[motorChoice - 1];

        cout << "\n1. Start" << endl;
        cout << "2. Stop" << endl;
        cout << "3. Set Speed" << endl;
        cout << "4. Set Direction" << endl;
        cout << "5. Ramp Up" << endl;
        cout << "6. Ramp Down" << endl;
        cout << "7. Get Status" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                selected.start();
                break;
            case 2:
                selected.stop();
                break;
            case 3:
                cout << "Enter speed (0-255): ";
                cin >> speedInput;
                selected.setSpeed(speedInput);
                break;
            case 4:
                cout << "1.Forward 2.Backward 3.Left 4.Right: ";
                cin >> dirChoice;
                selected.setDirection(dirChoice);
                break;
            case 5:
                selected.rampUp();
                break;
            case 6:
                selected.rampDown();
                break;
            case 7:
                selected.getStatus();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}