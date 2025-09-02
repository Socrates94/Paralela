#include<iostream>
#include<thread>
#include<mutex>


using namespace std;
int total_hojas = 0;
mutex mtx;

void persona01(){
    cout << "Persona 01 apilando hojas..." << endl;
    for(int i = 1; i <=50; i++){
        lock_guard<mutex> lock(mtx);
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "Hoja " << i << " apilada por Persona 01." << endl;
        total_hojas++;
    }
}

void persona02(){
        this_thread::sleep_for(chrono::milliseconds(50));
    cout << "Persona 02 apilando hojas..." << endl;
    for(int i = 1; i <=100; i++){
        lock_guard<mutex> lock(mtx);
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "Hoja " << i << " apilada por Persona 02." << endl;
        total_hojas++;
    }
}

void persona03(){
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "Persona 03 apilando hojas..." << endl;
    for(int i = 1; i <=200; i++){
        lock_guard<mutex> lock(mtx);
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "Hoja " << i << " apilada por Persona 03." << endl;
        total_hojas++;
    }
}

void contar_hojas(thread *h1, thread *h2, thread *h3){

    if(h1 != nullptr){ 
        h1->join();
    }
    if(h2 != nullptr){ 
        h2->join();
    }
    if(h3 != nullptr){ 
        h3->join();
    }
    cout << "\nContando hojas apiladas..." << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "Total de hojas apiladas: " << total_hojas <<"\n"<< endl;

}

int main(){
    thread t1(persona01);
    thread t2(persona02);
    thread t3(persona03);
    thread t4(contar_hojas, &t1, &t2, &t3);

    t4.join();

    return 0;
}

// Implemente en C++ la solución concurrente del siguiente problema: En una fábrica
// de papel bond, 3 personas son encargadas de colocar c/u, una hoja de papel en su
// respectiva caja. Una cuarta persona está esperando a que las personas terminen de
// colocar sus hojas en las cajas para entonces hacer un conteo total de las hojas. La
// persona 1 colocará 50 hojas en su caja (una por una), la persona 2 colocará 100 hojas
// en su caja (una por una) y la persona 3 colocará 200 hojas en su caja (una por una).