#ifndef FILEMODELBUILDDIRECTOR_H
#define FILEMODELBUILDDIRECTOR_H


#include "basemodelbuilddirector.h"
#include "filecarcassmodelloader.h"

class FileModelBuildDirector : public BaseModelBuildDirector {
public:
    FileModelBuildDirector();
    explicit FileModelBuildDirector(std::shared_ptr<FileCarcassModelLoader> &loader);

    ~FileModelBuildDirector() override = default;

    std::shared_ptr<CarcassModel> create(std::string &fileName) override;

protected:
    std::shared_ptr<FileCarcassModelLoader> _loader;
    std::shared_ptr<BaseModelBuilder> _builder;
};

#endif // FILEMODELBUILDDIRECTOR_H
