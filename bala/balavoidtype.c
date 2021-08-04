/* balavoidtype.c generated by balac, the Vala compiler
 * generated from balavoidtype.bala, do not modify */

/* balavoidtype.bala
 *
 * Copyright (C) 2007-2008  Jürg Billeter
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
#include <glib.h>
#include <stdlib.h>
#include <string.h>

static gpointer bala_void_type_parent_class = NULL;

static gboolean bala_void_type_real_stricter (ValaDataType* base,
                                       ValaDataType* type2);
static gboolean bala_void_type_real_compatible (ValaDataType* base,
                                         ValaDataType* type2);
static gchar* bala_void_type_real_to_qualified_string (ValaDataType* base,
                                                ValaScope* scope);
static ValaDataType* bala_void_type_real_copy (ValaDataType* base);
static GType bala_void_type_get_type_once (void);

ValaVoidType*
bala_void_type_construct (GType object_type,
                          ValaSourceReference* source_reference)
{
	ValaVoidType* self = NULL;
	self = (ValaVoidType*) bala_data_type_construct (object_type);
	bala_code_node_set_source_reference ((ValaCodeNode*) self, source_reference);
	return self;
}

ValaVoidType*
bala_void_type_new (ValaSourceReference* source_reference)
{
	return bala_void_type_construct (BALA_TYPE_VOID_TYPE, source_reference);
}

static gboolean
bala_void_type_real_stricter (ValaDataType* base,
                              ValaDataType* type2)
{
	ValaVoidType * self;
	gboolean result = FALSE;
	self = (ValaVoidType*) base;
	g_return_val_if_fail (type2 != NULL, FALSE);
	result = BALA_IS_VOID_TYPE (type2);
	return result;
}

static gboolean
bala_void_type_real_compatible (ValaDataType* base,
                                ValaDataType* type2)
{
	ValaVoidType * self;
	gboolean result = FALSE;
	self = (ValaVoidType*) base;
	g_return_val_if_fail (type2 != NULL, FALSE);
	result = BALA_IS_VOID_TYPE (type2);
	return result;
}

static gchar*
bala_void_type_real_to_qualified_string (ValaDataType* base,
                                         ValaScope* scope)
{
	ValaVoidType * self;
	gchar* _tmp0_;
	gchar* result = NULL;
	self = (ValaVoidType*) base;
	_tmp0_ = g_strdup ("void");
	result = _tmp0_;
	return result;
}

static ValaDataType*
bala_void_type_real_copy (ValaDataType* base)
{
	ValaVoidType * self;
	ValaSourceReference* _tmp0_;
	ValaSourceReference* _tmp1_;
	ValaVoidType* _tmp2_;
	ValaDataType* result = NULL;
	self = (ValaVoidType*) base;
	_tmp0_ = bala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp1_ = _tmp0_;
	_tmp2_ = bala_void_type_new (_tmp1_);
	result = (ValaDataType*) _tmp2_;
	return result;
}

static void
bala_void_type_class_init (ValaVoidTypeClass * klass,
                           gpointer klass_data)
{
	bala_void_type_parent_class = g_type_class_peek_parent (klass);
	((ValaDataTypeClass *) klass)->stricter = (gboolean (*) (ValaDataType*, ValaDataType*)) bala_void_type_real_stricter;
	((ValaDataTypeClass *) klass)->compatible = (gboolean (*) (ValaDataType*, ValaDataType*)) bala_void_type_real_compatible;
	((ValaDataTypeClass *) klass)->to_qualified_string = (gchar* (*) (ValaDataType*, ValaScope*)) bala_void_type_real_to_qualified_string;
	((ValaDataTypeClass *) klass)->copy = (ValaDataType* (*) (ValaDataType*)) bala_void_type_real_copy;
}

static void
bala_void_type_instance_init (ValaVoidType * self,
                              gpointer klass)
{
}

/**
 * The void type.
 */
static GType
bala_void_type_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaVoidTypeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_void_type_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaVoidType), 0, (GInstanceInitFunc) bala_void_type_instance_init, NULL };
	GType bala_void_type_type_id;
	bala_void_type_type_id = g_type_register_static (BALA_TYPE_DATA_TYPE, "ValaVoidType", &g_define_type_info, 0);
	return bala_void_type_type_id;
}

GType
bala_void_type_get_type (void)
{
	static volatile gsize bala_void_type_type_id__volatile = 0;
	if (g_once_init_enter (&bala_void_type_type_id__volatile)) {
		GType bala_void_type_type_id;
		bala_void_type_type_id = bala_void_type_get_type_once ();
		g_once_init_leave (&bala_void_type_type_id__volatile, bala_void_type_type_id);
	}
	return bala_void_type_type_id__volatile;
}
