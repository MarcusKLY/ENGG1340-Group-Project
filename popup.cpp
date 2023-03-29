#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow mainWindow;
    mainWindow.setWindowTitle("My Application");

    QMenuBar* menuBar = new QMenuBar(&mainWindow);

    QMenu* fileMenu = new QMenu("File");
    fileMenu->addAction("New");
    fileMenu->addAction("Open");
    fileMenu->addAction("Save");
    fileMenu->addAction("Exit");

    QMenu* editMenu = new QMenu("Edit");
    editMenu->addAction("Cut");
    editMenu->addAction("Copy");
    editMenu->addAction("Paste");

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(editMenu);

    mainWindow.setMenuBar(menuBar);
    mainWindow.show();

    return app.exec();
}