#include <iostream>
#include <cassert>
#include <string>
#include "linked_list.h"

using namespace std;

int main() {

    utec::linked_list_t ll;

    // Probar el metodo push_front;
    for(int i = 0; i < 10; ++i) {
        ll.push_front(i);
    }



    string result;
    for (int i = 0; i < 10; ++i) {
        result += to_string(ll.item(i)) + " ";
    }
    cout << result << endl;
    ll.insert(2,14);
    string result2;
    for (int i = 0; i < 11; ++i) {
        result2 += to_string(ll.item(i)) + " ";
    }
    cout << result2 << endl;
    string result3;
    ll.erase(3);
    for (int i = 0; i < 10; ++i) {
        result3 += to_string(ll.item(i)) + " ";
    }
    cout << ll.size() << endl;
    cout << result3 << endl;
    utec::linked_list_t prueba(ll);
    string result4;
    for (int i = 0; i < 10; ++i) {
        result4 += to_string(prueba.item(i)) + " ";
    }
    cout << prueba.size() << endl;
    cout << result4 << endl;
/*
    // pop_front
    // Probar el metodo push_front;
    for(int i = 0; i < 5; ++i) {
        ll.pop_front();
    }
    // Verifico el tamano
    assert(ll.size() == 5);

    // Probar el metodo push_front;
    for(int i = 0; i < 5; ++i) {
        ll.pop_front();
    }
    // Verifico el tamano
    assert(ll.size() == 0);



    std::cout << "Ejecucion exitosa!!" << std::endl;
    */
    return 0;
}
