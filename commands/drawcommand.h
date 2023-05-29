#ifndef DRAWCOMMAND_H
#define DRAWCOMMAND_H

#include <memory>
#include <string>

#include "basecommand.h"

class DrawCommand : public BaseCommand { };

class DrawScene : public DrawCommand {
public:
    DrawScene(std::shared_ptr<BaseDrawer> drawer);

    virtual void execute() override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
};


class ClearScene : public DrawCommand {
public:
    ClearScene(std::shared_ptr<BaseDrawer> drawer);

    virtual void execute() override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
};

#endif // DRAWCOMMAND_H
