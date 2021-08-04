/* balareferencetype.c generated by balac, the Bala compiler
 * generated from balareferencetype.bala, do not modify */

/* balareferencetype.bala
 *
 * Copyright (C) 2007  Jürg Billeter
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
 * 	Jürg Billeter <j@bitron.ch>
 */

#include "bala.h"

static gpointer bala_reference_type_parent_class = NULL;

static GType bala_reference_type_get_type_once (void);

BalaReferenceType*
bala_reference_type_construct (GType object_type,
                               BalaSymbol* symbol)
{
	BalaReferenceType* self = NULL;
	self = (BalaReferenceType*) bala_data_type_construct_with_symbol (object_type, symbol);
	return self;
}

static void
bala_reference_type_class_init (BalaReferenceTypeClass * klass,
                                gpointer klass_data)
{
	bala_reference_type_parent_class = g_type_class_peek_parent (klass);
}

static void
bala_reference_type_instance_init (BalaReferenceType * self,
                                   gpointer klass)
{
}

/**
 * A reference type, i.e. a class, interface, or array type.
 */
static GType
bala_reference_type_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaReferenceTypeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_reference_type_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaReferenceType), 0, (GInstanceInitFunc) bala_reference_type_instance_init, NULL };
	GType bala_reference_type_type_id;
	bala_reference_type_type_id = g_type_register_static (BALA_TYPE_DATA_TYPE, "BalaReferenceType", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	return bala_reference_type_type_id;
}

GType
bala_reference_type_get_type (void)
{
	static volatile gsize bala_reference_type_type_id__volatile = 0;
	if (g_once_init_enter (&bala_reference_type_type_id__volatile)) {
		GType bala_reference_type_type_id;
		bala_reference_type_type_id = bala_reference_type_get_type_once ();
		g_once_init_leave (&bala_reference_type_type_id__volatile, bala_reference_type_type_id);
	}
	return bala_reference_type_type_id__volatile;
}

