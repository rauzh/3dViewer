#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "basemanager.h"
#include "vertex.h"
#include "composite.h"
#include "camera.h"
#include "object.h"
#include "objectvisitor.h"
#include "drawvisitor.h"
#include "scene.h"
#include "basedrawer.h"
#include "drawvisitor.h"

class DrawManager : public BaseManager {
public:
    DrawManager() = default;
    DrawManager(const DrawManager &manager) = delete;
    DrawManager &operator = (const DrawManager &manager) = delete;

    ~DrawManager() = default;

    void setCamera(std::shared_ptr<Camera> camera) {_camera = camera;}
    void setDrawer(std::shared_ptr<BaseDrawer> drawer) {_drawer = drawer;}

    void drawScene(std::shared_ptr<Scene> scene);

private:
    std::shared_ptr<Camera> _camera;
    std::shared_ptr<BaseDrawer> _drawer;
};

#endif //DRAWMANAGER_H
