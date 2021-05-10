# OOP-A1-BUSAO

Atividade A1 para a disciplina de Programação Orientada a Objeto.

# Descrição Original da Atividade

A atividade deve ser em grupos de 2 à 4 integrantes. Deve ser entregue um arquivo zip com a implementação feita para o problema.

Durante o percurso de um onibus em sua linha existem N pontos, nomeadas de P1 à PN, de forma circular (após chegar em PN ele retoma a rota em P1). Em cada ponto, as pessoas podem subir ou descer do onibus.  O ônibus tem capacidade maxima para X pessoas sentadas mais Y em pé. 

Crie uma classe Onibus para armazenar as informações de ocupação em um onibus. A classe deve armazenar o numero de pessoas dentro do veiculo, quantas entraram com bilhete normal, de idoso e de estudante. Com base no numero de poltronas que ele possui, a classe deve conter também um método para indicar se existem pessoas em pé ou não, e quantas são. A classe deve também disponibilizar os seguintes métodos:

Inicializar: deve instanciar um objeto que permita manipular as informações do onibus. Nesse caso, o onibus tem capacidade maxima para 20 pessoas sentadas mais 40 em pé, e percorre uma linha com pontos 10 pontos.

Entrar: para acrescentar uma pessoa no onibus (só deve acrescentar se ainda houver espaço);

Sair: para remover uma pessoa do onibus (só deve remover se houver alguém dentro dele);

ContarTipoBilhetes: armazenar quantos passageiros usaram o onibus com base nos bilhetes usados

Pedirpara descer: informa que existe um passageiro quer descer no proximo ponto

Numero de viagens: quantas voltas o onibus já realizou entre os pontos P1 e PN.

Obs.: Encapsular todos os atributos da classe (criar os métodos set e get). Precisa também de um programa mostrando o funcionamento da classe.

Lembre-se! O onibus percorre a linha, então a rotina de teste da classe deve também considerar a viagem, podendo disponibilizar os dados a cada chegada no ponto final.

# Identificação dos Testes Unitários


## 1. Nome da classe é Onibus

Implementação:  
Como convenção informal na linguagem C++, classes normalmente começam com um C maiúsculo. Mas como foi pedido no enunciado, deve ser respeitado o nome da classe.

## 2. Deve haver um método inicial que instancie a classe Onibus

Implementação:  
Métodos estático (builder design pattern) que retorna uma instância de Onibus a partir dos parâmetros fornecidos. Tornar os construtores privados  
de forma a forçar a utilização do método estático como único instanciador da classe.

## 3. A classe Onibus deve inicializar com o número de pontos, a capacidade para pessoas sentadas e a capacidade para pessoas em pé

Implementação:  
Parte do teste unitário 2, esses são os parâmetros fornecidos para instanciar a classe Onibus.  

## 4. A classe deve armazenar o número de passageiros no Ônibus

Implementação:  
Propriedade da classe Onibus é uma coleção de passageiros.  

## 5. A classe deve identificar o tipo de passagem de cada passageiro

Implementação:  
Enumeração contendo os valores bilhete normal, de estudante e idoso.  

## 6. Os testes devem mostrar todos os atributos da classe ônibus no ponto final

Implementação:  
Retornar todos os atributos num dos testes no ponto final.  

## 7. Os testes devem mostrar quantos passageiros estão em pé, em todos os pontos

Implementação:  
Retornar todos os passgeiros em pé num dos testes no ponto final.  

## 8. O ônibus só deve aceitar um novo passageiro, ao parar num ponto, se houver espaço

Implementação:  
Testes mostrando todos os cenários possíveis.  

## 9. O ônibus só deve descer um passageiro, ao parar num ponto, se houver pelo menos 1 passageiro a bordo

Implementação:  
Testes mostrando todos os cenários possíveis.  

