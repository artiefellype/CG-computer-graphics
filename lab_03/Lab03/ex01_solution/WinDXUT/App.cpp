/**********************************************************************************
// App (C�digo Fonte)
//
// Cria��o:		11 Jan 2020
// Atualiza��o:	09 Jul 2023
// Compilador:	Visual C++ 2022
//
// Descri��o:	Uma classe abstrata para representar uma aplica��o
//              Todas as aplica��es derivadas da classe App devem
//              sobrescrever os m�todos Init, Update e Finalize.
//
**********************************************************************************/

#include "App.h"
#include "Engine.h"

// -------------------------------------------------------------------------------
// Inicializa��o de membros est�ticos da classe

// As refer�ncias fazem com que n�o seja necess�rio verificar
// se os ponteiros de Engine foram inicializados. Sendo uma
// refer�ncia, os atributos de App ser�o atualizados t�o logo
// os atributos de Engine recebam valores

Window* & App::window = Engine::window;		// ponteiro para a janela
Input* & App::input = Engine::input;		// ponteiro para a entrada

// -------------------------------------------------------------------------------

App::App()
{
}

// -------------------------------------------------------------------------------

App::~App()
{
}

// -------------------------------------------------------------------------------