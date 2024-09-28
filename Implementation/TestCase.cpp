#include "TestCase.hpp"

//construtor de caso de teste
TestCase::TestCase(int numTypeAlloy_, int clientDemand_) {

    numTypeAlloy = numTypeAlloy_;
    clientDemand = clientDemand_;
    numAlloyAdded = 0;

    alloySizes = new int[numTypeAlloy];

}

//destrutor de caso de teste
TestCase::~TestCase() {

    delete[] alloySizes;

}

//adiciona novo tamanho 
//de liga metalica
void TestCase::addNewAlloySize(int newAlloySize) {

    //adiciona os tamanhos de liga
    //de tras pra frente no vetor
    alloySizes[numTypeAlloy - numAlloyAdded - 1] = newAlloySize;
    numAlloyAdded++;

}

//imprime todos os tamanhos 
//de liga metalica disponiveis
void TestCase::printAlloySizes() {

    cout << "------------------Start Print------------------" << endl;
    
    for (int i = 0; i < numTypeAlloy; i++) {

        cout << i << " --> " << alloySizes[i] << endl;

    }

    cout << "------------------End Print------------------" << endl;

}

int TestCase::getMinNumAlloysIter() {

    //cria uma tabela dinâmica (demands)
    //com o tamanho de clientDemand + 1 e
    //inicializa todos os valores como INF
    int *demands = new int[clientDemand + 1];

    for (int i = 0; i <= clientDemand; i++) {
        
        demands[i] = INF;

    }

    //a demanda 0 pode ser atendida 
    //sem usar qualquer liga, então 
    //a demanda[0] é definida como 0
    demands[0] = 0;

    //itera sobre todos os tamanhos de liga
    for (int i = 0; i < numTypeAlloy; i++) {

        //para cada tamanho de liga, itera sobre todas 
        //as possíveis demandas de clientes (que são 
        //maiores ou iguais ao tamanho da liga atual)
        for (int j = alloySizes[i]; j <= clientDemand; j++) {
            
            //se a demanda j - tamanho da 
            //liga atual pode ser atendida
            if (demands[j - alloySizes[i]] != INF) {
                
                //atualiza o valor de demands[j] se um 
                //menor número de ligas puder ser usado
                demands[j] = min(demands[j], demands[j - alloySizes[i]] + 1);

            }

        }

    }

    //pega o resultado da tabela DP. Se 
    //a demanda do cliente puder ser atendida, 
    //o resultado será diferente de INF.
    int result = demands[clientDemand];
    
    //desaloca a memória
    delete[] demands;

    //se a demanda do cliente não 
    //puder ser atendida (result == 
    //INF), retorna -1. Caso contrário, 
    //retorna o número mínimo de ligas.
    if (result == INF) {
 
        return -1;

    } else {

        return result;

    }

}

//encontra o numero minimo de ligas 
//(dentre os tamanhos de ligas disponiveis) 
//necessarias para atender a demanda do cliente
int TestCase::getMinNumAlloysRec() {

    //armazena o numero minimo de 
    //ligas (dentre os tamanhos de ligas 
    //disponiveis) necessarias para atender 
    //uma demanda correspondente ao indice
    int *demands = new int[clientDemand + 1];
    
    //inicializa todas as posicoes 
    //do vetor demanda[] com -1
    for (int currentDemand = 0; currentDemand < clientDemand + 1; currentDemand++) {

        demands[currentDemand] = -1;

        //-1 indica que o numero minimo
        //de ligas necessarias para atender uma
        //demanda correspondente ao indice
        //atual ainda não foi calculado

    }

    //calcula o o numero minimo de ligas 
    //(dentre os tamanhos de ligas disponiveis) 
    //necessarias para atender a demanda do cliente
    int numAlloys = recursiveGetMinNumAlloys(clientDemand, demands);

    //desaloca memoria
    delete[] demands;

    return numAlloys;

}

int TestCase::recursiveGetMinNumAlloys(int currentDemand, int *demands) {

    //casos base

    //se a demanda atual for zero
    if (currentDemand == 0) {

        //retorna zero
        return 0;

        //pois o numero minimo de ligas 
        //necessarias para atender a 
        //demanda do cliente eh zero

    }

    //se a demanda for menor que zero
    if (currentDemand < 0) {

        //retorna infinito
        return INF;

        //pois eh um valor invalido

    }

    //se a o numero min de ligas 
    //necessarias para atender a 
    //demanda atual ja foi calculado
    if (demands[currentDemand] != -1) {

        //retorna o valor 
        //que ja foi calculado
        return demands[currentDemand]; // -1

    }

    int menor, temp;

    //calcula o numero minimo de ligas necessarias 
    //para atender uma demanda de igual a:
    //(demanda atual) - (tamanho liga 0)
    //e armazena esse numero como o menor (por enquanto)
    menor = recursiveGetMinNumAlloys(currentDemand - alloySizes[0], demands);

    //para cada outro tipo de tamanho de liga metalica
    for (int currentAlloySize = 1; currentAlloySize < numTypeAlloy; currentAlloySize++) {
        
        //calcula o numero minimo de ligas necessarias 
        //para atender uma demanda de igual a:
        //(demanda atual) - (tamanho liga currentAlloySize)
        //e armazena esse numero em uma variavel temporaria
        temp = recursiveGetMinNumAlloys(currentDemand - alloySizes[currentAlloySize], demands);

        //se o numero minimo de ligas temporario 
        //for menor que o numero minimo de ligas atual
        if (temp < menor) {

            //torne o numero minimo de ligas temporario 
            //o novo numero minimo de ligas necessarias 
            //para atender a demanda do cliente
            menor = temp;

        }

    }

    //armazena o numero minimo de ligas (dentre
    //os tamanhos de ligas disponiveis) necessarias
    //para atender a demanda atual sendo processada
    demands[currentDemand] = 1 + menor;

    //retorna o numero minimo de ligas (dentre
    //os tamanhos de ligas disponiveis) necessarias
    //para atender a demanda atual do cliente
    return demands[currentDemand];

}