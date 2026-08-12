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
       for (int i = 0; i < length; i++) 
       {
           new_data[i + 1] = data[i];
       }
       delete[] data;
       data = new_data;
       length++;
    }

    void pop_back() 
    {
        if (length == 0) return;
        if (length == 1) 
        {
            delete[] data;
            data = null;
            length = 0;
            return;
        }
        T* new_data = new T[length - 1];
        for (int i = 0; i < length - 1; i++) 
        {
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

    void pop_mid() 
    {
        if (length == 0) return;

        if (length == 1) 
        {
            delete[] data;
            data = nullptr;
            length = 0;
            return;
        }

        int mid = length / 2;
        T* new_data = new T[length - 1];

        for (int i = 0; i < mid; i++) 
        {
            new_data[i] = data[i];
        }

        for (int i = mid + 1; i < length; i++) 
        {
            new_data[i - 1] = data[i];
        }

        delete[] data;
        data = new_data;
        length--;
    }


};

    typedef struct s_intArray 
    {
        int length;
        int* data;
    } intArray;

    typedef intArray* ref_intArray;

    ref_intArray read_intArray() 
    {
    
        ref_intArray arr = new intArray;

        cout << "Digite o tamanho do arranjo: ";
    
        cin >> arr->length;
    
        arr->data = new int[arr->length];

        cout << "Digite os " << arr->length << " valores:\n";
    
        for (int i = 0; i < arr->length; i++) 
        {
            cout << i << ": ";
            cin >> arr->data[i];
    
        }

    
        return arr;
    }

    void print_intArray(ref_intArray arr) 
    {
        cout << "[ ";
        for (int i = 0; i < arr->length; i++) 
        {
            cout << arr->data[i] << " ";
        }
        cout << "]\n";
    }

    int intArray_cmp(ref_intArray p, ref_intArray q) 
    {
        if (p == nullptr && q == nullptr) return 0;
        if (p == nullptr) return -1;
        if (q == nullptr) return 1;

        int minLength;
        if (p->length < q->length) 
        {
            minLength = p->length;
        } else 
        {
            minLength = q->length;
        }

        for (int i = 0; i < minLength; i++) 
        {
            int diff = p->data[i] - q->data[i];
            if (diff != 0) return diff;
        }

        if (p->length < q->length) return -1;
        if (p->length > q->length) return 1;
        return 0;
    }

    ref_intArray intArray_cat(ref_intArray p, ref_intArray q) 
    {
        if (p == nullptr && q == nullptr) return nullptr;

        ref_intArray result = new intArray;
        result->length = 0;
        result->data = nullptr;

        if (p != nullptr) 
        {
            result->length += p->length;
        }

        if (q != nullptr) 
        {
            result->length += q->length;
        }

        result->data = new int[result->length];

        int index = 0;

        if (p != nullptr) 
        {
            for (int i = 0; i < p->length; i++) 
            {
                result->data[index++] = p->data[i];
            }
        }

        if (q != nullptr) 
        {
            for (int i = 0; i < q->length; i++) 
            {
                result->data[index++] = q->data[i];
            }
        }

        return result;

    }

    ref_intArray intArray_seek(ref_intArray a, int x) 
    {
        if (a == nullptr || a->data == nullptr || a->length <= 0)
            return nullptr;

        for (int i = 0; i < a->length; i++) 
        {
            if (a->data[i] == x) 
            {
                ref_intArray result = new intArray;
                result->length = 1;
                result->data = new int[1];
                result->data[0] = x;
                return result;
        }
    }

    // Não encontrou
    return nullptr;
    }


    ref_intArray intArray_sub(ref_intArray a, int start, int size) 
    {
        if (a == nullptr || a->data == nullptr || a->length <= 0)
            return nullptr;

        if (start < 0 || size <= 0 || start + size > a->length)
            return nullptr;

        ref_intArray result = new intArray;
        result->length = size;
        result->data = new int[size];

        for (int i = 0; i < size; i++) 
        {
            result->data[i] = a->data[start + i];
        }

        return result;
    }

    ref_intArray intArray_merge(ref_intArray p, ref_intArray q) 
    {
        if (p == nullptr || p->data == nullptr || p->length < 0) return nullptr;
        if (q == nullptr || q->data == nullptr || q->length < 0) return nullptr;

        int totalLength = p->length + q->length;

        ref_intArray result = new intArray;
        result->length = totalLength;
        result->data = new int[totalLength];

        int index = 0;
        int i = 0, j = 0;

        while (i < p->length || j < q->length) 
        {
            if (i < p->length) 
            {
                result->data[index++] = p->data[i++];
            }
            if (j < q->length) 
            {
                result->data[index++] = q->data[j++];
            }
        }

        return result;
    }

    ref_intArray intArray_mergeDown(ref_intArray p, ref_intArray q) 
    {
        if (p == nullptr || p->data == nullptr || p->length < 0) return nullptr;
        if (q == nullptr || q->data == nullptr || q->length < 0) return nullptr;

        int totalLength = p->length + q->length;
        ref_intArray result = new intArray;
        result->length = totalLength;
        result->data = new int[totalLength];

        int index = 0;

        for (int i = 0; i < p->length; i++) 
        {
            result->data[index++] = p->data[i];
        }

        for (int i = 0; i < q->length; i++) 
        {
            result->data[index++] = q->data[i];
        }

        for (int i = 0; i < result->length - 1; i++) 
        {
            for (int j = 0; j < result->length - i - 1; j++) 
            {
                if (result->data[j] < result->data[j + 1]) 
                {
                    int temp = result->data[j];
                    result->data[j] = result->data[j + 1];
                    result->data[j + 1] = temp;
                }
            }
        }

        return result;
    }

#endif