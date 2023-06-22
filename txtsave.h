#ifndef TXTSAVE_H
#define TXTSAVE_H

#include <QWidget>
#include "archivo.h"

namespace Ui {
class TxtSave;
}

class TxtSave : public QWidget
{
    Q_OBJECT

public:
    explicit TxtSave(QWidget *parent = nullptr);
    ~TxtSave();

    void setLista(const QStringList &newLista);

    void setClientes(const QList<Cliente *> &newClientes);

    const QStringList &lista() const;

    const QList<Cliente *> &clientes() const;

    void setDatos(Archivo &newDatos);

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_listWidget_currentTextChanged(const QString &currentText);

private:
    Ui::TxtSave *ui;
    QStringList m_lista;
    QList<Cliente*> m_clientes;

    Archivo *m_datos;
};

#endif // TXTSAVE_H
