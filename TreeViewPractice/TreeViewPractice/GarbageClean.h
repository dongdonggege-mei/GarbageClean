#include <iostream>
#include <unordered_map>


struct FileAttrib
{
	std::wstring fileName;
	std::wstring filePath;
	std::wstring fileSuffix;
	uint64_t fileSize;
};



class GarbageClean
{
public:
	void FindAllFile(std::unordered_map<std::wstring, std::list<FileAttrib>>& fileBuff, \
		std::unordered_map<std::wstring, uint64_t>& suffixSize,const std::wstring dir
	);



private:
	std::unordered_map<std::wstring, std::list<FileAttrib>> fileBuff;
	std::unordered_map<std::wstring, uint64_t> suffixSize;
};

static GarbageClean GBC;