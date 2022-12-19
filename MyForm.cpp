#include "MyForm.h"
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>


using namespace AtomModel;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}