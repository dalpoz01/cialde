#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "view/menubar.h"

class MainWindow : public QWidget{
    Q_OBJECT
private:
    MenuBar *menu;
public:
    explicit MainWindow(QWidget * = nullptr);
    ~MainWindow() override = default;
};

#endif // MAINWINDOW_H
