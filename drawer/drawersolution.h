#ifndef DRAWERFACTORYSOLUTION_H
#define DRAWERFACTORYSOLUTION_H

#include "abstractfactory.h"
#include "qtfactory.h"

template <typename Tfactory, typename Tscene>
class DrawerSolution {
public:
    std::unique_ptr<BaseDrawer> createDrawer(std::weak_ptr<Tscene> scene);
};

#include "drawersolution.hpp"

#endif // DRAWERFACTORYSOLUTION_H
