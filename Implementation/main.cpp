#include "TestCase.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    
    int numTestCases, numTypeAlloy, clientDemand, alloySize;
    
    //le quantos casos 
    //de teste haverao
    cin >> numTestCases;

    //itera pelos casos de teste
    for (int currentTestCaseNum = 0; currentTestCaseNum < numTestCases; currentTestCaseNum++) {

        // le a demanda e o numero 
        //de tipos de liga metalica
        cin >> numTypeAlloy >> clientDemand;

        //cria um novo caso de teste
        TestCase currentTestCase = TestCase(numTypeAlloy, clientDemand);

        //para cada tipo 
        //de liga metalica
        for (int currentAlloyType = 0; currentAlloyType < numTypeAlloy; currentAlloyType++) {

            //le o tamanho da liga
            cin >> alloySize;

            //adiciona novo tamanho de liga
            currentTestCase.addNewAlloySize(alloySize);

        }

        //printa o numero minimo de ligas 
        //(dentre os tamanhos de ligas disponiveis) 
        //necessario para atender a demanda do cliente
        cout << currentTestCase.getMinNumAlloysIter() << endl;

    }
    
    return 0;

}
