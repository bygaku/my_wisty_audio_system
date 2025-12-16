#include "application_engine.h"

#include <windows.h>
#include <cassert>
#include "window.h"

// COM
#include <wrl/client.h>
using Microsoft::WRL::ComPtr;

// DirectX11
#include <d3d11.h>
#include <dxgi.h>
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

// ImGui
#include "../../lib/imgui/imgui.h"
#include "../../lib/imgui/imgui_impl_win32.h"
#include "../../lib/imgui/imgui_impl_dx11.h"

using namespace wwist;

/**
 * @brief pImpl idiom for Engine.
 */
class ApplicationEngine::Impl {
public:
	HINSTANCE	hInstance_;		// Application instance handle.
	Window		main_window_;	// Main window.
	bool		is_running_;	// application running flag.
	std::unique_ptr<IApplication> user_app_; // User-defined Application class.

	// DirectX11
	ID3D11Device*           device_;
	ID3D11DeviceContext*    context_;
	IDXGISwapChain*         swap_chain_;
	ID3D11RenderTargetView* rtv_;

	/**
	 * @brief Constructor.
	 */
	Impl()
		: hInstance_(::GetModuleHandle(nullptr))
		, main_window_{"MainWindow"}
		, user_app_(nullptr)
		, device_(nullptr)
		, context_(nullptr)
		, swap_chain_(nullptr)
		, rtv_(nullptr)
		, is_running_(true){
	}

	/**
	 * @brief IApplication::Initialize() called.
	 */
	bool InitUserApp() const {
		if (!user_app_) assert("user_app nullptr");

		if (!user_app_->Initialize()) {
			return false;
		}

		return true;
	}

	/**
	 * @brief DX11 initialization.
	 */
	bool InitDX11() {
		auto hwnd = main_window_.GetWindowHandle();   // Window Handle

		DXGI_SWAP_CHAIN_DESC sd = {};
		sd.BufferCount = 2;
		sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		sd.OutputWindow = hwnd;
		sd.SampleDesc.Count = 1;
		sd.Windowed = TRUE;
		sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

		HRESULT hr = D3D11CreateDeviceAndSwapChain(
			nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
			nullptr, 0, D3D11_SDK_VERSION,
			&sd, &swap_chain_, &device_, nullptr, &context_);
		if (FAILED(hr)) return false;

		// Create RTV from BackBuffer
		ComPtr<ID3D11Texture2D> back_buffer;
		hr = swap_chain_->GetBuffer(0, __uuidof(ID3D11Texture2D),
									reinterpret_cast<void**>(back_buffer.GetAddressOf()));
		if (FAILED(hr)) return false;

		hr = device_->CreateRenderTargetView(back_buffer.Get(), nullptr, &rtv_);
		if (FAILED(hr)) return false;

		return true;
	}

	/**
	 * @brief ImGUI initialization.
	 */
	bool InitImGUI() const {
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		(void)io;
		ImGui::StyleColorsDark();

		if (!ImGui_ImplWin32_Init(main_window_.GetWindowHandle())) return false;
		if (!ImGui_ImplDX11_Init(device_, context_)) return false;

		return true;
	}

	/** @remark Please Run-implement it here. */
	void Run() {
		MSG msg = {};
		while (is_running_) {
			while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
				if (msg.message == WM_QUIT) {
					is_running_ = false;
					break;
				}
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

			auto dt = 0.f;
			user_app_->Update(dt);

			ImGui_ImplWin32_NewFrame();
			ImGui_ImplDX11_NewFrame();
			ImGui::NewFrame();

			user_app_->Render();

			RenderFrame();
		}
	}

	/** @remark Please RenderFrame-implement it here. */
	void RenderFrame() const {
		ImGui::Render();
		const float clear_color[4] = {0.1f, 0.1f, 0.1f, 1.0f};

		context_->OMSetRenderTargets(1, &rtv_, nullptr);
		context_->ClearRenderTargetView(rtv_, clear_color);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
		swap_chain_->Present(1, 0);
	}

	/** @remark Please Quit-implement it here. */
	void Quit() {
		is_running_ = false;

		// UserApp destroy.
		user_app_->Quit();

		// Library clean up.
		CleanUpImGUI();
		CleanUpDX11();

		// Window destroy.
		main_window_.Quit(hInstance_, "MainWindow");

		// Instance Handle release.
		hInstance_ = nullptr;
	}

	/**
	 * @brief Release ImGui resources.
	 */
	void CleanUpImGUI() {
		ImGui_ImplDX11_Shutdown();
		ImGui_ImplWin32_Shutdown();
		ImGui::DestroyContext();
	}

	/**
	 * @brief Release DX11 resources.
	 */
	void CleanUpDX11() {
		if (rtv_) {
			rtv_->Release();
			rtv_ = nullptr;
		}

		if (swap_chain_) {
			swap_chain_->Release();
			swap_chain_ = nullptr;
		}

		if (context_) {
			context_->Release();
			context_ = nullptr;
		}

		if (device_) {
			device_->Release();
			device_ = nullptr;
		}
	}

};

ApplicationEngine::ApplicationEngine()
	: impl_(std::make_unique<Impl>()) {
}

ApplicationEngine::~ApplicationEngine() {
}

bool ApplicationEngine::Initialize(std::unique_ptr<IApplication> app, const char *title, const int &width, const int &height) {
	const auto& instance	= impl_->hInstance_;	// application instance.
	auto& mw		 = impl_->main_window_;	// main_window_ instance.

	printf("Started Initializing the Engine.\n");
	// Window initialization.
	if (!mw.Initialize(instance, width, height, title, true)) return false;

	// Library initialization.
	if(!impl_->InitDX11())  return false;
	if(!impl_->InitImGUI()) return false;

	// User-defined app class initialization.
	impl_->user_app_ = std::move(app);
	if (!impl_->InitUserApp()) return false;

	printf("Complete Initializing the Engine.\n");

	return true;
}

void ApplicationEngine::Run() {
	impl_->Run();
}

void ApplicationEngine::Quit() {
	impl_->Quit();

	printf("Engine was Quit Safely\n");
}

void ApplicationEngine::RenderFrame() {
	impl_->RenderFrame();
}
