#ifndef DRAWVISITOR_H
#define DRAWVISITOR_H

#include <memory>
#include "objectvisitor.h"

using namespace std;

class DrawVisitor : public ObjectVisitor
{
public:
    DrawVisitor() = default;
    DrawVisitor(const DrawVisitor &visitor) {this->_camera = visitor._camera; this->_drawer = visitor._drawer;}
    DrawVisitor(const std::shared_ptr<Camera> camera, const std::shared_ptr<BaseDrawer> drawer);

    ~DrawVisitor() = default;

    virtual void visit(const std::shared_ptr<Object> &object) override;
    virtual void visit(CarcassModel &carc) override;
    virtual void visit(Camera &camera) override {};

    Vertex getProjection(const Vertex &vertex);

    virtual void setCenter(Vertex v) { }

protected:
    std::shared_ptr<Camera> _camera;
    std::shared_ptr<BaseDrawer> _drawer;
};

#endif // DRAWVISITOR_H
