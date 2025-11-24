/*
 * Strings.hpp - v0.0. - 23 / 11 / 2025
 * Author: Samuel Fragoso
 */

#ifndef _STRINGS_H_
#define _STRINGS_H_

#include <iostream>

using namespace std;

class Strings
{
private:
    /**
     * Funcao auxiliar para calcular tamanho da string usando ponteiros.
     */
    static int str_len(char *s)
    {
        if (s == nullptr) return 0;
        int len = 0;
        char *ptr = s;
        while (*ptr != '\0')
        {
            len++;
            ptr++;
        }
        return len;
    }

public:
    /**
     * 01.) Funcao para acrescentar caractere ao final.
     */
    static char *str_push_back(char *s, char c)
    {
        int len = str_len(s);
        char *resp = new char[len + 2]; // +1 char, +1 null terminator
        char *ptr_s = s;
        char *ptr_resp = resp;

        // Copiar string original
        if (s != nullptr)
        {
            while (*ptr_s != '\0')
            {
                *ptr_resp = *ptr_s;
                ptr_s++;
                ptr_resp++;
            }
        }
        
        // Adicionar novo char e fechar string
        *ptr_resp = c;
        *(ptr_resp + 1) = '\0';

        return resp;
    }

    /**
     * 02.) Funcao para remover caractere do final.
     */
    static char *str_pop_back(char *s)
    {
        int len = str_len(s);
        char *resp = nullptr;

        if (len > 0)
        {
            resp = new char[len]; // len original ja inclui o espaco que vamos remover, entao novo tamanho e' len (para caber null)
            char *ptr_s = s;
            char *ptr_resp = resp;
            int i = 0;
            
            // Copiar ate o penultimo
            while (i < len - 1)
            {
                *ptr_resp = *ptr_s;
                ptr_resp++;
                ptr_s++;
                i++;
            }
            *ptr_resp = '\0';
        }
        return resp;
    }

    /**
     * 03.) Funcao para acrescentar caractere ao inicio.
     */
    static char *str_push_front(char c, char *s)
    {
        int len = str_len(s);
        char *resp = new char[len + 2];
        char *ptr_resp = resp;
        char *ptr_s = s;

        // Adicionar char no inicio
        *ptr_resp = c;
        ptr_resp++;

        // Copiar o resto
        if (s != nullptr)
        {
            while (*ptr_s != '\0')
            {
                *ptr_resp = *ptr_s;
                ptr_s++;
                ptr_resp++;
            }
        }
        *ptr_resp = '\0';
        return resp;
    }

    /**
     * 04.) Funcao para remover caractere do inicio.
     */
    static char *str_pop_front(char *s)
    {
        int len = str_len(s);
        char *resp = nullptr;

        if (len > 0)
        {
            resp = new char[len];
            char *ptr_s = s + 1; // Pular o primeiro
            char *ptr_resp = resp;

            while (*ptr_s != '\0')
            {
                *ptr_resp = *ptr_s;
                ptr_resp++;
                ptr_s++;
            }
            *ptr_resp = '\0';
        }
        return resp;
    }

    /**
     * 05.) Inserir caractere no meio.
     */
    static char *str_push_mid(char *s, char c)
    {
        int len = str_len(s);
        if (len < 2) return str_push_back(s, c); // Se pequeno, insere no fim (comportamento padrao)

        char *resp = new char[len + 2];
        int mid = len / 2;
        char *ptr_s = s;
        char *ptr_resp = resp;
        int i = 0;

        // Copiar ate a metade
        while (i < mid)
        {
            *ptr_resp = *ptr_s;
            ptr_resp++;
            ptr_s++;
            i++;
        }

        // Inserir char
        *ptr_resp = c;
        ptr_resp++;

        // Copiar o resto
        while (*ptr_s != '\0')
        {
            *ptr_resp = *ptr_s;
            ptr_resp++;
            ptr_s++;
        }
        *ptr_resp = '\0';

        return resp;
    }

    /**
     * 06.) Remover caractere do meio.
     */
    static char *str_pop_mid(char *s)
    {
        int len = str_len(s);
        if (len < 3) return str_pop_back(s); // Condicao do enunciado

        char *resp = new char[len]; // len - 1 + 1 null
        int mid = len / 2;
        char *ptr_s = s;
        char *ptr_resp = resp;
        int i = 0;

        while (*ptr_s != '\0')
        {
            if (i != mid)
            {
                *ptr_resp = *ptr_s;
                ptr_resp++;
            }
            ptr_s++;
            i++;
        }
        *ptr_resp = '\0';
        return resp;
    }

    /**
     * 07.) Inserir caractere em posicao valida.
     */
    static char *str_insert(char *s, char c, int index)
    {
        int len = str_len(s);
        if (index < 0 || index > len) return s; // Retorna original se invalido

        char *resp = new char[len + 2];
        char *ptr_s = s;
        char *ptr_resp = resp;
        int i = 0;

        while (i < index)
        {
            *ptr_resp = *ptr_s;
            ptr_resp++;
            ptr_s++;
            i++;
        }

        *ptr_resp = c;
        ptr_resp++;

        while (*ptr_s != '\0')
        {
            *ptr_resp = *ptr_s;
            ptr_resp++;
            ptr_s++;
        }
        *ptr_resp = '\0';
        return resp;
    }

    /**
     * 08.) Remover caractere de posicao valida.
     */
    static char *str_remove(char *s, int index)
    {
        int len = str_len(s);
        if (index < 0 || index >= len) return s;

        char *resp = new char[len];
        char *ptr_s = s;
        char *ptr_resp = resp;
        int i = 0;

        while (*ptr_s != '\0')
        {
            if (i != index)
            {
                *ptr_resp = *ptr_s;
                ptr_resp++;
            }
            ptr_s++;
            i++;
        }
        *ptr_resp = '\0';
        return resp;
    }

    /**
     * 09.) Procurar primeira ocorrencia.
     */
    static char *str_chr(char *s, char c)
    {
        if (s == nullptr) return nullptr;
        char *ptr = s;
        while (*ptr != '\0')
        {
            if (*ptr == c) return ptr;
            ptr++;
        }
        return nullptr;
    }

    /**
     * 10.) Separar caracteres ate delimitador.
     */
    static char *str_tok(char *s, char delimiter)
    {
        if (s == nullptr) return nullptr;
        
        // Calcular tamanho ate delimitador ou fim
        int len = 0;
        char *ptr = s;
        bool found = false;
        while (*ptr != '\0' && !found)
        {
            if (*ptr == delimiter) found = true;
            else 
            {
                len++;
                ptr++;
            }
        }

        char *resp = new char[len + 1];
        char *ptr_resp = resp;
        char *ptr_s = s;
        int i = 0;
        
        while (i < len)
        {
            *ptr_resp = *ptr_s;
            ptr_resp++;
            ptr_s++;
            i++;
        }
        *ptr_resp = '\0';
        return resp;
    }

    /**
     * E1.) Procurar prefixo.
     */
    static char *str_prefix(char *prefix, char *s)
    {
        if (prefix == nullptr || s == nullptr) return nullptr;
        
        char *p_pre = prefix;
        char *p_s = s;
        bool match = true;

        while (*p_pre != '\0' && match)
        {
            if (*p_s == '\0' || *p_s != *p_pre)
            {
                match = false;
            }
            else
            {
                p_s++;
                p_pre++;
            }
        }

        if (match) return s;
        return nullptr;
    }

    /**
     * E2.) Procurar sufixo.
     */
    static char *str_suffix(char *s, char *suffix)
    {
        if (s == nullptr || suffix == nullptr) return nullptr;

        int len_s = str_len(s);
        int len_suf = str_len(suffix);

        if (len_suf > len_s) return nullptr;

        char *ptr_start = s + (len_s - len_suf); // Inicio da comparacao no s
        char *ptr_s = ptr_start;
        char *ptr_suf = suffix;
        bool match = true;

        while (*ptr_suf != '\0' && match)
        {
            if (*ptr_s != *ptr_suf)
            {
                match = false;
            }
            else
            {
                ptr_s++;
                ptr_suf++;
            }
        }

        if (match) return ptr_start;
        return nullptr;
    }
};

#endif