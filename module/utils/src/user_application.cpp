#include "ui_manager.h"


#include "user_application.h"

// ImGui
#include "imgui.h"

using namespace wwist;

UserApplication::UserApplication() : ui_manager_(nullptr){
}

UserApplication::~UserApplication() {
}

bool UserApplication::Initialize() {
	ui_manager_ = std::make_unique<ui::UIManager>(*this);
	ui_manager_->Initialize();
	return true;
}

void UserApplication::Update(float dt) {
	ui_manager_->Update(dt);
}

void UserApplication::Render() {
	{
		ImGui::Begin("TEXT WINDOW");
		ImGui::Text("Hello World");
		ImGui::End();
	}
	ui_manager_->Render();
}

void UserApplication::Quit() {
	ui_manager_->Quit();
}
