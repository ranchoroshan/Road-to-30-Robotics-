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
};

// Function using reference - changes original motor
void doubleSpeed(Motor &m) {
    m.speed = m.speed * 2;
    cout << "Speed doubled to: " << m.speed << endl;
}

// Function using pointer - changes original motor
void resetMotor(Motor *m) {
    m->speed = 0;
    m->isRunning = false;
    cout << m->name << " has been reset!" << endl;
}

int main() {
    Motor m1;
    m1.name = "BO Motor 1";
    m1.speed = 100;
    m1.isRunning = false;

    // Normal variable
    cout << "--- Normal Variable ---" << endl;
    cout << "Speed: " << m1.speed << endl;

    // Reference
    cout << "\n--- Reference ---" << endl;
    Motor &ref = m1;
    ref.speed = 150;
    cout << "Speed via reference: " << ref.speed << endl;
    cout << "Original speed also changed: " << m1.speed << endl;

    // Pointer
    cout << "\n--- Pointer ---" << endl;
    Motor *ptr = &m1;
    ptr->speed = 200;
    cout << "Speed via pointer: " << ptr->speed << endl;
    cout << "Original speed also changed: " << m1.speed << endl;

    // Functions with reference and pointer
    cout << "\n--- Functions ---" << endl;
    m1.start();
    doubleSpeed(m1);
    resetMotor(&m1);
    cout << "Final speed: " << m1.speed << endl;

    return 0;
}