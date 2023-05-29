#include "drawmanagercreator.h"


std::shared_ptr<DrawManager> DrawManagerCreator::createManager() {
    if (nullptr == _manager)
        createInstance();

    return _manager;
}


void DrawManagerCreator::createInstance() {
    static std::shared_ptr<DrawManager> manager = std::make_shared<DrawManager>();
    _manager = manager;
}
