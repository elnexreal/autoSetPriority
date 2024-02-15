#include <Geode/Geode.hpp>
#include <Geode/modify/LoadingLayer.hpp>

using namespace geode::prelude;

struct AutoSetPriority : Modify<AutoSetPriority, LoadingLayer> {
    void loadingFinished() {
        LoadingLayer::loadingFinished();

        log::debug("Trying to set the process priority to HIGH...");
        try {
            SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
            log::debug("Process priority is now set to HIGH.");
        } catch (...) {
            log::error("Couldn't set the process priority.");
        }
    }
};
