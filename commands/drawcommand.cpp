#include "drawcommand.h"

ClearScene::ClearScene(std::shared_ptr<BaseDrawer> drawer) : _drawer(drawer) {}

void ClearScene::execute() {
    _drawer->clearScene();
}

DrawScene::DrawScene(std::shared_ptr<BaseDrawer> drawer) : _drawer(drawer) { }

void DrawScene::execute() {
    _drawManager->setDrawer(_drawer);
    _drawManager->drawScene(_scene);
}
