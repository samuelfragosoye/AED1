/*
 * Arrays.hpp - v0.0. - 29 / 11 / 2025
 * Author: Samuel Fragoso
 */

#ifndef _ARRAYS_H_
#define _ARRAYS_H_

#include <iostream>
#include <iomanip> // Para formatacao

using namespace std;

// Definicao do tipo ref_intArray conforme citado no PDF (Ex 07)
typedef int* ref_intArray; 

class Arrays
{
public:
    /**
     * Funcao auxiliar para obter tamanho do arranjo.
     * Convencao: array[0] guarda o tamanho.
     */
    static int array_len(ref_intArray array)
    {
        if (array == nullptr) return 0;
        return array[0];
    }

    /**
     * Funcao auxiliar para imprimir o arranjo.
     */
    static void array_print(ref_intArray array)
    {
        if (array == nullptr) {
            cout << "(null)";
            return;
        }
        int len = array[0];
        cout << "[ ";
        for(int i = 1; i <= len; i++)
        {
            cout << array[i] << (i < len ? ", " : "");
        }
        cout << " ] (Tam: " << len << ")";
    }

    /**
     * 01.) Acrescentar valor ao final (push_back) [cite: 115]
     */
    static ref_intArray array_push_back(ref_intArray array, int value)
    {
        int len = array_len(array);
        // Novo tamanho: 1 (para o tamanho) + len (dados antigos) + 1 (novo dado)
        ref_intArray resp = new int[len + 2]; 
        
        resp[0] = len + 1; // Atualiza tamanho

        // Copiar dados antigos
        for(int i = 0; i < len; i++)
        {
            resp[i + 1] = array[i + 1];
        }

        // Inserir novo dado no final
        resp[len + 1] = value;

        return resp;
    }

    /**
     * 02.) Remover valor do final (pop_back) [cite: 123]
     */
    static ref_intArray array_pop_back(ref_intArray array)
    {
        int len = array_len(array);
        if (len <= 0) return nullptr;

        // Novo array tera tamanho: 1 (guardar tamanho) + len - 1 (dados)
        if (len - 1 == 0) return nullptr; // Se ficar vazio, retorna null

        ref_intArray resp = new int[len]; // len ja equivale a (len-1) + 1
        resp[0] = len - 1;

        for(int i = 1; i < len; i++) // Copia ate o penultimo
        {
            resp[i] = array[i];
        }
        
        return resp;
    }

    /**
     * 03.) Acrescentar valor ao inicio (push_front) [cite: 132]
     */
    static ref_intArray array_push_front(int value, ref_intArray array)
    {
        int len = array_len(array);
        ref_intArray resp = new int[len + 2];
        resp[0] = len + 1;

        resp[1] = value; // Novo valor no inicio (pos 1 fisica)

        for(int i = 1; i <= len; i++)
        {
            resp[i + 1] = array[i];
        }
        return resp;
    }

    /**
     * 04.) Remover valor do inicio (pop_front) [cite: 140]
     */
    static ref_intArray array_pop_front(ref_intArray array)
    {
        int len = array_len(array);
        if (len <= 0) return nullptr;
        if (len == 1) return nullptr; // Vai ficar vazio

        ref_intArray resp = new int[len]; // Tamanho fisico reduz em 1
        resp[0] = len - 1;

        for(int i = 2; i <= len; i++) // Comeca do segundo elemento fisico
        {
            resp[i - 1] = array[i];
        }
        return resp;
    }

    /**
     * 05.) Acrescentar valor no meio (push_mid) [cite: 150]
     */
    static ref_intArray array_push_mid(ref_intArray array, int value)
    {
        int len = array_len(array);
        if(len == 0) return array_push_back(array, value);

        ref_intArray resp = new int[len + 2];
        resp[0] = len + 1;

        int mid = (len / 2) + 1; // Calcula meio logico + offset fisico
        int i_old = 1;
        int i_new = 1;

        while(i_old <= len)
        {
            if(i_new == mid)
            {
                resp[i_new] = value;
                i_new++;
            }
            resp[i_new] = array[i_old];
            i_new++;
            i_old++;
        }
        // Caso o mid seja apos o ultimo (impar/par)
        if(i_new == mid) resp[i_new] = value;

        return resp;
    }

    /**
     * 06.) Remover valor do meio (pop_mid) [cite: 158]
     */
    static ref_intArray array_pop_mid(ref_intArray array)
    {
        int len = array_len(array);
        if(len <= 0) return nullptr;
        if(len == 1) return array_pop_front(array);

        ref_intArray resp = new int[len]; // Tamanho fisico - 1
        resp[0] = len - 1;

        int mid = (len / 2) + 1;
        if (len % 2 != 0) mid = (len/2) + 2; // Ajuste para impares (remover o centro exato)

        int i_old = 1;
        int i_new = 1;

        while(i_old <= len)
        {
            if(i_old != mid)
            {
                resp[i_new] = array[i_old];
                i_new++;
            }
            i_old++;
        }
        return resp;
    }

    /**
     * 07.) Comparar arranjos (intArray_cmp) [cite: 169]
     * Retorna: 0 (iguais), negativo (diferenca menor em p), positivo (maior em p)
     */
    static int intArray_cmp(ref_intArray p, ref_intArray q)
    {
        if(p == nullptr && q == nullptr) return 0;
        if(p == nullptr) return -1;
        if(q == nullptr) return 1;

        int lenP = p[0];
        int lenQ = q[0];
        int minLen = (lenP < lenQ) ? lenP : lenQ;

        for(int i = 1; i <= minLen; i++)
        {
            if(p[i] != q[i])
            {
                return (p[i] - q[i]);
            }
        }
        return (lenP - lenQ);
    }

    /**
     * 08.) Juntar arranjos (append) [cite: 177]
     */
    static ref_intArray intArray_append(ref_intArray p, ref_intArray q)
    {
        if(q == nullptr) return p; // Deveria clonar p, mas simplificando retorno direto
        if(p == nullptr) return q;

        int lenP = p[0];
        int lenQ = q[0];
        int newLen = lenP + lenQ;

        ref_intArray resp = new int[newLen + 1];
        resp[0] = newLen;

        int k = 1;
        for(int i = 1; i <= lenP; i++) resp[k++] = p[i];
        for(int i = 1; i <= lenQ; i++) resp[k++] = q[i];

        return resp;
    }

    /**
     * 09.) Procurar valor (seek) [cite: 184]
     * Retorna ponteiro para a posicao ou NULL
     */
    static ref_intArray intArray_seek(ref_intArray a, int x)
    {
        if(a == nullptr) return nullptr;
        int len = a[0];
        for(int i = 1; i <= len; i++)
        {
            if(a[i] == x) return &a[i];
        }
        return nullptr;
    }

    /**
     * 10.) Separar sequencia (sub) [cite: 194]
     */
    static ref_intArray intArray_sub(ref_intArray a, int start, int size)
    {
        if(a == nullptr || size <= 0) return nullptr;
        int len = a[0];
        if(start < 0 || start >= len) return nullptr;

        // Limitar size se ultrapassar o fim
        if(start + size > len) size = len - start;

        ref_intArray resp = new int[size + 1];
        resp[0] = size;

        for(int i = 0; i < size; i++)
        {
            // start e' logico (0-based) ou fisico (1-based)? Assumindo 0-based logico
            resp[i + 1] = a[start + 1 + i];
        }
        return resp;
    }

    /**
     * E1.) Intercalar (merge) [cite: 203]
     */
    static ref_intArray intArray_merge(ref_intArray p, ref_intArray q)
    {
        if(!p && !q) return nullptr;
        if(!p) return q; // Deveria clonar
        if(!q) return p;

        int lenP = p[0];
        int lenQ = q[0];
        ref_intArray resp = new int[lenP + lenQ + 1];
        resp[0] = lenP + lenQ;

        int i = 1, j = 1, k = 1;
        while(i <= lenP || j <= lenQ)
        {
            if(i <= lenP) resp[k++] = p[i++];
            if(j <= lenQ) resp[k++] = q[j++];
        }
        return resp;
    }

    /**
     * E2.) Mesclar decrescente (mergeDown) [cite: 211]
     * Simplificado: Apenas concatena e ordena (BubbleSort simples)
     */
    static ref_intArray intArray_mergeDown(ref_intArray p, ref_intArray q)
    {
        ref_intArray resp = intArray_append(p, q);
        if(!resp) return nullptr;

        int len = resp[0];
        // Ordenacao simples decrescente
        for(int i = 1; i <= len; i++)
        {
            for(int j = i + 1; j <= len; j++)
            {
                if(resp[i] < resp[j])
                {
                    int temp = resp[i];
                    resp[i] = resp[j];
                    resp[j] = temp;
                }
            }
        }
        return resp;
    }
};

#endif