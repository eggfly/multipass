/*
 * Copyright (C) 2017-2022 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Alberto Aguirre <alberto.aguirre@canonical.com>
 *
 */

#include "temp_file.h"

#include <stdexcept>

namespace mpt = multipass::test;

mpt::TempFile::TempFile()
{
    if (file.open())
    {
        the_name = file.fileName();
        the_url = QUrl::fromLocalFile(the_name).toString();
    }
    else
    {
        throw std::runtime_error("test failed to create temporary file");
    }
}
