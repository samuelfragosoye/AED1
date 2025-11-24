/*
 * MyString.hpp - v0.0. - 22 / 11 / 2025
 * Author: Samuel Fragoso
 */

#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>
#include <string>
#include "Erro.hpp"

using namespace std;

/**
 * Classe MyString, derivada da classe Erro.
 */
class MyString : public Erro
{
private:
    string conteudo;

public:
    /**
     * Construtor padrao.
     */
    MyString()
    {
        setErro(0);
        conteudo = "";
    }

    /**
     * Construtor alternativo.
     */
    MyString(string texto)
    {
        setErro(0);
        conteudo = texto;
    }

    /**
     * Metodo para definir conteudo.
     */
    void setConteudo(string texto)
    {
        conteudo = texto;
    }

    /**
     * Metodo para obter conteudo.
     */
    string getConteudo()
    {
        return conteudo;
    }

    /**
     * Sobrescrita de getErroMsg.
     */
    std::string getErroMsg()
    {
        return (getErro() == 0) ? NO_ERROR : "[ERRO] Operacao invalida ou falha na conversao.";
    }

    // ---------------------------------------------------------------- Exercicios

    /**
     * 01.) Funcao para converter conteudo para inteiro. [cite: 220]
     * @return valor inteiro ou -1 se erro
     */
    int getInt()
    {
        if (conteudo.empty()) return -1;
        
        int i = 0;
        int sinal = 1;
        int resultado = 0;

        // Verificar sinal
        if (conteudo[0] == '-') { sinal = -1; i++; }
        else if (conteudo[0] == '+') { i++; }

        for (; i < conteudo.length(); i++)
        {
            if (conteudo[i] >= '0' && conteudo[i] <= '9')
            {
                resultado = resultado * 10 + (conteudo[i] - '0');
            }
            else
            {
                return -1; // Caractere invalido
            }
        }
        return resultado * sinal;
    }

    /**
     * 02.) Funcao para converter conteudo para double. [cite: 226]
     * @return valor real ou 0.0 se erro
     */
    double getDouble()
    {
        if (conteudo.empty()) return 0.0;

        int i = 0;
        double sinal = 1.0;
        double resultado = 0.0;
        double divisor = 10.0;
        bool pontoEncontrado = false;

        if (conteudo[0] == '-') { sinal = -1.0; i++; }
        else if (conteudo[0] == '+') { i++; }

        for (; i < conteudo.length(); i++)
        {
            if (conteudo[i] >= '0' && conteudo[i] <= '9')
            {
                if (!pontoEncontrado)
                    resultado = resultado * 10.0 + (conteudo[i] - '0');
                else
                {
                    resultado = resultado + (conteudo[i] - '0') / divisor;
                    divisor *= 10.0;
                }
            }
            else if (conteudo[i] == '.' && !pontoEncontrado)
            {
                pontoEncontrado = true;
            }
            else
            {
                return 0.0; // Invalido
            }
        }
        return resultado * sinal;
    }

    /**
     * 03.) Funcao para converter para logico. [cite: 235]
     * Validos: {false, true, F, T, 0, 1}
     */
    bool getBoolean()
    {
        if (conteudo == "true" || conteudo == "T" || conteudo == "1") return true;
        if (conteudo == "false" || conteudo == "F" || conteudo == "0") return false;
        
        setErro(1); // Erro de conversao
        return false;
    }

    /**
     * 04.) Verificar se contem subtexto. [cite: 243]
     */
    bool contains(string subtexto)
    {
        if (subtexto.length() > conteudo.length()) return false;
        
        // Implementacao manual de busca (simulando strstr/find)
        for (int i = 0; i <= conteudo.length() - subtexto.length(); i++)
        {
            bool match = true;
            for (int j = 0; j < subtexto.length(); j++)
            {
                if (conteudo[i + j] != subtexto[j])
                {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }
        return false;
    }

    /**
     * 05.) Converter para maiusculas. [cite: 249]
     */
    string toUpperCase()
    {
        string temp = conteudo;
        for (int i = 0; i < temp.length(); i++)
        {
            if (temp[i] >= 'a' && temp[i] <= 'z')
            {
                temp[i] = temp[i] - 32;
            }
        }
        return temp;
    }

    /**
     * 06.) Converter para minusculas. [cite: 256]
     */
    string toLowerCase()
    {
        string temp = conteudo;
        for (int i = 0; i < temp.length(); i++)
        {
            if (temp[i] >= 'A' && temp[i] <= 'Z')
            {
                temp[i] = temp[i] + 32;
            }
        }
        return temp;
    }

    /**
     * 07.) Trocar ocorrencias de caractere. [cite: 263]
     */
    string replace(char original, char novo)
    {
        string temp = conteudo;
        bool alterou = false;
        for (int i = 0; i < temp.length(); i++)
        {
            if (temp[i] == original)
            {
                temp[i] = novo;
                alterou = true;
            }
        }
        if (!alterou) return conteudo; // Retorna o proprio valor caso contrario
        return temp;
    }

    /**
     * 08.) Cifra de Cesar (Encrypt). [cite: 269]
     * Deslocamento fixo de 3.
     */
    string encrypt()
    {
        string temp = conteudo;
        for (int i = 0; i < temp.length(); i++)
        {
            if (isalpha(temp[i]))
            {
                char base = (isupper(temp[i])) ? 'A' : 'a';
                temp[i] = base + (temp[i] - base + 3) % 26;
            }
        }
        return temp;
    }

    /**
     * 09.) Cifra de Cesar (Decrypt). [cite: 275]
     */
    string decrypt()
    {
        string temp = conteudo;
        for (int i = 0; i < temp.length(); i++)
        {
            if (isalpha(temp[i]))
            {
                char base = (isupper(temp[i])) ? 'A' : 'a';
                // +26 garante que o resultado do modulo seja positivo em C++
                temp[i] = base + (temp[i] - base - 3 + 26) % 26;
            }
        }
        return temp;
    }

    /**
     * 10.) Split por espacos em branco. [cite: 280]
     */
    int split(string sequencia[])
    {
        string temp = "";
        int count = 0;
        for (int i = 0; i < conteudo.length(); i++)
        {
            if (conteudo[i] != ' ')
            {
                temp += conteudo[i];
            }
            else
            {
                if (temp.length() > 0)
                {
                    sequencia[count] = temp;
                    count++;
                    temp = "";
                }
            }
        }
        if (temp.length() > 0)
        {
            sequencia[count] = temp;
            count++;
        }
        return count;
    }

    /**
     * E1.) Split por delimitador customizado. [cite: 285]
     */
    int split(string sequencia[], char delimitador)
    {
        string temp = "";
        int count = 0;
        for (int i = 0; i < conteudo.length(); i++)
        {
            if (conteudo[i] != delimitador)
            {
                temp += conteudo[i];
            }
            else
            {
                if (temp.length() > 0)
                {
                    sequencia[count] = temp;
                    count++;
                    temp = "";
                }
            }
        }
        if (temp.length() > 0)
        {
            sequencia[count] = temp;
            count++;
        }
        return count;
    }

    /**
     * E2.) Inverter a string. [cite: 286]
     */
    string reverse()
    {
        string temp = "";
        for (int i = conteudo.length() - 1; i >= 0; i--)
        {
            temp += conteudo[i];
        }
        return temp;
    }
};

#endif