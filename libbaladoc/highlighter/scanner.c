/* scanner.c generated by balac, the Bala compiler
 * generated from scanner.bala, do not modify */

/* scanner.bala
 *
 * Copyright (C) 2015       Florian Brosch
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

static GType baladoc_highlighter_scanner_get_type_once (void);

BaladocHighlighterCodeToken*
baladoc_highlighter_scanner_next (BaladocHighlighterScanner* self)
{
	g_return_val_if_fail (self != NULL, NULL);
	return BALADOC_HIGHLIGHTER_SCANNER_GET_INTERFACE (self)->next (self);
}

static void
baladoc_highlighter_scanner_default_init (BaladocHighlighterScannerIface * iface,
                                          gpointer iface_data)
{
}

/**
 * Scanner interface used to highlight source code.
 */
static GType
baladoc_highlighter_scanner_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BaladocHighlighterScannerIface), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) baladoc_highlighter_scanner_default_init, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
	GType baladoc_highlighter_scanner_type_id;
	baladoc_highlighter_scanner_type_id = g_type_register_static (G_TYPE_INTERFACE, "BaladocHighlighterScanner", &g_define_type_info, 0);
	g_type_interface_add_prerequisite (baladoc_highlighter_scanner_type_id, G_TYPE_OBJECT);
	return baladoc_highlighter_scanner_type_id;
}

GType
baladoc_highlighter_scanner_get_type (void)
{
	static volatile gsize baladoc_highlighter_scanner_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_highlighter_scanner_type_id__volatile)) {
		GType baladoc_highlighter_scanner_type_id;
		baladoc_highlighter_scanner_type_id = baladoc_highlighter_scanner_get_type_once ();
		g_once_init_leave (&baladoc_highlighter_scanner_type_id__volatile, baladoc_highlighter_scanner_type_id);
	}
	return baladoc_highlighter_scanner_type_id__volatile;
}

