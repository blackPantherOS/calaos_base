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
#ifndef S_ZIGBEE_H
#define S_ZIGBEE_H

#include <Calaos.h>
#include <Timer.h>

namespace uvw {
//Forward declare classes here to prevent long build time
//because of uvw.hpp being header only
class UDPHandle;
}

class Zigbee;
class ZigbeeManager
{
public:
    ~ZigbeeManager()
    {
        std::for_each(maps.begin(), maps.end(), Delete());
        maps.clear();
    }

    vector<Zigbee *> maps;
};


class Zigbee
{

protected:
    std::string host;
    int port;

    Zigbee(std::string host, int port);

    static ZigbeeManager zigbeemaps;

public:
    ~Zigbee();

    //Singleton
    static Zigbee &Instance(std::string host, int port);
    static vector<Zigbee *> &get_maps() { return zigbeemaps.maps; }

    std::string get_host() { return host; }
    int get_port() { return port; }

    sigc::signal<void, double> sig_newdata;

};

#endif
