#include "filesystem/FileManager.h"
#include <iostream>

File::File(const int fileId, const std::string &name, const int ownerId, const std::string &content)
{
    this->fileId = fileId;
    this->name = name;
    this->ownerId = ownerId;
    this->content = content;
}

int File::getId() const
{
    return fileId;
}

int File::getOwnerId() const
{
    return ownerId;
}
std::string File::getName() const
{
    return name;
}

std::string File::getContent() const
{
    return content;
}

FileManager::FileManager()
{
}

void FileManager::createFile(const std::string &name, int ownerId, const std::string &content)
{
    int ID = files.size() + 1;
    File newFile = File(ID, name, ownerId, content);
    files.push_back(newFile);
}

void FileManager::listFiles(int ownerId)
{
    for (auto file : files)
    {
        if (file.getOwnerId() == ownerId)
        {
            std::cout << "Id -> " << file.getId() << " Name -> " << file.getName() << std::endl;
        }
    }
}

bool FileManager::deleteFile(int ownerId, int fileId)
{
    for (auto it = files.begin(); it != files.end(); ++it)
    {
        if (it->getOwnerId() == ownerId && it->getId() == fileId)
        {
            files.erase(it);
            return true;
        }
    }
    return false;
}