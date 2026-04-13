#include <iostream>
#include <string>
using namespace std;

class Motor {
    public:
    string name;
    int speed;
    bool isRunning;
    string direction;

    void start() {
        isRunning = true;
        cout << name << " started!" << endl;
        }

    void stop() {
        isRunning = false;
        cout << name << " stopped!" << endl;
        }
    
    void setSpeed(int newSpeed) {
        speed = newSpeed;
        cout << name << " speed: " << speed << endl;
    }

    void getStatus() {
        cout << "Name: " << name << endl;
        cout << "Speed: " << speed << endl;
        cout << "Running: " << isRunning << endl;
    }
};

int main() {
    Motor m1;
    m1.name = "BO Motor 1" ;
    m1.speed = 0;
    m1.isRunning = false;
    m1.direction = "forward" ;

    m1.start();
    m1.setSpeed(150);
    m1.getStatus();
    m1.stop();
    m1.getStatus();

    return 0;
}