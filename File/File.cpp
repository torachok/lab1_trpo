#include "File.h"

File::File(QString path)
{
    this->path = path; //инициализация поля path
    QFileInfo q(path);
    size = (int)q.size(); //инициализация поля size
    isThere = q.exists(); //инициализация поля isThere
}

int File::getSize()
{
    return size;
}

QString File::getPath()
{
    return path;
}

bool File::getIsThere()
{
    return isThere;
}

void File::update()
{
    QFileInfo q(path);
    int new_size = (int) q.size();
    bool tillNowThere = q.exists();

    if(tillNowThere != isThere || new_size != size){
        size = new_size;
        isThere = tillNowThere;
        emit changes("Something");
    }
}
