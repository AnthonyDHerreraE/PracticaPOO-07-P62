#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cliente.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnEntrada_clicked();

    void on_btnTerminar_clicked();

signals:


private:
    Ui::MainWindow *ui;
    Cliente m_cliente;
};
#endif // MAINWINDOW_H
