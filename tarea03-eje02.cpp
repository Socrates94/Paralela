#include <iostream>
#include <thread>
#include <cstdlib>  // rand, srand
#include <ctime>    // time

using namespace std;

int a[9];   // a[0] no se usa

void impar() {
    a[3] = a[1] + 4; // S1
    a[5] = a[3] + 4; // S2
    a[7] = a[5] + 4; // S3
}

void par() {
    a[4] = a[2] + 4; // S4
    a[6] = a[4] + 4; // S5
    a[8] = a[6] + 4; // S6
}

int main() {

    // Inicializar semilla de aleatorios
    srand(time(0));

    // Generar valores aleatorios para a[1] y a[2]
    a[1] = rand() % 50 + 1;  // número aleatorio entre 1 y 50
    a[2] = rand() % 50 + 1;

    cout << "Valores iniciales:" << endl;
    cout << "a[1] = " << a[1] << endl;
    cout << "a[2] = " << a[2] << endl;
    cout << endl;

    thread t1(impar);
    thread t2(par);

    t1.join();
    t2.join();

    for (int i = 1; i <= 8; i++) {
        cout << "a[" << i << "] = " << a[i] << endl;
    }

    return 0;

}


