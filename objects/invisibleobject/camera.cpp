#include "camera.h"
#include "objectvisitor.h"

void Camera::accept(shared_ptr<ObjectVisitor> &vis) {
    vis->visit(*this);
}

Vertex Camera::getCenter() const {
    return _location;
}
