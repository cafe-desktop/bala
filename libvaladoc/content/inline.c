/* inline.c generated by valac, the Vala compiler
 * generated from inline.vala, do not modify */

/* inline.vala
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

#include "valadoc.h"

static GType valadoc_content_inline_get_type_once (void);

static void
valadoc_content_inline_default_init (ValadocContentInlineIface * iface,
                                     gpointer iface_data)
{
}

static GType
valadoc_content_inline_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocContentInlineIface), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) valadoc_content_inline_default_init, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
	GType valadoc_content_inline_type_id;
	valadoc_content_inline_type_id = g_type_register_static (G_TYPE_INTERFACE, "ValadocContentInline", &g_define_type_info, 0);
	g_type_interface_add_prerequisite (valadoc_content_inline_type_id, VALADOC_CONTENT_TYPE_CONTENT_ELEMENT);
	return valadoc_content_inline_type_id;
}

GType
valadoc_content_inline_get_type (void)
{
	static volatile gsize valadoc_content_inline_type_id__volatile = 0;
	if (g_once_init_enter (&valadoc_content_inline_type_id__volatile)) {
		GType valadoc_content_inline_type_id;
		valadoc_content_inline_type_id = valadoc_content_inline_get_type_once ();
		g_once_init_leave (&valadoc_content_inline_type_id__volatile, valadoc_content_inline_type_id);
	}
	return valadoc_content_inline_type_id__volatile;
}

