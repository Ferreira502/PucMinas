/* 
   myarray.hpp   - v0.0. - 27 / 05 / 2025 
   Author: Gabriel Ferreira Pereira
*/ 
 
// ----------------------------------------------- definicoes globais 
 
#ifndef  _MYARRAY_HPP_ 
#define _MYARRAY_HPP_ 
 
// dependencias 
 
#include <iostream> 
using std::cin  ;  // para entrada 
using std::cout;  // para saida 
using std::endl;  // para mudar de linha 
 
#include <iomanip> 
using std::setw;   // para definir espacamento 
 
#include <string> 
using std::string;   // para cadeia de caracteres 
 
#include <fstream> 
using std::ofstream;   // para gravar arquivo 
using std::ifstream ;   // para ler       arquivo 
 
#define null nullptr

template <typename T>
class Array {
private:
    int length;
    T* data;

public:
    Array(int n = 0, T initial = T()) : length(n), data(null) {
        if (length > 0) {
            data = new T[length];
            for (int i = 0; i < length; i++) {
                data[i] = initial;
            }
        }
    }

    ~Array() {
        delete[] data;
    }

    void free() {
        delete[] data;
        data = null;
        length = 0;
    }

    int size() const {
        return length;
    }

    void push_back(const T& value) 
    {
        T* new_data = new T[length + 1];
        for (int i = 0; i < length; i++) {
            new_data[i] = data[i];
        }
        new_data[length] = value;
        delete[] data;
        data = new_data;
        length++;
    }

     void push_front(const T& value) 
     {
        T* new_data = new T[length + 1];
        new_data[0] = value;
        for (int i = 0; i < length; i++) {
            new_data[i + 1] = data[i];
        }
        delete[] data;
        data = new_data;
        length++;
    }

    void pop_back() 
    {
        if (length == 0) return;
        if (length == 1) {
            delete[] data;
            data = null;
            length = 0;
            return;
        }
        T* new_data = new T[length - 1];
        for (int i = 0; i < length - 1; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        length--;
    }

    void pop_front() 
    {
        if (length == 0) return;

        if (length == 1) 
        {
            delete[] data;
            data = nullptr;
            length = 0;
            return;
        }

        T* new_data = new T[length - 1];

        for (int i = 1; i < length; i++) 
        {
            new_data[i - 1] = data[i];
        }

        delete[] data;
        data = new_data;
        length--;
    }

    void push_mid(const T& value) 
    {
        T* new_data = new T[length + 1];
        int mid = length / 2;

        for (int i = 0; i < mid; i++) 
        {
            new_data[i] = data[i];
        }

        new_data[mid] = value;

        for (int i = mid; i < length; i++) 
        {
            new_data[i + 1] = data[i];
        }

        delete[] data;
        data = new_data;
        length++;
    }


    T& operator[](int index) 
    {
        return data[index];
    }

    const T& operator[](int index) const {
        return data[index];
    }

    void print() const {
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

#endif // ARRAY_HPP