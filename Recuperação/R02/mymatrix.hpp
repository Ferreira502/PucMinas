/* 
   mymatrix.hpp  - v0.0. - 06 / 06 / 2025 
   Author: Gabriel Ferreira Pereira
*/ 
 
#ifndef  _MYMATRIX_H_
#define  _MYMATRIX_H_
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;
using std::ifstream;

template <typename T>
class Matrix 
{
private:
    T   optional;
    int rows;
    int columns;
    T** data;

public:
    // Construtor padrão
    Matrix()
    {
        rows = 0;
        columns = 0;
        data = nullptr;
    }

    // Construtor que aloca (rows x columns) e inicializa
    Matrix(int rows, int columns, T initial)
    {
        optional   = initial;
        this->rows    = rows;
        this->columns = columns;

        data = new T*[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new T[columns];
            // opcional: inicializar todos os elementos com o valor “initial”
            for (int j = 0; j < columns; j++)
                data[i][j] = initial;
        }
    }

    // Destrutor: desaloca linhas e depois o ponteiro “data”
    ~Matrix()
    {
        if (data != nullptr)
        {
            for (int i = 0; i < rows; i++)
                delete[] data[i];
            delete[] data;
            data = nullptr;
        }
    }

    // seta o valor (row, column)
    void set(int row, int column, T value)
    {
        if (row < 0 || row >= rows || column < 0 || column >= columns)
        {
            cout << "\nERROR: Invalid position.\n";
        }
        else
        {
            data[row][column] = value;
        }
    }

    // retorna o valor (row, column)
    T get(int row, int column) const
    {
        if (row < 0 || row >= rows || column < 0 || column >= columns)
        {
            cout << "\nERROR: Invalid position.\n";
            return optional;
        }
        else
        {
            return data[row][column];
        }
    }

    // imprime toda a matriz
    void print() const
    {
        cout << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    // lê do teclado linha a linha (não usado neste exemplo)
    void read()
    {
        cout << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << setw(2) << i << ", " << setw(2) << j << " : ";
                cin >> data[i][j];
            }
        }
        cout << endl;
    }

    // grava em arquivo: primeira linha = rows, segunda = columns; depois todos os elementos linha a linha
    void fprint(const string fileName) const
    {
        ofstream afile(fileName);
        afile << rows << endl;
        afile << columns << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                afile << data[i][j] << endl;
            }
        }
        afile.close();
    }

    // lê de arquivo no mesmo formato: rows, columns e depois valores
    void fread(const string fileName)
    {
        ifstream afile(fileName);
        int m = 0, n = 0;
        afile >> m;
        afile >> n;
        if (m <= 0 || n <= 0)
        {
            cout << "\nERROR: Invalid dimensions for matrix.\n" << endl;
            return;
        }

        // se já houver memória alocada, libera antes de alocar nova
        if (data != nullptr)
        {
            for (int i = 0; i < rows; i++)
                delete[] data[i];
            delete[] data;
        }

        rows = m;
        columns = n;
        data = new T*[rows];
        for (int i = 0; i < rows; i++)
            data[i] = new T[columns];

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                afile >> data[i][j];
            }
        }
        afile.close();
    }

    // sobrescreve operador = (copia conteúdo de other para this)
    Matrix& operator=(const Matrix<T>& other)
    {
        if (this == &other) return *this; // autoatribuição

        // libera memória antiga, se houver
        if (data != nullptr)
        {
            for (int i = 0; i < rows; i++)
                delete[] data[i];
            delete[] data;
        }

        rows = other.rows;
        columns = other.columns;
        optional = other.optional;

        if (rows > 0 && columns > 0)
        {
            data = new T*[rows];
            for (int i = 0; i < rows; i++)
            {
                data[i] = new T[columns];
                for (int j = 0; j < columns; j++)
                    data[i][j] = other.data[i][j];
            }
        }
        else
        {
            data = nullptr;
        }

        return *this;
    }

    // verifica se a matriz é toda zero (não usado aqui)
    bool isZeros() const
    {
        if (rows <= 0 || columns <= 0) return false;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                if (data[i][j] != 0)
                    return false;
        return true;
    }

    // operador != (compara se existe ao menos um elemento diferente)
    bool operator!=(const Matrix<T>& other) const
    {
        if (rows != other.rows || columns != other.columns)
        {
            return true; // diferem em dimensões
        }
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                if (data[i][j] != other.data[i][j])
                    return true;
        return false; // todos iguais
    }

    // operador - (diferença posição a posição)
    Matrix operator-(const Matrix<T>& other) const
    {
        Matrix<T> result(1, 1, optional);
        if (rows != other.rows || columns != other.columns)
        {
            cout << "\nERROR: Missing data.\n" << endl;
            return result;
        }

        result.rows = rows;
        result.columns = columns;
        // alocar matriz de saída
        if (result.data != nullptr)
        {
            for (int i = 0; i < result.rows; i++)
                delete[] result.data[i];
            delete[] result.data;
        }
        result.data = new T*[rows];
        for (int i = 0; i < rows; i++)
            result.data[i] = new T[columns];

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                result.data[i][j] = data[i][j] - other.data[i][j];

        return result;
    }

    // operador * (multiplicação de matrizes)
    Matrix operator*(const Matrix<T>& other) const
    {
        Matrix<T> result(1, 1, optional);

        if (rows <= 0 || columns <= 0 || other.rows <= 0 || other.columns <= 0 || columns != other.rows)
        {
            cout << "\nERROR: Invalid data for multiplication.\n";
            return result;
        }

        result.rows = rows;
        result.columns = other.columns;
        // alocar result
        if (result.data != nullptr)
        {
            for (int i = 0; i < result.rows; i++)
                delete[] result.data[i];
            delete[] result.data;
        }
        result.data = new T*[rows];
        for (int i = 0; i < rows; i++)
            result.data[i] = new T[other.columns];

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < other.columns; j++)
            {
                T sum = 0;
                for (int k = 0; k < columns; k++)
                    sum += data[i][k] * other.data[k][j];
                result.data[i][j] = sum;
            }
        }

        return result;
    }

    // método scalar: multiplica TODOS os elementos por k e retorna nova matriz
    Matrix<T> scalar(T k) const
    {
        Matrix<T> result(rows, columns, optional);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                result.set(i, j, data[i][j] * k);
            }
        }
        return result;
    }

    const int getRows() const { return rows; }
    const int getColumns() const { return columns; }

    bool identidade() const
   {
    if (rows != columns)
    {
        return false;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i == j && data[i][j] != 1)
                return false;
            if (i != j && data[i][j] != 0)
                return false;
        }
    }

    return true;
   }

   bool operator== (const Matrix<T> &other) const
{
    if (rows != other.rows || columns != other.columns)
        return false;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (data[i][j] != other.data[i][j])
                return false;
        }
    }

    return true;
}

Matrix<T> add(const Matrix<T> &other)
{
    Matrix<T> result(rows, columns, optional);

    if (rows != other.rows || columns != other.columns)
    {
        cout << "\nERRO: As matrizes devem ter as mesmas dimensoes" << endl;
    }
    else
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                result.set(i, j, this->get(i, j) + other.get(i, j));
            }
        }
    }

    return result;
}

void addRows(int targetRow, int sourceRow, T multiplier)
{
    if (targetRow < 0 || targetRow >= rows || sourceRow < 0 || sourceRow >= rows)
    {
        cout << "\nERROR: valores da linha invalida\n";
    }
    else
    {
        for (int j = 0; j < columns; j++)
        {
            data[targetRow][j] = data[targetRow][j] + multiplier * data[sourceRow][j];
        }
    }
}

void subtractRows(int targetRow, int sourceRow, T multiplier)
{
    if (targetRow < 0 || targetRow >= rows || sourceRow < 0 || sourceRow >= rows)
    {
        cout << "\nERROR: valores da linha invalida\n";
    }
    else
    {
        for (int j = 0; j < columns; j++)
        {
            data[targetRow][j] = data[targetRow][j] - multiplier * data[sourceRow][j];
        }
    }
}

int searchRows(T value)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (data[i][j] == value)
            {
                return i;
            }
        }
    }
    return -1;
}

int searchColumns(T value)
{
    for (int j = 0; j < columns; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            if (data[i][j] == value)
            {
                return j;
            }
        }
    }
    return -1;
}

void transpose()
{
    if (rows <= 0 || columns <= 0)
    {
        cout << "\nERRO: As matrizes devem ter as mesmas dimensoes\n";
    }
    else
    {
        Matrix<T> temp(columns, rows, optional);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                temp.set(j, i, data[i][j]);
            }
        }

        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;

        rows = temp.getRows();
        columns = temp.getColumns();

        data = new T*[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new T[columns];
            for (int j = 0; j < columns; j++)
            {
                data[i][j] = temp.get(i, j);
            }
        }
    }
}

bool hasSequentialValuesByRow()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns - 1; j++)
        {
            if (data[i][j] + 1 != data[i][j + 1])
            {
                return false;
            }
        }
    }
    return true;
}

void buildCustomPatternE2()
{
    int value = 1;

    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = 0; j < columns; j++)
        {
            data[i][j] = value;
            value++;
        }
    }
}

};

#endif