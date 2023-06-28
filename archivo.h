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
    QString ruta = "Clientes.csv";
    QStringList m_lista;
    QList<Cliente*> m_clientes;
    Cliente *m_actual;
    void leerArchivoBIN();
    void guardarArchivoBIN();
    void leerArchivoCSV();
    void guardarArchivoCSV();
    void setActual(Cliente *newActual);
};

#endif // ARCHIVO_H
