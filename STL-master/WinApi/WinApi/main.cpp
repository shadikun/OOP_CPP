#include<Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, 
	HINSTANCE hPrevInst, 
	LPSTR lpCmdLine, 
	int nShowCmd)
{
	MessageBox(NULL, "Hello its my first window in winapi", "Hello WinApi", MB_YESNOCANCEL | MB_ICONWARNING);
	int answer = MessageBox(NULL, " its  апро Hello first my in winapi window ", "Hello первак WinApi", MB_YESNOCANCEL | MB_DEFBUTTON3 | MB_APPLMODAL);
	if ( answer == IDYES)
	{
		MessageBox(NULL, "jsfksdf", "qwerty", MB_OK | MB_ICONINFORMATION);
	}
	else if(answer == IDNO)
	{
	MessageBox(NULL, "qwerty", "fdhkfjg", MB_OK | MB_ICONERROR);
	}

}