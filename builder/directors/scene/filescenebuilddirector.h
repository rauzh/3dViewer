#ifndef FILESCENEBUILDDIRECTOR_H
#define FILESCENEBUILDDIRECTOR_H


#include "basescenebuilddirector.h"
#include "filecarcassmodelloader.h"

class FileSceneBuildDirector : public BaseSceneBuildDirector {
public:
    FileSceneBuildDirector();
    explicit FileSceneBuildDirector(std::shared_ptr<FileCarcassModelLoader> &loader);
    ~FileSceneBuildDirector() = default;

    std::shared_ptr<Scene> create(std::string &fileName) override;

protected:
    virtual void createModels(std::shared_ptr<SceneBuilder> builder,
                    std::string &fileName) override;
    virtual void createCameras(std::shared_ptr<SceneBuilder> builder,
                     std::string &fileName) override;

    std::shared_ptr<FileCarcassModelLoader> _loader;
    std::shared_ptr<SceneBuilder> _builder;
};

#endif // FILESCENEBUILDDIRECTOR_H
