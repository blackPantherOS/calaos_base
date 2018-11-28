/******************************************************************************
**  Copyright (c) 2006-2018, Calaos. All Rights Reserved.
**
**  This file is part of Calaos Home.
**
**  Calaos Home is free software; you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation; either version 3 of the License, or
**  (at your option) any later version.
**
**  Calaos Home is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with Foobar; if not, write to the Free Software
**  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
**
******************************************************************************/
#include <Zigbee.h>
#include <tcpsocket.h>
#include "libuvw.h"

ZigbeeManager Zigbee::zigbeemaps;

Zigbee::Zigbee(std::string h, int p):
    host(h),
    port(p)
{
}

Zigbee::~Zigbee()
{
}

Zigbee &Zigbee::Instance(std::string h, int p)
{

    for (uint i = 0;i < zigbeemaps.maps.size();i++)
    {
        if (zigbeemaps.maps[i]->get_host() == h &&
            zigbeemaps.maps[i]->get_port() == p)
        {
            return *zigbeemaps.maps[i];
        }
    }

    // Create a new zigbee object
    Zigbee *zbase = new Zigbee(h, p);
    zigbeemaps.maps.push_back(zbase);

    return *zigbeemaps.maps[zigbeemaps.maps.size() - 1];
}

