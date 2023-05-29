#include "drawmanager.h"
#include "basemodel.h"
#include "drawvisitor.h"
#include "camera.h"

void DrawManager::drawScene(std::shared_ptr<Scene> scene) {
    shared_ptr<ObjectVisitor> visitor = std::make_shared<DrawVisitor>(_camera, _drawer);

    (*scene->getVisibleObjects()).accept(visitor);
}
