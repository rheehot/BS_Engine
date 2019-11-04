#pragma once

#include "Interface.h"

/// @see This is good architecture?
enum class EManager
{
	ManagerManager,
	MemoryManager,
	ThreadManager,
	RenderingManager,
	AudioManager,
	InputManager,
	PhysicsManager,
	ResourceManager,
	AnimationManager,
	UiManager,
	ConfigManager
};

INTERFACE_BEGIN(Manager)
	INTERFACE_DEF(bool, Init)
	INTERFACE_DEF(void, Update, float)
	INTERFACE_DEF(void, Release)
INTERFACE_END