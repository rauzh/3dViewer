#include "modelloadmoderatorcreator.h"
#include "filemodelbuilddirector.h"

std::shared_ptr<ModelLoadModerator> ModelLoadModeratorCreator::createModerator() {
    if (nullptr == _moderator)
        createInstance();

    return _moderator;
}

void ModelLoadModeratorCreator::createInstance() {
    static std::shared_ptr<ModelLoadModerator> moderator;

    if (!moderator) {
        auto loader = std::make_shared<FileCarcassModelLoader>();
        std::shared_ptr<BaseModelBuildDirector> director = std::make_shared<FileModelBuildDirector>(loader);
        moderator = std::make_shared<ModelLoadModerator>(director);
    }

    _moderator = moderator;
}
