#ifndef CLIENTE_H
#define CLIENTE_H

#include <QObject>
#include <QDebug>

class Cliente : public QObject
{
    Q_OBJECT
public:
    explicit Cliente(QObject *parent = nullptr);

    const QString &nombre() const;
    const QString &cedula() const;
    const QString &direccion() const;
    const QString &ciudad() const;
    const QString &telefono() const;
    const QString &correo() const;


    QString nombres() const;
    void setNombres(const QString &newNombres);

    QString apellidos() const;
    void setApellidos(const QString &newApellidos);

public slots:
    void setNombre(const QString &newNombre);
    void setCedula(const QString &newCedula);
    void setDireccion(const QString &newDireccion);
    void setCiudad(const QString &newCiudad);
    void setTelefono(const QString &newTelefono);
    void setCorreo(const QString &newCorreo);
    void inDatos(QString &entradaDatos);
    int filtro(QString &dato);
    void reset();

signals:


private:
    QString m_nombre;
    QString m_nombres;
    QString m_apellidos;
    QString m_cedula;
    QString m_direccion;
    QString m_ciudad;
    QString m_telefono;
    QString m_correo;
};

#endif // CLIENTE_H
