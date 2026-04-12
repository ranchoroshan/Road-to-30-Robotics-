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
        cout << name << "started at speed" << speed << endl;
        }

    void stop() {
        isRunning = false;
        cout << name << "stopped." << endl;
        }

    void runForSeconds(int seconds) {
        start();
        for (int i=1; i <= seconds; i++){
            cout << "Running... second" << i << "at speed " << speed << endl;
        }
        stop();
    }
};

int main() {
    Motor m1;
    m1.name = "BO Motor 1";
    m1.speed = 150;
    m1.runForSeconds(5);

    cout << "\n--- Increasing speed test ---" << endl;

    Motor m2;
    m2.name = "N20 Gear Motor";
    m2.speed = 0;
    m2.start();

    for (int speed = 0; speed <= 255; speed += 50) {
        m2.speed = speed;
        cout << "  Speed set to: " << speed << endl;
    }
    m2.stop();

    return 0;
}