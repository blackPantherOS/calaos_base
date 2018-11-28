/******************************************************************************
 **  Copyright (c) 2006-2018, Calaos. All Rights Reserved.
 **
 **  This file is part of Calaos.
 **
 **  Calaos is free software; you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation; either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  Calaos is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with Foobar; if not, write to the Free Software
 **  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 **
 ******************************************************************************/
#ifndef S_ZigbeeDigitalIn_H
#define S_ZigbeeDigitalIn_H

#include <InputSwitch.h>
#include "Zigbee.h"

class ZigbeeInfoSensor;

namespace Calaos
{

class ZigbeeDigitalIn : public InputSwitch, public sigc::trackable
{
protected:
    std::string host;
    int port;
    std::string id;
    std::string id2;
    bool val;
    void valueUpdated(double _val);

    virtual bool readValue();

public:
    ZigbeeDigitalIn(Params &p);
    virtual ~ZigbeeDigitalIn();
};

}
#endif
