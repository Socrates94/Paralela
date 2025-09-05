#include <iostream>
#include <thread>
#include <cstdlib>  // rand, srand
#include <ctime>    // time

using namespace std;

int t, num, den, x;
int a, b, c, d;

void numerador() {
    num = t + c; // S2
}

void denominador() {
    den = t - d; // S3
}

int main() {
    // Inicializar semilla de aleatorios
    srand(time(0));

    // Generar valores aleatorios entre 1 y 20 (puedes ajustar el rango)
    a = rand() % 20 + 1;
    b = rand() % 20 + 1;
    c = rand() % 20 + 1;
    d = rand() % 20 + 1;

    cout << "Valores aleatorios:" << endl;
    cout << "a = " << a << ", b = " << b
         << ", c = " << c << ", d = " << d << endl;

    // S1: calcular t = a * b
    t = a * b;

    // Ejecutar S2 y S3 en paralelo
    thread t1(numerador);
    thread t2(denominador);

    t1.join();
    t2.join();

    // S4: división final
    if (den != 0) {
        x = num / den;
        cout << "\nResultados:" << endl;
        cout << "t = " << t << endl;
        cout << "num = " << num << endl;
        cout << "den = " << den << endl;
        cout << "x = " << x << endl;
    } else {
        cout << "\nError: denominador = 0, no se puede dividir." << endl;
    }

    return 0;
}
