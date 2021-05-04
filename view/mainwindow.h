#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDesktopWidget>
#include <QApplication>
#include "view/menubar.h"
#include "view/catalog.h"
#include "view/addproduct.h"

class MainWindow : public QWidget{
    Q_OBJECT
private:
    MenuBar *menu;
    catalog *catalogo;
    addproduct *aggiungiProdotto;
public:
    explicit MainWindow(QWidget * = nullptr);
    ~MainWindow() override = default;
    virtual QSize sizeHint() const override;
};

#endif // MAINWINDOW_H
