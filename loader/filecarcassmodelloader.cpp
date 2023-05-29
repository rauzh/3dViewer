#include "filecarcassmodelloader.h"
#include "exceptions.h"


FileCarcassModelLoader::FileCarcassModelLoader() {
    _file = std::make_shared<std::ifstream>();
}

FileCarcassModelLoader::FileCarcassModelLoader(std::shared_ptr<std::ifstream> &file) {
    _file = file;
}

void FileCarcassModelLoader::open(std::string &fileName) {
    if (!_file){
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }

    _file->open(fileName);

    if (!_file) { 
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }
}

void FileCarcassModelLoader::close() {
    if (!_file) {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }

    _file->close();
}

std::size_t FileCarcassModelLoader::loadCount() {
    int count;

    *_file >> count;

    return count;
}

Vertex FileCarcassModelLoader::loadVertex() {
    double x, y, z;

    *_file >> x >> y >> z;

    return Vertex(x, y, z);
}

std::vector<Vertex> FileCarcassModelLoader::loadVertexes() {
    std::vector<Vertex> vertexes;

    int vertexNum;
    *_file >> vertexNum;

    if (vertexNum <= 0)
    {
        std::string msg = "wrong vertex num";
        throw SourceException(msg);
    }

    double x, y, z;

    for (int i = 0; i < vertexNum; i++)
    {
       *_file >> x >> y >> z;
       vertexes.push_back(Vertex(x, y, z));
    }

    return vertexes;
}

std::vector<Link> FileCarcassModelLoader::loadLinks(int &vertexNum) {
    std::vector<Link> links;

    int linksNum;
    *_file >> linksNum;

    if (linksNum <= 0) {
        std::string msg = "wrong links num";
        throw SourceException(msg);
    }

    int vertex1Index, vertex2Index;

    for (int i = 0; i < linksNum; i++) {
        *_file >> vertex1Index >> vertex2Index;

        if (vertex1Index <= 0 or vertex2Index <= 0 or
            vertex1Index > vertexNum or vertex2Index > vertexNum)
        {
            std::string msg = "wrong link data";
            throw SourceException(msg);
        }

        links.push_back(Link(vertex1Index, vertex2Index));
    }

    return links;
}
