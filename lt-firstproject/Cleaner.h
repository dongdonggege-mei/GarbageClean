#pragma once
#pragma execution_character_set("utf-8")//保证中文的正常显示

#include <QtWidgets/QMainWindow>
#include "GarbageClean.h"
#include "ui_Cleaner.h"
#include <QDateTime>
#include <QTimer>
#include <QTime>
#include <QString>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QDebug>

class Cleaner : public QMainWindow, public FirstGarbageClean
{
	Q_OBJECT

public:
	Cleaner(QWidget* parent = Q_NULLPTR);
	~Cleaner();

	void initTree();
	//wstring GetSuffixFromItem(QCheckBox* qcb);
private slots:
	void on_startButton_clicked();
	void on_stopButtton_clicked();
	void updateTime();
	void on_deleteFileButton_clicked();

	void on_treeView_clicked(const QModelIndex& index);
	void treeItemChanged(QStandardItem* item);
	void treeItem_checkAllChild(QStandardItem* item, bool check = true);
	void treeItem_checkAllChild_recursion(QStandardItem* item, bool check = true);
	void treeItem_CheckChildChanged(QStandardItem* item);
	Qt::CheckState checkSibling(QStandardItem* item);
	//void getSelectedItemsData(QStandardItem* item);

	void on_unfold_all_clicked();
	void on_fold_all_clicked();

private:
	Ui::CleanerClass* ui;
	bool IsStop = false;//停止扫描方法
	QTimer* timer;//定时器，每秒更新时间
	QTime* timeRecord;//记录时间
	bool isStart;
	std::unordered_map<std::wstring, std::list<FileAttrib>> fileBuf;//存储扫描结果，很多地方需要用到这个对象，所以定义到这里
	std::unordered_map<std::wstring, uint64_t> extenFileSize;//存储后缀文件总大小
	QStandardItemModel* scanModel;//将model定义在这里，可以解决资源浪费的问题
	QStandardItemModel* model;
};
