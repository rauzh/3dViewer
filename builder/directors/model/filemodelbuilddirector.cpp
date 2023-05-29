#include "filemodelbuilddirector.h"
#include "exceptions.h"
#include "modelbuilder.h"


FileModelBuildDirector::FileModelBuildDirector() {
    _builder = std::make_shared<ModelBuilder>();
    _loader = std::make_shared<FileCarcassModelLoader>();
}

FileModelBuildDirector::FileModelBuildDirector(std::shared_ptr<FileCarcassModelLoader> &loader) {
    _builder = std::make_shared<ModelBuilder>();
    _loader = loader;
}

std::shared_ptr<CarcassModel> FileModelBuildDirector::create(std::string &fileName) {
    
    _loader->open(fileName);
    _builder->build();

    vector<Vertex> vertexes = _loader->loadVertexes();
    int vertexNum = vertexes.size();

    std::vector<Link> links = _loader->loadLinks(vertexNum);
    int linksNum = links.size();

    for (int i = 0; i < vertexNum; i++)
        _builder->buildVertex(vertexes[i]);

    for (int i = 0; i < linksNum; i++)
        _builder->buildLink(links[i]);

    _loader->close();

    return _builder->get();
}
