#include <cmath>

#include "transformmanager.h"

void TransformManager::moveObject(const std::shared_ptr <Object> &object,
                                  const double &dx,
                                  const double &dy,
                                  const double &dz)
{
    Transformer(dx, dy, dz).move(object);
}


void TransformManager::scaleObject(const std::shared_ptr <Object> &object,
                                   const double &kx,
                                   const double &ky,
                                   const double &kz)
{
    Transformer(kx, ky, kz).scale(object);
}


void TransformManager::rotateObject(const std::shared_ptr <Object> &object,
                                   const double &ox,
                                   const double &oy,
                                   const double &oz)
{
    Transformer(ox, oy, oz).rotate(object);
}

void TransformManager::transformObject(const std::shared_ptr<Object> &object,
                                       const Matrix<double> &mtr)
{
    Vertex center = object->getCenter();
    
    shared_ptr<ObjectVisitor> visitor = std::make_shared<TransformVisitor>(mtr, center);
    object->accept(visitor);
}
