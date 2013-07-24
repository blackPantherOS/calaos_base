/******************************************************************************
**  Copyright (c) 2007-2008, Calaos. All Rights Reserved.
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
#ifndef S_OWTemp_H
#define S_OWTemp_H

#include <Calaos.h>
#include <Input.h>
#include <Ecore.h>

namespace Calaos
{

class OWTemp : public Input
{
        protected:
                std::string ow_id;
		std::string ow_req;
		std::string ow_args;
                double value;
                double timer;
		double time;
        public:
                OWTemp(Params &p);
                ~OWTemp();

                virtual DATA_TYPE get_type() { return TINT; }

                virtual void force_input_double(double v);

                virtual double get_value_double();

                virtual void hasChanged();
};

}
#endif