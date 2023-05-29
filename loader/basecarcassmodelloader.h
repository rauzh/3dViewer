#ifndef BASECARCASSMODELLOADER_H
#define BASECARCASSMODELLOADER_H

#include <string>
#include <vector>

#include "vertex.h"
#include "link.h"


class BaseCarcassModelLoader {
public:
    BaseCarcassModelLoader() = default;
    virtual ~BaseCarcassModelLoader() = default;

    virtual void open(std::string &fileName) = 0;
    virtual void close() = 0;

    virtual std::size_t loadCount() = 0;
    virtual Vertex loadVertex() = 0;
    virtual std::vector<Vertex> loadVertexes() = 0;
    virtual std::vector<Link> loadLinks(int &vertexNum) = 0;
};

#endif // BASECARCASSMODELLOADER_H
