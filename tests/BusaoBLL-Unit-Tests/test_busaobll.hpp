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

BOOST_AUTO_TEST_CASE(test_onibus_inicializa_sucesso)
{
    BOOST_TEST_MESSAGE( "TEST CASE 2. SUCESSO: Deve haver um método inicial que instancie a classe Onibus" );
    BOOST_TEST_MESSAGE( "TEST CASE 3. SUCESSO: A classe Onibus deve inicializar com o número de pontos, a capacidade para pessoas sentadas e a capacidade para pessoas em pé" );
    Onibus onibus = Onibus::instantiate(1U, 1U, 1U);
    BOOST_TEST ( true );
}

BOOST_AUTO_TEST_CASE(test_onibus_inicializa_numero_pontos_falha)
{
    BOOST_TEST_MESSAGE( "TEST CASE 3. EXCEÇÃO: A classe Onibus deve inicializar com o número de pontos, a capacidade para pessoas sentadas e a capacidade para pessoas em pé" );
    BOOST_REQUIRE_THROW(Onibus::instantiate(0U, 1U, 1U), CExcecao);
}

BOOST_AUTO_TEST_CASE(test_onibus_inicializa_capacidade_sentadas_falha)
{
    BOOST_TEST_MESSAGE( "TEST CASE 3. EXCEÇÃO: A classe Onibus deve inicializar com o número de pontos, a capacidade para pessoas sentadas e a capacidade para pessoas em pé" );
    BOOST_REQUIRE_THROW(Onibus::instantiate(1U, 0U, 1U), CExcecao);
}

BOOST_AUTO_TEST_CASE(test_onibus_inicializa_capacidade_empe_falha)
{
    BOOST_TEST_MESSAGE( "TEST CASE 3. EXCEÇÃO: A classe Onibus deve inicializar com o número de pontos, a capacidade para pessoas sentadas e a capacidade para pessoas em pé" );
    BOOST_REQUIRE_THROW(Onibus::instantiate(1U, 1U, 0U), CExcecao);
}

BOOST_AUTO_TEST_SUITE_END()

/*
## 4. A classe deve armazenar o número de passageiros no Ônibus

## 5. A classe deve identificar o tipo de passagem de cada passageiro
*/

BOOST_AUTO_TEST_SUITE(suite_onibus_passageiros_get_set)

BOOST_AUTO_TEST_CASE(test_onibus_passageiros_get_set_sem_passageiros)
{
    Onibus onibus = Onibus::instantiate(1U, 1U, 1U);
    BOOST_TEST_MESSAGE( "TEST CASE 4. SUCESSO: Onibus inicia primeira volta sem passageiros." );
    BOOST_TEST ( onibus.get_passageiros().size() == 0U );
}

BOOST_AUTO_TEST_CASE(test_onibus_passageiros_get_set_passageiro_normal)
{
    Onibus onibus = Onibus::instantiate(1U, 1U, 1U);
    Bilhete bilhete = Bilhete::Normal;
    Passageiro passageiro = Passageiro::instantiate(bilhete);
    onibus.Entrar(passageiro);
    BOOST_TEST_MESSAGE( "TEST CASE 4. SUCESSO: Onibus pega passageiro com bilhete Normal." );
    BOOST_TEST ( onibus.get_passageiros().size() == 1U );
    BOOST_TEST_MESSAGE( "TEST CASE 5. SUCESSO: A classe deve identificar o tipo de passagem de cada passageiro (Normal)." );
    BOOST_TEST ( onibus.get_passageiros()[0].get_bilhete() == Bilhete::Normal );
}

BOOST_AUTO_TEST_CASE(test_onibus_passageiros_get_set_passageiro_idoso)
{
    Onibus onibus = Onibus::instantiate(1U, 1U, 1U);
    Bilhete bilhete = Bilhete::Idoso;
    Passageiro passageiro = Passageiro::instantiate(bilhete);
    onibus.Entrar(passageiro);
    BOOST_TEST_MESSAGE( "TEST CASE 4. SUCESSO: Onibus pega passageiro com bilhete Idoso." );
    BOOST_TEST ( onibus.get_passageiros().size() == 1U );
    BOOST_TEST_MESSAGE( "TEST CASE 5. SUCESSO: A classe deve identificar o tipo de passagem de cada passageiro (Idoso)." );
    BOOST_TEST ( onibus.get_passageiros()[0].get_bilhete() == Bilhete::Idoso );
}

BOOST_AUTO_TEST_CASE(test_onibus_passageiros_get_set_passageiro_estudante)
{
    Onibus onibus = Onibus::instantiate(1U, 1U, 1U);
    Bilhete bilhete = Bilhete::Estudante;
    Passageiro passageiro = Passageiro::instantiate(bilhete);
    onibus.Entrar(passageiro);
    BOOST_TEST_MESSAGE( "TEST CASE 4. SUCESSO: Onibus pega passageiro com bilhete Estudante." );
    BOOST_TEST ( onibus.get_passageiros().size() == 1U );
    BOOST_TEST_MESSAGE( "TEST CASE 5. SUCESSO: A classe deve identificar o tipo de passagem de cada passageiro (Estudante)." );
    BOOST_TEST ( onibus.get_passageiros()[0].get_bilhete() == Bilhete::Estudante );
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
