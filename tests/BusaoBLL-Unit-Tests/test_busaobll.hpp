/**
    test_busaobll.hpp
    Purpose: Unit Tests for the BusaoBLL class.

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#pragma once
#include <boost/test/included/unit_test.hpp>
#include "stdafx.h"

/*
## 1. Nome da classe é Onibus

## 2. Deve haver um método inicial que instancie a classe Onibus

## 3. A classe Onibus deve inicializar com o número de pontos, a capacidade para pessoas sentadas e a capacidade para pessoas em pé
*/
BOOST_AUTO_TEST_SUITE(suite_onibus_inicializacao)

BOOST_AUTO_TEST_CASE(test_onibus_metodo_inicializador)
{
    BOOST_TEST ( false );
}

BOOST_AUTO_TEST_CASE(test_onibus_inicializa_sucesso)
{
    BOOST_TEST ( false );
}

BOOST_AUTO_TEST_CASE(test_onibus_inicializa_numero_pontos_falha)
{
    BOOST_TEST ( false );
}

BOOST_AUTO_TEST_CASE(test_onibus_inicializa_capacidade_sentadas_falha)
{
    BOOST_TEST ( false );
}

BOOST_AUTO_TEST_CASE(test_onibus_inicializa_capacidade_empe_falha)
{
    BOOST_TEST ( false );
}

BOOST_AUTO_TEST_SUITE_END()

/*
## 4. A classe deve armazenar o número de passageiros no Ônibus

## 5. A classe deve identificar o tipo de passagem de cada passageiro
*/

BOOST_AUTO_TEST_SUITE(suite_onibus_passageiros_get_set)

BOOST_AUTO_TEST_CASE(test_onibus_passageiros_get_set_sem_passageiros)
{
    BOOST_TEST ( false );
}

BOOST_AUTO_TEST_CASE(test_onibus_passageiros_get_set_passageiro_normal)
{
    BOOST_TEST ( false );
}

BOOST_AUTO_TEST_CASE(test_onibus_passageiros_get_set_passageiro_idoso)
{
    BOOST_TEST ( false );
}

BOOST_AUTO_TEST_CASE(test_onibus_passageiros_get_set_passageiro_estudante)
{
    BOOST_TEST ( false );
}

BOOST_AUTO_TEST_SUITE_END()

/*
## 6. Os testes devem mostrar todos os atributos da classe ônibus no ponto final
*/

BOOST_AUTO_TEST_SUITE(suite_onibus_atributos_ponto_final)

BOOST_AUTO_TEST_CASE(test_onibus_atributos_ponto_inicial)
{
    BOOST_TEST ( false );
}

BOOST_AUTO_TEST_CASE(test_onibus_atributos_ponto_final)
{
    BOOST_TEST ( false );
}

BOOST_AUTO_TEST_SUITE_END()

/*
## 7. Os testes devem mostrar quantos passageiros estão em pé, em todos os pontos
*/

BOOST_AUTO_TEST_SUITE(suite_onibus_atributos_pontos)

BOOST_AUTO_TEST_CASE(test_onibus_passageiros_empe_ponto_n)
{
    BOOST_TEST ( false );
}

BOOST_AUTO_TEST_SUITE_END()

/*
## 8. O ônibus só deve aceitar um novo passageiro, ao parar num ponto, se houver espaço

## 9. O ônibus só deve descer um passageiro, ao parar num ponto, se houver pelo menos 1 passageiro a bordo
*/

BOOST_AUTO_TEST_SUITE(suite_onibus_passageiros_subir_descer)

BOOST_AUTO_TEST_CASE(test_onibus_passageiros_subir_passageiro_bancos_disponiveis)
{
    BOOST_TEST ( false );
}

BOOST_AUTO_TEST_CASE(test_onibus_passageiros_subir_passageiro_empe_disponiveis)
{
    BOOST_TEST ( false );
}

BOOST_AUTO_TEST_CASE(test_onibus_passageiros_subir_passageiro_empe_nao_disponiveis)
{
    BOOST_TEST ( false );
}

BOOST_AUTO_TEST_SUITE_END()
