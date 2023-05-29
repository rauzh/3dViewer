#ifndef DRAWERSOLUTION_H
#define DRAWERSOLUTION_H

#include "drawersolution.h"

template <typename Tfactory, typename Tscene>
std::unique_ptr<BaseDrawer> DrawerSolution<Tfactory, Tscene>::createDrawer(std::weak_ptr<Tscene> scene) {
    std::shared_ptr<AbstractFactory> factory = std::make_shared<Tfactory>(scene);

    return factory->createDrawer();
}


#endif // DRAWERSOLUTION_H
