/*******************************************************************************
* Copyright © 2014, Sergey Radionov <rsatom_gmail.com>
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice,
*      this list of conditions and the following disclaimer.
*   2. Redistributions in binary form must reproduce the above copyright notice,
*      this list of conditions and the following disclaimer in the documentation
*      and/or other materials provided with the distribution.

* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
* OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#include "QmlVlc.h"

#include <QtQml/qqml.h>

#include "QmlVlcVideoSurface.h"
#include "QmlVlcPlayer.h"
#include "QmlVlcConfig.h"

#ifndef Q_OS_ANDROID
//    #include "QmlVlcMediaListPlayer.h"
#endif

const char* qmlVlcUri = "QmlVlc";
const int QmlVlcVersionMajor = 0;
const int QmlVlcVersionMinor = 1;

static QObject * vlcConfig_qobject_singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    QmlVlcConfig& config = QmlVlcConfig::instance();
    return &config;
}

void RegisterQmlVlcPlayer()
{
    qmlRegisterSingletonType<QmlVlcConfig>("Qt.vlc.config", QmlVlcVersionMajor, QmlVlcVersionMinor,"configApi", vlcConfig_qobject_singletontype_provider);

    // @uri QmlVlc
    qmlRegisterUncreatableType<QmlVlcVideoSource>(
        qmlVlcUri, QmlVlcVersionMajor, QmlVlcVersionMinor,
        "QmlVlcVideoSource",
        QStringLiteral("QmlVlcVideoSource cannot be instantiated directly") );

    //qmlRegisterUncreatableType<QmlVlcInput>(
    //    qmlVlcUri, QmlVlcVersionMajor, QmlVlcVersionMinor,
    //    "VlcInput",
    //    QStringLiteral("VlcInput cannot be instantiated directly") );
    //qmlRegisterUncreatableType<QmlVlcVideo>(
    //    qmlVlcUri, QmlVlcVersionMajor, QmlVlcVersionMinor,
    //    "VlcVideo",
    //    QStringLiteral("VlcVideo cannot be instantiated directly") );
    qmlRegisterUncreatableType<QmlVlcAudio>(
        qmlVlcUri, QmlVlcVersionMajor, QmlVlcVersionMinor,
        "VlcAudio",
        QStringLiteral("VlcAudio cannot be instantiated directly") );
    //qmlRegisterUncreatableType<QmlVlcSubtitle>(
    //    qmlVlcUri, QmlVlcVersionMajor, QmlVlcVersionMinor,
    //    "VlcSubtitle",
    //    QStringLiteral("VlcSubtitle cannot be instantiated directly") );
    //qmlRegisterUncreatableType<QmlVlcPlaylist>(
    //    qmlVlcUri, QmlVlcVersionMajor, QmlVlcVersionMinor,
    //    "VlcPlaylist",
    //    QStringLiteral("VlcPlaylist cannot be instantiated directly") );
    //qmlRegisterUncreatableType<QmlVlcMarquee>(
    //    qmlVlcUri, QmlVlcVersionMajor, QmlVlcVersionMinor,
    //    "VlcMarquee",
    //    QStringLiteral("VlcMarquee cannot be instantiated directly") );
    //qmlRegisterUncreatableType<QmlVlcLogo>(
    //    qmlVlcUri, QmlVlcVersionMajor, QmlVlcVersionMinor,
    //    "VlcLogo",
    //    QStringLiteral("VlcLogo cannot be instantiated directly") );
    //qmlRegisterUncreatableType<QmlVlcDeinterlace>(
    //    qmlVlcUri, QmlVlcVersionMajor, QmlVlcVersionMinor,
    //    "VlcDeinterlace",
    //    QStringLiteral("VlcDeinterlace cannot be instantiated directly") );
    //qmlRegisterUncreatableType<QmlVlcMedia>(
    //    qmlVlcUri, QmlVlcVersionMajor, QmlVlcVersionMinor,
    //    "VlcMediaDesc",
    //    QStringLiteral("VlcMediaDesc cannot be instantiated directly") );

    qmlRegisterType<QmlVlcVideoSurface>(
        qmlVlcUri, QmlVlcVersionMajor, QmlVlcVersionMinor,
        "VlcVideoSurface" );
    qmlRegisterType<QmlVlcPlayer>(
        qmlVlcUri, QmlVlcVersionMajor, QmlVlcVersionMinor,
        "VlcPlayer" );

//#ifndef Q_OS_ANDROID
//    qmlRegisterType<QmlVlcMediaListPlayer>(
//        qmlVlcUri, QmlVlcVersionMajor, QmlVlcVersionMinor,
//        "VlcMediaListPlayer" );
//#endif
}

void QmlVlcPlugin::registerTypes(const char *uri)
{
    Q_UNUSED(uri);

    RegisterQmlVlcPlayer();
}
