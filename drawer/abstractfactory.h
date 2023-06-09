#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <memory>
#include "basecommand.h"

class AbstractFactory {
public:
    virtual std::unique_ptr<BaseDrawer> createDrawer() = 0;
};

#endif // ABSTRACTFACTORY_H
