#ifndef PERMISSIONS_H
#define PERMISSIONS_H

#include <QtMultimedia/QAudioDevice>

class Permissions
{
public:
    Permissions();
    bool connect();
    bool getPermissionMicrophone();
    bool getPermissionsPerifericosB();
    bool getPermissionsCamera();
    bool getPermissionsContacts();
    bool getPermissionsLocation();
private:
    QAudioDevice m_microphone;
};

#endif // PERMISSIONS_H
