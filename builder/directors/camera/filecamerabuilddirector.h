#ifndef FILECAMERABUILDDIRECTOR_H
#define FILECAMERABUILDDIRECTOR_H


#include "basecamerabuilddirector.h"
#include "filecarcassmodelloader.h"

class FileCameraBuildDirector : public BaseCameraBuildDirector {
public:
    FileCameraBuildDirector();
    explicit FileCameraBuildDirector(std::shared_ptr<FileCarcassModelLoader> &loader);

    ~FileCameraBuildDirector() override = default;

    std::shared_ptr<Camera> create(std::string &fileName) override;

protected:
    std::shared_ptr<BaseCameraBuilder> _builder;
    std::shared_ptr<FileCarcassModelLoader> _loader;
};

#endif // FILECAMERABUILDDIRECTOR_H
