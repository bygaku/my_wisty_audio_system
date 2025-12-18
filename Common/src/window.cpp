#include "../include/window.h"

#include <cstdio>

Window::Window(LPCTSTR window_class_name)
	: window_class_name_(window_class_name)
	, hWnd_			(nullptr)
	, title_name_	("Default")
	, w_			(800)
	, h_			(600) {
	// Nothing to do here.
}

void Window::Quit(HINSTANCE hInstance, LPCTSTR window_class_name) {
	UnregisterClass(window_class_name, hInstance);
}

bool Window::Initialize(HINSTANCE hInstance, const int &size_w, const int &size_h, const char* title, bool main_window) {
	if (hInstance == nullptr) return false;

	// Window custom settings.
	w_ 			= size_w;
	h_ 			= size_h;
	title_name_ = title;

	// Window configurations.
	WNDCLASSEX wc{};
	wc.hInstance			= hInstance;
	wc.lpszClassName		= window_class_name_;
	wc.lpfnWndProc			= Window::StaticWndProc;
	wc.style				= 0;
	wc.cbSize				= sizeof(WNDCLASSEX);
	wc.hIcon				= LoadIcon(hInstance, IDI_APPLICATION);
	wc.hIconSm				= LoadIcon(hInstance, IDI_APPLICATION);
	wc.hCursor				= LoadCursor(hInstance, IDC_ARROW);
	wc.lpszMenuName			= nullptr;
	wc.hbrBackground		= GetSysColorBrush(COLOR_WINDOW);
	if (!RegisterClassEx(&wc)) return false;

	// Create main window.
	hWnd_ = CreateWindowEx(
		WS_EX_TOOLWINDOW,
		window_class_name_,
		title_name_,
		WS_OVERLAPPED | WS_CAPTION | WS_VISIBLE | WS_SYSMENU,
		CW_USEDEFAULT, CW_USEDEFAULT,
		w_, h_,
		HWND_DESKTOP,
		nullptr,
		hInstance,
		nullptr
		);
	if (!hWnd_) return false;

	return true;
}

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT Window::StaticWndProc(HWND hWnd, UINT uMsg, WPARAM wP, LPARAM lP) {
	if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wP, lP)) return true;

	switch (uMsg) {
		case WM_CREATE: {
			printf("WM_CREATE called.\n");
			auto* tpCreateSt = reinterpret_cast<CREATESTRUCT*>(lP);

			::ShowWindow(hWnd, SW_SHOWNORMAL);
			::UpdateWindow(hWnd);
		}
		break;
		case WM_DESTROY: {
			printf("WM_DESTROY called\n");
			PostQuitMessage(0);
		}
		break;
		default: return DefWindowProc(hWnd, uMsg, wP, lP);
	}

	return 0;
}
