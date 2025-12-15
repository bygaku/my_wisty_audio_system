#ifndef WINDOW_HEADER
#define WINDOW_HEADER
#include <windows.h>

/** Window management class */
class Window {
	LPCTSTR	   window_class_name_;	// Window identifier name
	HWND	   hWnd_;			    // Window handle
	LPCTSTR	   title_name_;			// Name of title bar
	int  	   w_;				    // Window width
	int  	   h_;				    // Window height

public:
	/**
	 * @brief Constructor
	 * @param window_class_name Window identifier name.
	 */
	explicit Window(LPCTSTR window_class_name);

	/** @brief Destructor */
	~Window() = default;

	// TODO: add later.
	// void Show();
	// void Hide();
	// void Close();
	// void OnClose();
	// void OnResize();

	// TODO: creating documentation.
	/**
	 *
	 * @param hInstance
	 * @param window_class_name
	 */
	void Quit(HINSTANCE hInstance, LPCTSTR window_class_name);

	/**
	 * @brief Start up the main window.
	 * @param hInstance Instance handle
	 * @param size_w: Window width. default: 800
	 * @param size_h: Window height. default: 600
	 * @param title: The name of window title bar. default: "Default"
	 * @param main_window: Is this main window?
	 * @return If there is an error, return false.
	 */
	bool Initialize(HINSTANCE hInstance, const int& size_w = 800, const int& size_h = 600, const char* title = "Default", bool main_window = false);

	/**
	 * @return The specified window handle. NO DISCARD!!
	 */
	[[nodiscard]] HWND GetWindowHandle() const { return hWnd_; }

private:
	/**
	 * @brief Window procedure.
	 * @param hWnd Window handle.
	 * @param uMsg Message code.
	 * @param wP Additional data related to the message.
	 * @param lP Additional data related to the message.
	 */
	static LRESULT CALLBACK StaticWndProc(HWND hWnd, UINT uMsg, WPARAM wP, LPARAM lP);

	/**
	 * @brief
	 * @param hWnd
	 * @param uMsg
	 * @param wP
	 * @param lP
	 * @return
	 */
	LRESULT HandleMessage(HWND hWnd, UINT uMsg, WPARAM wP, LPARAM lP);

};

#endif // WINDOW_HEADER