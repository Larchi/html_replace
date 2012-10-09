#include "htmlreplacer.h"

HtmlReplacer::HtmlReplacer(const std::string &fileName, const std::string &newPath) : xPattern("(<[aA(link)])(.*?)(href=\")(.*?)(\")(.*?)(>)")
{
    this->fileName = fileName;
    this->newPath = newPath;
    openFile();
}

bool HtmlReplacer::openFile()
{
    std::ifstream openIn(fileName.c_str());

    if(!openIn) {
        std::cout << "File not found" << std::endl;
        return false;
    } else {
        while(!openIn.eof())
        {
            fileData.append(1, openIn.get());
        }

        openIn.close();
        return true;
    }
}

bool HtmlReplacer::saveFile()
{  
	std::ofstream openOut(getResultPath().c_str());

    if(!openOut) {
        std::cout << "Can't create file" << std::endl;
        return false;
    } else {
        for(unsigned int i = 0; i != fileData.length() - 1; i++)
        {
            openOut.put(fileData.at(i));
        }

        openOut.close();
        return true;
    }
}

std::string HtmlReplacer::getResultPath()
{
    boost::filesystem::path result(boost::filesystem::absolute("result"));
    if(!boost::filesystem::exists(result)) {
        boost::filesystem::create_directory(result);
    }
    boost::filesystem::path newpath(boost::filesystem::absolute(boost::filesystem::path(fileName).filename(), result));
    return newpath.string();
}

void HtmlReplacer::replace()
{
    std::string newPattern = "$1$2$3" + newPath + "$5$6$7";
    fileData = boost::regex_replace(fileData, xPattern, newPattern, boost::match_default | boost::format_perl);
}
