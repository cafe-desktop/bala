/* balagenericdupfield.c generated by balac, the Vala compiler
 * generated from balagenericdupfield.bala, do not modify */

/* balagenericdupfield.bala
 *
 * Copyright (C) 2019  Rico Tzschichholz
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
 * 	Rico Tzschichholz <ricotz@ubuntu.com>
 */

#include "bala.h"
#include <glib.h>

#define _bala_code_context_unref0(var) ((var == NULL) ? NULL : (var = (bala_code_context_unref (var), NULL)))

static gpointer bala_generic_dup_field_parent_class = NULL;

static GType bala_generic_dup_field_get_type_once (void);

/**
 * Creates a new generic dup field.
 *
 * @return newly created field
 */
ValaGenericDupField*
bala_generic_dup_field_construct (GType object_type,
                                  ValaSourceReference* source_reference)
{
	ValaGenericDupField* self = NULL;
	ValaCodeContext* _tmp0_;
	ValaCodeContext* _tmp1_;
	ValaSemanticAnalyzer* _tmp2_;
	ValaSemanticAnalyzer* _tmp3_;
	ValaDelegateType* _tmp4_;
	_tmp0_ = bala_code_context_get ();
	_tmp1_ = _tmp0_;
	_tmp2_ = bala_code_context_get_analyzer (_tmp1_);
	_tmp3_ = _tmp2_;
	_tmp4_ = _tmp3_->generics_dup_func_type;
	self = (ValaGenericDupField*) bala_field_construct (object_type, "dup", (ValaDataType*) _tmp4_, NULL, source_reference, NULL);
	_bala_code_context_unref0 (_tmp1_);
	bala_symbol_set_external ((ValaSymbol*) self, TRUE);
	return self;
}

ValaGenericDupField*
bala_generic_dup_field_new (ValaSourceReference* source_reference)
{
	return bala_generic_dup_field_construct (BALA_TYPE_GENERIC_DUP_FIELD, source_reference);
}

static void
bala_generic_dup_field_class_init (ValaGenericDupFieldClass * klass,
                                   gpointer klass_data)
{
	bala_generic_dup_field_parent_class = g_type_class_peek_parent (klass);
}

static void
bala_generic_dup_field_instance_init (ValaGenericDupField * self,
                                      gpointer klass)
{
}

/**
 * Represents the Generic.dup field.
 */
static GType
bala_generic_dup_field_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaGenericDupFieldClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_generic_dup_field_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaGenericDupField), 0, (GInstanceInitFunc) bala_generic_dup_field_instance_init, NULL };
	GType bala_generic_dup_field_type_id;
	bala_generic_dup_field_type_id = g_type_register_static (BALA_TYPE_FIELD, "ValaGenericDupField", &g_define_type_info, 0);
	return bala_generic_dup_field_type_id;
}

GType
bala_generic_dup_field_get_type (void)
{
	static volatile gsize bala_generic_dup_field_type_id__volatile = 0;
	if (g_once_init_enter (&bala_generic_dup_field_type_id__volatile)) {
		GType bala_generic_dup_field_type_id;
		bala_generic_dup_field_type_id = bala_generic_dup_field_get_type_once ();
		g_once_init_leave (&bala_generic_dup_field_type_id__volatile, bala_generic_dup_field_type_id);
	}
	return bala_generic_dup_field_type_id__volatile;
}
