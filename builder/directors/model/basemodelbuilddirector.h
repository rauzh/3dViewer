#ifndef BASEMODELBUILDDIRECTOR_H
#define BASEMODELBUILDDIRECTOR_H


#include "basedirector.h"
#include "modelbuilder.h"

class BaseModelBuildDirector : public BaseDirector {
public:
    virtual std::shared_ptr<CarcassModel> create(std::string &fileName) = 0;
};

#endif // BASEMODELBUILDDIRECTOR_H
