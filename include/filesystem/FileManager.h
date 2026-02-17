#pragma once
#include<string>
#include<vector>


class file
{
    private:
    int fileId;
    std::string name;
    int ownerId;
    std::string content;

    std::vector<file> files;

    public:
    void createFile();
    void listFiles();
    bool deleteFile(int ownerId , int fileId);
};