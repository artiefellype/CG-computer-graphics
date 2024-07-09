/**********************************************************************************
// Timed (Código Fonte)
//
// Criação:		16 Jan 2020
// Atualização:	09 Jul 2023
// Compilador:	Visual C++ 2022
//
// Descrição:	Testa as funcionalidades de animação do motor DXUT
//
**********************************************************************************/

#include "DXUT.h"

// ------------------------------------------------------------------------------

class Timed : public App
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
	void Draw();
	void Finalize();	
};

// ------------------------------------------------------------------------------

void Timed::Init()
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

void Timed::Update()
{
	// sai com o pressionamento da tecla ESC
	if (input->KeyPress(VK_ESCAPE))
		window->Close();

	// sai com o pressionamento da tecla ESC
	if (input->KeyPress(VK_ESCAPE))
		window->Close();


	if (input->KeyPress(VK_LBUTTON)) {
		if (click) {
			lastX = input->MouseX();
			lastY = input->MouseY();
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

// ------------------------------------------------------------------------------

void Timed::Draw()
{
	if (click) {
		window->Clear();
		MoveToEx(hdc, initX, initY, NULL);
		LineTo(hdc, input->MouseX(), input->MouseY());
	}
}

// ------------------------------------------------------------------------------

void Timed::Finalize()
{
	ReleaseDC(hwnd, hdc);
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	                 _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// cria motor e configura a janela
	Engine* engine = new Engine();
	engine->window->Mode(WINDOWED);
	engine->window->Size(1024, 600);
	engine->window->Color(0, 122, 204);
	engine->window->Title("Timed DXUT");
	engine->window->Icon(IDI_ICON);

	// cria e executa a aplicação
	return engine->Start(new Timed());
}

// ----------------------------------------------------------------------------

