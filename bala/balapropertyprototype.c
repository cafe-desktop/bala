/* balapropertyprototype.c generated by balac, the Bala compiler
 * generated from balapropertyprototype.bala, do not modify */

/* balafieldprototype.bala
 *
 * Copyright (C) 2018  Rico Tzschichholz
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
#include <stdlib.h>
#include <string.h>
#include <glib.h>

static gpointer bala_property_prototype_parent_class = NULL;

static BalaDataType* bala_property_prototype_real_copy (BalaDataType* base);
static gchar* bala_property_prototype_real_to_qualified_string (BalaDataType* base,
                                                         BalaScope* scope);
static GType bala_property_prototype_get_type_once (void);

BalaProperty*
bala_property_prototype_get_property_symbol (BalaPropertyPrototype* self)
{
	BalaProperty* result;
	BalaSymbol* _tmp0_;
	BalaSymbol* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = bala_data_type_get_symbol ((BalaDataType*) self);
	_tmp1_ = _tmp0_;
	result = G_TYPE_CHECK_INSTANCE_CAST (_tmp1_, BALA_TYPE_PROPERTY, BalaProperty);
	return result;
}

BalaPropertyPrototype*
bala_property_prototype_construct (GType object_type,
                                   BalaProperty* property_symbol)
{
	BalaPropertyPrototype* self = NULL;
	g_return_val_if_fail (property_symbol != NULL, NULL);
	self = (BalaPropertyPrototype*) bala_data_type_construct_with_symbol (object_type, (BalaSymbol*) property_symbol);
	return self;
}

BalaPropertyPrototype*
bala_property_prototype_new (BalaProperty* property_symbol)
{
	return bala_property_prototype_construct (BALA_TYPE_PROPERTY_PROTOTYPE, property_symbol);
}

static BalaDataType*
bala_property_prototype_real_copy (BalaDataType* base)
{
	BalaPropertyPrototype * self;
	BalaPropertyPrototype* _result_ = NULL;
	BalaProperty* _tmp0_;
	BalaProperty* _tmp1_;
	BalaPropertyPrototype* _tmp2_;
	BalaDataType* result = NULL;
	self = (BalaPropertyPrototype*) base;
	_tmp0_ = bala_property_prototype_get_property_symbol (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = bala_property_prototype_new (_tmp1_);
	_result_ = _tmp2_;
	result = (BalaDataType*) _result_;
	return result;
}

static gchar*
bala_property_prototype_real_to_qualified_string (BalaDataType* base,
                                                  BalaScope* scope)
{
	BalaPropertyPrototype * self;
	BalaProperty* _tmp0_;
	BalaProperty* _tmp1_;
	gchar* _tmp2_;
	gchar* result = NULL;
	self = (BalaPropertyPrototype*) base;
	_tmp0_ = bala_property_prototype_get_property_symbol (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = bala_symbol_get_full_name ((BalaSymbol*) _tmp1_);
	result = _tmp2_;
	return result;
}

static void
bala_property_prototype_class_init (BalaPropertyPrototypeClass * klass,
                                    gpointer klass_data)
{
	bala_property_prototype_parent_class = g_type_class_peek_parent (klass);
	((BalaDataTypeClass *) klass)->copy = (BalaDataType* (*) (BalaDataType*)) bala_property_prototype_real_copy;
	((BalaDataTypeClass *) klass)->to_qualified_string = (gchar* (*) (BalaDataType*, BalaScope*)) bala_property_prototype_real_to_qualified_string;
}

static void
bala_property_prototype_instance_init (BalaPropertyPrototype * self,
                                       gpointer klass)
{
}

/**
 * A reference to an instance property without a specific instance.
 */
static GType
bala_property_prototype_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaPropertyPrototypeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_property_prototype_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaPropertyPrototype), 0, (GInstanceInitFunc) bala_property_prototype_instance_init, NULL };
	GType bala_property_prototype_type_id;
	bala_property_prototype_type_id = g_type_register_static (BALA_TYPE_DATA_TYPE, "BalaPropertyPrototype", &g_define_type_info, 0);
	return bala_property_prototype_type_id;
}

GType
bala_property_prototype_get_type (void)
{
	static volatile gsize bala_property_prototype_type_id__volatile = 0;
	if (g_once_init_enter (&bala_property_prototype_type_id__volatile)) {
		GType bala_property_prototype_type_id;
		bala_property_prototype_type_id = bala_property_prototype_get_type_once ();
		g_once_init_leave (&bala_property_prototype_type_id__volatile, bala_property_prototype_type_id);
	}
	return bala_property_prototype_type_id__volatile;
}

