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
#include "ZigbeeDigitalIn.h"
#include "Zigbee.h"
#include <IOFactory.h>

using namespace Calaos;

REGISTER_IO(ZigbeeDigitalIn)

ZigbeeDigitalIn::ZigbeeDigitalIn(Params &p):
    InputSwitch(p),
    port(0)
{
    // Define IO documentation
    ioDoc->friendlyNameSet("ZigbeeDigitalIn");
    ioDoc->descriptionSet(_("Zigbee digital input. This object acts as a switch"));
    ioDoc->paramAdd("host", _("Zigbee IP address on the network"), IODoc::TYPE_STRING, true);
    ioDoc->paramAddInt("port", _("Zigbee ethernet port, default to 17100"), 0, 65535, false, 17100);
    ioDoc->paramAdd("zigbee_id", _("First Zigbee device ID (ABC)"), IODoc::TYPE_STRING, true);

    if (!param_exists("zigbee_sensor")) set_param("zigbee_sensor", "detect");
    if (!param_exists("port")) set_param("port", "17100");

    std::string type = get_param("zigbee_sensor");
    host = get_param("host");
    Utils::from_string(get_param("port"), port);
    id = get_param("zigbee_id");

    Zigbee::Instance(host, port).sig_newdata.connect(sigc::mem_fun(*this, &ZigbeeDigitalIn::valueUpdated));

    cDebugDom("input") << get_param("id");
}

ZigbeeDigitalIn::~ZigbeeDigitalIn()
{
}

void ZigbeeDigitalIn::valueUpdated(double _val)
{
    val = _val;
    hasChanged();
}

bool ZigbeeDigitalIn::readValue()
{
    return val;
}

