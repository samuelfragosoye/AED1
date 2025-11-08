/*
mymatrix.hpp - v0.0. - 01 / 11 / 2025
Author: _________________________
*/
// ----------------------------------------------- definicoes globais
#ifndef _MYMATRIX_H_
#define _MYMATRIX_H_
// dependencias
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdexcept> // para std::invalid_argument, std::out_of_range
#include <cstdlib>   // para rand() e srand()
#include <ctime>     // para time()

using std::cin;    // para entrada
using std::cout;   // para saida
using std::endl;   // para mudar de linha
using std::setw;   // para definir espacamento
using std::string; // para cadeia de caracteres
using std::ofstream; // para gravar arquivo
using std::ifstream; // para ler arquivo

template <typename T>
class Matrix
{
private: // area reservada
    T optional;
    int rows;
    int columns;
    T **data;

    // Metodo utilitario para limpar a memoria
    void clearData()
    {
        if (data != nullptr)
        {
            for (int x = 0; x < rows; x = x + 1)
            {
                delete[] data[x];
            } // end for
            delete[] data;
            data = nullptr;
        } // end if
    }

public: // area aberta
    Matrix()
    {
        // definir valores iniciais
        this->rows = 0;
        this->columns = 0;
        // sem reservar area
        data = nullptr;
    } // end constructor

    Matrix(int rows, int columns, T initial)
    {
        // definir valores iniciais
        this->optional = initial;
        this->rows = rows;
        this->columns = columns;
        // reservar area
        data = new T *[rows];
        if (data != nullptr)
        {
            for (int x = 0; x < rows; x = x + 1)
            {
                data[x] = new T[columns];
                if (data[x] == nullptr)
                {
                    // Se falhar a alocacao de uma linha, limpa tudo
                    for (int k = 0; k < x; k = k + 1)
                    {
                        delete[] data[k];
                    }
                    delete[] data;
                    data = nullptr;
                    this->rows = 0;
                    this->columns = 0;
                    throw std::bad_alloc(); // Lanca excecao
                }
                else
                {
                    // Inicializa a linha com o valor padrao
                    for (int y = 0; y < columns; y = y + 1)
                    {
                        data[x][y] = initial;
                    }
                }
            } // end for
        } // end if
    } // end constructor

    ~Matrix()
    {
        clearData();
    } // end destructor ( )

    void set(int row, int column, T value)
    {
        if (row < 0 || row >= rows ||
            column < 0 || column >= columns)
        {
            cout << "\nERROR: Invalid position.\n";
        }
        else
        {
            data[row][column] = value;
        } // end if
    } // end set ( )

    T get(int row, int column)
    {
        T value = optional;
        if (row < 0 || row >= rows ||
            column < 0 || column >= columns)
        {
            cout << "\nERROR: Invalid position.\n";
        }
        else
        {
            value = data[row][column];
        } // end if
        return (value);
    } // end get ( )

    void print()
    {
        cout << endl;
        for (int x = 0; x < rows; x = x + 1)
        {
            for (int y = 0; y < columns; y = y + 1)
            {
                cout << data[x][y] << "\t";
            } // end for
            cout << endl;
        } // end for
        cout << endl;
    } // end print ( )

    void read()
    {
        cout << endl;
        for (int x = 0; x < rows; x = x + 1)
        {
            for (int y = 0; y < columns; y = y + 1)
            {
                cout << setw(2) << x << ", "
                     << setw(2) << y << " : ";
                cin >> data[x][y];
            } // end for
        } // end for
        cout << endl;
    } // end read ( )

    void fprint(string fileName)
    {
        ofstream afile;
        afile.open(fileName);
        afile << rows << endl;
        afile << columns << endl;
        for (int x = 0; x < rows; x = x + 1)
        {
            for (int y = 0; y < columns; y = y + 1)
            {
                afile << data[x][y] << endl;
            } // end for
        } // end for
        afile.close();
    } // end fprint ( )

    void fread(string fileName)
    {
        ifstream afile;
        int m = 0;
        int n = 0;
        afile.open(fileName);
        afile >> m;
        afile >> n;
        if (m <= 0 || n <= 0)
        {
            cout << "\nERROR: Invalid dimensions for matrix.\n"
                 << endl;
        }
        else
        {
            // Limpar dados antigos
            clearData();
            // guardar a quantidade de dados
            rows = m;
            columns = n;
            // reservar area
            data = new T *[rows];
            for (int x = 0; x < rows; x = x + 1)
            {
                data[x] = new T[columns];
            } // end for
              // ler dados
            for (int x = 0; x < rows; x = x + 1)
            {
                for (int y = 0; y < columns; y = y + 1)
                {
                    afile >> data[x][y];
                } // end for
            } // end for
        } // end if
        afile.close();
    } // end fread ( )

    // (1214) operator= - CORRIGIDO
    Matrix &operator=(const Matrix<T> &other)
    {
        if (this == &other) // Protecao contra auto-atribuicao
        {
            return *this;
        }

        if (other.rows == 0 || other.columns == 0)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            // Limpa dados antigos
            this->clearData();
            
            this->rows = other.rows;
            this->columns = other.columns;
            this->optional = other.optional;

            // Aloca nova memoria
            this->data = new T *[rows];
            for (int x = 0; x < rows; x = x + 1)
            {
                this->data[x] = new T[columns];
            } // end for

            // Copia os dados
            for (int x = 0; x < this->rows; x = x + 1)
            {
                for (int y = 0; y < this->columns; y = y + 1)
                {
                    data[x][y] = other.data[x][y];
                } // end for
            } // end for
        } // end if
        return (*this);
    } // end operator= ( )

    bool isZeros()
    {
        bool result = false;
        int x = 0;
        int y = 0;
        if (rows > 0 && columns > 0)
        {
            result = true;
            while (x < rows && result)
            {
                y = 0;
                while (y < columns && result)
                {
                    result = result && (data[x][y] == 0);
                    y = y + 1;
                } // end while
                x = x + 1;
            } // end while
        } // end if
        return (result);
    } // end isZeros ( )

    bool operator!=(const Matrix<T> &other)
    {
        bool result = false;
        int x = 0;
        int y = 0;
        if (other.rows == 0 || rows != other.rows ||
            other.columns == 0 || columns != other.columns)
        {
            // Se as dimensoes sao diferentes, sao diferentes
            result = true; 
        }
        else
        {
            x = 0;
            while (x < rows && !result)
            {
                y = 0;
                while (y < columns && !result)
                {
                    result = (data[x][y] != other.data[x][y]);
                    y = y + 1;
                } // end while
                x = x + 1;
            } // end while
        } // end if
        return (result);
    } // end operator!= ( )

    // (1208) operator- - CORRIGIDO (sem static e sem memory leak)
    Matrix operator-(const Matrix<T> &other)
    {
        if (other.rows == 0 || rows != other.rows ||
            other.columns == 0 || columns != other.columns)
        {
            cout << "\nERROR: Missing or incompatible data.\n"
                 << endl;
            return Matrix(0, 0, 0); // Retorna matriz vazia
        }

        Matrix<T> result(rows, columns, 0); // Cria nova matriz

        for (int x = 0; x < result.rows; x = x + 1)
        {
            for (int y = 0; y < result.columns; y = y + 1)
            {
                result.data[x][y] = data[x][y] - other.data[x][y];
            } // end for
        } // end for
        
        return (result); // Retorna por valor
    } // end operator- ( )


    // (1209) operator* - CORRIGIDO (sem static e sem memory leak)
    Matrix operator*(const Matrix<T> &other)
    {
        if (rows <= 0 || columns == 0 ||
            other.rows <= 0 || other.columns == 0 ||
            columns != other.rows)
        {
            cout << endl
                 << "ERROR: Invalid data for multiplication." << endl;
            return Matrix(0, 0, 0); // Retorna matriz vazia
        }

        Matrix<T> result(rows, other.columns, 0); // Matriz resultado
        T sum;

        for (int x = 0; x < result.rows; x = x + 1)
        {
            for (int y = 0; y < result.columns; y = y + 1)
            {
                sum = 0;
                for (int z = 0; z < columns; z = z + 1)
                {
                    sum = sum + data[x][z] * other.data[z][y];
                } // end for
                result.data[x][y] = sum;
            } // end for
        } // end for
        
        return (result); // Retorna por valor
    } // end operator* ( )

    const int getRows()
    {
        return (rows);
    } // end getRows ( )

    const int getColumns()
    {
        return (columns);
    } // end getColumns ( )

    // ----------------------------------------------- NOVOS METODOS (EXERCICIOS)

    /**
     * (1211) Gerar valores aleatorios para preencher a matriz.
     * @param inferior - Limite inferior do intervalo
     * @param superior - Limite superior do intervalo
     */
    void randomIntGenerate(int inferior, int superior)
    {
        if (data == nullptr || rows == 0 || columns == 0)
        {
            cout << "ERROR: Matrix not initialized." << endl;
            return;
        }

        if (inferior > superior)
        {
            cout << "ERROR: Invalid interval." << endl;
            return;
        }

        for (int x = 0; x < rows; x = x + 1)
        {
            for (int y = 0; y < columns; y = y + 1)
            {
                data[x][y] = (rand() % (superior - inferior + 1)) + inferior;
            }
        }
    } // end randomIntGenerate ( )

    /**
     * (1212) Escalar a matriz por uma constante.
     * @param constant - Valor pelo qual multiplicar
     * @return uma nova matriz com os valores escalados
     */
    Matrix scalar(T constant)
    {
        Matrix<T> result(rows, columns, 0); // Cria nova matriz

        for (int x = 0; x < rows; x = x + 1)
        {
            for (int y = 0; y < columns; y = y + 1)
            {
                result.data[x][y] = data[x][y] * constant;
            }
        }
        return result; // Retorna por valor
    } // end scalar ( )

    /**
     * (1213) Testar se a matriz e a identidade.
     * @return true se for identidade, false caso contrario
     */
    bool isIdentity() // Exemplo usava "identidade()", mas isIdentity e' mais padrao
    {
        if (rows != columns || rows == 0)
        {
            return false; // Nao e' quadrada ou esta vazia
        }

        bool result = true;
        int x = 0;
        int y = 0;
        
        while (x < rows && result)
        {
            y = 0;
            while (y < columns && result)
            {
                if (x == y)
                {
                    result = result && (data[x][y] == 1);
                }
                else
                {
                    result = result && (data[x][y] == 0);
                }
                y = y + 1;
            } // end while
            x = x + 1;
        } // end while
        
        return result;
    } // end isIdentity ( )

    /**
     * (1214) Testar se duas matrizes sao iguais.
     * @param other - A outra matriz para comparar
     * @return true se forem iguais, false caso contrario
     */
    bool operator==(const Matrix<T> &other)
    {
        if (rows != other.rows || columns != other.columns)
        {
            return false; // Dimensoes diferentes
        }

        bool result = true;
        int x = 0;
        int y = 0;

        while (x < rows && result)
        {
            y = 0;
            while (y < columns && result)
            {
                result = result && (data[x][y] == other.data[x][y]);
                y = y + 1;
            } // end while
            x = x + 1;
        } // end while

        return result;
    } // end operator== ( )

    /**
     * (1215) Somar duas matrizes.
     * @param other - A outra matriz para somar
     * @return uma nova matriz com a soma
     */
    Matrix add(const Matrix<T> &other)
    {
        if (other.rows == 0 || rows != other.rows ||
            other.columns == 0 || columns != other.columns)
        {
            cout << "\nERROR: Missing or incompatible data.\n"
                 << endl;
            return Matrix(0, 0, 0); // Retorna matriz vazia
        }

        Matrix<T> result(rows, columns, 0); // Cria nova matriz

        for (int x = 0; x < result.rows; x = x + 1)
        {
            for (int y = 0; y < result.columns; y = y + 1)
            {
                result.data[x][y] = data[x][y] + other.data[x][y];
            } // end for
        } // end for
        
        return (result); // Retorna por valor
    } // end add ( )

    /**
     * (1216) Somar linha (R1 = R1 + R2 * K).
     * @param r1 - Linha a ser modificada
     * @param r2 - Linha a ser usada como base
     * @param k - Constante
     */
    void addRows(int r1, int r2, T k)
    {
        if (r1 < 0 || r1 >= rows || r2 < 0 || r2 >= rows)
        {
            cout << "ERROR: Invalid row index." << endl;
            return;
        }

        for (int y = 0; y < columns; y = y + 1)
        {
            data[r1][y] = data[r1][y] + (data[r2][y] * k);
        }
    } // end addRows ( )

    /**
     * (1217) Subtrair linha (R1 = R1 - R2 * K).
     * @param r1 - Linha a ser modificada
     * @param r2 - Linha a ser usada como base
     * @param k - Constante
     */
    void subtractRows(int r1, int r2, T k)
    {
        if (r1 < 0 || r1 >= rows || r2 < 0 || r2 >= rows)
        {
            cout << "ERROR: Invalid row index." << endl;
            return;
        }

        for (int y = 0; y < columns; y = y + 1)
        {
            data[r1][y] = data[r1][y] - (data[r2][y] * k);
        }
    } // end subtractRows ( )


    /**
     * (1218) Procurar valor e retornar linha.
     * @param value - Valor a ser procurado
     * @return indice da linha (primeira ocorrencia) ou -1 se nao achar
     */
    int searchRow(T value)
    {
        int x = 0;
        int y = 0;
        bool found = false;
        
        while (x < rows && !found)
        {
            y = 0;
            while (y < columns && !found)
            {
                if (data[x][y] == value)
                {
                    found = true;
                }
                y = y + 1;
            } // end while
            if (!found) 
            {
               x = x + 1;
            }
        } // end while

        if (found)
        {
            return x;
        }
        else
        {
            return -1; // Nao encontrado
        }
    } // end searchRow ( )

    /**
     * (1219) Procurar valor e retornar coluna.
     * @param value - Valor a ser procurado
     * @return indice da coluna (primeira ocorrencia, varrendo colunas primeiro) ou -1
     */
    int searchColumn(T value)
    {
        int x = 0;
        int y = 0;
        bool found = false;

        // Varre por coluna, depois por linha
        while (y < columns && !found)
        {
            x = 0;
            while (x < rows && !found)
            {
                if (data[x][y] == value)
                {
                    found = true;
                }
                x = x + 1;
            } // end while
            if (!found)
            {
                y = y + 1;
            }
        } // end while

        if (found)
        {
            return y;
        }
        else
        {
            return -1; // Nao encontrado
        }
    } // end searchColumn ( )

    /**
     * (1220) Transpor a matriz.
     * @return uma nova matriz transposta
     */
    Matrix transpose()
    {
        // A nova matriz tera dimensoes invertidas
        Matrix<T> result(columns, rows, 0); 

        for (int x = 0; x < rows; x = x + 1)
        {
            for (int y = 0; y < columns; y = y + 1)
            {
                result.data[y][x] = data[x][y];
            }
        }
        return result; // Retorna por valor
    } // end transpose ( )

}; // end class
#endif