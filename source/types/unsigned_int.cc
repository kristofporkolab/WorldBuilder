/*
  Copyright (C) 2018 by the authors of the World Builder code.

  This file is part of the World Builder.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published
   by the Free Software Foundation, either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include <world_builder/types/unsigned_int.h>
#include <world_builder/assert.h>
#include <world_builder/utilities.h>
#include <world_builder/parameters.h>

#include <world_builder/nan.h>

namespace WorldBuilder
{
  namespace Types
  {
    UnsignedInt::UnsignedInt(unsigned int default_value)
      :
      value(0),
      default_value(default_value)
    {
      this->type_name = Types::type::UnsignedInt;
    }


    UnsignedInt::UnsignedInt(unsigned int value, unsigned int default_value)
      :
      value(value),
      default_value(default_value)
    {
      this->type_name = Types::type::UnsignedInt;
    }


    UnsignedInt::~UnsignedInt ()
    {}

    std::unique_ptr<Interface>
    UnsignedInt::clone() const
    {
      return std::unique_ptr<Interface>(new UnsignedInt(value, default_value));
    }

    void
    UnsignedInt::write_schema(Parameters &prm,
                              const std::string &name,
                              const std::string &documentation) const
    {
      using namespace rapidjson;
      Document &declarations = prm.declarations;

      const std::string base = prm.get_full_json_path() + "/" + name;
      Pointer((base + "/default value").c_str()).Set(declarations,default_value);
      Pointer((base + "/type").c_str()).Set(declarations,"integer");
      Pointer((base + "/documentation").c_str()).Set(declarations,documentation.c_str());

    }
  }
}

