#include "CDirectory.hpp"
#include "CFile.hpp"

void CDirectory::getName()
{
    WIN32_FIND_DATA winFileData;
    HANDLE hFile;
    QString tmpPath = m_fullPath + "\\*.*";
    QString buffer;
    CDirectory *pDir = new CDirectory(m_fullPath);

    hFile = FindFirstFile(tmpPath.toStdString().c_str(),&winFileData);

    if (hFile!=INVALID_HANDLE_VALUE)
    {
        do
        {
            if (!strcmp(winFileData.cFileName, ".") || !strcmp(winFileData.cFileName, ".."))
                continue;

            if (winFileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
            {
                buffer = m_fullPath + "\\" + winFileData.cFileName;
                addObject(pDir);
            }
            else
            {
                buffer = m_fullPath + "\\" + winFileData.cFileName;
                addObject(new CFile(buffer));
            }

        }
        while (FindNextFile(hFile,&winFileData)!=0);

        FindClose(hFile);
    }
}

void CDirectory::addObject(IFileSystemObject *pSystemObject)
{
    listObject.push_back(pSystemObject);
}

CDirectory::~CDirectory()
{
    while(!listObject.empty())
           {
             list<IFileSystemObject*>::iterator it = listObject.begin();
             delete *it;
             listObject.erase(it);
           }
}
