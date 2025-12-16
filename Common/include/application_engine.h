#ifndef ENGINE_APP_HEADER
#define ENGINE_APP_HEADER

#include "if_app.h"

#include <memory>

namespace wwist {
	/**
	 * @brief Engine for software development.
	 *
	 * @code
	 * int main() {
	 *		using namespace wwist;
	 *
	 *		Engine engine;				// this!
	 *		auto app = std::make_unique<UserApplication>();	// Inherited from IApplication.
	 *
	 *		if (!engine.Initialize(std::move(app), "TestApp")) {
	 *			printf("!! Initialize Failed !!\n");
	 *			return -1;
	 *		}
	 *
	 *		engine.Run();
	 *		engine.Quit();
	 *
	 *		return 0;
	 * }
	 * @endcode
	 *
	 * @remarks Please ensure that calls are made only at the entry point.
	 */
	class ApplicationEngine {
	public:
		/**
		 * @brief Constructor.
		 */
		ApplicationEngine();

		/**
		 * @brief Destructor.
		 */
		~ApplicationEngine();

		/**
		 * @brief Engine initialize.
		 *
		 * @param app User-defined class inheriting from IApplication.
		 * @param title Application name. default: "default skeleton".
		 * @param width Application window x-size. default: "1200".
		 * @param height Application window y-size. default: "800".
		 *
		 * @retval true Succeeded engine initialize.
		 * @retval false Please check your CMakeLists to ensure the required libraries are properly linked.
		 */
		bool Initialize(std::unique_ptr<IApplication> app
		              , const char* title = "Default Skeleton"
		              , const int& width  = 1200
		              , const int& height = 800);

		/**
		 * @brief Start the loop.
		 */
		void Run();

		/**
		 * @brief Software closing.
		 */
		void Quit();

	private:
		/**
		 * @brief Rendering process per frame.
		 */
		void RenderFrame();

	private: /** pImpl idiom. */
		class Impl;
		std::unique_ptr<Impl> impl_;

	};
}

#endif // ENGINE_APP_HEADER