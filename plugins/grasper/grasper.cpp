// -*- coding: utf-8 -*-
// Copyright (C) 2006-2011 Rosen Diankov <rosen.diankov@gmail.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
#include "plugindefs.h"
#include <openrave/plugin.h>

PlannerBasePtr CreateGrasperPlanner(EnvironmentBasePtr penv, std::istream& sinput);
ModuleBasePtr CreateGrasperModule(EnvironmentBasePtr penv, std::istream& sinput);

InterfaceBasePtr CreateInterfaceValidated(InterfaceType type, const std::string& interfacename, std::istream& sinput, EnvironmentBasePtr penv)
{
    switch(type) {
    case PT_Planner:
        if( interfacename == "grasper" ) {
            return CreateGrasperPlanner(penv,sinput);
        }
        break;
    case PT_Module:
        if( interfacename == "grasper") {
            return CreateGrasperModule(penv,sinput);
        }
        break;
    default:
        break;
    }
    return InterfaceBasePtr();
}

void GetPluginAttributesValidated(PLUGININFO& info)
{
    info.interfacenames[OpenRAVE::PT_Planner].push_back("Grasper");
    info.interfacenames[OpenRAVE::PT_Module].push_back("Grasper");
}

OPENRAVE_PLUGIN_API void DestroyPlugin()
{
}
