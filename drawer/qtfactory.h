#ifndef QTFACTORY_H
#define QTFACTORY_H

#include "abstractfactory.h"
#include "qtdrawer.h"

class QtFactory : public AbstractFactory {
public:
    explicit QtFactory(weak_ptr<QGraphicsScene> scene);

    std::unique_ptr<BaseDrawer> createDrawer() override;

private:
    weak_ptr<QGraphicsScene> _scene;
};

#endif // QTFACTORY_H
