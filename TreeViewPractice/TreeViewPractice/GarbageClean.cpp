#include "GarbageClean.h"]
#include <QDir>

bool NotDot(std::wstring fileName)
{
	return wcscmp(L".", fileName.c_str()) && wcscmp(L"..", fileName.c_str());
}



void GarbageClean::FindAllFile(std::unordered_map<std::wstring, std::list<FileAttrib>>& fileBuff, std::unordered_map<std::wstring, uint64_t>& suffixSize, const std::wstring dir)
{
	QDir Dir(QString::fromStdWString(dir));
	QFileInfoList fileInfoList;
	FileAttrib fileAttrib = {};
	fileInfoList = Dir.entryInfoList();
	for (auto fileinfo : fileInfoList)
	{
		if (!fileinfo.isDir())
		{
			std::wstring suffix = fileinfo.suffix().toStdWString();
			fileBuff[suffix].push_back({ fileinfo.fileName().toStdWString(),fileinfo.absoluteFilePath().toStdWString(),fileinfo.suffix().toStdWString() ,static_cast<uint64_t>(fileinfo.size())});
		}
		else
		{
            if (!NotDot(fileinfo.fileName().toStdWString()))
            {
                continue;
            }
			QString newdir = QString::fromStdWString(dir + L"/") + fileinfo.fileName();
			std::wstring newdirw = newdir.toStdWString();
			FindAllFile(fileBuff, suffixSize,newdirw);
		}
	}
}

std::string GetFileSize(uint64_t size)
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
    return sizeStr;
}