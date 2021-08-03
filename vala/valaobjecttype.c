/* valaobjecttype.c generated by valac, the Vala compiler
 * generated from valaobjecttype.vala, do not modify */

/* valaobjecttype.vala
 *
 * Copyright (C) 2007-2010  Jürg Billeter
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

#include "vala.h"
#include <glib.h>
#include <valagee.h>
#include <glib-object.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))
#define _vala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterable_unref (var), NULL)))

static gpointer vala_object_type_parent_class = NULL;

static ValaDataType* vala_object_type_real_copy (ValaDataType* base);
static gboolean vala_object_type_real_stricter (ValaDataType* base,
                                         ValaDataType* target_type);
static gboolean vala_object_type_real_is_invokable (ValaDataType* base);
static ValaDataType* vala_object_type_real_get_return_type (ValaDataType* base);
static ValaList* vala_object_type_real_get_parameters (ValaDataType* base);
static gboolean vala_object_type_real_check (ValaCodeNode* base,
                                      ValaCodeContext* context);
static GType vala_object_type_get_type_once (void);

ValaObjectTypeSymbol*
vala_object_type_get_object_type_symbol (ValaObjectType* self)
{
	ValaObjectTypeSymbol* result;
	ValaSymbol* _tmp0_;
	ValaSymbol* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = vala_data_type_get_symbol ((ValaDataType*) self);
	_tmp1_ = _tmp0_;
	result = G_TYPE_CHECK_INSTANCE_CAST (_tmp1_, VALA_TYPE_OBJECT_TYPE_SYMBOL, ValaObjectTypeSymbol);
	return result;
}

ValaObjectType*
vala_object_type_construct (GType object_type,
                            ValaObjectTypeSymbol* type_symbol)
{
	ValaObjectType* self = NULL;
	g_return_val_if_fail (type_symbol != NULL, NULL);
	self = (ValaObjectType*) vala_reference_type_construct (object_type, (ValaSymbol*) type_symbol);
	return self;
}

ValaObjectType*
vala_object_type_new (ValaObjectTypeSymbol* type_symbol)
{
	return vala_object_type_construct (VALA_TYPE_OBJECT_TYPE, type_symbol);
}

static gpointer
_vala_iterable_ref0 (gpointer self)
{
	return self ? vala_iterable_ref (self) : NULL;
}

static ValaDataType*
vala_object_type_real_copy (ValaDataType* base)
{
	ValaObjectType * self;
	ValaObjectType* _result_ = NULL;
	ValaObjectTypeSymbol* _tmp0_;
	ValaObjectTypeSymbol* _tmp1_;
	ValaObjectType* _tmp2_;
	ValaObjectType* _tmp3_;
	ValaSourceReference* _tmp4_;
	ValaSourceReference* _tmp5_;
	ValaObjectType* _tmp6_;
	gboolean _tmp7_;
	gboolean _tmp8_;
	ValaObjectType* _tmp9_;
	gboolean _tmp10_;
	gboolean _tmp11_;
	ValaObjectType* _tmp12_;
	gboolean _tmp13_;
	gboolean _tmp14_;
	ValaObjectType* _tmp15_;
	gboolean _tmp16_;
	gboolean _tmp17_;
	ValaDataType* result = NULL;
	self = (ValaObjectType*) base;
	_tmp0_ = vala_object_type_get_object_type_symbol (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = vala_object_type_new (_tmp1_);
	_result_ = _tmp2_;
	_tmp3_ = _result_;
	_tmp4_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp5_ = _tmp4_;
	vala_code_node_set_source_reference ((ValaCodeNode*) _tmp3_, _tmp5_);
	_tmp6_ = _result_;
	_tmp7_ = vala_data_type_get_value_owned ((ValaDataType*) self);
	_tmp8_ = _tmp7_;
	vala_data_type_set_value_owned ((ValaDataType*) _tmp6_, _tmp8_);
	_tmp9_ = _result_;
	_tmp10_ = vala_data_type_get_nullable ((ValaDataType*) self);
	_tmp11_ = _tmp10_;
	vala_data_type_set_nullable ((ValaDataType*) _tmp9_, _tmp11_);
	_tmp12_ = _result_;
	_tmp13_ = vala_data_type_get_is_dynamic ((ValaDataType*) self);
	_tmp14_ = _tmp13_;
	vala_data_type_set_is_dynamic ((ValaDataType*) _tmp12_, _tmp14_);
	_tmp15_ = _result_;
	_tmp16_ = vala_data_type_get_floating_reference ((ValaDataType*) self);
	_tmp17_ = _tmp16_;
	vala_data_type_set_floating_reference ((ValaDataType*) _tmp15_, _tmp17_);
	{
		ValaList* _arg_list = NULL;
		ValaList* _tmp18_;
		ValaList* _tmp19_;
		gint _arg_size = 0;
		ValaList* _tmp20_;
		gint _tmp21_;
		gint _tmp22_;
		gint _arg_index = 0;
		_tmp18_ = vala_data_type_get_type_arguments ((ValaDataType*) self);
		_tmp19_ = _vala_iterable_ref0 (_tmp18_);
		_arg_list = _tmp19_;
		_tmp20_ = _arg_list;
		_tmp21_ = vala_collection_get_size ((ValaCollection*) _tmp20_);
		_tmp22_ = _tmp21_;
		_arg_size = _tmp22_;
		_arg_index = -1;
		while (TRUE) {
			gint _tmp23_;
			gint _tmp24_;
			ValaDataType* arg = NULL;
			ValaList* _tmp25_;
			gpointer _tmp26_;
			ValaObjectType* _tmp27_;
			ValaDataType* _tmp28_;
			ValaDataType* _tmp29_;
			ValaDataType* _tmp30_;
			_arg_index = _arg_index + 1;
			_tmp23_ = _arg_index;
			_tmp24_ = _arg_size;
			if (!(_tmp23_ < _tmp24_)) {
				break;
			}
			_tmp25_ = _arg_list;
			_tmp26_ = vala_list_get (_tmp25_, _arg_index);
			arg = (ValaDataType*) _tmp26_;
			_tmp27_ = _result_;
			_tmp28_ = arg;
			_tmp29_ = vala_data_type_copy (_tmp28_);
			_tmp30_ = _tmp29_;
			vala_data_type_add_type_argument ((ValaDataType*) _tmp27_, _tmp30_);
			_vala_code_node_unref0 (_tmp30_);
			_vala_code_node_unref0 (arg);
		}
		_vala_iterable_unref0 (_arg_list);
	}
	result = (ValaDataType*) _result_;
	return result;
}

static gboolean
vala_object_type_real_stricter (ValaDataType* base,
                                ValaDataType* target_type)
{
	ValaObjectType * self;
	ValaObjectType* obj_target_type = NULL;
	ValaObjectType* _tmp0_;
	gboolean _tmp1_;
	gboolean _tmp2_;
	gboolean _tmp3_;
	gboolean _tmp4_;
	gboolean _tmp5_ = FALSE;
	gboolean _tmp6_;
	gboolean _tmp7_;
	ValaTypeSymbol* _tmp10_;
	ValaTypeSymbol* _tmp11_;
	ValaObjectType* _tmp12_;
	ValaTypeSymbol* _tmp13_;
	ValaTypeSymbol* _tmp14_;
	gboolean result = FALSE;
	self = (ValaObjectType*) base;
	g_return_val_if_fail (target_type != NULL, FALSE);
	obj_target_type = VALA_IS_OBJECT_TYPE (target_type) ? ((ValaObjectType*) target_type) : NULL;
	_tmp0_ = obj_target_type;
	if (_tmp0_ == NULL) {
		result = FALSE;
		return result;
	}
	_tmp1_ = vala_data_type_get_value_owned ((ValaDataType*) self);
	_tmp2_ = _tmp1_;
	_tmp3_ = vala_data_type_get_value_owned (target_type);
	_tmp4_ = _tmp3_;
	if (_tmp2_ != _tmp4_) {
		result = FALSE;
		return result;
	}
	_tmp6_ = vala_data_type_get_nullable ((ValaDataType*) self);
	_tmp7_ = _tmp6_;
	if (_tmp7_) {
		gboolean _tmp8_;
		gboolean _tmp9_;
		_tmp8_ = vala_data_type_get_nullable (target_type);
		_tmp9_ = _tmp8_;
		_tmp5_ = !_tmp9_;
	} else {
		_tmp5_ = FALSE;
	}
	if (_tmp5_) {
		result = FALSE;
		return result;
	}
	_tmp10_ = vala_data_type_get_type_symbol ((ValaDataType*) self);
	_tmp11_ = _tmp10_;
	_tmp12_ = obj_target_type;
	_tmp13_ = vala_data_type_get_type_symbol ((ValaDataType*) _tmp12_);
	_tmp14_ = _tmp13_;
	result = vala_typesymbol_is_subtype_of (_tmp11_, _tmp14_);
	return result;
}

static gboolean
vala_object_type_real_is_invokable (ValaDataType* base)
{
	ValaObjectType * self;
	ValaClass* cl = NULL;
	ValaTypeSymbol* _tmp0_;
	ValaTypeSymbol* _tmp1_;
	gboolean _tmp2_ = FALSE;
	ValaClass* _tmp3_;
	gboolean result = FALSE;
	self = (ValaObjectType*) base;
	_tmp0_ = vala_data_type_get_type_symbol ((ValaDataType*) self);
	_tmp1_ = _tmp0_;
	cl = VALA_IS_CLASS (_tmp1_) ? ((ValaClass*) _tmp1_) : NULL;
	_tmp3_ = cl;
	if (_tmp3_ != NULL) {
		ValaClass* _tmp4_;
		ValaCreationMethod* _tmp5_;
		ValaCreationMethod* _tmp6_;
		_tmp4_ = cl;
		_tmp5_ = vala_class_get_default_construction_method (_tmp4_);
		_tmp6_ = _tmp5_;
		_tmp2_ = _tmp6_ != NULL;
	} else {
		_tmp2_ = FALSE;
	}
	if (_tmp2_) {
		result = TRUE;
		return result;
	} else {
		result = FALSE;
		return result;
	}
}

static ValaDataType*
vala_object_type_real_get_return_type (ValaDataType* base)
{
	ValaObjectType * self;
	ValaClass* cl = NULL;
	ValaTypeSymbol* _tmp0_;
	ValaTypeSymbol* _tmp1_;
	gboolean _tmp2_ = FALSE;
	ValaClass* _tmp3_;
	ValaDataType* result = NULL;
	self = (ValaObjectType*) base;
	_tmp0_ = vala_data_type_get_type_symbol ((ValaDataType*) self);
	_tmp1_ = _tmp0_;
	cl = VALA_IS_CLASS (_tmp1_) ? ((ValaClass*) _tmp1_) : NULL;
	_tmp3_ = cl;
	if (_tmp3_ != NULL) {
		ValaClass* _tmp4_;
		ValaCreationMethod* _tmp5_;
		ValaCreationMethod* _tmp6_;
		_tmp4_ = cl;
		_tmp5_ = vala_class_get_default_construction_method (_tmp4_);
		_tmp6_ = _tmp5_;
		_tmp2_ = _tmp6_ != NULL;
	} else {
		_tmp2_ = FALSE;
	}
	if (_tmp2_) {
		ValaClass* _tmp7_;
		ValaCreationMethod* _tmp8_;
		ValaCreationMethod* _tmp9_;
		ValaDataType* _tmp10_;
		ValaDataType* _tmp11_;
		_tmp7_ = cl;
		_tmp8_ = vala_class_get_default_construction_method (_tmp7_);
		_tmp9_ = _tmp8_;
		_tmp10_ = vala_callable_get_return_type ((ValaCallable*) _tmp9_);
		_tmp11_ = _tmp10_;
		result = _tmp11_;
		return result;
	} else {
		result = NULL;
		return result;
	}
}

static ValaList*
vala_object_type_real_get_parameters (ValaDataType* base)
{
	ValaObjectType * self;
	ValaClass* cl = NULL;
	ValaTypeSymbol* _tmp0_;
	ValaTypeSymbol* _tmp1_;
	gboolean _tmp2_ = FALSE;
	ValaClass* _tmp3_;
	ValaList* result = NULL;
	self = (ValaObjectType*) base;
	_tmp0_ = vala_data_type_get_type_symbol ((ValaDataType*) self);
	_tmp1_ = _tmp0_;
	cl = VALA_IS_CLASS (_tmp1_) ? ((ValaClass*) _tmp1_) : NULL;
	_tmp3_ = cl;
	if (_tmp3_ != NULL) {
		ValaClass* _tmp4_;
		ValaCreationMethod* _tmp5_;
		ValaCreationMethod* _tmp6_;
		_tmp4_ = cl;
		_tmp5_ = vala_class_get_default_construction_method (_tmp4_);
		_tmp6_ = _tmp5_;
		_tmp2_ = _tmp6_ != NULL;
	} else {
		_tmp2_ = FALSE;
	}
	if (_tmp2_) {
		ValaClass* _tmp7_;
		ValaCreationMethod* _tmp8_;
		ValaCreationMethod* _tmp9_;
		ValaList* _tmp10_;
		_tmp7_ = cl;
		_tmp8_ = vala_class_get_default_construction_method (_tmp7_);
		_tmp9_ = _tmp8_;
		_tmp10_ = vala_callable_get_parameters ((ValaCallable*) _tmp9_);
		result = _tmp10_;
		return result;
	} else {
		result = NULL;
		return result;
	}
}

static gboolean
vala_object_type_real_check (ValaCodeNode* base,
                             ValaCodeContext* context)
{
	ValaObjectType * self;
	ValaTypeSymbol* _tmp0_;
	ValaTypeSymbol* _tmp1_;
	gboolean result = FALSE;
	self = (ValaObjectType*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	_tmp0_ = vala_data_type_get_type_symbol ((ValaDataType*) self);
	_tmp1_ = _tmp0_;
	if (!vala_code_node_check ((ValaCodeNode*) _tmp1_, context)) {
		result = FALSE;
		return result;
	}
	if (!vala_data_type_check_type_arguments ((ValaDataType*) self, context, TRUE)) {
		result = FALSE;
		return result;
	}
	result = TRUE;
	return result;
}

static void
vala_object_type_class_init (ValaObjectTypeClass * klass,
                             gpointer klass_data)
{
	vala_object_type_parent_class = g_type_class_peek_parent (klass);
	((ValaDataTypeClass *) klass)->copy = (ValaDataType* (*) (ValaDataType*)) vala_object_type_real_copy;
	((ValaDataTypeClass *) klass)->stricter = (gboolean (*) (ValaDataType*, ValaDataType*)) vala_object_type_real_stricter;
	((ValaDataTypeClass *) klass)->is_invokable = (gboolean (*) (ValaDataType*)) vala_object_type_real_is_invokable;
	((ValaDataTypeClass *) klass)->get_return_type = (ValaDataType* (*) (ValaDataType*)) vala_object_type_real_get_return_type;
	((ValaDataTypeClass *) klass)->get_parameters = (ValaList* (*) (ValaDataType*)) vala_object_type_real_get_parameters;
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) vala_object_type_real_check;
}

static void
vala_object_type_instance_init (ValaObjectType * self,
                                gpointer klass)
{
}

/**
 * A class type.
 */
static GType
vala_object_type_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaObjectTypeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_object_type_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaObjectType), 0, (GInstanceInitFunc) vala_object_type_instance_init, NULL };
	GType vala_object_type_type_id;
	vala_object_type_type_id = g_type_register_static (VALA_TYPE_REFERENCE_TYPE, "ValaObjectType", &g_define_type_info, 0);
	return vala_object_type_type_id;
}

GType
vala_object_type_get_type (void)
{
	static volatile gsize vala_object_type_type_id__volatile = 0;
	if (g_once_init_enter (&vala_object_type_type_id__volatile)) {
		GType vala_object_type_type_id;
		vala_object_type_type_id = vala_object_type_get_type_once ();
		g_once_init_leave (&vala_object_type_type_id__volatile, vala_object_type_type_id);
	}
	return vala_object_type_type_id__volatile;
}

