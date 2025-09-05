#include <iostream>
#include <thread>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int a, b, c;
double d, p, delta, r, num1, num2, den, x1, x2;

// Inicializar variables aleatorias
void setVariables() {
    srand(time(0));
    a = rand() % 10 + 1;
    b = rand() % 10 + 1;
    c = rand() % 10 + 1;
}

// S1 y S2: calcular d y p en paralelo
void calcularD() { d = b * b; }     // S1
void calcularP() { p = 4 * a * c; } // S2

// S3: delta depende de S1 y S2
void calcularDelta() { delta = d - p; } // S3

// S4: r depende de delta
void calcularR() { r = sqrt(delta); } // S4

// S5 y S6: numeradores
void calcularNum1() { num1 = -b + r; } // S5
void calcularNum2() { num2 = -b - r; } // S6

// S7: denominador
void calcularDen() { den = 2 * a; } // S7

// S8 y S9: resultados finales
void calcularX1() { x1 = num1 / den; } // S8
void calcularX2() { x2 = num2 / den; } // S9

int main() {
    setVariables();
    cout << "a=" << a << ", b=" << b << ", c=" << c << endl;

    // S1 y S2 en paralelo
    thread t1(calcularD), t2(calcularP);
    t1.join(); 
    t2.join();

    
    calcularDelta(); // S3
    if (delta < 0) {
        cout << "Discriminante negativo. Raices complejas." << endl;
        return 0;
    }


    calcularR(); // S4

    // S5, S6 y S7 en paralelo
    thread t3(calcularNum1), t4(calcularNum2), t5(calcularDen);
    t3.join(); 
    t4.join(); 
    t5.join();

    // S8 y S9 en paralelo
    thread t6(calcularX1), t7(calcularX2);
    t6.join(); 
    t7.join();

    cout << "d=" << d << ", p=" << p << ", delta=" << delta << ", r=" << r << endl;
    cout << "num1=" << num1 << ", num2=" << num2 << ", den=" << den << endl;
    cout << "x1=" << x1 << ", x2=" << x2 << endl;

    return 0;
}
