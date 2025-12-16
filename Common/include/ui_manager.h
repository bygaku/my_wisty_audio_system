#ifndef UI_MANAGER_HEADER
#define UI_MANAGER_HEADER

#include <memory>
#include "user_application.h"

namespace wwist {
	class UserApplication;
}

namespace wwist::ui {
class UIManager {
public:
	UIManager(UserApplication& app);

	~UIManager();

	void Initialize();

	void Update(const float& dt);

	void Render() const;

	void Quit();
private:
	class Impl;
	std::unique_ptr<Impl> impl_;

};

}

#endif // UI_MANAGER_HEADER