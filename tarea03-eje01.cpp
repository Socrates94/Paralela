#include <iostream>
#include <thread>

using namespace std;

int j = 0, k = 0;

// funciones del proceso 1 de j
void S1(){
    j = j + 10;
    cout << "S1 ejecutado: j = " << j << endl;
}

void S3(thread *h1){
    h1->join(); // Espera a S1
    j = j + 10;
    cout << "S3 ejecutado: j = " << j << endl;
}

void S5(thread *h3){
    h3->join(); // Espera a S3
    j = j + 10;
    cout << "S5 ejecutado: j = " << j << endl;
}

// funciones del proceso 2 de k
void S2(){
    k = k + 100;
    cout << "S2 ejecutado: k = " << k << endl;
}

void S4(thread *h2){
    h2->join(); // Espera a S2
    k = k + 100;
    cout << "S4 ejecutado: k = " << k << endl;
}

void S6(thread *h4){
    h4->join(); // Espera a S4
    k = k + 100;
    cout << "S6 ejecutado: k = " << k << endl;
}

int main(){
    j = 0, k = 0;

    cout << "Ejecutar bloques concurrentes con hilos anidados\n";

        

    // proceso 1 de j
    thread *h1 = new thread(S1);
    thread *h3 = new thread(S3, h1);
    thread *h5 = new thread(S5, h3);

    // proceso 2 de k
    thread *h2 = new thread(S2);
    thread *h4 = new thread(S4, h2);
    thread *h6 = new thread(S6, h4);

    // Esperar a los hilos finales
    h5->join();
    h6->join();
    cout << "Resultado final: j = " << j << ", k = " << k << endl;
    cout << "Fin de la ejecucion\n";

    // Liberar memoria
    delete h1;
    delete h2;
    delete h3;
    delete h4;
    delete h5;
    delete h6;

    return 0;
}   