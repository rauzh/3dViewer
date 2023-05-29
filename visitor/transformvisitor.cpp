#include <iostream>

#include "transformvisitor.h"
#include <cmath>

TransformVisitor::TransformVisitor(const Matrix<double> &mtr, Vertex &center) {
    this->_mtr = mtr;
    this->_center = center;
}

TransformVisitor::TransformVisitor(const TransformVisitor &visitor) {
    this->_mtr = visitor._mtr;
    this->_center = visitor._center;
}

TransformVisitor &TransformVisitor::operator = (const TransformVisitor &visitor) {
    this->_mtr = visitor._mtr;
    this->_center = visitor._center;
    return *this;
}

void TransformVisitor::visit(const std::shared_ptr <Object> &object) {
    object->updateCenter();
    this->_center = object->getCenter();
    auto myself = _self_ptr.lock();
    object->accept(myself);
}

void TransformVisitor::visit(CarcassModel &carc) {
    auto model = carc.getModel();
    model->updateCenter();

    moveToCenter(carc);
    transform(carc);
    moveToOrigin(carc);

    model->updateCenter();
}

void TransformVisitor::transform(CarcassModel &carc) {
    for (auto &vertex : carc.getModel()->getVertexes()) {
        Matrix<double> cur_location = {{vertex.getX(), vertex.getY(), vertex.getZ(), 1}};
        Matrix<double> new_location = cur_location * _mtr;

        vertex.setX(new_location[0][0]);
        vertex.setY(new_location[0][1]);
        vertex.setZ(new_location[0][2]);
    }

    carc.getModel()->updateCenter();
}

void TransformVisitor::moveToCenter(CarcassModel &carc) {
    Vertex diff = _center - Vertex(0, 0, 0);
    Matrix<double> mtrToCenter = {{    1,            0,            0,             0      },
                                  {    0,            1,            0,             0      },
                                  {    0,            0,            1,             0      },
                                  {diff.getX(),  diff.getY(),  diff.getZ(),       1      }};

    for (auto &vertex : carc.getModel()->getVertexes()) {
        Matrix<double> cur_location = {{vertex.getX(), vertex.getY(), vertex.getZ(), 1}};
        Matrix<double> new_location = cur_location * mtrToCenter;

        vertex.setX(new_location[0][0]);
        vertex.setY(new_location[0][1]);
        vertex.setZ(new_location[0][2]);
    }

    carc.getModel()->updateCenter();
}

void TransformVisitor::moveToOrigin(CarcassModel &carc) {
    Vertex diff = Vertex(0, 0, 0) - _center;
    Matrix<double> mtrToCenter = {{    1,            0,            0,             0      },
                                  {    0,            1,            0,             0      },
                                  {    0,            0,            1,             0      },
                                  {diff.getX(),  diff.getY(),  diff.getZ(),       1      }};
    
    for (auto &vertex : carc.getModel()->getVertexes()) {
        Matrix<double> cur_location = {{vertex.getX(), vertex.getY(), vertex.getZ(), 1}};
        Matrix<double> new_location = cur_location * mtrToCenter;

        vertex.setX(new_location[0][0]);
        vertex.setY(new_location[0][1]);
        vertex.setZ(new_location[0][2]);
    }

    carc.getModel()->updateCenter();
}

void TransformVisitor::visit(Camera &camera) {
    Vertex diff = Vertex(0, 0, 0) - _center;
    camera.setLocation(camera.getLocation() + diff);

    Matrix<double> cur_location = {{camera.getLocation().getX(), camera.getLocation().getY(), camera.getLocation().getZ(), 1}};
    Matrix<double> new_location = cur_location * _mtr;

    camera.setLocation(Vertex(new_location[0][0], new_location[0][1], new_location[0][2]));

    camera.setLocation(camera.getLocation() - diff);
}
