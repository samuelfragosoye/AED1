/*
 * Erro.hpp - v0.0. - 22 / 11 / 2025
 * Author: Samuel Fragoso
 */

#ifndef _ERRO_H_
#define _ERRO_H_

#include <string>

class Erro
{
private:
    int erro;

protected:
    /**
     * Metodo para estabelecer novo codigo de erro.
     * @param codigo de erro a ser guardado
     */
    void setErro(int codigo)
    {
        erro = codigo;
    } 

public:
    /**
     * Destrutor.
     */
    virtual ~Erro() {}

    /**
     * Construtor padrao.
     */
    Erro()
    {
        erro = 0;
    }

    // Constante da classe (simulada como estática ou apenas definição interna)
    // No C++ moderno, pode-se usar static constexpr, mas manterei simples.
    static const std::string NO_ERROR; 

    /**
     * Funcao para obter o codigo de erro.
     * @return codigo de erro guardado
     */
    int getErro()
    {
        return (erro);
    }

    /**
     * Funcao para testar se ha' erro.
     * @return true, se houver; false, caso contrario
     */
    bool hasErro()
    {
        return (getErro() != 0);
    }

    /**
     * Funcao virtual para obter mensagem relativa ao codigo de erro.
     * @return mensagem sobre o erro
     */
    virtual std::string getErroMsg()
    {
        return "";
    }
};

const std::string Erro::NO_ERROR = "[ERRO] Nao ha' erro.";

#endif