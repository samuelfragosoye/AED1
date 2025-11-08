/*
 * Erro.hpp - v0.0. - 08 / 11 / 2025
 * Author: Samuel Fragoso
 */

// ----------------------------------------------- definicoes globais
#ifndef _ERRO_H_
#define _ERRO_H_


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
    } // end setErro ()


public:
   
    ~Erro()
    {
    } // end destructor

 
    Erro()
    {
        erro = 0; 
    } 

    /**
     * Funcao para obter o codigo de erro. [cite: 54]
     * @return codigo de erro guardado [cite: 55]
     */
    int getErro()
    {
        return (erro); 
    } 


    bool hasErro()
    {
        return (getErro() != 0); 
    } 

}; 
#endif