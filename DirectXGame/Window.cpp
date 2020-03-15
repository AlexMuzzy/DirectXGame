#include "Window.h"

Window* window = nullptr;

Window::Window()
{
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_CREATE:
	{
		// Event fired when the window is created
		break;
	}

	case WM_DESTROY:
	{
		//Event fired when the window is destroyed
		::PostQuitMessage(0);
		break;
	}


	default:
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}






}


bool Window::init()
{
	WNDCLASSEX wc;
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = "MyWindowClass";
	wc.lpszMenuName = "";
	wc.style = NULL;
	wc.lpfnWndProc = &WndProc;



	if (!::RegisterClassEx(&wc))
	{
		return false;
	}

	//creation of the window
	m_hwnd=::CreateWindowEx
	(
		WS_EX_OVERLAPPEDWINDOW,
		"MyWindowClass",
		"DirectX Application",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		1024,
		768,
		NULL, NULL, NULL, NULL
	);
	
	//if the creation fail return false
	if (!m_hwnd)
	{
		return false;
	}

	//show up the window
	::ShowWindow(m_hwnd, SW_SHOW);
	::UpdateWindow(m_hwnd);

	return true;
}


bool Window::release()
{
	//return window
	if (!::DestroyWindow(m_hwnd))
	{
		return false;
	}


	return true;
}

Window::~Window()
{
}
