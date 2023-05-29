#include "transformer.h"

Transformer::Transformer(const double &p1,
                         const double &p2,
                         const double &p3)
{
    _p1 = p1;
    _p2 = p2;
    _p3 = p3;
}

Transformer::Transformer(const Transformer &trans) {
    _p1 = trans._p1;
    _p2 = trans._p2;
    _p3 = trans._p3;
}

Transformer &Transformer::operator = (const Transformer &trans) {
    _p1 = trans._p1;
    _p2 = trans._p2;
    _p3 = trans._p3;

    return *this;
}

void Transformer::toVisitor(Matrix<double> &mtr, const std::shared_ptr <Object> &object) {

    object->updateCenter();
    Vertex center = object->getCenter();
    shared_ptr<ObjectVisitor> visitor = std::make_shared<TransformVisitor>(mtr, center);
    // cout << "Transformer::toVisitor center" << object->getCenter().getX() << "\n";
    object->accept(visitor);
    // // cout << "Transformer::toVisitor center" << object->getCenter().getX() << "\n";
    // // object->updateCenter();
    // cout << "Transformer::toVisitor center" << object->getCenter().getX() << "\n";
}

void Transformer::move(const std::shared_ptr <Object> &object) {
    Matrix<double> mtr = {{ 1,  0,  0, 0},
                          { 0,  1,  0, 0},
                          { 0,  0,  1, 0},
                          {_p1, _p2, _p3, 1}};

    toVisitor(mtr, object);
}

void Transformer::scale(const std::shared_ptr <Object> &object) {
    Matrix<double> mtr = {{_p1,  0,  0, 0},
                          { 0, _p2,  0, 0},
                          { 0,  0, _p3, 0},
                          { 0,  0,  0, 1}};

    toVisitor(mtr, object);
}

void Transformer::rotate(const std::shared_ptr <Object> &object) {
    Matrix<double> mtr_ox = {{1,        0,        0,          0},
                             {0,     cos(_p1), -sin(_p1),     0},
                             {0,     sin(_p1),  cos(_p1),     0},
                             {0,        0,        0,          1}};

    Matrix<double> mtr_oy = {{ cos(_p2), 0, sin(_p2), 0},
                             {    0,    1,    0,      0},
                             {-sin(_p2), 0, cos(_p2), 0},
                             {    0,    0,    0,      1}};

    Matrix<double> mtr_oz = {{ cos(_p3), -sin(_p3),     0,        0},
                             { sin(_p3),  cos(_p3),     0,        0},
                             {    0,        0,          1,        0},
                             {    0,        0,          0,        1}};

    Matrix<double> mtr = mtr_ox * mtr_oy * mtr_oz;
    toVisitor(mtr, object);
}
