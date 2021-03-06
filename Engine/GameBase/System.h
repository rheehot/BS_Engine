#pragma once

#include "Core.h"

namespace BE
{
	/**
	 * @brief A system that is a singleton object in the system layer.
	 * @see README
	*/
	class BS_API System
	{
	public:
		/// @brief Initializes everything necessary to run the game engine.
		void Initialize() noexcept;

		/// @brief To constantly call to update the scene with the manager.
		Int32 RunLoop() noexcept;

		/// @brief Clean up everything created by the game engine.
		void Release() noexcept;

	private:
		class ThreadManager* threadManager;
	};
}