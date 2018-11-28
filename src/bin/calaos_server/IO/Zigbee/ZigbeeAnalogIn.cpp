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
#include "ZigbeeAnalogIn.h"
#include "Zigbee.h"
#include <IOFactory.h>

using namespace Calaos;

REGISTER_IO(ZigbeeAnalogIn)

ZigbeeAnalogIn::ZigbeeAnalogIn(Params &p):
    InputAnalog(p),
    port(0)
{
    // Define IO documentation
    ioDoc->friendlyNameSet("ZigbeeAnalogIn");
    ioDoc->descriptionSet(_("Zigbee analog input. This object can read value from devices like Energy monitor sensors, Lux sensors, ..."));
    ioDoc->paramAdd("host", _("Zigbee IP address on the network"), IODoc::TYPE_STRING, true);
    ioDoc->paramAddInt("port", _("Zigbee ethernet port, default to 17100"), 0, 65535, false, 17100);
    ioDoc->paramAdd("zigbee_id", _("Zigbee device ID (ABC)"), IODoc::TYPE_STRING, true);

    host = get_param("host");
    Utils::from_string(get_param("port"), port);
    id = get_param("zigbee_id");

    Zigbee::Instance(host, port).sig_newdata.connect(sigc::mem_fun(*this, &ZigbeeAnalogIn::valueUpdated));

    cDebugDom("input") << get_param("id");
}

ZigbeeAnalogIn::~ZigbeeAnalogIn()
{
}

void ZigbeeAnalogIn::valueUpdated(double val)
{
    value = val;
    emitChange();
}

void ZigbeeAnalogIn::readValue()
{
    //don't do anything here, as we can't query the zigbee sensor for a value,
    //the zigbee will send us new values
}

