#include "GarbageClean.h"

bool FirstGarbageClean::IsFolder(const WIN32_FIND_DATA& fileInfo)
{
    return fileInfo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;//WIN32_FIND_DATA中的dwFileAttributes字段为文件属性，FILE_ATTRIBUTE_DIRECTORY表示文件夹
}

bool FirstGarbageClean::IsNotDot(const WIN32_FIND_DATA& fileInfo)
{
    return wcscmp(fileInfo.cFileName, L".") && \
        wcscmp(fileInfo.cFileName, L"..");
}

bool FirstGarbageClean::GetSysTempFolder(wchar_t* path)
{
    return GetTempPathW(MAX_PATH, path);
}

const wchar_t* FirstGarbageClean::GetFileExtNameFromPath(const wchar_t* lpszPathName)
{
    auto& p = InternalGetSpecialValuePtr();
    QAXASSERT(p);
    return p ? p->GetFileExtNameFromPath(lpszPathName) : L"";

}

bool FirstGarbageClean::GetFileExtNameFromPath(const wchar_t* lpszPathname, Base::CPathString& buffer)
{
    auto& p = InternalGetSpecialValuePtr();
    QAXASSERT(p);
    p->GetFileExtNameFromPath(lpszPathname, buffer);
    if (0 == wcslen(buffer.buffer()))
    {
        wchar_t nosuffix[9] = { L"nosuffix" };
        for (int i = 0; i < _countof(nosuffix); i++)
        {
            buffer[i] = nosuffix[i];
        }
    }
    return p;
}

ISpecialValuePtr& FirstGarbageClean::InternalGetSpecialValuePtr(void)
{
    if (_svptr) return _svptr;
    Base::CObjectLoader loader(L"module.base");
    _svptr = loader.CreateObject<decltype(_svptr)>();
    return _svptr;
}

std::wstring GetFileSize(uint32_t size)
{
    std::string sizeStr = "";
    if (size < 1024) {
        sizeStr = std::to_string(size);
        sizeStr += "B";
    }
    else if (size < 1024 * 1024) {
        sizeStr = std::to_string((size / 1024.0));
        sizeStr.erase(sizeStr.length() - 4, sizeStr.length());//保留sizeStr的两位小数
        sizeStr += "KB";
    }
    else if (size < 1024 * 1024 * 1024) {
        sizeStr = std::to_string((size / (1024.0 * 1024.0)));
        sizeStr.erase(sizeStr.length() - 4, sizeStr.length());//保留sizeStr的两位小数
        sizeStr += "MB";
    }
    else {
        sizeStr = std::to_string((size / (1024.0 * 1024.0 * 1024.0)));
        sizeStr.erase(sizeStr.length() - 4, sizeStr.length());//保留sizeStr的两位小数
        sizeStr += "GB";
    }
    return Base::String::utf8_to_utf16(sizeStr.c_str());
}

void FindAllFile(std::unordered_map<std::wstring, std::list<FileAttrib>>& fileBuf, \
    std::unordered_map<std::wstring, uint64_t>& extenFileSize, const wchar_t* dir)
{
	if (wcslen(dir)==0)//加一层判断，避免点击扫描却没有选择文件夹时出现的问题
	{
		return;
	}
    wchar_t* findDir = new wchar_t[wcslen(dir) + 3]{};
    wcscpy_s(findDir, wcslen(dir) + 3, dir);
    if (findDir[wcslen(findDir) - 1] != L'\\') {
        wcscat_s(findDir, wcslen(dir) + 3, L"\\");
    }
    wcscat_s(findDir, wcslen(dir) + 3, L"*");
    WIN32_FIND_DATA fileInfo;
    HANDLE handle = FindFirstFile(findDir, &fileInfo);
    if (INVALID_HANDLE_VALUE == handle) {
        std::wcout << findDir << ": FindFirstFile failed." << std::endl;
        return;
    }
    do {
        if (FGC.IsFolder(fileInfo)) {
            if (FGC.IsNotDot(fileInfo)) {
                int32_t len = wcslen(findDir) + wcslen(fileInfo.cFileName);
                wchar_t* childDir = new wchar_t[len] {};
                wcsncpy_s(childDir, len, findDir, wcslen(findDir) - 1);
                wcscat_s(childDir, len, fileInfo.cFileName);
                FindAllFile(fileBuf, extenFileSize, childDir);
                delete[] childDir;
            }
        }
        else {
            //key:FGC.GetFileExtNameFromPath(fileInfo.name)
            Base::CPathString key;
            FGC.GetFileExtNameFromPath(fileInfo.cFileName, key);
            //value:findDir + fileInfo.name
            int32_t len = wcslen(findDir) + wcslen(fileInfo.cFileName);
            wchar_t* valueOfPath = new wchar_t[len + 1]{};
            wcsncpy_s(valueOfPath, len, findDir, wcslen(findDir) - 1);
            wcscat_s(valueOfPath, len, fileInfo.cFileName);

            //去除重复的项
            //目前仅仅使用路径和文件大小判断是否重复，后续若增加文件句柄属性，可以考虑使用文件句柄判断重复
            auto valueItreator = find_if(\
                fileBuf[key.buffer()].begin(), fileBuf[key.buffer()].end(), \
                [&valueOfPath, &fileInfo](const FileAttrib& fa) \
            {return !wcscmp(fa._path.c_str(), valueOfPath) && fa._size == fileInfo.nFileSizeLow; });
            if (valueItreator == fileBuf[key.buffer()].end())
            {
                fileBuf[key.buffer()].push_back({ valueOfPath, fileInfo.nFileSizeLow, key.buffer() });
                extenFileSize[key.buffer()] += fileInfo.nFileSizeLow;
            }
            delete[] valueOfPath;
        }
    } while (FindNextFile(handle, &fileInfo));
    delete[] findDir;
    FindClose(handle);
}

DWORD DeleteFileByFileAttr(FileAttrib& fileAttr, std::unordered_map<std::wstring, uint64_t>& extenFileSize)
{
    if (nullptr == fileAttr._path.c_str() || !safeapi::path::is_path_exists(fileAttr._path.c_str())) {
        return PathNoExist;
    }
    if (DeleteFile(fileAttr._path.c_str())) {
        extenFileSize[fileAttr._exten] -= fileAttr._size;
        return DeleteSucceed;
    }
    return DeleteFailed;
}

void DeleteFileByExten(std::unordered_map<std::wstring, std::list<FileAttrib>>& fileBuf, \
    std::unordered_map<std::wstring, uint64_t>& extenFileSize, const wchar_t* ex)
{
    for (auto it = fileBuf[ex].begin(); it != fileBuf[ex].end();)
    {
        if (DeleteSucceed == DeleteFileByFileAttr(*it, extenFileSize))
        {
            auto tempit = it;
            it++;
            fileBuf[ex].erase(tempit);//将文件信息从filebuf中删除
        }
        else
        {
            //删除失败，这里可以添加删除失败的逻辑，后续也可以根据DeleteFileByPath的返回值判断是何种原因删除失败。
            it++;
        }
    }
}

void DeleteAllFile(std::unordered_map<std::wstring, std::list<FileAttrib>>& fileBuf, \
    std::unordered_map<std::wstring, uint64_t>& extenFileSize)
{
    for (auto& [k, v] : fileBuf)
    {
        DeleteFileByExten(fileBuf, extenFileSize, k.c_str());
    }
}


//std::wstring GetSuffixFormCheckBox(QCheckBox* qcb)
//{
//    std::wstring text = qcb->text().toStdWString();
//    wchar_t* pos = (wchar_t*)wcschr(text.c_str(), L' ');
//    if (pos != nullptr)
//    {
//        *pos = 0;
//    }
//    return text;
//}

//void UpdateCheckBoxText(std::vector<QCheckBox*>& extenCheckBox, 
//                        std::unordered_map<std::wstring, std::list<FileAttrib>>& fileBuf,
//                        std::unordered_map<std::wstring, uint64_t>& extenFileSize)
//{
//    {//topk问题
//        auto cmp = [](const std::pair<std::wstring, uint64_t>& p1, const std::pair<std::wstring, uint64_t>& p2) \
//        {return p1.second > p2.second; };
//        std::priority_queue < std::pair<std::wstring, uint64_t>, \
//            std::vector<std::pair<std::wstring, uint64_t>>, \
//            decltype(cmp) > minHeap(cmp);
//
//        /*********************
//        * extenFileSize中后缀对应的文件大小为0的时候，在fileBuf中可能有两种情况
//        * 一：fileBuf中存在对应的后缀文件，但大小为0
//        * 二：fileBuf中不存在对应的后缀文件
//        * 第一种情况extenFileSize中的后缀需要保留，第二种情况extenFileSize中的后缀应该删除
//        **********************/
//        for (auto it = extenFileSize.begin(); it != extenFileSize.end();)
//        {
//            if (0 == it->second)
//            {
//                if (fileBuf[it->first].empty())
//                {
//                    auto tempit = it;
//                    it++;
//                    extenFileSize.erase(tempit);//避免使用it++引起的错误
//                }
//                else
//                {
//                    it++;
//                }
//            }
//            else
//            {
//                it++;
//            }
//        }
//
//        for (auto p : extenFileSize)
//        {
//            if (minHeap.size() < extenCheckBox.size())
//            {
//                minHeap.push(p);
//            }
//            else
//            {
//                if (minHeap.top().second < p.second)
//                {
//                    minHeap.pop();
//                    minHeap.push(p);
//                }
//            }
//        }
//        int count = minHeap.size();
//        int blankcount = count;
//        while (blankcount < extenCheckBox.size())
//        {
//            extenCheckBox[blankcount]->setText("***");
//            blankcount++;
//        }
//        while (count > 0)
//        {
//            auto exten = minHeap.top(); minHeap.pop();
//            QString str = QString::fromStdWString(exten.first) + " total " \
//                + QString::fromStdWString(GetFileSize(exten.second));
//            extenCheckBox[count - 1]->setText(str);
//            count--;
//        }
//    }
//}

/*
void UpdateTableViewText(QTableView* qtv,  
                        QLCDNumber* fCountN,
                        QStandardItemModel* tableViewModel,
                        std::unordered_map<std::wstring, std::list<FileAttrib>>& fileBuf)
{
    int fConut = 0;
    tableViewModel->removeRows(0, tableViewModel->rowCount());//再次扫描时，先将tableview清空
    for (auto& [k, v] : fileBuf)
    {
        for (auto& at : v)
        {
            auto fSize = at._size;
            tableViewModel->setItem(fConut, 0, new QStandardItem(QString::fromStdWString(k)));
            tableViewModel->setItem(fConut, 1, new QStandardItem(QString::fromStdWString(at._path)));
            tableViewModel->setItem(fConut, 2, new QStandardItem(QString::fromStdWString(GetFileSize(fSize))));
            fConut++;
        }
    }
    fCountN->display(fConut);
    qtv->setModel(tableViewModel);
    qtv->show();
}
*/