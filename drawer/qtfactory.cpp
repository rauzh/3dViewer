#include "qtfactory.h"

QtFactory::QtFactory(weak_ptr<QGraphicsScene> scene) { _scene = scene; }

std::unique_ptr<BaseDrawer> QtFactory::createDrawer() {
    std::unique_ptr<BaseDrawer> aboba = std::make_unique<QtDrawer>(_scene);
    return aboba;
}
