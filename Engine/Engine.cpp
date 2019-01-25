#include "Engine.hpp"

// Purpose of the Engine class is so track the state of the Engine
Engine::Engine (void) {
	on = false;
}

bool Engine::isOn () {
	return on;
}

void Engine::setOn (bool o) {
	on = o;
}
