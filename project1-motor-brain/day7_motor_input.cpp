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
        cout << name << " started!" << endl;
    }

    void stop() {
        isRunning = false;
        cout << name << " stopped!" << endl;
    }

    void setSpeed(int newSpeed) {
        if (newSpeed < 0 || newSpeed > 255) {
            cout << "Invalid speed! Enter between 0 and 255" << endl;
        } else {
            speed = newSpeed;
            cout << name << " speed set to: " << speed << endl;
        }
    }

    void getStatus() {
        cout << "\n--- Motor Status ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Speed: " << speed << endl;
        if (isRunning) {
            cout << "Status: RUNNING" << endl;
        } else {
            cout << "Status: STOPPED" << endl;
        }
        cout << "--------------------" << endl;
    }
};

int main() {
    Motor m1;
    m1.name = "BO Motor 1";
    m1.speed = 0;
    m1.isRunning = false;

    int choice;
    int inputSpeed;

    cout << "==============================" << endl;
    cout << "   MOTOR BRAIN CONTROL PANEL  " << endl;
    cout << "==============================" << endl;

    while (true) {
        cout << "\n1. Start Motor" << endl;
        cout << "2. Stop Motor" << endl;
        cout << "3. Set Speed" << endl;
        cout << "4. Get Status" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                m1.start();
                break;
            case 2:
                m1.stop();
                break;
            case 3:
                cout << "Enter speed (0-255): ";
                cin >> inputSpeed;
                m1.setSpeed(inputSpeed);
                break;
            case 4:
                m1.getStatus();
                break;
            case 5:
                cout << "Shutting down Motor Brain..." << endl;
                m1.stop();
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}