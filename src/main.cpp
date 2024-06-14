#include <Geode/Geode.hpp>
#include <Geode/modify/LoadingLayer.hpp>

using namespace geode::prelude;

$execute {
	if (!SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS)) {
		DWORD error = GetLastError();
		log::error("Couldn't set the process priority, error: {}", error);
		return;
	}

	log::debug("Process priority is now set to HIGH.");
};
