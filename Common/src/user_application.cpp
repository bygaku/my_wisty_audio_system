#include "user_application.h"

// ImGui
#include "../../lib/imgui/imgui.h"

using namespace wwist;

UserApplication::UserApplication() {
}

UserApplication::~UserApplication() {
}

bool UserApplication::Initialize() {
	return true;
}

void UserApplication::Update(float dt) {
}

void UserApplication::Render() {

	// SampleBank Window
	{
		ImGui::Begin("Sample Bank");

		if (ImGui::BeginTable("SampleTable", 3,
		                      ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg)) {
			ImGui::TableSetupColumn("Index");
			ImGui::TableSetupColumn("Tag (8 chars)");
			ImGui::TableSetupColumn("FilePath");
			ImGui::TableHeadersRow();

			ImGui::EndTable();
		}

		ImGui::End();
	}
}

void UserApplication::Quit() {
}
