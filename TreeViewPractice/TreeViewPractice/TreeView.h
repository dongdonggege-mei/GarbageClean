#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QMainWindow>
#include "ui_TreeView.h"
#include <qfiledialog.h>
#include "GarbageClean.h"
#include <qstandarditemmodel.h>
#include <qmessagebox.h>
#include <filesystem>
using namespace std::filesystem;


class TreeView : public QMainWindow
{
    Q_OBJECT

public slots:
    void on_startButton_clicked();
    void ScanChanged(QStandardItem* item);
    void DeleteFile();

public:
    TreeView(QWidget *parent = nullptr);
    ~TreeView();

    QString OpenDirectory();
    void UpdateTreeView();
    void UpdateModel();
    void ScanChecked(std::unordered_map<std::wstring, std::vector<std::wstring>>& CheckedfilePath);
    void UpdateFileBuffer();
    void CheckFatherState(QStandardItem* item);
    void CheckAllChild(QStandardItem* father, Qt::CheckState state);
    void CheckedChildDelete(QStandardItem* item, std::unordered_map<std::wstring, std::vector<std::wstring>>& CheckedfilePath);


private:
    Ui::TreeViewClass* ui;
    std::unordered_map<std::wstring, std::list<FileAttrib>> fileBuff;
    std::unordered_map<std::wstring, uint64_t> suffixSize;
    std::unordered_map<std::wstring, std::vector<std::wstring>> CheckedfilePath;
    QStandardItemModel* model;
    
};
