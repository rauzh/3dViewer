#ifndef LOADCOMMAND_H
#define LOADCOMMAND_H

#include <cstddef>
#include <memory>

#include "basecommand.h"

using ID = std::shared_ptr<std::size_t>;

class LoadCommand : public BaseCommand { };

class LoadModel : public LoadCommand {
public:
    LoadModel(const ID &id, std::string &fileName);

    virtual void execute() override;

private:
    std::string _fileName;
    ID _id;
};


class LoadScene : public LoadCommand {
public:
    LoadScene(const std::string fileName);

    virtual void execute() override;

private:
    std::string _fileName;
};

#endif // LOADCOMMAND_H
