#ifndef FILECARCASSMODELLOADER_H
#define FILECARCASSMODELLOADER_H

#include <fstream>

#include "basecarcassmodelloader.h"

class FileCarcassModelLoader : public BaseCarcassModelLoader {
public:
    FileCarcassModelLoader();
    FileCarcassModelLoader(std::shared_ptr<std::ifstream> &file);

    virtual void open(std::string &fileName) override;
    virtual void close() override;

    virtual std::size_t loadCount() override;
    virtual Vertex loadVertex() override;
    virtual std::vector<Vertex> loadVertexes() override;
    virtual std::vector<Link> loadLinks(int &vertexNum) override;

private:
    std::shared_ptr<std::ifstream> _file;
};

#endif // FILECARCASSMODELLOADER_H
