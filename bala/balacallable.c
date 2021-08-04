/* balacallable.c generated by balac, the Vala compiler
 * generated from balacallable.bala, do not modify */

/* balacallable.bala
 *
 * Copyright (C) 2011  Luca Bruno
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * Author:
 * 	Luca Bruno <lucabru@src.gnome.org>
 */

#include "bala.h"
#include <glib.h>
#include <balagee.h>
#include <glib-object.h>

static GType bala_callable_get_type_once (void);

ValaDataType*
bala_callable_get_return_type (ValaCallable* self)
{
	g_return_val_if_fail (self != NULL, NULL);
	return BALA_CALLABLE_GET_INTERFACE (self)->get_return_type (self);
}

void
bala_callable_set_return_type (ValaCallable* self,
                               ValaDataType* value)
{
	g_return_if_fail (self != NULL);
	BALA_CALLABLE_GET_INTERFACE (self)->set_return_type (self, value);
}

/**
 * Appends parameter to this callable.
 *
 * @param param a formal parameter
 */
void
bala_callable_add_parameter (ValaCallable* self,
                             ValaParameter* param)
{
	g_return_if_fail (self != NULL);
	BALA_CALLABLE_GET_INTERFACE (self)->add_parameter (self, param);
}

/**
 * Returns the parameter list.
 */
ValaList*
bala_callable_get_parameters (ValaCallable* self)
{
	g_return_val_if_fail (self != NULL, NULL);
	return BALA_CALLABLE_GET_INTERFACE (self)->get_parameters (self);
}

static void
bala_callable_default_init (ValaCallableIface * iface,
                            gpointer iface_data)
{
}

/**
 * Interface for all callable types.
 */
static GType
bala_callable_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaCallableIface), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_callable_default_init, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
	GType bala_callable_type_id;
	bala_callable_type_id = g_type_register_static (G_TYPE_INTERFACE, "ValaCallable", &g_define_type_info, 0);
	g_type_interface_add_prerequisite (bala_callable_type_id, BALA_TYPE_SYMBOL);
	return bala_callable_type_id;
}

GType
bala_callable_get_type (void)
{
	static volatile gsize bala_callable_type_id__volatile = 0;
	if (g_once_init_enter (&bala_callable_type_id__volatile)) {
		GType bala_callable_type_id;
		bala_callable_type_id = bala_callable_get_type_once ();
		g_once_init_leave (&bala_callable_type_id__volatile, bala_callable_type_id);
	}
	return bala_callable_type_id__volatile;
}
