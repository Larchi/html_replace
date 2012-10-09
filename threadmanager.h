#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <boost/thread/thread.hpp>
#include "folderkeeper.h"
#include "htmlreplacer.h"

class ThreadManager
{
    FolderKeeper keeper;   
    int threadsCount;
    void create();
    void distribute();
    std::string newPath;
    boost::mutex tMutex;
	
public:
    ThreadManager(const std::string &name, const std::string &path);
};

#endif // THREADMANAGER_H
