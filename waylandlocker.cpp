/********************************************************************
 KSld - the KDE Screenlocker Daemon
 This file is part of the KDE project.

 Copyright (C) 2015 Bhushan Shah <bhush94@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*********************************************************************/

#include "waylandlocker.h"
#include <KWayland/Server/display.h>
#include <KWayland/Server/seat_interface.h>

namespace ScreenLocker
{

WaylandLocker::WaylandLocker(KWayland::Server::Display *display)
    : AbstractLocker()
{
    const auto seats = display->seats();
    for (auto s : seats) {
        connect(s, &KWayland::Server::SeatInterface::timestampChanged, this, &WaylandLocker::userActivity);
    }
}

WaylandLocker::~WaylandLocker()
{
}

void WaylandLocker::showLockWindow()
{
}

void WaylandLocker::hideLockWindow()
{
}

void WaylandLocker::addAllowedWindow(quint32 window)
{
}

void WaylandLocker::stayOnTop()
{
}

}
