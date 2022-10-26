#include "TreeView.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TreeView w;
    w.show();
    return a.exec();
}
