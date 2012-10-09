#ifndef FOLDERKEEPER_H
#define FOLDERKEEPER_H

#include <vector>
#include <string>
#include <boost/filesystem.hpp>
#include <boost/thread/mutex.hpp>

class FolderKeeper
{
    std::vector<std::string> fileNames;
    void readFolder(const std::string &name);
    int nextIndex;
    int folderSize;
    boost::mutex fMutex;
	
public:
    FolderKeeper(const std::string &name);
    std::string getNextFileName();
    bool haveNext() const;
};

#endif // FOLDERKEEPER_H
