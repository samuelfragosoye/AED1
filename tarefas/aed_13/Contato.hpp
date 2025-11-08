/*
 * Contato.hpp - v0.0. - 08 / 11 / 2025
 * Author: Samuel Fragoso
 */

// ----------------------------------------------- definicoes globais
#ifndef _CONTATO_H_
#define _CONTATO_H_

// dependencias
#include <iostream>     // para cin, cout, endl [cite: 76-82]
#include <iomanip>      // para setw [cite: 83-85]
#include <string>       // para string [cite: 86-88]
#include <fstream>      // para ifstream, ofstream [cite: 89-92]
#include <algorithm>    // para std::find_if (usado em isValidPhone)

// outras dependencias
#include "Erro.hpp"     // classe para tratamento de erros [cite: 103]

// definicoes globais
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::string;
using std::ifstream;
using std::ofstream;

/**
 * Classe para tratar contatos, derivada da classe Erro. [cite: 106]
 */
class Contato : public Erro
{
/**
 * atributos privados. [cite: 110]
 */
private:
    string nome; 
    static const int MAX_FONES = 10; // (E1) [cite: 646]
    string fones[MAX_FONES];         // (E1) [cite: 648]
    int n_fones;                     // (1317) [cite: 623, 648]
    string end_residencial;          // (E2) [cite: 650]
    string end_profissional;         // (E2) [cite: 650]

    /**
     * (1313) Metodo privado para testar se fone e' valido. [cite: 601]
     * DICA: Testar se as posições contêm apenas algarismos e o símbolo '-'. [cite: 603]
     */
    bool isValidPhone(string phone)
    {
        if (phone.empty())
        {
            return false;
        }
        // Itera por cada caractere da string
        for (const char c : phone)
        {
            // Se nao for digito E nao for '-', e' invalido
            if (!isdigit(c) && c != '-')
            {
                return false;
            }
        }
        return true;
    } // end isValidPhone ()

/**
 * definicoes publicas. [cite: 115]
 */
public:
    /**
     * Destrutor. [cite: 118]
     */
    ~Contato()
    {
    } // end destructor

    /**
     * Construtor padrao. [cite: 123]
     */
    Contato()
    {
        setErro(0); // (08) [cite: 333]
        nome = "";  // (01) [cite: 127]
        n_fones = 0; // (E1)
        end_residencial = "";  // (E2)
        end_profissional = ""; // (E2)
    } // end constructor (padrao)

    /**
     * (06) Construtor alternativo. [cite: 294]
     */
    Contato(std::string nome_inicial, std::string fone_inicial)
    {
        setErro(0); // (08) [cite: 366]
        n_fones = 0;
        end_residencial = "";
        end_profissional = "";
        setNome(nome_inicial);   // (08) [cite: 368]
        addFone(fone_inicial); // (E1)
    } // end constructor (alternativo 1)

    /**
     * (1316) Construtor alternativo (2 telefones). [cite: 621]
     */
    Contato(std::string nome_inicial, std::string fone1, std::string fone2)
    {
        setErro(0);
        n_fones = 0;
        end_residencial = "";
        end_profissional = "";
        setNome(nome_inicial);
        addFone(fone1);
        addFone(fone2);
    } // end constructor (alternativo 2)

    /**
     * (15) Construtor alternativo baseado em copia. [cite: 469]
     */
    Contato(const Contato &another)
    {
        setErro(0); // (15) [cite: 473]
        // copiar atributos
        setNome(another.nome); // (15) [cite: 475]
        
        // (E1) Copiar array de telefones
        this->n_fones = another.n_fones;
        for (int x = 0; x < this->n_fones; x = x + 1)
        {
            this->fones[x] = another.fones[x];
        }
        
        // (E2) Copiar enderecos
        this->end_residencial = another.end_residencial;
        this->end_profissional = another.end_profissional;
    } // end constructor (copia)

    /**
     * (04) Metodo para atribuir nome. [cite: 218]
     * (08) Com tratamento de erro. [cite: 339]
     */
    void setNome(std::string nome)
    {
        if (nome.empty())
        {
            setErro(1); // nome invalido [cite: 345]
        }
        else
        {
            this->nome = nome; 
        }
    } // end setNome ()

    /**
     * (04) Funcao para obter nome. [cite: 230]
     */
    std::string getNome()
    {
        return (this->nome); 
    } // end getNome ()

    /**
     * (E1 / 1319) Metodo para atribuir fone em um indice. [cite: 635]
     */
    void setFone(int index, std::string fone)
    {
        if (index < 0 || index >= n_fones)
        {
            setErro(5); // Indice invalido
        }
        else if (fone.empty())
        {
            setErro(2); // fone invalido [cite: 355]
        }
        else if (!isValidPhone(fone))
        {
            setErro(3); // fone invalido (formato)
        }
        else
        {
            this->fones[index] = fone;
        }
    } // end setFone ()

    /**
     * (04) Metodo para atribuir o *primeiro* telefone (compatibilidade). [cite: 224]
     */
    void setFone(std::string fone)
    {
        if (n_fones == 0) // Se nao tem fone, adiciona
        {
            addFone(fone);
        }
        else // Se tem, modifica o primeiro
        {
            setFone(0, fone);
        }
    } // end setFone (compatibilidade)

    /**
     * (E1 / 1318) Metodo para adicionar novo fone. [cite: 628]
     */
    bool addFone(std::string fone)
    {
        if (n_fones >= MAX_FONES)
        {
            setErro(4); // Limite alcancado
            return false;
        }
        else if (fone.empty())
        {
            setErro(2); // fone invalido
            return false;
        }
        else if (!isValidPhone(fone))
        {
            setErro(3); // fone invalido (formato)
            return false;
        }
        else
        {
            this->fones[n_fones] = fone;
            n_fones = n_fones + 1;
            setErro(0); // Sucesso
            return true;
        }
    } // end addFone ()

    /**
     * (E1 / 1320) Metodo para remover fone de um indice. [cite: 640]
     */
    void removeFone(int index)
    {
        if (index < 0 || index >= n_fones)
        {
            setErro(6); // Indice invalido ou array vazio
        }
        else
        {
            // Desloca todos os elementos a partir do indice
            for (int x = index; x < n_fones - 1; x = x + 1)
            {
                fones[x] = fones[x + 1];
            }
            n_fones = n_fones - 1; // Decrementa contagem
            setErro(0); // Sucesso
        }
    } // end removeFone ()

    /**
     * (E1) Funcao para obter fone de um indice.
     */
    std::string getFone(int index)
    {
        if (index < 0 || index >= n_fones)
        {
            setErro(5); // Indice invalido
            return ("");
        }
        else
        {
            return (this->fones[index]);
        }
    } // end getFone (index)

    /**
     * (04) Funcao para obter o *primeiro* fone (compatibilidade). [cite: 236]
     */
    std::string getFone()
    {
        return (getFone(0));
    } // end getFone ()

    /**
     * (1317) Funcao para obter quantos telefones. [cite: 623]
     */
    int phones()
    {
        return (n_fones); 
    } // end phones ()

    /**
     * (E2) Metodos para Endereco Residencial. [cite: 650]
     */
    void setEndResidencial(std::string end)
    {
        this->end_residencial = end;
    }
    std::string getEndResidencial()
    {
        return (this->end_residencial);
    }

    /**
     * (E2) Metodos para Endereco Profissional. [cite: 650]
     */
    void setEndProfissional(std::string end)
    {
        this->end_profissional = end;
    }
    std::string getEndProfissional()
    {
        return (this->end_profissional);
    }

    /**
     * (05) Funcao para obter dados de uma pessoa. [cite: 264]
     * (E1+E2) Atualizado para multiplos fones e enderecos.
     */
    std::string toString()
    {
        std::string fones_str = "";
        for (int x = 0; x < n_fones; x = x + 1)
        {
            fones_str = fones_str + fones[x];
            if (x < n_fones - 1)
                fones_str = fones_str + ", ";
        }

        return ("{" + getNome() + ", " +
                "Fones: [" + fones_str + "], " +
                "End: [R: " + getEndResidencial() + ", P: " + getEndProfissional() + "]" +
                "}");
    } // end toString()

    /**
     * (1311) Ler do teclado e atribuir nome. [cite: 591]
     */
    void readName(std::string prompt)
    {
        std::string temp_name = "";
        cout << prompt;
        std::getline(cin, temp_name); // Usar getline para ler nomes com espaco
        setNome(temp_name);
    } // end readName ()

    /**
     * (1312) Ler do teclado e adicionar fone. [cite: 596]
     */
    void readAndAddFone(std::string prompt)
    {
        std::string temp_fone = "";
        cout << prompt;
        std::getline(cin, temp_fone);
        if (!addFone(temp_fone))
        {
            cout << "ERRO: Telefone invalido ou limite atingido. (Erro: " << getErro() << ")" << endl;
        }
    } // end readAndAddFone ()

    /**
     * (1314) Ler dados de arquivo. [cite: 605]
     * (E1+E2) Atualizado.
     */
    void readFromFile(std::string fileName)
    {
        ifstream afile;
        std::string temp_nome, temp_fone, temp_endR, temp_endP;
        int temp_n_fones = 0;

        afile.open(fileName);
        if (afile.is_open())
        {
            setErro(0);
            std::getline(afile, temp_nome);
            afile >> temp_n_fones;
            afile.ignore(); // Consome o '\n' apos o numero

            // (E2) Ler enderecos
            std::getline(afile, temp_endR);
            std::getline(afile, temp_endP);

            // Limpa dados antigos
            setNome(temp_nome);
            n_fones = 0;
            setEndResidencial(temp_endR);
            setEndProfissional(temp_endP);

            // Le telefones
            for (int x = 0; x < temp_n_fones; x = x + 1)
            {
                std::getline(afile, temp_fone);
                addFone(temp_fone);
            }
        }
        else
        {
            setErro(7); // Erro de arquivo
        }
        afile.close();
    } // end readFromFile ()

    /**
     * (1315) Gravar dados em arquivo. [cite: 610]
     * (E1+E2) Atualizado.
     */
    void writeToFile(std::string fileName)
    {
        ofstream afile;
        afile.open(fileName);
        if (afile.is_open())
        {
            afile << getNome() << endl;
            afile << phones() << endl; // (1317)
            
            // (E2) Grava enderecos
            afile << getEndResidencial() << endl;
            afile << getEndProfissional() << endl;

            // (E1) Grava telefones
            for (int x = 0; x < phones(); x = x + 1)
            {
                afile << getFone(x) << endl;
            }
        }
        else
        {
            setErro(7); // Erro de arquivo
        }
        afile.close();
    } // end writeToFile ()

}; // fim da classe Contato [cite: 130]

using ref_Contato = Contato *; // [cite: 131]
#endif