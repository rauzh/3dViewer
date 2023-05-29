#include "transformmanagercreator.h"


std::shared_ptr<TransformManager> TransformManagerCreator::createManager() {
    if (nullptr == _manager)
        createInstance();

    return _manager;
}

void TransformManagerCreator::createInstance() {
    static std::shared_ptr<TransformManager> manager = std::make_shared<TransformManager>();
    _manager = manager;
}
