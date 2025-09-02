#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

int x = 100;

void P1(){
    this_thread::sleep_for(chrono::milliseconds(100));
    x = x + 10;
}

void P2(){
    if(x > 100)
        cout << x << endl;
    else
        cout << x - 50 << endl;
}

int main(){
    thread t1(P1);
    thread t2(P2);

    t1.join();
    t2.join();

    return 0;
}



// En el siguiente programa se espera que como resultado de su ejecución se imprima
// 110 ó 50, sin embargo, dicho programa no es correcto. Traduzca el programa a C++
// para comprobar dicha aseveración.
// program verbatim;
// var x: integer;
// process P1;
// begin
// x:=x+10;
// end;
// process P2;
// begin
// if x>100
// then write(x);
// else write(x-50);
// end;
// begin
// x:=100;
// cobegin
// P1;P2;
// coend
// end.