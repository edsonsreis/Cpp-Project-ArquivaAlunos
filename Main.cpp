#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#define MAX 50
using namespace std;

const int STRMAX = 51;

struct Aluno
{

    char nome[STRMAX];
    int matricula;
    float nota;
};



void lerArq(Aluno alunos[],int&n ,char nomArq[]);
void imprime_alunos( Aluno alunos[], int n);
int verifica_string( Aluno alunos[], char s[], int n);


int main()
{

    Aluno alunos[MAX];
    int n, x;


    lerArq(alunos,n,"alunos.txt");

    char s[STRMAX];
    cin.getline(s, STRMAX);

    x = verifica_string(alunos,s,n);

    cout<<alunos[x].matricula<<" "<<alunos[x].nome<<" - "<<alunos[x].nota<<endl;

    return 0;

}




void lerArq(Aluno alunos[],int&n ,char nomArq[])
{
    fstream arq;
    arq.open(nomArq);
    if(!arq.is_open())
    {
        cout << "Erro: arquivo nao encontrado\n";
        exit(0); //sai do programa (biblioteca cstdlib)
    }


    arq>>n;




    for(int i=0; i<n; i++)
    {
        arq.ignore();
        arq.getline(alunos[i].nome, STRMAX);
        arq>>alunos[i].matricula;
        arq>>alunos[i].nota;


    }

}



void imprime_alunos( Aluno alunos[], int n)
{

    for(int i=0; i<n; i++)
    {

        cout<<alunos[i].matricula<<": "<<alunos[i].nome<<" - "<<alunos[i].nota<<endl;

    }
}

int verifica_string( Aluno alunos[], char s[], int n)
{


    for(int i=0; i<n; i++)
    {


        if(strcmp(alunos[i].nome, s)==0)
        {
            return i;

        }

    }
    return -1;

}



