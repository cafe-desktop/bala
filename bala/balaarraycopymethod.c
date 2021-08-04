/* balaarraycopymethod.c generated by balac, the Bala compiler
 * generated from balaarraycopymethod.bala, do not modify */

/* balaarraycopymethod.bala
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

#define _bala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (bala_code_node_unref (var), NULL)))

static gpointer bala_array_copy_method_parent_class = NULL;

static GType bala_array_copy_method_get_type_once (void);

/**
 * Creates a new array copy method.
 *
 * @return newly created method
 */
BalaArrayCopyMethod*
bala_array_copy_method_construct (GType object_type,
                                  BalaSourceReference* source_reference)
{
	BalaArrayCopyMethod* self = NULL;
	BalaInvalidType* _tmp0_;
	BalaInvalidType* _tmp1_;
	_tmp0_ = bala_invalid_type_new ();
	_tmp1_ = _tmp0_;
	self = (BalaArrayCopyMethod*) bala_method_construct (object_type, "copy", (BalaDataType*) _tmp1_, source_reference, NULL);
	_bala_code_node_unref0 (_tmp1_);
	bala_symbol_set_external ((BalaSymbol*) self, TRUE);
	return self;
}

BalaArrayCopyMethod*
bala_array_copy_method_new (BalaSourceReference* source_reference)
{
	return bala_array_copy_method_construct (BALA_TYPE_ARRAY_COPY_METHOD, source_reference);
}

static void
bala_array_copy_method_class_init (BalaArrayCopyMethodClass * klass,
                                   gpointer klass_data)
{
	bala_array_copy_method_parent_class = g_type_class_peek_parent (klass);
}

static void
bala_array_copy_method_instance_init (BalaArrayCopyMethod * self,
                                      gpointer klass)
{
}

/**
 * Represents the Array.copy method.
 */
static GType
bala_array_copy_method_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaArrayCopyMethodClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_array_copy_method_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaArrayCopyMethod), 0, (GInstanceInitFunc) bala_array_copy_method_instance_init, NULL };
	GType bala_array_copy_method_type_id;
	bala_array_copy_method_type_id = g_type_register_static (BALA_TYPE_METHOD, "BalaArrayCopyMethod", &g_define_type_info, 0);
	return bala_array_copy_method_type_id;
}

GType
bala_array_copy_method_get_type (void)
{
	static volatile gsize bala_array_copy_method_type_id__volatile = 0;
	if (g_once_init_enter (&bala_array_copy_method_type_id__volatile)) {
		GType bala_array_copy_method_type_id;
		bala_array_copy_method_type_id = bala_array_copy_method_get_type_once ();
		g_once_init_leave (&bala_array_copy_method_type_id__volatile, bala_array_copy_method_type_id);
	}
	return bala_array_copy_method_type_id__volatile;
}

