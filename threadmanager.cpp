#include "threadmanager.h"

ThreadManager::ThreadManager(const std::string &name, const std::string &path) : keeper(name), newPath(path)
{
    threadsCount = 4;
    create();
}

void ThreadManager::distribute()
{
    std::string name;
    while(keeper.haveNext()) 
    {
	{
 	  boost::lock_guard<boost::mutex> lock(tMutex);
	  name = keeper.getNextFileName();
	}
	HtmlReplacer task(name, newPath);
	task.replace();
	task.saveFile();
    }
}

void ThreadManager::create()
{
    boost::thread_group replacers;
    for(int i = 0; i < threadsCount; i++) 
    {
        replacers.create_thread(boost::bind(&ThreadManager::distribute, this));        
    }
    replacers.join_all();
}

