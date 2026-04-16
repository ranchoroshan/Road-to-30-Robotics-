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

int main() {
    Motor m1;
    m1.name = "BO Motor 1";
    m1.speed = 0;
    m1.isRunning = false;

    // While loop - increase speed until max
    cout << "--- Increasing speed ---" << endl;
    m1.start();

    while (m1.speed < 255) {
        m1.speed += 50;
        if (m1.speed > 255) {
            m1.speed = 255;
        }
        cout << m1.name << " speed: " << m1.speed << endl;
    }

    cout << "Maximum speed reached!" << endl;
    m1.stop();

    // While loop - decrease speed until zero
    cout << "\n--- Decreasing speed ---" << endl;
    m1.start();

    while (m1.speed > 0) {
        m1.speed -= 50;
        if (m1.speed < 0) {
            m1.speed = 0;
        }
        cout << m1.name << " speed: " << m1.speed << endl;
    }

    cout << "Motor slowed to zero!" << endl;
    m1.stop();

    return 0;
}