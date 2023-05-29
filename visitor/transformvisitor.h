#ifndef TRANSFORMVISITOR_H
#define TRANSFORMVISITOR_H

#include <memory>
#include "objectvisitor.h"

using namespace std;

class TransformVisitor : public ObjectVisitor
{
public:
    TransformVisitor() = default;
    TransformVisitor(const Matrix<double> &mtr, Vertex &center);
    TransformVisitor(const TransformVisitor &visitor);
    TransformVisitor &operator = (const TransformVisitor &visitor);

    ~TransformVisitor() = default;

    virtual void visit(const std::shared_ptr<Object> &object) override;
    virtual void visit(CarcassModel &carc) override;
    virtual void visit(Camera &camera) override;

    void transform(std::vector<Vertex> vertexes);
    void transform(CarcassModel &carc);
    void moveToCenter(CarcassModel &carc);
    void moveToOrigin(CarcassModel &carc);

    virtual void setCenter(Vertex v) {_center = v;}
    Vertex getCenter() {return _center;}

protected:
    Matrix<double> _mtr;
    Vertex _center;
};

#endif // TRANSFORMVISITOR_H
