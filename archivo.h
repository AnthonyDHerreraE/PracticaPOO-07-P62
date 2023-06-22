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

private:
    QStringList m_lista;
    QList<Cliente*> m_clientes;
    void leerArchivo();
    void guardarArchivo();

};

#endif // ARCHIVO_H
