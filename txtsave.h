#ifndef TXTSAVE_H
#define TXTSAVE_H

#include <QWidget>
#include <QMessageBox>
#include <QDir>
#include <QDebug>
#include "cliente.h"

namespace Ui {
class TxtSave;
}

class TxtSave : public QWidget
{
    Q_OBJECT

public:
    explicit TxtSave(QWidget *parent = nullptr);
    ~TxtSave();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_listWidget_currentTextChanged(const QString &currentText);

private:
    Ui::TxtSave *ui;
    QStringList m_lista;
    QList<Cliente*> m_clientes;
    void leerArchivo();
    friend class MainWindow;
    QFile nombreArchivo;
    QTextStream io;
};

#endif // TXTSAVE_H
