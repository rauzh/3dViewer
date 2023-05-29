#include "drawvisitor.h"

DrawVisitor::DrawVisitor(const std::shared_ptr<Camera> camera, const std::shared_ptr<BaseDrawer> drawer) {
    _camera = camera;
    _drawer = drawer;
}

void DrawVisitor::visit(const std::shared_ptr <Object> &object) {
    auto myself = _self_ptr.lock();
    object->accept(myself); 
}

Vertex DrawVisitor::getProjection(const Vertex &vertex) {
    Vertex projection = vertex;

    projection.setX(projection.getX() + _camera->getLocation().getX());
    projection.setY(projection.getY() + _camera->getLocation().getY());

    return projection;
}

void DrawVisitor::visit(CarcassModel &model) {
    auto vertexes = model.getModel()->getVertexes();
    auto links = model.getModel()->getLinks();
    auto center = model.getModel()->getCenter();

    for (auto link : links) {
        _drawer->drawLine(getProjection(vertexes.at(link.getFirst() - 1)).getAbsVertex(center),
                            getProjection(vertexes.at(link.getSecond() - 1)).getAbsVertex(center));
    }
}
