#ifndef TEST_CASE_HPP
#define TEST_CASE_HPP

#include <vector>
#include <iostream>

#define INF 0x3f3f3f3f

using namespace std;

class TestCase {

    private:

        //armazena o numero de diferentes 
        //tipos (tamanhos) de liga metalica,
        //a demanda do cliente, e quantos 
        //tipos de liga ja foram adicionados
        int numTypeAlloy, clientDemand, numAlloyAdded;
        int *alloySizes;

    public:

        //construtuor de caso de teste
        TestCase(int numTypeAlloy_, int clientDemand_);

        //adiciona novo tamanho 
        //de liga metalica
        void addNewAlloySize(int newAlloySize);

        //imprime todos os tamanhos 
        //de liga metalica disponiveis
        void printAlloySizes();

        //encontra o numero minimo de ligas 
        //(dentre os tamanhos de ligas disponiveis) 
        //necessarias para atender a demanda do cliente
        int getMinNumAlloysRec();

        int getMinNumAlloysIter();

        //funcao recursiva que 
        //auxilia getMinNumAlloys();
        int recursiveGetMinNumAlloys(int currentDemand, int *demands);

        //construtuor de caso de teste
        ~TestCase(); 

};

#endif