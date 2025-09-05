#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

const int META = 50;
mutex mtx;

void start_race() {

    cout << "Get ready...\n" << endl;
    for (size_t i = 1; i <= 3; i++)
    {
        lock_guard<mutex> lock(mtx);
        cout << "-" << i << "-\n" << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << "The race is on!\n" << endl;

}

void tortuga() {

    this_thread::sleep_for(chrono::milliseconds(100));
    for (int i = 0; i <= META; i++) {
        {
            lock_guard<mutex> lock(mtx);
            cout << "Turtle: " << i << endl;
            if (i == META)
            {
                cout << "\nTurtle: I made it to the finish line so late" << endl;
                cout << "Turtle has lost the race!\n" << endl;
            }
        }
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

void liebre() {
    // La liebre duerme al inicio
    this_thread::sleep_for(chrono::seconds(7));

    for (int i = 0; i <= META; i+=2) {
        {
            lock_guard<mutex> lock(mtx);
            cout << "Liebre: " << i << endl;
            if (i == 40)
            {
                cout << "Hare: I'm tired! I'm going to stretch my legs for a moment..." << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }
            
            if (i == META)
            {
                cout << "\nHare: He reached the finish line with ease!" << endl;
                cout << "Hare has won the race!, congratulations Mr. hare!\n" << endl;
            }
            
        }
        this_thread::sleep_for(chrono::milliseconds(50));
    }
}

int main() {
    cout << "\nStar the race between the turtle and the hare!\n" << endl;

    thread h0(start_race);
    thread h1(tortuga);
    thread h2(liebre);

    h0.join();
    h1.join();
    h2.join();

    cout << "\nRace over!\n" << endl;
    return 0;
}

// Hacer un programa concurrente en C++ que muestre la famosa carrera de la liebre
// y la tortuga. En un inicio la tortuga irá más rápido que la liebre, pero conforme vaya
// pasando el tiempo, la liebre deberá alcanzar a la tortuga hasta rebasarla.





