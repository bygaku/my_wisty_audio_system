#ifndef APPLICATION_HEADER
#define APPLICATION_HEADER

#include <if_app.h>

namespace wwist {
	/**
	 * @attention This class operated by SoftwareEngine.
	 */
	class UserApplication final : public IApplication {
	public:
		/**
		 * @brief Constructor.
		 */
		UserApplication();

		/**
		 * @brief Destructor.
		 */
		~UserApplication() override;

		/**
		 * @brief Application initialize.
		 *
		 * @retval true Succeeded engine initialize.
		 * @retval false Something happened in this method.
		 */
		bool Initialize() override;

		/**
		 * @brief Update Process.
		 * @param dt Delta-Time.
		 * @remark It's called every frame on Engine.
		 */
		void Update(float dt) override;

		/**
		 * @brief Rendering Process.
		 * @remark It's called every frame on Engine.
		 */
		void Render() override;

		/**
		 * @brief Quit Process.
		 * @remark It's called on Engine, when application closing.
		 */
		void Quit() override;
	};
}


#endif // APPLICATION_HEADER