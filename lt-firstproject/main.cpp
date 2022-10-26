#define __MY_PROJECT_IS_EXE_AND_I_WANT_TO_INITIALIZE_SAFEBASE_DLL__

#include "Cleaner.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <QAXBase/Helper/AppHelper.h>
#include <Public/Helper/qaxpublic.h>

#define _MAX_PATH  260 

#include <atlstr.h>

Cleaner* myWindow = nullptr;

//获取当前窗口句柄
static QAX_HANDLE GetMainWindowHandle()
{
	if (myWindow == nullptr) return nullptr;

	return (QAX_HANDLE)myWindow->winId();

}

void STDCALLTYPE OnBringMyAppToTop(const void* pData, size_t nDataLength)
{
	// 命令行
	auto strCommandLine = reinterpret_cast<const wchar_t*>(pData);
	QAXASSERT(Base::String::GetByteLength(strCommandLine, true) == nDataLength);

#ifdef _DEBUG
	std::wcout << L"CommandLine = " << strCommandLine << std::endl;
#endif

	// 把老的窗口给弄到前面去
	Base::CObjectLoader qaxbase(MODULE_QAX_BASE);
	auto spUI = qaxbase.CreateObject<IUserInterfacePtr>();

	if (spUI == nullptr) return;

	spUI->BringWindowToTop(GetMainWindowHandle());
}

int main(int argc, char *argv[])
{
	// 初始化
	QAXBase::CAppHelper app;
	if (app.Init() == false) return -1;

	// 检测单实例
	if (app.CheckSingleInstance(L"SettingCenter", false, OnBringMyAppToTop) == false) return -1;

    QApplication a(argc, argv);
    Cleaner w;
	myWindow = &w;

    w.show();
    return a.exec();
}
