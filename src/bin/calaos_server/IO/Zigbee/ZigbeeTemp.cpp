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
#include "ZigbeeTemp.h"
#include "Zigbee.h"
#include <IOFactory.h>

using namespace Calaos;

REGISTER_IO(ZigbeeTemp)

ZigbeeTemp::ZigbeeTemp(Params &p):
    InputTemp(p),
    port(0)
{
    // Define IO documentation
    ioDoc->friendlyNameSet("ZigbeeTemp");
    ioDoc->descriptionSet(_("Zigbee temperature sensor"));
    ioDoc->paramAdd("host", _("Zigbee IP address on the network"), IODoc::TYPE_STRING, true);
    ioDoc->paramAddInt("port", _("Zigbee ethernet port, default to 17100"), 0, 65535, false, 17100);
    ioDoc->paramAdd("zigbee_id", _("Zigbee device ID (ABC)"), IODoc::TYPE_STRING, true);

    Params devList = {{ "temp", _("Temperature sensor") }};
    ioDoc->paramAddList("zigbee_sensor", "Type of sensor", true, devList, "temp");

    if (!param_exists("port")) set_param("port", "17100");

    host = get_param("host");
    Utils::from_string(get_param("port"), port);
    id = get_param("zigbee_id");

    Zigbee::Instance(host, port).sig_newdata.connect(sigc::mem_fun(*this, &ZigbeeTemp::valueUpdated));

    cDebugDom("input") << get_param("id");
}

ZigbeeTemp::~ZigbeeTemp()
{
}

void ZigbeeTemp::valueUpdated(double val)
{
    value = val;
    emitChange();
}

void ZigbeeTemp::readValue()
{
    //don't do anything here, as we can't query the zigbee sensor for a value,
    //the zigbee will send us new values
}

