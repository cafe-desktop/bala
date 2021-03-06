/* tagletinit.c generated by balac, the Bala compiler
 * generated from tagletinit.bala, do not modify */

/* tagletinit.bala
 *
 * Copyright (C) 2008-2009 Florian Brosch
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * Author:
 * 	Florian Brosch <flo.brosch@gmail.com>
 */

#include "baladoc.h"
#include <glib.h>
#include <glib-object.h>

void
baladoc_taglets_init (BaladocModuleLoader* loader)
{
	g_return_if_fail (loader != NULL);
	baladoc_module_loader_register_taglet (loader, "see", BALADOC_TAGLETS_TYPE_SEE);
	baladoc_module_loader_register_taglet (loader, "since", BALADOC_TAGLETS_TYPE_SINCE);
	baladoc_module_loader_register_taglet (loader, "link", BALADOC_TAGLETS_TYPE_LINK);
	baladoc_module_loader_register_taglet (loader, "throws", BALADOC_TAGLETS_TYPE_THROWS);
	baladoc_module_loader_register_taglet (loader, "return", BALADOC_TAGLETS_TYPE_RETURN);
	baladoc_module_loader_register_taglet (loader, "param", BALADOC_TAGLETS_TYPE_PARAM);
	baladoc_module_loader_register_taglet (loader, "deprecated", BALADOC_TAGLETS_TYPE_DEPRECATED);
	baladoc_module_loader_register_taglet (loader, "inheritDoc", BALADOC_TAGLETS_TYPE_INHERIT_DOC);
}

