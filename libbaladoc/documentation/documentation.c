/* documentation.c generated by balac, the Bala compiler
 * generated from documentation.bala, do not modify */

/* documentation.bala
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
 *  Florian Brosch <flo.brosch@gmail.com>
 */

#include "baladoc.h"
#include <glib.h>
#include <stdlib.h>
#include <string.h>

static GType baladoc_documentation_get_type_once (void);

BaladocApiPackage*
baladoc_documentation_get_package (BaladocDocumentation* self)
{
	g_return_val_if_fail (self != NULL, NULL);
	return BALADOC_DOCUMENTATION_GET_INTERFACE (self)->get_package (self);
}

/**
 * The corresponding file name
 */
gchar*
baladoc_documentation_get_filename (BaladocDocumentation* self)
{
	g_return_val_if_fail (self != NULL, NULL);
	return BALADOC_DOCUMENTATION_GET_INTERFACE (self)->get_filename (self);
}

static void
baladoc_documentation_default_init (BaladocDocumentationIface * iface,
                                    gpointer iface_data)
{
	/**
	 * The corresponding package
	 */
	g_object_interface_install_property (iface, g_param_spec_object ("package", "package", "package", BALADOC_API_TYPE_PACKAGE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
}

static GType
baladoc_documentation_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BaladocDocumentationIface), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) baladoc_documentation_default_init, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
	GType baladoc_documentation_type_id;
	baladoc_documentation_type_id = g_type_register_static (G_TYPE_INTERFACE, "BaladocDocumentation", &g_define_type_info, 0);
	g_type_interface_add_prerequisite (baladoc_documentation_type_id, G_TYPE_OBJECT);
	return baladoc_documentation_type_id;
}

GType
baladoc_documentation_get_type (void)
{
	static volatile gsize baladoc_documentation_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_documentation_type_id__volatile)) {
		GType baladoc_documentation_type_id;
		baladoc_documentation_type_id = baladoc_documentation_get_type_once ();
		g_once_init_leave (&baladoc_documentation_type_id__volatile, baladoc_documentation_type_id);
	}
	return baladoc_documentation_type_id__volatile;
}

