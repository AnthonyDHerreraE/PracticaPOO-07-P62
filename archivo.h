#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <QObject>
#include <QThread>
#include <QFile>
#include <QMessageBox>
#include <QDir>
#include <QDebug>
#include "cliente.h"

class Archivo : public QObject
{
    Q_OBJECT
public:
    Archivo();

    void guardarCliente(Cliente &dato);

    const QList<Cliente *> &clientes();

    const QStringList &lista();

    Cliente *actual() const;


private:
    QStringList m_lista;
    QList<Cliente*> m_clientes;
    Cliente *m_actual;
    void leerArchivoCSV();
    void guardarArchivoCSV();
    void setActual(Cliente *newActual);
};

#endif // ARCHIVO_H
