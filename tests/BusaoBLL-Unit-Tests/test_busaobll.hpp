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
    BOOST_TEST_MESSAGE( "TEST CENÁRIO 2. Deve haver um método inicial que instancie a classe Onibus" );
    BOOST_TEST_MESSAGE( "TEST CENÁRIO 3. A classe Onibus deve inicializar com o número de pontos, a capacidade para pessoas sentadas e a capacidade para pessoas em pé" );
    Onibus onibus = Onibus::instantiate(2U, 1U, 1U);
    BOOST_TEST ( true );
}

BOOST_AUTO_TEST_CASE(test_onibus_inicializa_numero_pontos_falha)
{
    BOOST_TEST_MESSAGE( "TEST CENÁRIO 3. A classe Onibus deve inicializar com o número de pontos, a capacidade para pessoas sentadas e a capacidade para pessoas em pé" );
    BOOST_REQUIRE_THROW(Onibus::instantiate(0U, 2U, 2U), CExcecao);
}

BOOST_AUTO_TEST_CASE(test_onibus_inicializa_capacidade_sentadas_falha)
{
    BOOST_TEST_MESSAGE( "TEST CENÁRIO 3. A classe Onibus deve inicializar com o número de pontos, a capacidade para pessoas sentadas e a capacidade para pessoas em pé" );
    BOOST_REQUIRE_THROW(Onibus::instantiate(2U, 0U, 2U), CExcecao);
}

BOOST_AUTO_TEST_CASE(test_onibus_inicializa_capacidade_empe_falha)
{
    BOOST_TEST_MESSAGE( "TEST CENÁRIO 3. A classe Onibus deve inicializar com o número de pontos, a capacidade para pessoas sentadas e a capacidade para pessoas em pé" );
    BOOST_REQUIRE_THROW(Onibus::instantiate(2U, 2U, 0U), CExcecao);
}

BOOST_AUTO_TEST_SUITE_END()

/*
## 4. A classe deve armazenar o número de passageiros no Ônibus

## 5. A classe deve identificar o tipo de passagem de cada passageiro
*/

BOOST_AUTO_TEST_SUITE(suite_onibus_passageiros_get_set)

BOOST_AUTO_TEST_CASE(test_onibus_passageiros_get_set_sem_passageiros)
{
    Onibus onibus = Onibus::instantiate(2U, 1U, 1U);
    BOOST_TEST_MESSAGE( "TEST CENÁRIO 4. Onibus inicia primeira volta sem passageiros." );
    BOOST_TEST ( onibus.get_passageiros().size() == 0U );
}

BOOST_AUTO_TEST_CASE(test_onibus_passageiros_get_set_passageiro_normal)
{
    Onibus onibus = Onibus::instantiate(2U, 1U, 1U);
    Bilhete bilhete = Bilhete::Normal;
    Passageiro passageiro = Passageiro::instantiate(bilhete);
    onibus.Entrar(passageiro);
    BOOST_TEST_MESSAGE( "TEST CENÁRIO 4. Onibus pega passageiro com bilhete Normal." );
    BOOST_TEST ( onibus.get_passageiros().size() == 1U );
    BOOST_TEST_MESSAGE( "TEST CENÁRIO 5. A classe deve identificar o tipo de passagem de cada passageiro (Normal)." );
    BOOST_TEST ( onibus.get_passageiros()[0].get_bilhete() == Bilhete::Normal );
}

BOOST_AUTO_TEST_CASE(test_onibus_passageiros_get_set_passageiro_idoso)
{
    Onibus onibus = Onibus::instantiate(2U, 1U, 1U);
    Bilhete bilhete = Bilhete::Idoso;
    Passageiro passageiro = Passageiro::instantiate(bilhete);
    onibus.Entrar(passageiro);
    BOOST_TEST_MESSAGE( "TEST CENÁRIO 4. Onibus pega passageiro com bilhete Idoso." );
    BOOST_TEST ( onibus.get_passageiros().size() == 1U );
    BOOST_TEST_MESSAGE( "TEST CENÁRIO 5. A classe deve identificar o tipo de passagem de cada passageiro (Idoso)." );
    BOOST_TEST ( onibus.get_passageiros()[0].get_bilhete() == Bilhete::Idoso );
}

BOOST_AUTO_TEST_CASE(test_onibus_passageiros_get_set_passageiro_estudante)
{
    Onibus onibus = Onibus::instantiate(2U, 1U, 1U);
    Bilhete bilhete = Bilhete::Estudante;
    Passageiro passageiro = Passageiro::instantiate(bilhete);
    onibus.Entrar(passageiro);
    BOOST_TEST_MESSAGE( "TEST CENÁRIO 4. Onibus pega passageiro com bilhete Estudante." );
    BOOST_TEST ( onibus.get_passageiros().size() == 1U );
    BOOST_TEST ( onibus.get_passageiros()[0].get_bilhete() == Bilhete::Estudante );
}

BOOST_AUTO_TEST_SUITE_END()

/*
## 6. Os testes devem mostrar todos os atributos da classe ônibus no ponto final
*/

BOOST_AUTO_TEST_SUITE(suite_onibus_atributos_ponto_final)

BOOST_AUTO_TEST_CASE(test_onibus_atributos_ponto_inicial)
{
    Onibus onibus = Onibus::instantiate(2U, 1U, 1U);
    Bilhete bilhete = Bilhete::Estudante;
    Passageiro passageiro = Passageiro::instantiate(bilhete);
    onibus.Entrar(passageiro);
    onibus.Entrar(passageiro);
    BOOST_TEST_MESSAGE( "TEST CENÁRIO 6. Os testes devem mostrar todos os atributos da classe ônibus no ponto final" );
    BOOST_TEST ( onibus.ContarTipoBilhetes(Bilhete::Estudante) == 2U );
    BOOST_TEST ( onibus.ContarTipoBilhetes(Bilhete::Idoso) == 0U );
    BOOST_TEST ( onibus.ContarTipoBilhetes(Bilhete::Normal) == 0U );
}

BOOST_AUTO_TEST_CASE(test_onibus_atributos_ponto_final)
{
    const unsigned int pontos = 2U;
    const unsigned int bancos = 1U;
    const unsigned int empe = 1U;
    
    Onibus onibus = Onibus::instantiate(pontos, bancos, empe);
    Bilhete bilhete = Bilhete::Estudante;
    Passageiro passageiro = Passageiro::instantiate(bilhete);
    onibus.Entrar(passageiro);
    onibus.Entrar(passageiro);
    BOOST_TEST_MESSAGE( "TEST CENÁRIO 6. Os testes devem mostrar todos os atributos da classe ônibus no ponto final" );
    BOOST_TEST ( onibus.ContarTipoBilhetes(Bilhete::Estudante) == 2U );
    BOOST_TEST ( onibus.ContarTipoBilhetes(Bilhete::Idoso) == 0U );
    BOOST_TEST ( onibus.ContarTipoBilhetes(Bilhete::Normal) == 0U );
    BOOST_TEST ( onibus.PassageirosEmPe() == 1U );
    BOOST_TEST ( onibus.PassageirosSentados() == 1U );
    BOOST_TEST ( onibus.Numerodeviagens() == 0U );
    BOOST_TEST ( onibus.get_pontos() == pontos );
    BOOST_TEST ( onibus.get_bancos() == bancos );
    BOOST_TEST ( onibus.get_empe() == empe );
    BOOST_TEST ( onibus.get_voltas() == 0U );
    BOOST_TEST ( onibus.get_ponto() == 1U );
}

BOOST_AUTO_TEST_SUITE_END()

/*
## 7. Os testes devem mostrar quantos passageiros estão em pé, em todos os pontos
*/

BOOST_AUTO_TEST_SUITE(suite_onibus_atributos_pontos)

BOOST_AUTO_TEST_CASE(test_onibus_passageiros_empe_ponto_n)
{
    Onibus onibus = Onibus::instantiate(2U, 1U, 1U);
    Bilhete bilhete = Bilhete::Estudante;
    Passageiro passageiro = Passageiro::instantiate(bilhete);
    onibus.Entrar(passageiro);
    onibus.Entrar(passageiro);
    BOOST_TEST_MESSAGE( "TEST CENÁRIO 7. Os testes devem mostrar quantos passageiros estão em pé, em todos os pontos" );
    BOOST_TEST ( onibus.ContarTipoBilhetes(Bilhete::Estudante) == 2U );
    BOOST_TEST ( onibus.ContarTipoBilhetes(Bilhete::Idoso) == 0U );
    BOOST_TEST ( onibus.ContarTipoBilhetes(Bilhete::Normal) == 0U );
    BOOST_TEST ( onibus.PassageirosEmPe() == 1U );
    BOOST_TEST ( onibus.PassageirosSentados() == 1U );
    onibus.Pedirparadescer(1U);
    onibus.Passarnoproximoponto();
    BOOST_TEST ( onibus.PassageirosEmPe() == 0U );
    BOOST_TEST ( onibus.PassageirosSentados() == 1U );
    BOOST_TEST ( onibus.Numerodeviagens() == 0U );
    onibus.Pedirparadescer(1U);
    onibus.Passarnoproximoponto();
    BOOST_TEST ( onibus.PassageirosEmPe() == 0U );
    BOOST_TEST ( onibus.PassageirosSentados() == 0U );
    BOOST_TEST ( onibus.Numerodeviagens() == 1U );
}

BOOST_AUTO_TEST_SUITE_END()

/*
## 8. O ônibus só deve aceitar um novo passageiro, ao parar num ponto, se houver espaço

## 9. O ônibus só deve descer um passageiro, ao parar num ponto, se houver pelo menos 1 passageiro a bordo
*/

BOOST_AUTO_TEST_SUITE(suite_onibus_passageiros_subir_descer)

BOOST_AUTO_TEST_CASE(test_onibus_passageiros_subir_passageiro_empe_nao_disponiveis)
{
    Onibus onibus = Onibus::instantiate(2U, 1U, 1U);
    Bilhete bilhete = Bilhete::Estudante;
    Passageiro passageiro = Passageiro::instantiate(bilhete);
    onibus.Entrar(passageiro);
    onibus.Entrar(passageiro);
    BOOST_TEST_MESSAGE( "TEST CENÁRIO 8. O ônibus só deve aceitar um novo passageiro, ao parar num ponto, se houver espaço" );
    BOOST_TEST ( onibus.PassageirosEmPe() == 1U );
    BOOST_TEST ( onibus.PassageirosSentados() == 1U );
    BOOST_REQUIRE_THROW(onibus.Entrar(passageiro), CExcecao);
}

BOOST_AUTO_TEST_CASE(test_onibus_passageiros_descer_passageiro_onibus_vazio)
{
    Onibus onibus = Onibus::instantiate(2U, 1U, 1U);
    BOOST_TEST_MESSAGE( "TEST CENÁRIO 9. O ônibus só deve descer um passageiro, ao parar num ponto, se houver pelo menos 1 passageiro a bordo" );
    BOOST_TEST ( onibus.PassageirosEmPe() == 0U );
    BOOST_TEST ( onibus.PassageirosSentados() == 0U );
    onibus.Pedirparadescer(1U);
    BOOST_REQUIRE_THROW(onibus.Passarnoproximoponto(), CExcecao);
}

BOOST_AUTO_TEST_SUITE_END()
