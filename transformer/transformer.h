#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "matrix.h"
#include "object.h"
#include "transformvisitor.h"

class Transformer {
public:
    Transformer(const double &p1, const double &p2, const double &p3);
    Transformer(const Transformer &trans);
    Transformer &operator = (const Transformer &trans);
    ~Transformer() = default;

    void toVisitor(Matrix<double> &mtr, const std::shared_ptr <Object> &object);

    void move(const std::shared_ptr<Object> &object);
    void scale(const std::shared_ptr<Object> &object);
    void rotate(const std::shared_ptr<Object> &object);

private:
    double _p1, _p2, _p3;    
};

#endif // TRANSFORMER_H
