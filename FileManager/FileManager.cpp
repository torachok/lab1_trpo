#include "FileManager.h"

FileManager::FileManager(ILog *log) {
    logger = log;
    if(logger == nullptr) qWarning("Logger is not initialized!");

}

FileManager::~FileManager()
{
    for(int i =0; i<trackFiles.size(); i++){
        delete trackFiles[i];
        trackFiles[i]=nullptr;}

}

void FileManager::addFile(QString path)
{
    File* temp = new File(path);
    trackFiles.push_back(temp);

    connect(temp, &File::changes, logger, &ILog::log);
}

void FileManager::updateFile()
{
    for(int i = 0; i < trackFiles.size(); i++){
        trackFiles[i]->update();
    }
}
