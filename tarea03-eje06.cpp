#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
#include<cmath>

using namespace std;
vector<int> numeros(100);

void hilo_pares(){
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "\nNumeros pares: " << endl;
    for(int i = 0; i < numeros.size(); i++){
        if(numeros[i] % 2 == 0){
            cout << " " << numeros[i];
        }
    }
    cout << endl;
}

void hilo_impares(){
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "\nNumeros impares: " << endl;
    for(int i = 0; i < numeros.size(); i++){
        if(numeros[i] % 2 != 0){
            cout << " " << numeros[i];
        }
    }
    cout << endl;
}

void hilo_primos(){
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "\nNumeros primos: " << endl;
    for(int i = 0; i < numeros.size(); i++){
        bool es_primo = true;
        if(numeros[i] < 2) es_primo = false;
        for(int j = 2; j <= sqrt(numeros[i]); j++){
            if(numeros[i] % j == 0){
                es_primo = false;
                break;
            }
        }
        if(es_primo){
            cout << " " << numeros[i];
        }
    }
    cout << endl;
}

int main(){

    cout << "Arreglo con los primeros cien naturales" << endl;
    // llenar el arreglo con los primeros 100 numeros naturales
    for(int i = 0; i < 100; i++){
        numeros[i] = i;
        cout << " " << numeros[i];
    }
    cout << endl;

    thread t1(hilo_pares);
    thread t2(hilo_impares);
    thread t3(hilo_primos);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}


// Implemente un programa concurrente en C++ para lanzar tres hilos de manera que
// a cada hilo se le asignará una copia de un arreglo que contendrá los primeros cien
// números naturales. El primer hilo mostrará en pantalla sólo los números pares, el
// segundo hilo mostrará los números nones y el tercer hilo mostrará sólo los números
// primos.