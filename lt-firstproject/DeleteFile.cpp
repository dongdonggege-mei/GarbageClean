#include "DeleteFile.h"




bool DeleteFile::DeleteSelectedFile(wchar_t Drv)
{
	bool bFound;
	BOOL result;
	CString strFname;

	//-- Delete All Data Files --
	TCHAR SearchDir[512];
	TCHAR strFile[512];

	sprintf(SearchDir, "%c:\\*.*", Drv);

	// Find the first file in the directory.
	HANDLE hFind = INVALID_HANDLE_VALUE;
	WIN32_FIND_DATA ffd;

	bFound = false;
	hFind = FindFirstFile(SearchDir, &ffd);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do {
			if ((ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
			{
				strFname.Format(_T("%s"), ffd.cFileName);
				if (strFname.Find(_T(".h2w")) != -1)
				{
					sprintf(strFile, "%c:\\%s", Drv, ffd.cFileName);
					result = DeleteFile(strFile);
					bFound = (result) ? true : bFound;
				}
			}
		} while (FindNextFile(hFind, &ffd) != 0);
		FindClose(hFind);
	}

	return bFound;
}