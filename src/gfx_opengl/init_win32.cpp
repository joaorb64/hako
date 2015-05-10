#ifdef HAKO_BUILD_GFXOPENGL


#include "init.h"


#ifdef HAKO_BUILD_WIN32

void HakoInternal::OpenGL::win32_enable(HWND hwnd, HDC* hdc, HGLRC* hrc)
{
	PIXELFORMATDESCRIPTOR pfd;
	int iFormat;

	// Get the device context.
	*hdc = GetDC(hwnd);

	// Set the pixel format for the device context.
	ZeroMemory(&pfd, sizeof(pfd));
	pfd.nSize      = sizeof(pfd);
	pfd.nVersion   = 1;
	pfd.dwFlags    = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;

	iFormat = ChoosePixelFormat(*hdc, &pfd);
	SetPixelFormat(*hdc, iFormat, &pfd);

	// Create and enable the render context.
	*hrc = wglCreateContext(*hdc);
	wglMakeCurrent(*hdc, *hrc);
}


void HakoInternal::OpenGL::win32_disable(HWND hwnd, HDC hdc, HGLRC hrc)
{
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(hrc);
	ReleaseDC(hwnd, hdc);
}

#endif


#endif
