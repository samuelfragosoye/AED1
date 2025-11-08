/*
 * Exemplo1300 - v0.0. - 08 / 11 / 2025
 * Author: Samuel Fragoso
 *
 * Para compilar em terminal (janela de comandos):
 * Linux   : g++ -o Exemplo1300 Exemplo1300.cpp
 * Windows : g++ -o Exemplo1300 Exemplo1300.cpp
 *
 * Para executar em terminal (janela de comandos):
 * Linux   : ./Exemplo1300
 * Windows : Exemplo1300
 */

// ----------------------------------------------- classes
#include "Contato.hpp"

using namespace std;

void pause(string text)
{
    string dummy;
    cin.clear();
    cout << endl << text;
    cin.ignore();
    getline(cin, dummy);
    cout << endl << endl;
}

void method_00()
{
}

void method_01()
{
    Contato pessoa1;
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato();

    cout << "\nMethod 01 - v0.0\n" << endl;
    
    cout << "Testando criacao de objetos..." << endl;
    cout << "pessoa1 (estatico): " << pessoa1.toString() << endl;
    cout << "pessoa3 (dinamico): " << pessoa3->toString() << endl;

    delete pessoa3;
    pause("Apertar ENTER para continuar");
}

void method_02()
{
    Contato pessoa1;
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato();

    cout << "\nMethod_02 - v0.0\n" << endl;

    pessoa1.setNome("Pessoa_01");
    pessoa1.setFone("111-1111");
    pessoa3->setNome("Pessoa_03");
    pessoa3->setFone("333-3333");

    cout << "pessoa1 - " << pessoa1.toString() << endl;
    cout << "pessoa3 - " << pessoa3->toString() << endl;

    delete pessoa3;
    pause("Apertar ENTER para continuar");
}

void method_03()
{
    Contato pessoa1;
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato();

    cout << "\nMethod_03 - v0.0\n" << endl;

    pessoa1.setNome("Pessoa_01");
    pessoa1.setFone("111-1111");
    pessoa3->setNome("Pessoa_03");
    pessoa3->setFone("333-3333");

    cout << "pessoa1 - " << pessoa1.toString() << endl;
    cout << "pessoa3 - " << pessoa3->toString() << endl;

    delete pessoa3;
    pause("Apertar ENTER para continuar");
}

void method_04()
{
    Contato pessoa1("Pessoa_01", "111-1111");
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato("Pessoa_03", "333-3333");

    cout << "\nMethod_04 - v0.0\n" << endl;

    cout << "pessoa1 - " << pessoa1.toString() << endl;
    cout << "pessoa3 - " << pessoa3->toString() << endl;

    delete pessoa3;
    pause("Apertar ENTER para continuar");
}

void method_05()
{
    Contato pessoa1("Pessoa_01", "111-1111");
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato("", "333-3333");

    cout << "\nMethod_05 - v0.0\n" << endl;

    cout << "pessoa1 - " << pessoa1.toString() << " (" << pessoa1.getErro() << ")" << endl;
    cout << "pessoa3 - " << pessoa3->toString() << " (" << pessoa3->getErro() << ")" << endl;

    delete pessoa3;
    pause("Apertar ENTER para continuar");
}

void method_06()
{
    Contato pessoa1("Pessoa_01", "111-1111");
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato("", "333-3333");

    cout << "\nMethod_06 - v0.0\n" << endl;

    if (!pessoa1.hasErro())
        cout << "pessoa1 - " << pessoa1.toString() << endl;
    else
        cout << "pessoa1 tem erro (" << pessoa1.getErro() << ")" << endl;

    if (!pessoa3->hasErro())
        cout << "pessoa3 - " << pessoa3->toString() << endl;
    else
        cout << "pessoa3 tem erro (" << pessoa3->getErro() << ")" << endl;

    delete pessoa3;
    pause("Apertar ENTER para continuar");
}

void method_07()
{
    Contato pessoa1("Pessoa_01", "111-1111");
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato("", "333-3333");

    cout << "\nMethod_07 - v0.0\n" << endl;

    pessoa2 = &pessoa1;
    if (!pessoa2->hasErro())
        cout << "pessoa1 (via p2) - " << pessoa2->toString() << endl;
    else
        cout << "pessoa1 (via p2) tem erro (" << pessoa2->getErro() << ")" << endl;

    pessoa2 = pessoa3;
    if (!pessoa2->hasErro())
        cout << "pessoa3 (via p2) - " << pessoa2->toString() << endl;
    else
        cout << "pessoa3 (via p2) tem erro (" << pessoa2->getErro() << ")" << endl;

    delete pessoa3;
    pause("Apertar ENTER para continuar");
}

void method_08()
{
    Contato pessoa1("Pessoa_01", "111-1111");
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato("", "333-3333");
    ref_Contato pessoa4 = nullptr;

    cout << "\nMethod_08 - v0.0\n" << endl;

    pessoa2 = new Contato(pessoa1);
    if (pessoa2)
        cout << "pessoa2 (copia p1) - " << pessoa2->toString() << endl;
    else
        cout << "pessoa2 tem erro (" << pessoa2->getErro() << ")" << endl;

    if (pessoa3)
    {
        pessoa2 = new Contato(*pessoa3);
        if (pessoa2)
            cout << "pessoa2 (copia p3) - " << pessoa2->toString() << endl;
        else
            cout << "pessoa2 tem erro (" << pessoa3->getErro() << ")" << endl;
    }

    if (pessoa4)
    {
        cout << "pessoa4 nao existe, teste pulado." << endl;
    }

    delete pessoa2;
    delete pessoa3;
    pause("Apertar ENTER para continuar");
}

void method_09()
{
    Contato pessoa[3];
    int x = 0;

    cout << "\nMethod_09 - v0.0\n" << endl;

    pessoa[0].setNome("Pessoa_1");
    pessoa[0].setFone("111-1111");
    pessoa[1].setNome("Pessoa_2");
    pessoa[1].setFone("222-2222");
    pessoa[2].setNome("Pessoa_3");
    pessoa[2].setFone("333-3333");

    for (x = 0; x < 3; x = x + 1)
    {
        cout << x << ": " << pessoa[x].toString() << endl;
    }

    pause("Apertar ENTER para continuar");
}

void method_10()
{
    Contato *pessoa[3];
    int x = 0;

    cout << "\nMethod_10 - v0.0\n" << endl;

    pessoa[0] = new Contato("Pessoa_1", "111-1111");
    pessoa[1] = new Contato("Pessoa_2", "222-2222");
    pessoa[2] = new Contato("Pessoa_3", "333-3333");

    for (x = 0; x < 3; x = x + 1)
    {
        cout << x << ": " << pessoa[x]->toString() << endl;
    }

    for (x = 0; x < 3; x = x + 1)
    {
        delete pessoa[x];
    }
    pause("Apertar ENTER para continuar");
}

void method_11()
{
    Contato pessoa;

    cout << "\nMethod_11 - v0.0\n" << endl;
    
    pessoa.readName("Digite o nome: ");
    cout << "\nContato lido: " << pessoa.toString() << endl;
    cout << "Erro: " << pessoa.getErro() << endl;

    cout << "\nTestando nome vazio..." << endl;
    pessoa.readName("Digite o nome (ENTER para vazio): ");
    cout << "\nContato lido: " << pessoa.toString() << endl;
    cout << "Erro: " << pessoa.getErro() << endl;

    pause("Apertar ENTER para continuar");
}

void method_12()
{
    Contato pessoa;
    pessoa.setNome("Pessoa_12");

    cout << "\nMethod_12 - v0.0\n" << endl;
    
    pessoa.readAndAddFone("Digite o fone: ");
    cout << "\nContato lido: " << pessoa.toString() << endl;
    cout << "Erro: " << pessoa.getErro() << endl;

    cout << "\nTestando fone vazio..." << endl;
    pessoa.readAndAddFone("Digite o fone (ENTER para vazio): ");
    cout << "\nContato: " << pessoa.toString() << endl;

    pause("Apertar ENTER para continuar");
}

void method_13()
{
    Contato pessoa;
    pessoa.setNome("Pessoa_13");

    cout << "\nMethod_13 - v0.0\n" << endl;
    
    cout << "Testando fone invalido ('123-abc')..." << endl;
    pessoa.addFone("123-abc");
    cout << "Erro: " << pessoa.getErro() << " (Esperado: 3)" << endl;
    cout << "Contato: " << pessoa.toString() << endl;

    cout << "\nTestando fone valido ('9999-8888')..." << endl;
    pessoa.addFone("9999-8888");
    cout << "Erro: " << pessoa.getErro() << " (Esperado: 0)" << endl;
    cout << "Contato: " << pessoa.toString() << endl;

    pause("Apertar ENTER para continuar");
}

void method_14()
{
    Contato pessoa;
    string fileName = "PESSOA1.TXT";

    cout << "\nMethod_14 - v0.0\n" << endl;
    
    cout << "Lendo dados do arquivo '" << fileName << "'..." << endl;
    pessoa.readFromFile(fileName);

    if (pessoa.hasErro())
    {
        cout << "ERRO ao ler o arquivo. (Execute o method 15 primeiro)" << endl;
    }
    else
    {
        cout << "Contato lido: " << pessoa.toString() << endl;
    }

    pause("Apertar ENTER para continuar");
}

void method_15()
{
    Contato pessoa("Pessoa_15", "1515-1515");
    pessoa.addFone("5151-5151");
    pessoa.setEndResidencial("Rua 15");
    string fileName = "PESSOA1.TXT";

    cout << "\nMethod_15 - v0.0\n" << endl;
    
    cout << "Gravando dados no arquivo '" << fileName << "'..." << endl;
    cout << "Contato: " << pessoa.toString() << endl;
    pessoa.writeToFile(fileName);

    if (pessoa.hasErro())
    {
        cout << "ERRO ao gravar o arquivo." << endl;
    }
    else
    {
        cout << "Gravacao concluida." << endl;
    }

    pause("Apertar ENTER para continuar");
}

void method_16()
{
    cout << "\nMethod_16 - v0.0\n" << endl;
    
    Contato pessoa("Pessoa_16", "1616-1616", "6161-6161");
    cout << "Contato: " << pessoa.toString() << endl;
    cout << "Erro: " << pessoa.getErro() << endl;

    pause("Apertar ENTER para continuar");
}

void method_17()
{
    cout << "\nMethod_17 - v0.0\n" << endl;
    
    Contato pessoa("Pessoa_17", "1717-1717", "7171-7171");
    pessoa.addFone("7777-1111");

    cout << "Contato: " << pessoa.toString() << endl;
    cout << "Numero de telefones: " << pessoa.phones() << " (Esperado: 3)" << endl;

    pause("Apertar ENTER para continuar");
}

void method_18()
{
    cout << "\nMethod_18 - v0.0\n" << endl;
    
    Contato pessoa("Pessoa_18", "1818-1818");
    cout << "Contato Original: " << pessoa.toString() << endl;
    
    cout << "\nAdicionando '8181-8181'..." << endl;
    pessoa.addFone("8181-8181");
    
    cout << "Contato Modificado: " << pessoa.toString() << endl;
    cout << "Erro: " << pessoa.getErro() << endl;

    pause("Apertar ENTER para continuar");
}

void method_19()
{
    cout << "\nMethod_19 - v0.0\n" << endl;
    
    Contato pessoa("Pessoa_19", "1919-1919", "9191-9191");
    cout << "Contato Original: " << pessoa.toString() << endl;
    
    cout << "\nAlterando fone 2 (indice 1) para '9999-9999'..." << endl;
    pessoa.setFone(1, "9999-9999");
    
    cout << "Contato Modificado: " << pessoa.toString() << endl;
    cout << "Erro: " << pessoa.getErro() << endl;

    cout << "\nTentando alterar fone 5 (indice 4)..." << endl;
    pessoa.setFone(4, "4444-4444");
    cout << "Erro: " << pessoa.getErro() << " (Esperado: 5)" << endl;

    pause("Apertar ENTER para continuar");
}

void method_20()
{
    cout << "\nMethod_20 - v0.0\n" << endl;
    
    Contato pessoa("Pessoa_20", "2020-2020", "0202-0202");
    pessoa.addFone("0022-0022");
    cout << "Contato Original: " << pessoa.toString() << endl;
    
    cout << "\nRemovendo fone 2 (indice 1)..." << endl;
    pessoa.removeFone(1);
    
    cout << "Contato Modificado: " << pessoa.toString() << endl;
    cout << "Erro: " << pessoa.getErro() << endl;

    cout << "\nTentando remover fone 5 (indice 4)..." << endl;
    pessoa.removeFone(4);
    cout << "Erro: " << pessoa.getErro() << " (Esperado: 6)" << endl;

    pause("Apertar ENTER para continuar");
}

void method_21()
{
    cout << "\nMethod_21 - v0.0\n" << endl;
    
    Contato pessoa("Pessoa_21", "");
    cout << "Adicionando 10 telefones..." << endl;

    for (int x = 0; x < 10; x = x + 1)
    {
        pessoa.addFone("0000-" + std::to_string(x));
    }
    cout << "Contato: " << pessoa.toString() << endl;
    cout << "Telefones: " << pessoa.phones() << endl;
    cout << "Erro: " << pessoa.getErro() << endl;

    cout << "\nTentando adicionar 11o telefone..." << endl;
    pessoa.addFone("1111-1111");
    cout << "Erro: " << pessoa.getErro() << " (Esperado: 4)" << endl;

    pause("Apertar ENTER para continuar");
}

void method_22()
{
    cout << "\nMethod_22 - v0.0\n" << endl;
    
    Contato pessoa("Pessoa_22", "2222-2222");
    cout << "Contato Original: " << pessoa.toString() << endl;

    cout << "\nAdicionando enderecos..." << endl;
    pessoa.setEndResidencial("Rua A, 123");
    pessoa.setEndProfissional("Rua B, 456");

    cout << "Contato Modificado: " << pessoa.toString() << endl;
    cout << "\nEndereco Residencial: " << pessoa.getEndResidencial() << endl;
    cout << "Endereco Profissional: " << pessoa.getEndProfissional() << endl;

    cout << "\n(Gravacao/Leitura de enderecos e' testada nos metodos 14 e 15)" << endl;

    pause("Apertar ENTER para continuar");
}

int main(int argc, char **argv)
{
    int x = 0;

    do
    {
        cout << "EXEMPLO1300 - Programa - v0.0\n" << endl;

        cout << "Opcoes:" << endl;
        cout << " 0 - parar" << endl;
        cout << " 1 - Method_01 (Testar criacao de objetos)" << endl;
        cout << " 2 - Method_02 (Testar atribuicoes set/get)" << endl;
        cout << " 3 - Method_03 (Testar toString)" << endl;
        cout << " 4 - Method_04 (Testar construtor alternativo)" << endl;
        cout << " 5 - Method_05 (Testar erro (nome vazio))" << endl;
        cout << " 6 - Method_06 (Testar hasErro())" << endl;
        cout << " 7 - Method_07 (Testar referencia de objeto)" << endl;
        cout << " 8 - Method_08 (Testar construtor de copia)" << endl;
        cout << " 9 - Method_09 (Testar arranjo de objetos)" << endl;
        cout << "10 - Method_10 (Testar arranjo de referencias)" << endl;
        cout << "11 - Method_11 (Ex 1311: Testar readName)" << endl;
        cout << "12 - Method_12 (Ex 1312: Testar readAndAddFone)" << endl;
        cout << "13 - Method_13 (Ex 1313: Testar isValidPhone)" << endl;
        cout << "14 - Method_14 (Ex 1314: Testar readFromFile)" << endl;
        cout << "15 - Method_15 (Ex 1315: Testar writeToFile)" << endl;
        cout << "16 - Method_16 (Ex 1316: Testar construtor 2 fones)" << endl;
        cout << "17 - Method_17 (Ex 1317: Testar phones())" << endl;
        cout << "18 - Method_18 (Ex 1318: Testar addFone (2o fone))" << endl;
        cout << "19 - Method_19 (Ex 1319: Testar setFone (indice 1))" << endl;
        cout << "20 - Method_20 (Ex 1320: Testar removeFone (indice 1))" << endl;
        cout << "21 - Method_21 (Ex E1: Testar limite de fones)" << endl;
        cout << "22 - Method_22 (Ex E2: Testar enderecos)" << endl;

        cout << endl << "Entrar com uma opcao: ";
        cin >> x;
        cin.ignore(1000, '\n');

        // escolher acao
        switch (x)
        {
        case 0:
            method_00(); 
            /*
            (Nenhuma saida)
            */
            break;
        case 1:
            method_01(); 
            /*
            Method 01 - v0.0

            Testando criacao de objetos...
            pessoa1 (estatico): {, Fones: [], End: [R: , P: ]}
            pessoa3 (dinamico): {, Fones: [], End: [R: , P: ]}

            Apertar ENTER para continuar
            */
            break;
        case 2:
            method_02();
            /*
            Method_02 - v0.0

            pessoa1 - {Pessoa_01, Fones: [111-1111], End: [R: , P: ]}
            pessoa3 - {Pessoa_03, Fones: [333-3333], End: [R: , P: ]}

            Apertar ENTER para continuar
            */
            break;
        case 3:
            method_03();
            /*
            Method_03 - v0.0

            pessoa1 - {Pessoa_01, Fones: [111-1111], End: [R: , P: ]}
            pessoa3 - {Pessoa_03, Fones: [333-3333], End: [R: , P: ]}

            Apertar ENTER para continuar
            */
            break;
        case 4:
            method_04();
            /*
            Method_04 - v0.0

            pessoa1 - {Pessoa_01, Fones: [111-1111], End: [R: , P: ]}
            pessoa3 - {Pessoa_03, Fones: [333-3333], End: [R: , P: ]}

            Apertar ENTER para continuar
            */
            break;
        case 5:
            method_05();
            /*
            Method_05 - v0.0

            pessoa1 - {Pessoa_01, Fones: [111-1111], End: [R: , P: ]} (0)
            pessoa3 - {, Fones: [], End: [R: , P: ]} (1)

            Apertar ENTER para continuar
            */
            break;
        case 6:
            method_06();
            /*
            Method_06 - v0.0

            pessoa1 - {Pessoa_01, Fones: [111-1111], End: [R: , P: ]}
            pessoa3 tem erro (1)

            Apertar ENTER para continuar
            */
            break;
        case 7:
            method_07();
            /*
            Method_07 - v0.0

            pessoa1 (via p2) - {Pessoa_01, Fones: [111-1111], End: [R: , P: ]}
            pessoa3 (via p2) tem erro (1)

            Apertar ENTER para continuar
            */
            break;
        case 8:
            method_08();
            /*
            Method_08 - v0.0

            pessoa2 (copia p1) - {Pessoa_01, Fones: [111-1111], End: [R: , P: ]}
            pessoa2 (copia p3) - {, Fones: [], End: [R: , P: ]}

            Apertar ENTER para continuar
            */
            break;
        case 9:
            method_09();
            /*
            Method_09 - v0.0

            0: {Pessoa_1, Fones: [111-1111], End: [R: , P: ]}
            1: {Pessoa_2, Fones: [222-2222], End: [R: , P: ]}
            2: {Pessoa_3, Fones: [333-3333], End: [R: , P: ]}

            Apertar ENTER para continuar
            */
            break;
        case 10:
            method_10();
            /*
            Method_10 - v0.0

            0: {Pessoa_1, Fones: [111-1111], End: [R: , P: ]}
            1: {Pessoa_2, Fones: [222-2222], End: [R: , P: ]}
            2: {Pessoa_3, Fones: [333-3333], End: [R: , P: ]}

            Apertar ENTER para continuar
            */
            break;
        case 11:
            method_11();
            /* (Supondo entrada: "Joao Silva" e depois "")
            Method_11 - v0.0

            Digite o nome: Joao Silva

            Contato lido: {Joao Silva, Fones: [], End: [R: , P: ]}
            Erro: 0

            Testando nome vazio...
            Digite o nome (ENTER para vazio): 

            Contato lido: {Joao Silva, Fones: [], End: [R: , P: ]}
            Erro: 1

            Apertar ENTER para continuar
            */
            break;
        case 12:
            method_12();
            /* (Supondo entrada: "9876-5432" e depois "")
            Method_12 - v0.0

            Digite o fone: 9876-5432

            Contato lido: {Pessoa_12, Fones: [9876-5432], End: [R: , P: ]}
            Erro: 0

            Testando fone vazio...
            Digite o fone (ENTER para vazio): 
            ERRO: Telefone invalido ou limite atingido. (Erro: 2)

            Contato: {Pessoa_12, Fones: [9876-5432], End: [R: , P: ]}

            Apertar ENTER para continuar
            */
            break;
        case 13:
            method_13();
            /*
            Method_13 - v0.0

            Testando fone invalido ('123-abc')...
            Erro: 3 (Esperado: 3)
            Contato: {Pessoa_13, Fones: [], End: [R: , P: ]}

            Testando fone valido ('9999-8888')...
            Erro: 0 (Esperado: 0)
            Contato: {Pessoa_13, Fones: [9999-8888], End: [R: , P: ]}

            Apertar ENTER para continuar
            */
            break;
        case 14:
            method_14();
            /* (Supondo que method 15 foi executado)
            Method_14 - v0.0

            Lendo dados do arquivo 'PESSOA1.TXT'...
            Contato lido: {Pessoa_15, Fones: [1515-1515, 5151-5151], End: [R: Rua 15, P: ]}

            Apertar ENTER para continuar
            */
            break;
        case 15:
            method_15();
            /*
            Method_15 - v0.0

            Gravando dados no arquivo 'PESSOA1.TXT'...
            Contato: {Pessoa_15, Fones: [1515-1515, 5151-5151], End: [R: Rua 15, P: ]}
            Gravacao concluida.

            Apertar ENTER para continuar
            */
            break;
        case 16:
            method_16();
            /*
            Method_16 - v0.0

            Contato: {Pessoa_16, Fones: [1616-1616, 6161-6161], End: [R: , P: ]}
            Erro: 0

            Apertar ENTER para continuar
            */
            break;
        case 17:
            method_17();
            /*
            Method_17 - v0.0

            Contato: {Pessoa_17, Fones: [1717-1717, 7171-7171, 7777-1111], End: [R: , P: ]}
            Numero de telefones: 3 (Esperado: 3)

            Apertar ENTER para continuar
            */
            break;
        case 18:
            method_18();
            /*
            Method_18 - v0.0

            Contato Original: {Pessoa_18, Fones: [1818-1818], End: [R: , P: ]}

            Adicionando '8181-8181'...
            Contato Modificado: {Pessoa_18, Fones: [1818-1818, 8181-8181], End: [R: , P: ]}
            Erro: 0

            Apertar ENTER para continuar
            */
            break;
        case 19:
            method_19();
            /*
            Method_19 - v0.0

            Contato Original: {Pessoa_19, Fones: [1919-1919, 9191-9191], End: [R: , P: ]}

            Alterando fone 2 (indice 1) para '9999-9999'...
            Contato Modificado: {Pessoa_19, Fones: [1919-1919, 9999-9999], End: [R: , P: ]}
            Erro: 0

            Tentando alterar fone 5 (indice 4)...
            Erro: 5 (Esperado: 5)

            Apertar ENTER para continuar
            */
            break;
        case 20:
            method_20();
            /*
            Method_20 - v0.0

            Contato Original: {Pessoa_20, Fones: [2020-2020, 0202-0202, 0022-0022], End: [R: , P: ]}

            Removendo fone 2 (indice 1)...
            Contato Modificado: {Pessoa_20, Fones: [2020-2020, 0022-0022], End: [R: , P: ]}
            Erro: 0

            Tentando remover fone 5 (indice 4)...
            Erro: 6 (Esperado: 6)

            Apertar ENTER para continuar
            */
            break;
        case 21:
            method_21();
            /*
            Method_21 - v0.0

            Adicionando 10 telefones...
            Contato: {Pessoa_21, Fones: [0000-0, 0000-1, 0000-2, 0000-3, 0000-4, 0000-5, 0000-6, 0000-7, 0000-8, 0000-9], End: [R: , P: ]}
            Telefones: 10
            Erro: 0

            Tentando adicionar 11o telefone...
            Erro: 4 (Esperado: 4)

            Apertar ENTER para continuar
            */
            break;
        case 22:
            method_22();
            /*
            Method_22 - v0.0

            Contato Original: {Pessoa_22, Fones: [2222-2222], End: [R: , P: ]}

            Adicionando enderecos...
            Contato Modificado: {Pessoa_22, Fones: [2222-2222], End: [R: Rua A, 123, P: Rua B, 456]}

            Endereco Residencial: Rua A, 123
            Endereco Profissional: Rua B, 456

            (Gravacao/Leitura de enderecos e' testada nos metodos 14 e 15)

            Apertar ENTER para continuar
            */
            break;
        default:
            cout << endl
                 << "ERRO: Valor invalido." << endl; 
        } // end switch
    } while (x != 0);

    // encerrar
    pause("Apertar ENTER para terminar"); 
    return (0); 
} // end main ()