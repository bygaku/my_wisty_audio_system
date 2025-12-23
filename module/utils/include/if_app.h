#ifndef IF_APP_HEADER
#define IF_APP_HEADER

namespace wwist {
	/**
	 * @brief Interface for User Application!!
	 * @remark Please create your own App class by inheriting from this class.
	 */
	class IApplication {
	public:
		virtual ~IApplication() = default;

		virtual bool Initialize() = 0;

		virtual void Update(float dt) = 0;

		virtual void Render() = 0;

		virtual void Quit() = 0;
	};
}

#endif // IF_APP_HEADER