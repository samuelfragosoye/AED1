/*
  myarray.hpp - v0.0. - 26/10/2025
  Author: Samuel Fragoso
  Matricula: 902665

  Para o Estudo Dirigido 11 - Classe Array<T>
*/

// definicoes globais
#ifndef _MYARRAY_HPP_
#define _MYARRAY_HPP_

// dependencias
#include <iostream>
using std::cin;      // para entrada
using std::cout;     // para saida
using std::endl;     // para mudar de linha

#include <iomanip>
using std::setw;     // para definir espacamento

#include <string>
using std::string;   // para cadeia de caracteres

#include <fstream>
using std::ofstream; // para gravar arquivo
using std::ifstream; // para ler arquivo

#include <stdexcept> // para excecoes
#include <ctime>     // para rand() nos exercicios

template <typename T>
class Array
{
private: // area reservada
    T optional; // Valor opcional para retornos de erro
    int length;
    T *data;

public: // area aberta

    /**
     * Construtor principal.
     * @param n - tamanho do arranjo
     * @param initial - valor inicial para 'optional'
     */
    Array(int n, T initial)
    {
        // definir valores iniciais
        optional = initial;
        length = 0;
        data = nullptr;
        // reservar area
        if (n > 0)
        {
            length = n;
            data = new T[length];
            // NOTA: O PDF não inicializa os dados aqui.
        }
    } // end constructor

    /**
     * Construtor padrao (Ex. 13).
     */
    Array()
    {
        // construtor padrao
        // definir valores iniciais
        length = 0;
        // reservar area
        data = nullptr;
        optional = T(); // Inicializa 'optional' com valor padrao de T
    } // end constructor

    /**
     * Construtor baseado em copia de C-array (Ex. 13).
     * @param length - tamanho do arranjo
     * @param other - arranjo C-style
     */
    Array(int length, T other[]) // Corrigido de 'int other[]' para 'T other[]'
    {
        optional = T();
        if (length <= 0)
        {
            cout << "\nERROR: Missing data.\n" << endl;
            this->length = 0;
            this->data = nullptr;
        }
        else
        {
            // criar copia
            this->length = length;
            // reservar area
            data = new T[this->length];
            // ler dados
            for (int x = 0; x < this->length; x = x + 1)
            {
                data[x] = other[x];
            } // end for
        } // end if
    } // end constructor ()

    /**
     * Construtor de copia (Ex. 16).
     * @param other - outro objeto Array
     */
    Array(const Array &other)
    {
        optional = other.optional;
        if (other.length <= 0)
        {
            cout << "\nERROR: Missing data.\n" << endl;
            this->length = 0;
            this->data = nullptr;
        }
        else
        {
            // criar copia
            length = other.length;
            // reservar area
            data = new T[other.length];
            // ler dados
            for (int x = 0; x < length; x = x + 1)
            {
                data[x] = other.data[x];
            } // end for
        } // end if
    } // end constructor ()

    /**
     * Destrutor (libera memoria).
     */
    ~Array() // Nomeado como 'free' no PDF, mas destrutor e' mais apropriado
    {
        if (data != nullptr)
        {
            delete[] data; // Usa delete[] para arrays
            data = nullptr;
        } // end if
    } // end free ()
    
    // O PDF pede 'free()', entao vamos manter
    void free()
    {
        if (data != nullptr)
        {
            delete[] data; // Usa delete[] para arrays
            data = nullptr;
            length = 0;
        } // end if
    } // end free ()


    /**
     * Operador de atribuicao (Ex. 19).
     * @param other - outro objeto Array
     * @return referencia para o objeto atual
     */
    Array &operator=(const Array<T> other)
    {
        if (this != &other) // Evita auto-atribuicao
        {
            if (other.length <= 0)
            {
                cout << "\nERROR: Missing data.\n" << endl;
            }
            else
            {
                // Libera memoria antiga
                if (data != nullptr)
                {
                    delete[] data;
                }
                
                // Copia dados
                this->length = other.length;
                this->optional = other.optional;
                this->data = new T[other.length];
                
                for (int x = 0; x < this->length; x = x + 1)
                {
                    data[x] = other.data[x];
                } // end for
            } // end if
        }
        return (*this); // Retorna o proprio objeto
    } // end operator= ()

    /**
     * Operador de igualdade (Ex. 22).
     * @param other - outro objeto Array
     * @return true se igual, false caso contrario
     */
    bool operator==(const Array<T> other)
    {
        bool result = false;
        int x = 0;
        if (other.length == 0 || length != other.length)
        {
            // PDF da erro, mas comparacao deve so retornar false
            // cout << "\nERROR: Missing data or different length.\n" << endl;
            result = false;
        }
        else
        {
            x = 0;
            result = true;
            while (x < this->length && result)
            {
                result = result && (data[x] == other.data[x]);
                x = x + 1;
            } // end while
        } // end if
        return (result);
    } // end operator== ()

    /**
     * Operador de adicao (Ex. 25).
     * @param other - outro objeto Array
     * @return um NOVO Array com a soma
     */
    Array operator+(const Array<T> other)
    {
        // O PDF usa 'static' e retorna referencia, o que e' perigoso.
        // Esta versao retorna um novo objeto por valor.
        Array<T> result(other); // Comeca com uma copia de 'other'
        
        if (other.length <= 0 || this->length != other.length)
        {
            cout << "\nERROR: Missing data or different length.\n" << endl;
            result.free(); // Retorna um array vazio em caso de erro
        }
        else
        {
            for (int x = 0; x < this->length; x = x + 1)
            {
                // Soma 'this' aos dados de 'other' (que estao em 'result')
                result.data[x] = result.data[x] + this->data[x];
            } // end for
        } // end if
        return (result);
    } // end operator+ ()
    
    /**
     * Operador de acesso (Ex. 28).
     * @param position - indice
     * @return referencia ao dado
     */
    T& operator[](const int position)
    {
        // A implementacao do PDF e' falha (retorna ref para static).
        // Esta versao retorna o dado real ou lanca excecao.
        if (position < 0 || length <= position)
        {
            cout << endl << "\nERROR: Invalid position (" << position << ").\n" << endl;
            static T errorValue = optional; // Como no PDF
            errorValue = optional;          // Reseta
            return errorValue;              // Retorna ref estatica (como no PDF)
        }
        else
        {
            return data[position]; // Retorna ref real
        }
    } // end operator []


    /**
     * Metodo set (Ex. 01).
     * @param position - indice
     * @param value - valor
     */
    void set(int position, T value)
    {
        if (0 <= position && position < length)
        {
            data[position] = value;
        } // end if
    } // end set ()

    /**
     * Metodo get (Ex. 01).
     * @param position - indice
     * @return valor no indice
     */
    T get(int position)
    {
        T value = optional;
        if (0 <= position && position < length)
        {
            value = data[position];
        } // end if
        return (value);
    } // end get ()

    /**
     * Metodo print (Ex. 01).
     */
    void print()
    {
        cout << endl;
        for (int x = 0; x < length; x = x + 1)
        {
            cout << setw(3) << x << " : "
                 << setw(9) << data[x]
                 << endl;
        } // end for
        cout << endl;
    } // end print ()

    /**
     * Metodo read (Ex. 04).
     */
    void read()
    {
        cout << endl;
        for (int x = 0; x < length; x = x + 1)
        {
            cout << setw(3) << x << " : ";
            cin >> data[x];
        } // end for
        cout << endl;
    } // end read ()

    /**
     * Metodo fprint (Ex. 07).
     * @param fileName - nome do arquivo
     */
    void fprint(string fileName)
    {
        ofstream afile; // output file
        afile.open(fileName);
        afile << length << endl;
        for (int x = 0; x < length; x = x + 1)
        {
            afile << data[x] << endl;
        } // end for
        afile.close();
    } // end fprint ()

    /**
     * Metodo fread (Ex. 10).
     * @param fileName - nome do arquivo
     */
    void fread(string fileName)
    {
        ifstream afile; // input file
        int n = 0;
        afile.open(fileName);
        
        if (!afile.is_open()) {
            cout << "\nERROR: Could not open file " << fileName << endl;
            return;
        }
        
        afile >> n;
        if (n <= 0)
        {
            cout << "\nERROR: Invalid length.\n" << endl;
        }
        else
        {
            // Se ja houver dados, libera
            if (data != nullptr) {
                delete[] data;
            }
            
            // guardar a quantidade de dados
            length = n;
            // reservar area
            data = new T[n];
            // ler dados
            for (int x = 0; x < length; x = x + 1)
            {
                afile >> data[x];
            } // end for
        } // end if
        afile.close();
    } // end fread()

    /**
     * Metodo getLength (Ex. 28).
     * @return tamanho do arranjo
     */
    const int getLength()
    {
        return (length);
    } // end getLength ()
    
    
    // ------------------------------------------- EXERCICIOS 11-20, E1-E2

    /**
     * (1111) Gerar inteiros aleatorios (int) e preencher o arranjo.
     * @param min - valor minimo
     * @param max - valor maximo
     */
    void generateInts(int min, int max)
    {
        if (data && length > 0 && max > min)
        {
            for (int x = 0; x < length; x = x + 1)
            {
                // (static_cast<T>...) so' funciona se T for numerico
                data[x] = (rand() % (max - min + 1)) + min;
            }
        }
    }

    /**
     * (1112) Procurar o maior valor par em um arranjo.
     * @return maior valor par, ou 'optional' se nao houver
     */
    T findLargestEven()
    {
        T largestEven = optional; // 'optional' pode ser 0
        bool foundFirst = false;

        for (int x = 0; x < length; x = x + 1)
        {
            // Assume T pode ser testado com % 2
            if (data[x] % 2 == 0)
            {
                if (!foundFirst)
                {
                    largestEven = data[x];
                    foundFirst = true;
                }
                else if (data[x] > largestEven)
                {
                    largestEven = data[x];
                }
            }
        }
        return largestEven;
    }

    /**
     * (1113) Procurar o menor valor par múltiplo de 3. (PDF esta confuso, fala "maior" no texto e "menor" no exemplo)
     * [cite_start]Vou implementar "menor" conforme exemplo [cite: 1837]
     * @return menor valor par e multiplo de 3
     */
    T findSmallestEvenMultipleOf3()
    {
        T smallest = optional;
        bool foundFirst = false;

        for (int x = 0; x < length; x = x + 1)
        {
            if (data[x] % 2 == 0 && data[x] % 3 == 0)
            {
                if (!foundFirst)
                {
                    smallest = data[x];
                    foundFirst = true;
                }
                else if (data[x] < smallest)
                {
                    smallest = data[x];
                }
            }
        }
        return smallest;
    }

    /**
     * (1114) Somar todos os valores em um arranjo entre duas posições.
     * @param inicio - posicao inicial (inclusiva)
     * @param fim - posicao final (inclusiva)
     * @return soma
     */
    T addInterval(int inicio, int fim)
    {
        T soma = T(); // Valor 'zero' de T

        if (inicio < 0 || fim >= length || inicio > fim)
        {
            cout << "\nERROR: Invalid interval.\n" << endl;
        }
        else
        {
            for (int x = inicio; x <= fim; x = x + 1)
            {
                soma = soma + data[x];
            }
        }
        return soma;
    }

    /**
     * (1115) Achar a média dos valores em um arranjo entre duas posições.
     * @param inicio - posicao inicial (inclusiva)
     * @param fim - posicao final (inclusiva)
     * @return media (double)
     */
    double averageInterval(int inicio, int fim)
    {
        T soma = T(); // Valor 'zero' de T
        double media = 0.0;
        int count = 0;

        if (inicio < 0 || fim >= length || inicio > fim)
        {
            cout << "\nERROR: Invalid interval.\n" << endl;
        }
        else
        {
            for (int x = inicio; x <= fim; x = x + 1)
            {
                soma = soma + data[x];
                count = count + 1;
            }
            if (count > 0)
            {
                media = (double)soma / count;
            }
        }
        return media;
    }

    /**
     * (1116) Verificar se todos os valores são positivos e menores que 100.
     * @return true se sim, false se nao
     */
    bool arePositivesAndLess100()
    {
        bool result = true;
        int x = 0;
        while (x < length && result)
        {
            // > 0 (positivo) e < 100
            if (data[x] <= 0 || data[x] >= 100)
            {
                result = false;
            }
            x = x + 1;
        }
        return result;
    }

    /**
     * (1117) Dizer se está ordenado, ou não, em ordem decrescente.
     * @return true se decrescente, false caso contrario
     */
    bool isDecrescent()
    {
        bool result = true;
        int x = 0;
        // Sem break
        while (x < length - 1 && result)
        {
            if (data[x] < data[x + 1])
            {
                result = false;
            }
            x = x + 1;
        }
        return result;
    }

    /**
     * (1118) Dizer se determinado valor está presente em arranjo,
     * entre duas posições indicadas.
     * @param procurado - valor a procurar
     * @param inicio - posicao inicial (inclusiva)
     * @param fim - posicao final (inclusiva)
     * @return true se encontrou, false se nao
     */
    bool searchInterval(T procurado, int inicio, int fim)
    {
        bool found = false;
        
        if (inicio < 0 || fim >= length || inicio > fim)
        {
            cout << "\nERROR: Invalid interval.\n" << endl;
        }
        else
        {
            int x = inicio;
            // Sem break (loop para quando 'found' e' true)
            while (x <= fim && !found)
            {
                if (data[x] == procurado)
                {
                    found = true;
                }
                x = x + 1;
            }
        }
        return found;
    }

    /**
     * (1119) Escalar dados em arranjo, entre duas posições,
     * multiplicando por uma constante.
     * @param constante - fator de escala
     * @param inicio - posicao inicial (inclusiva)
     * @param fim - posicao final (inclusiva)
     * @return NOVO arranjo com valores escalados
     */
    Array<T> scalar(T constante, int inicio, int fim)
    {
        Array<T> novo(*this); // Cria uma copia

        if (inicio < 0 || fim >= length || inicio > fim)
        {
            cout << "\nERROR: Invalid interval.\n" << endl;
        }
        else
        {
            for (int x = inicio; x <= fim; x = x + 1)
            {
                novo.data[x] = novo.data[x] * constante;
            }
        }
        return novo;
    }

    /**
     * (1120) Colocar valores em arranjo em ordem decrescente (Bubble Sort).
     * Modifica o arranjo atual (in-place).
     */
    void sortDown()
    {
        if (data && length > 0)
        {
            for (int i = 0; i < length - 1; i = i + 1)
            {
                for (int j = 0; j < length - 1 - i; j = j + 1)
                {
                    if (data[j] < data[j + 1])
                    {
                        T temp = data[j];
                        data[j] = data[j + 1];
                        data[j + 1] = temp;
                    }
                }
            }
        }
    }
    
    /**
     * (11E1) Operador de diferenca.
     * @param other - outro objeto Array
     * @return true se diferente, false caso contrario
     */
    bool operator!=(const Array<T>& other)
    {
        return !(*this == other);
    }

    /**
     * (11E2) Calcular a quantidade de diferenças entre dois arranjos.
     * @param other - outro objeto Array
     * @return numero de diferencas
     */
     int countDifferences(const Array<T>& other)
     {
        int count = 0;
        if (length != other.length)
        {
            cout << "\nERROR: Different lengths, cannot count differences.\n" << endl;
            count = -1; // Erro
        }
        else
        {
            for (int x = 0; x < length; x = x + 1)
            {
                if (data[x] != other.data[x])
                {
                    count = count + 1;
                }
            }
        }
        return count;
     }

}; // end class Array

#endif
/*
  Comentarios sobre as Saidas - Estudo Dirigido 11 (C++ - Exemplo1100.cpp)
 
  NOTA: Varios metodos dependem de arquivos (INT_ARRAY1.TXT, DADOS.TXT)
  criados por metodos anteriores. E recomendado executar os metodos
  03 e 11 primeiro para gerar esses arquivos.

  -------------------------------------------------
  Exemplos (Metodos 01-10)
  -------------------------------------------------
 
  * Method 01: Exibe um array de 5 posicoes (1 a 5) definido no codigo (usando obj.set()).
  * Method 02: Pede ao usuario 5 valores inteiros (tamanho fixo 5) (usando obj.read()). Imprime o array.
  * Method 03: Pede ao usuario 5 valores. Salva em "INT_ARRAY1.TXT" (usando obj.fprint()).
  * Method 04: Le "INT_ARRAY1.TXT" (usando obj.fread()) e imprime o array.
      * Dependencia: Method 03 (para criar INT_ARRAY1.TXT).
  * Method 05: Cria um array a partir de um vetor C-style ({1,2,3,4,5}) (usando construtor). Imprime o array.
  * Method 06: Le "INT_ARRAY1.TXT" (arr1). Cria "arr2" (usando construtor de copia). Imprime "Original" e "Copia".
      * Dependencia: Method 03.
  * Method 07: Le "INT_ARRAY1.TXT" (arr1). Copia para "arr2" (usando operator=). Imprime "Original" e "Copia".
      * Dependencia: Method 03.
  * Method 08: Cria dois arrays ({1,2,3}). Testa "operator==" (saida: 1). Modifica arr2[0]. Testa de novo (saida: 0).
  * Method 09: Le "INT_ARRAY1.TXT" (arr1). Copia (arr2). Calcula "arr3 = arr1 + arr2" (usando operator+). Imprime os 3 arrays.
      * Dependencia: Method 03.
  * Method 10: Cria array ({1,2,3,4,5}). Testa "operator[]" modificando arr[0] para 99. Tenta acessar indices invalidos (deve dar erro).

  -------------------------------------------------
  Exercicios (Metodos 11-20 e E1-E2)
  -------------------------------------------------

  * Method 11 (1111): Pede N, min, max. Gera N valores aleatorios (usando obj.generateInts()), imprime e salva em "DADOS.TXT".
  * Method 12 (1112): Le "DADOS.TXT". Imprime o array e o "Maior valor par encontrado: X".
      * Dependencia: Method 11 (para criar DADOS.TXT).
  * Method 13 (1113): Le "DADOS.TXT". Imprime o array e o "Menor valor par e multiplo de 3: X".
      * Dependencia: Method 11.
  * Method 14 (1114): Le "DADOS.TXT". Pede inicio e fim. Imprime o array e a "Soma do intervalo [X, Y]: Z".
      * Dependencia: Method 11.
  * Method 15 (1115): Le "DADOS.TXT". Pede inicio e fim. Imprime o array e a "Media do intervalo [X, Y]: Z.ZZ".
      * Dependencia: Method 11.
  * Method 16 (1116): Le "DADOS.TXT". Imprime o array e informa "Todos os valores sao > 0 e < 100? SIM" ou "NAO".
      * Dependencia: Method 11.
  * Method 17 (1117): Le "DADOS.TXT". Imprime o array e informa "O arranjo esta em ordem decrescente? SIM" ou "NAO".
      * Dependencia: Method 11.
  * Method 18 (1118): Le "DADOS.TXT". Pede valor, inicio e fim. Informa se o valor "existe no intervalo [X, Y]? SIM" ou "NAO".
      * Dependencia: Method 11.
  * Method 19 (1119): Le "DADOS.TXT". Pede constante, inicio e fim. Imprime o "Arranjo Original" e o "Novo Arranjo" (escalado).
      * Dependencia: Method 11.
  * Method 20 (1120): Le "DADOS.TXT". Imprime o "Arranjo Original". Ordena o proprio array (in-place) e o imprime como "Arranjo Ordenado".
      * Dependencia: Method 11.
  * Method E1 (11E1): Le "DADOS.TXT" (arr1) e copia (arr2). Testa "operator!=" (saida: "NAO"). Modifica arr2[0]. Testa de novo (saida: "SIM").
      * Dependencia: Method 11.
  * Method E2 (11E2): Le "DADOS.TXT" (arr1) e copia (arr2). Conta diferencas (saida: "0"). Modifica 2 elementos em arr2. Conta de novo (saida: "2").
      * Dependencia: Method 11.
*/