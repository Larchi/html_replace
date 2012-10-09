#include "folderkeeper.h"
using namespace boost;

FolderKeeper::FolderKeeper(const std::string &name) : nextIndex(0)
{
    readFolder(name);
}

void FolderKeeper::readFolder(const std::string &name)
{
    filesystem::path p(name);

    if(!filesystem::exists(p)) {
        std::cout << "File don't exist" << std::endl;
        return;
    }

    if(filesystem::is_directory(p)) {

        filesystem::directory_iterator endIter;
        for(filesystem::directory_iterator dIter(p); dIter != endIter; ++dIter)
        {
            if(filesystem::is_regular_file(*dIter)) {
                fileNames.push_back(filesystem::path(*dIter).string());
            }
        }
    }
    folderSize = fileNames.size();
}

std::string FolderKeeper::getNextFileName()
{
    boost::lock_guard<boost::mutex> lock(fMutex);
    return fileNames.at(nextIndex++);
}

bool FolderKeeper::haveNext() const
{
    if(nextIndex >= folderSize | fileNames.empty()) {
	return false;
    }
    return true;
}
