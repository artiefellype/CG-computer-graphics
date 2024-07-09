/**********************************************************************************
// WinApp (Código Fonte)
//
// Criação:		11 Jan 2020
// Atualização:	08 Jul 2023
// Compilador:	Visual C++ 2022
//
// Descrição:	Testa a execução de uma aplicação usando DXUT
//
**********************************************************************************/

#include "DXUT.h"
#include <sstream>
using std::stringstream;

// ------------------------------------------------------------------------------

class WinApp : public App
{
private:
	HWND hwnd;
	HDC hdc;
	int initX, initY;
	int lastX, lastY;
	bool click;

public:
	void Init();
	void Update();
	void Display();
	void Finalize();	
};

// ------------------------------------------------------------------------------

void WinApp::Init()
{

	click = false;
	initX = 0;
	initY = 0;
	lastX = 0;
	lastY = 0;
	// identificador da janela
	hwnd = window->Id();
	// captura dispositivo
	hdc = GetDC(hwnd);
	

	
}

// ------------------------------------------------------------------------------

void WinApp::Update()
{
	// sai com o pressionamento da tecla ESC
	if (input->KeyPress(VK_ESCAPE))
		window->Close();


	if (input->KeyPress(VK_LBUTTON)) {
		if (click) {
			lastX = input->MouseX();
			lastY = input->MouseY();
			Display();
			click = false;
		}
		else {
			// first click
			initX = input->MouseX();
			initY = input->MouseY();
			click = true;
		}
	}
	
	
}
// -----------------------------------------------------------------------------


void WinApp::Display()
{
	MoveToEx(hdc, initX, initY, NULL);
	LineTo(hdc, lastX, lastY);
}

// ------------------------------------------------------------------------------

void WinApp::Finalize()
{
	ReleaseDC(hwnd, hdc);
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	                 _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// cria motor e configura janela
	Engine* engine = new Engine();
	engine->window->Mode(WINDOWED);
	engine->window->Size(1024, 600);
	engine->window->Color(0, 122, 204);
	engine->window->Title("Aplicação Windows");
	engine->window->Icon(IDI_ICON);

	// cria e executa a aplicação
	return engine->Start(new WinApp());
}

// ----------------------------------------------------------------------------

