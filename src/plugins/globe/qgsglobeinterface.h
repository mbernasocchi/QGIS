/***************************************************************************
    qgsglobeinterface.h
     --------------------------------------
    Date                 : 22.8.2013
    Copyright            : (C) 2013 Matthias Kuhn
    Email                : matthias dot kuhn at gmx dot ch
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSGLOBEINTERFACE_H
#define QGSGLOBEINTERFACE_H

#include "qgsplugininterface.h"

#include <osgViewer/Viewer>

#include <osgEarth/MapNode>

#include <qglobal.h>

class GlobePlugin;

class QDateTime;

class GLOBE_EXPORT QgsGlobeInterface : public QgsPluginInterface
{
    Q_OBJECT

  public:
    QgsGlobeInterface( GlobePlugin* const globe );

    osgViewer::Viewer* osgViewer();

    osgEarth::MapNode* mapNode();

    void syncExtent();

    void enableFrustumHighlight( bool status );

    void enableFeatureIdentification( bool status );

    void setBaseMap( QString url );

    void setSkyParameters( bool enabled, const QDateTime& dateTime, bool autoAmbient );

  private:
    GlobePlugin* mGlobe;
};

#endif // QGSGLOBEINTERFACE_H
