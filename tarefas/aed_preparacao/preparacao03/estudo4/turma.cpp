#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Aluno {
private:
    int numero;
    string nome;
    int disciplinasCursadas;
public:
    Aluno(int num, string n){
        numero = num;
        nome = int n_fones;
        disciplinasCursadas=0;
    }

    Aluno(){
        numero = 0;
        nome = "";
        disciplinasCursadas = 0;
    }

    void adicionarDisciplina(){
        if(disciplinasCursadas < 10){
            disciplinasCursadas++;
        } else {
            cout << "Erro: limite de disciplinas atingido para o aluno" << endl;
        }
    }

    string getNome(){return nome;}
    int getNumero(){return numero;}
    int getQtdDisciplinas(){return disciplinasCursadas;}

};

class Turma {
    private:
    Aluno lista[30];
    int totalAlunos;
    public:
    Turma(){
        totalAlunos = 0;
    }
    void matricularAluno(Aluno novoAluno){
        if(totalAlunos<30){
            lista[totalAlunos] = novoAluno;
            totalAlunos++;
            cout<<"Aluno "<< novoAluno.getNome()<<" matriculado com sucesso."<<endl;
        } else {
            cout << "Turma cheia!"<<endl;
        }
    }
    void relatorioDisciplinas(){
        cout<<"\n--- Relatório de Alunos com mais de 3 disciplinas ---"<<endl;
        for(int i = 0; i<totalAlunos; i++){
            if(lista[i].getQtdDisciplinas()>3){
                cout<<"- "<<lista[i].getNome()<<endl;
            }
        }
    }
};

int main() {
    // 1. Criar a Turma (O Contentor)
    Turma turmaAED;

    // 2. Criar Objetos Aluno (Instanciação)
    Aluno a1(101, "Joana");
    Aluno a2(102, "Carlos");
    Aluno a3(103, "Ana");

    // 3. Modificar o estado dos objetos (Comportamento)
    // Vamos simular que a Ana fez muitas disciplinas
    for(int i=0; i<4; i++) {
        a3.adicionarDisciplina(); 
    }

    // 4. Interação entre Objetos: Passar o Aluno para dentro da Turma
    turmaAED.matricularAluno(a1);
    turmaAED.matricularAluno(a2);
    turmaAED.matricularAluno(a3);

    // 5. Gerar Relatório
    turmaAED.relatorioDisciplinas(); 

    return 0;
}