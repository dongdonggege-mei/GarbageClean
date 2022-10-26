#include "TreeView.h"




TreeView::TreeView(QWidget *parent)
    : QMainWindow(parent),ui(new Ui::TreeViewClass())
{
    ui->setupUi(this);

    model = new QStandardItemModel(ui->treeView);
    model->setHorizontalHeaderLabels(QStringList() << "文件名称" << "大小");
    ui->treeView->setModel(model);

    connect(ui->start, &QPushButton::clicked, this, &TreeView::on_startButton_clicked);

    void (TreeView:: * func)(QStandardItem*) = &TreeView::ScanChanged;
    connect(model, &QStandardItemModel::itemChanged, this, func);
    connect(ui->deleteFile, &QPushButton::clicked, this, &TreeView::DeleteFile);

}

TreeView::~TreeView()
{
    delete ui;
}

void TreeView::ScanChanged(QStandardItem* item)
{
    
    if (!item->isCheckable())
    {
        return;
    }
    model->blockSignals(true);
    if (item->isTristate())
    {
        CheckAllChild(item, item->checkState());
        
    }
    else
    {
        CheckFatherState(item);
    }
    model->blockSignals(false);
}


QString TreeView::OpenDirectory()
{
    QString dir = QFileDialog::getExistingDirectory(this, "Open Directory", "/home");
    return dir;
    
}

void TreeView::UpdateTreeView()
{

}

void TreeView::UpdateModel()
{
    auto Size = 0;
    auto fNcount = 0;

    for (auto& [k, v] : fileBuff)
    {
        QStandardItem* itemSuffix = new QStandardItem(QString::fromStdWString(k));
        itemSuffix->setCheckable(true);
        itemSuffix->setTristate(true);
        model->appendRow(itemSuffix);
        for (auto& it : v)
        {
            auto fSize = it.fileSize;
            auto fPath = it.filePath;
            QStandardItem* itemFileName = new QStandardItem(QString::fromStdWString(fPath));
            itemFileName->setCheckable(true);
            QStandardItem* itemFileSize = new QStandardItem(QString::fromStdString(std::to_string(fSize)));
            itemSuffix->appendRow(itemFileName);
            itemSuffix->setChild(itemFileName->index().row(), 1, itemFileSize);
            Size += fSize;
            fNcount++;
        }
        QStandardItem* itemSumSuffixSize = new QStandardItem(QString::fromStdString(std::to_string(Size)));
        model->setItem(itemSuffix->index().row(), 1, itemSumSuffixSize);
    }
}

//将选中项记录到CheckedfilePath中，并更新fileBuff
void TreeView::CheckedChildDelete(QStandardItem* item, std::unordered_map<std::wstring, std::vector<std::wstring>>& CheckedfilePath)
{
    if (item == nullptr || !item->isTristate())
        return;
    CheckedfilePath.clear();

    int ChildCount = item->rowCount();
    std::wstring suffixName = item->index().data().toString().toStdWString();
    for (int i = 0; i < ChildCount; i++)
    {
        QStandardItem* child = item->child(i);
        std::wstring filePath = child->index().data().toString().toStdWString();
        if (child->checkState() == Qt::Checked)
        {
            CheckedfilePath[suffixName].push_back(filePath);
        }
    }

    auto it = CheckedfilePath[suffixName].begin();
    auto itA = fileBuff[suffixName].begin();
    for (; it != CheckedfilePath[suffixName].end(); it++)
    {
        for (; itA != fileBuff[suffixName].end(); itA++)
        {
            FileAttrib attri = *itA;
            if (*it == attri.filePath)
            {
                fileBuff[suffixName].erase(itA);
            }
        }
    }

}

//从第一个父节点开始扫描
void TreeView::ScanChecked(std::unordered_map<std::wstring, std::vector<std::wstring>>& CheckedfilePath)
{
    int itemCount = model->rowCount();
    for (int i = 0; i < itemCount; i++)
    {
        QStandardItem* item = model->takeItem(i, 0);
        CheckedChildDelete(item, CheckedfilePath);
    }
    /*char str[20] = { 0 };
    itoa(itemCount,str,10);
    QMessageBox::information(this, str, str);

    QString strTemp = QStringLiteral("%1").arg(item->index().data().toString());*/
}

//遍历CheckedfilePath，执行删除操作
void TreeView::DeleteFile()
{
    ScanChecked(CheckedfilePath);
    
    auto it = CheckedfilePath.begin();
    for (; it != CheckedfilePath.end(); it++)
    {
        auto vec = *it;
        auto itA = CheckedfilePath[vec.first].begin();
        for (; itA != CheckedfilePath[vec.first].end(); itA++)
        {
            auto filePath = *itA;
            path deletePath(filePath);
            remove(deletePath);
        }
    }
    UpdateModel();
}

void TreeView::UpdateFileBuffer()
{
}

void TreeView::CheckFatherState(QStandardItem* item)
{
    if (item == nullptr)
        return;

    QStandardItem* itemFather = item->parent();
    int ChildCount = itemFather->rowCount();
    int CheckedItem = 0, UnCheckedItem = 0;


    for (int i = 0; i < ChildCount; i++)
    {
        QStandardItem* item = itemFather->child(i);
        switch (item->checkState())
        {
        case Qt::Unchecked:
            UnCheckedItem++;
            break;
        case Qt::Checked:
            CheckedItem++;
            break;
        default:
            break;
        }
    }
    if (CheckedItem == 0) {
        itemFather->setCheckState(Qt::Unchecked);
    }
    if (UnCheckedItem == 0) {
        itemFather->setCheckState(Qt::Checked);
    }
    if(CheckedItem>0&&UnCheckedItem>0)
    {
        itemFather->setCheckState(Qt::PartiallyChecked);
    }
        
}

void TreeView::CheckAllChild(QStandardItem* father, Qt::CheckState state)
{
    if (father == nullptr)
        return;
    int ChildCount = father->rowCount();
    for (int i = 0; i < ChildCount; i++)
    {
        father->child(i)->setCheckState(state);
    }
}



void TreeView::on_startButton_clicked()
{
    QString dir = OpenDirectory();
    fileBuff.clear();
    suffixSize.clear();

    GBC.FindAllFile(fileBuff, suffixSize, dir.toStdWString());
    UpdateModel();

    ui->treeView->setModel(model);
    

}