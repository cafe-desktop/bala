/* scanner.c generated by balac, the Bala compiler
 * generated from scanner.bala, do not modify */

/* scanner.bala
 *
 * Copyright (C) 2008-2009 Florian Brosch, Didier Villevalois
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
 * 	Didier 'Ptitjes Villevalois <ptitjes@free.fr>
 */

#include "baladoc.h"
#include <glib.h>
#include <stdlib.h>
#include <string.h>

static GType baladoc_scanner_get_type_once (void);

void
baladoc_scanner_set_parser (BaladocScanner* self,
                            BaladocParser* parser)
{
	g_return_if_fail (self != NULL);
	BALADOC_SCANNER_GET_INTERFACE (self)->set_parser (self, parser);
}

void
baladoc_scanner_reset (BaladocScanner* self)
{
	g_return_if_fail (self != NULL);
	BALADOC_SCANNER_GET_INTERFACE (self)->reset (self);
}

void
baladoc_scanner_scan (BaladocScanner* self,
                      const gchar* content,
                      GError** error)
{
	g_return_if_fail (self != NULL);
	BALADOC_SCANNER_GET_INTERFACE (self)->scan (self, content, error);
}

void
baladoc_scanner_end (BaladocScanner* self,
                     GError** error)
{
	g_return_if_fail (self != NULL);
	BALADOC_SCANNER_GET_INTERFACE (self)->end (self, error);
}

void
baladoc_scanner_stop (BaladocScanner* self)
{
	g_return_if_fail (self != NULL);
	BALADOC_SCANNER_GET_INTERFACE (self)->stop (self);
}

gchar*
baladoc_scanner_get_line_content (BaladocScanner* self)
{
	g_return_val_if_fail (self != NULL, NULL);
	return BALADOC_SCANNER_GET_INTERFACE (self)->get_line_content (self);
}

static void
baladoc_scanner_default_init (BaladocScannerIface * iface,
                              gpointer iface_data)
{
}

static GType
baladoc_scanner_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BaladocScannerIface), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) baladoc_scanner_default_init, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
	GType baladoc_scanner_type_id;
	baladoc_scanner_type_id = g_type_register_static (G_TYPE_INTERFACE, "BaladocScanner", &g_define_type_info, 0);
	g_type_interface_add_prerequisite (baladoc_scanner_type_id, G_TYPE_OBJECT);
	return baladoc_scanner_type_id;
}

GType
baladoc_scanner_get_type (void)
{
	static volatile gsize baladoc_scanner_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_scanner_type_id__volatile)) {
		GType baladoc_scanner_type_id;
		baladoc_scanner_type_id = baladoc_scanner_get_type_once ();
		g_once_init_leave (&baladoc_scanner_type_id__volatile, baladoc_scanner_type_id);
	}
	return baladoc_scanner_type_id__volatile;
}

