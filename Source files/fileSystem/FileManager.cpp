#include "filesystem/FileManager.h"
#include <iostream>

#include "filesystem/FileManager.h"
#include <fstream>
#include <sstream>

FileManager::FileManager(const std::string& path)
{
    filePath = path;
}

std::vector<File> FileManager::loadFiles()
{
    std::vector<File> files;
    std::ifstream file(filePath);

    if (!file.is_open())
        return files;

    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string idStr, ownerStr, name, content;

        std::getline(ss, idStr, '|');
        std::getline(ss, ownerStr, '|');
        std::getline(ss, name, '|');
        std::getline(ss, content, '|');

        int id = std::stoi(idStr);
        int ownerId = std::stoi(ownerStr);

        files.push_back(File(id, name, ownerId, content));
    }

    return files;
}

void FileManager::saveFiles(const std::vector<File>& files)
{
    std::ofstream file(filePath);

    for (const auto& f : files)
    {
        file << f.getId() << "|"
             << f.getOwnerId() << "|"
             << f.getName() << "|"
             << f.getContent() << "\n";
    }
}


// FileManager::FileManager()
// {
// }

// void FileManager::createFile(const std::string &name, int ownerId, const std::string &content)
// {
//     int ID = files.size() + 1;
//     File newFile = File(ID, name, ownerId, content);
//     files.push_back(newFile);
// }

// void FileManager::listFiles(int ownerId)
// {
//     for (const auto& file : files)
//     {
//         if (file.getOwnerId() == ownerId)
//         {
//             std::cout << "Id -> " << file.getId() << " Name -> " << file.getName() << std::endl;
//         }
//     }
// }

// bool FileManager::deleteFile(int ownerId, int fileId)
// {
//     for (auto it = files.begin(); it != files.end(); ++it)
//     {
//         if (it->getOwnerId() == ownerId && it->getId() == fileId)
//         {
//             files.erase(it);
//             return true;
//         }
//     }
//     return false;
// }