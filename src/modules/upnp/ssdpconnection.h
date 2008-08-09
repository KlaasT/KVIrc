//=============================================================================
//
//   Creation date : Fri Aug 08 18:00:00 2000 GMT by Szymon Stefanek 
//
//   This file is part of the KVirc irc client distribution
//   Copyright (C) 2008 Szymon Stefanek (pragma at kvirc dot net)
//
//   This program is FREE software. You can redistribute it and/or
//   modify it under the terms of the GNU General Public License
//   as published by the Free Software Foundation; either version 2
//   of the License, or (at your opinion) any later version.
//
//   This program is distributed in the HOPE that it will be USEFUL,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//   See the GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with this program. If not, write to the Free Software Foundation,
//   Inc. ,59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//
// Original Copyright following:
//=============================================================================

/***************************************************************************
                          ssdpconnection.h -  description
                             -------------------
    begin                : Fri Jul 29 2005
    copyright            : (C) 2005 by Diederik van der Boor
    email                : vdboor --at-- codingdomain.com
 ***************************************************************************/

#ifndef UPNP_SSDPCONNECTION_H
#define UPNP_SSDPCONNECTION_H

#include <QObject>

class QUdpSocket;

namespace UPnP
{


/**
 * The Simple Service Discovery Protocol allows UPnP clients
 * to discover UPnP devices on a network.
 * This is achieved by broadcasting a HTTP-like message over UDP.
 * Devices can respond with their location and root service name.
 * The RootService class uses this information to query the device for
 * it's meta information and service list.
 *
 * @author Diederik van der Boor
 * @ingroup NetworkUPnP
 */
class SsdpConnection : public QObject
{
	Q_OBJECT

	public:
	SsdpConnection();
	virtual ~SsdpConnection();

	void queryDevices(int bindPort = 1500);

	private slots:
	// Data was received by the socket
	void slotDataReceived();

	private:
	QUdpSocket *socket_;
	signals:
	// Called when a query completed
	void deviceFound(const QString &hostname, int port, const QString &rootUrl);
};

}

#endif
