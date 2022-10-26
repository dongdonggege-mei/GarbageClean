#ifndef _GARBAGE_CLEAN_
#define _GARBAGE_CLEAN_

#include <Public/Helper/qaxpublic.h>
#include <QAXBase/Interface/ISpecialValue.h>
#include <Public/Helper/StringUtils.h>
#include <Windows.h>
#include <io.h>
#include <list>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <vector>
#include <QCheckBox>
#include <QTableView>
#include <QLCDNumber>
#include <QStandardItemModel>

enum GarbageFileType
{
    BlankFileType = 0,
    SystemTempFile,
    InternetCache,
};

enum SignOfDeleteFile
{
    BlankSign = 0,
    DeleteSucceed,
    DeleteFailed,
    PathNoExist,
    FileOpening
};

struct FileAttrib {         //扫描到的文件用这个结构体描述
    std::wstring _path;     //路径        ---->若改变位置，需要注意GarbageClean.cpp文件中的FindAllFile函数的数据写入
    uint32_t _size;         //文件大小     ---->若改变位置，需要注意GarbageClean.cpp文件中的FindAllFile函数的数据写入
    std::wstring _exten;    //文件后缀
    HANDLE _fHandle;        //文件在当前进程中的句柄
    //uint32_t _attrib;        //文件属性
};

class FirstGarbageClean {
public:
    //判断文件是否存在子文件夹
    bool IsFolder(const WIN32_FIND_DATA& fileInfo);

    bool IsNotDot(const WIN32_FIND_DATA& fileInfo);

    //获取系统临时文件夹,将临时文件夹字符串存储到path中
    bool GetSysTempFolder(wchar_t* path);

    //获取文件扩展名，以.为区分，若文件没有后缀.，则获取失败(一直会读取内存出错，不清楚具体原因)
    const wchar_t* GetFileExtNameFromPath(const wchar_t* lpszPathName);

    //获取文件扩展名，以.为区分，将后缀存储到buffer中
    bool GetFileExtNameFromPath(const wchar_t* lpszPathname, Base::CPathString& buffer);


private:
    ISpecialValuePtr& InternalGetSpecialValuePtr(void);

private:
    ISpecialValuePtr _svptr;
};

static FirstGarbageClean FGC;

//将文件大小转换为“B”或“KB”的字符串
std::wstring GetFileSize(uint32_t size);

//查找dir目录下的所有文件（包括子文件夹），将文件根据<后缀名，自定义文件属性>存储到fileBuf中
void FindAllFile(std::unordered_map<std::wstring, std::list<FileAttrib>>& fileBuf,\
    std::unordered_map<std::wstring, uint64_t>& extenFileSize, const wchar_t* dir);

//根据文件属性删除文件（根据绝对路径删除文件），使用FileAttrib作为形参，便于后续做删除文件的各种判断
DWORD DeleteFileByFileAttr(FileAttrib& fileAttr, std::unordered_map<std::wstring, uint64_t>& extenFileSize);

//根据后缀删除文件
void DeleteFileByExten(std::unordered_map<std::wstring, std::list<FileAttrib>>& fileBuf,\
    std::unordered_map<std::wstring, uint64_t>& extenFileSize, const wchar_t* ex);

//删除所有文件
void DeleteAllFile(std::unordered_map<std::wstring, std::list<FileAttrib>>& fileBuf,\
    std::unordered_map<std::wstring, uint64_t>& extenFileSize);

#endif // !_GARBAGE_CLEAN_

