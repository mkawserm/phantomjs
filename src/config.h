/*
  This file is part of the PhantomJS project from Ofi Labs.

  Copyright (C) 2011 Ariya Hidayat <ariya.hidayat@gmail.com>
  Copyright (C) 2011 execjosh, http://execjosh.blogspot.com

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include <QString>
#include <QStringList>
#include <QNetworkProxy>

class Config: QObject
{
    Q_OBJECT
    Q_PROPERTY(QString cookiesFile READ cookiesFile WRITE setCookiesFile)
    Q_PROPERTY(bool diskCacheEnabled READ diskCacheEnabled WRITE setDiskCacheEnabled)
    Q_PROPERTY(int maxDiskCacheSize READ maxDiskCacheSize WRITE setMaxDiskCacheSize)
    Q_PROPERTY(bool ignoreSslErrors READ ignoreSslErrors WRITE setIgnoreSslErrors)
    Q_PROPERTY(bool localToRemoteUrlAccessEnabled READ localToRemoteUrlAccessEnabled WRITE setLocalToRemoteUrlAccessEnabled)
    Q_PROPERTY(QString outputEncoding READ outputEncoding WRITE setOutputEncoding)
    Q_PROPERTY(QString proxyType READ proxyType WRITE setProxyType)
    Q_PROPERTY(QString proxy READ proxy WRITE setProxy)
    Q_PROPERTY(QString proxyAuth READ proxyAuth WRITE setProxyAuth)
    Q_PROPERTY(QString scriptEncoding READ scriptEncoding WRITE setScriptEncoding)
    Q_PROPERTY(bool webSecurityEnabled READ webSecurityEnabled WRITE setWebSecurityEnabled)
    Q_PROPERTY(QString offlineStoragePath READ offlineStoragePath WRITE setOfflineStoragePath)
    Q_PROPERTY(int offlineStorageDefaultQuota READ offlineStorageDefaultQuota WRITE setOfflineStorageDefaultQuota)

public:
    Config(QObject *parent = 0);

    void init(const QStringList *const args);
    void processArgs(const QStringList &args);
    void loadJsonFile(const QString &filePath);

    bool autoLoadImages() const;
    void setAutoLoadImages(const bool value);

    QString cookiesFile() const;
    void setCookiesFile(const QString &cookiesFile);

    QString offlineStoragePath() const;
    void setOfflineStoragePath(const QString &value);

    int offlineStorageDefaultQuota() const;
    void setOfflineStorageDefaultQuota(int offlineStorageDefaultQuota);

    bool diskCacheEnabled() const;
    void setDiskCacheEnabled(const bool value);

    int maxDiskCacheSize() const;
    void setMaxDiskCacheSize(int maxDiskCacheSize);

    bool ignoreSslErrors() const;
    void setIgnoreSslErrors(const bool value);

    bool localToRemoteUrlAccessEnabled() const;
    void setLocalToRemoteUrlAccessEnabled(const bool value);

    QString outputEncoding() const;
    void setOutputEncoding(const QString &value);

    QString proxyType() const;
    void setProxyType(const QString value);

    QString proxy() const;
    void setProxy(const QString &value);
    QString proxyHost() const;
    int proxyPort() const;

    QString proxyAuth() const;
    void setProxyAuth(const QString &value);
    QString proxyAuthUser() const;
    QString proxyAuthPass() const;
    void setProxyAuthUser(const QString &value);
    void setProxyAuthPass(const QString &value);

    QStringList scriptArgs() const;
    void setScriptArgs(const QStringList &value);

    QString scriptEncoding() const;
    void setScriptEncoding(const QString &value);

    QString scriptFile() const;
    void setScriptFile(const QString &value);

    QString unknownOption() const;
    void setUnknownOption(const QString &value);

    bool versionFlag() const;
    void setVersionFlag(const bool value);

    void setDebug(const bool value);
    bool debug() const;

    void setRemoteDebugPort(const int port);
    int remoteDebugPort() const;

    void setRemoteDebugAutorun(const bool value);
    bool remoteDebugAutorun() const;

    bool webSecurityEnabled() const;
    void setWebSecurityEnabled(const bool value);

    bool helpFlag() const;
    void setHelpFlag(const bool value);

private:
    void resetToDefaults();
    void setProxyHost(const QString &value);
    void setProxyPort(const int value);
    void setAuthUser(const QString &value);
    void setAuthPass(const QString &value);

    bool m_autoLoadImages;
    QString m_cookiesFile;
    QString m_offlineStoragePath;
    int m_offlineStorageDefaultQuota;
    bool m_diskCacheEnabled;
    int m_maxDiskCacheSize;
    bool m_ignoreSslErrors;
    bool m_localToRemoteUrlAccessEnabled;
    QString m_outputEncoding;
    QString m_proxyType;
    QString m_proxyHost;
    int m_proxyPort;
    QString m_proxyAuthUser;
    QString m_proxyAuthPass;
    QStringList m_scriptArgs;
    QString m_scriptEncoding;
    QString m_scriptFile;
    QString m_unknownOption;
    bool m_versionFlag;
    QString m_authUser;
    QString m_authPass;
    bool m_debug;
    int m_remoteDebugPort;
    bool m_remoteDebugAutorun;
    bool m_webSecurityEnabled;
    bool m_helpFlag;
};

#endif // CONFIG_H
