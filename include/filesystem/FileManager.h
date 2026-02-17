#pragma once
#include <string>
#include <vector>

class File
{
private:
    int fileId;
    std::string name;
    int ownerId;
    std::string content;

    public:
    File(const int fileId,const std::string& name,const int ownerId,const std::string& content);

     int getId() const;
     int getOwnerId() const;
     std::string getName() const;
     std::string getContent() const;
};

class FileManager
{
    std::vector<File> files;

public:
    void createFile(const std::string& name, int ownerId, const std::string& content);
    void listFiles(int ownerId);
    bool deleteFile(int ownerId, int fileId);
};