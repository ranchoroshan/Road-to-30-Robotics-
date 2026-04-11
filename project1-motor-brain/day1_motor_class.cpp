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
};
int main() {
    Motor m1;
    m1.name = "BO Motor 1";
    m1.speed = 150;
    m1.start();
    m1.stop();
    return 0;
}