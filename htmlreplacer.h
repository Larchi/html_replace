#ifndef HTMLREPLACER_H
#define HTMLREPLACER_H

#include <string>
#include <boost/regex.hpp>
#include <boost/filesystem.hpp>
#include <fstream>
#include <iostream>

class HtmlReplacer
{
private:
    std::string fileData;
    std::string fileName;
    std::string newPath;
    const boost::regex xPattern;
    bool openFile();
    std::string getResultPath();
public:
    HtmlReplacer(const std::string &fileName, const std::string &newPath);
    void replace();
    bool saveFile();
};

#endif // HTMLREPLACER_H
