#include "ui_manager.h"

#include <algorithm>
#include <vector>

#include "ui_structure.h"

//
#include "../../lib/imgui/imgui.h"

using namespace wwist::ui;

class UIManager::Impl {
public:
	// Declare the UI you wish to add below.
	std::vector<SampleEntry> samples_;	// Display on sample tree.

	size_t next_ = 1;
public:
	const std::vector<SampleEntry>& GetSampleContainer() const {
		return samples_;
	}

	void RenderSampleTree() {
		ImGui::SetNextWindowSize(ImVec2(800, 400), ImGuiCond_Once);
		ImGui::Begin("SampleTree", nullptr, ImGuiWindowFlags_NoCollapse);

		if (ImGui::BeginTable("SampleTable", 3,
			ImGuiTableFlags_Borders |
			ImGuiTableFlags_RowBg
			)) {
			ImGui::TableSetupColumn("Index",        ImGuiTableColumnFlags_WidthFixed,   60.0f);
			ImGui::TableSetupColumn("Tag (8 chars)",ImGuiTableColumnFlags_WidthFixed,  120.0f);
			ImGui::TableSetupColumn("File Path",    ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableHeadersRow();

			for (const auto& s : samples_) {
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("%d", s.index_);
				ImGui::TableNextColumn(); ImGui::TextUnformatted(s.tag_.c_str());
				ImGui::TableNextColumn(); ImGui::TextUnformatted(s.path_.c_str());
			}

			ImGui::EndTable();
		}
		ImGui::End();
	}

	void Update(const float& dt) {
	}
};

UIManager::UIManager(UserApplication& app) : impl_(std::make_unique<Impl>()) {
}

UIManager::~UIManager() {
}

void UIManager::Initialize() {
	auto& sample = impl_->samples_;

	for (int i = 0; i < 10; ++i) {
		sample.emplace_back(i, "tag", "C:/test.wav");
	}
}

void UIManager::Render() const {
	impl_->RenderSampleTree();

	// Menu Bar
	{
		if (ImGui::BeginMainMenuBar()) {
			if (ImGui::BeginMenu("File")) {
				ImGui::MenuItem("Save Project");
				ImGui::MenuItem("Load Project");
				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("Tree")) {
				ImGui::MenuItem("Load Sample");
				ImGui::MenuItem("Delete Sample");
				ImGui::MenuItem("Clear Tree");
				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}
	}
}

void UIManager::Quit() {
}

void UIManager::Update(const float& dt) {
	impl_->Update(dt);
}
