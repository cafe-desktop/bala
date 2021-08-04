/* balasignaltype.c generated by balac, the Bala compiler
 * generated from balasignaltype.bala, do not modify */

/* balasignaltype.bala
 *
 * Copyright (C) 2007-2011  Jürg Billeter
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
#include <balagee.h>
#include <glib-object.h>

#define _bala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (bala_code_node_unref (var), NULL)))
#define _bala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (bala_iterable_unref (var), NULL)))
#define _bala_code_context_unref0(var) ((var == NULL) ? NULL : (var = (bala_code_context_unref (var), NULL)))

struct _BalaSignalTypePrivate {
	BalaMethod* connect_method;
	BalaMethod* connect_after_method;
	BalaMethod* disconnect_method;
};

static gint BalaSignalType_private_offset;
static gpointer bala_signal_type_parent_class = NULL;

static BalaDataType* bala_signal_type_real_copy (BalaDataType* base);
static gboolean bala_signal_type_real_compatible (BalaDataType* base,
                                           BalaDataType* target_type);
static gchar* bala_signal_type_real_to_qualified_string (BalaDataType* base,
                                                  BalaScope* scope);
static BalaMethod* bala_signal_type_get_connect_method (BalaSignalType* self);
static BalaMethod* bala_signal_type_get_connect_after_method (BalaSignalType* self);
static BalaMethod* bala_signal_type_get_disconnect_method (BalaSignalType* self);
static BalaSymbol* bala_signal_type_real_get_member (BalaDataType* base,
                                              const gchar* member_name);
static gboolean bala_signal_type_real_is_accessible (BalaDataType* base,
                                              BalaSymbol* sym);
static void bala_signal_type_finalize (BalaCodeNode * obj);
static GType bala_signal_type_get_type_once (void);

static inline gpointer
bala_signal_type_get_instance_private (BalaSignalType* self)
{
	return G_STRUCT_MEMBER_P (self, BalaSignalType_private_offset);
}

BalaSignal*
bala_signal_type_get_signal_symbol (BalaSignalType* self)
{
	BalaSignal* result;
	BalaSymbol* _tmp0_;
	BalaSymbol* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = bala_data_type_get_symbol ((BalaDataType*) self);
	_tmp1_ = _tmp0_;
	result = G_TYPE_CHECK_INSTANCE_CAST (_tmp1_, BALA_TYPE_SIGNAL, BalaSignal);
	return result;
}

BalaSignalType*
bala_signal_type_construct (GType object_type,
                            BalaSignal* signal_symbol)
{
	BalaSignalType* self = NULL;
	g_return_val_if_fail (signal_symbol != NULL, NULL);
	self = (BalaSignalType*) bala_callable_type_construct (object_type, (BalaSymbol*) signal_symbol);
	return self;
}

BalaSignalType*
bala_signal_type_new (BalaSignal* signal_symbol)
{
	return bala_signal_type_construct (BALA_TYPE_SIGNAL_TYPE, signal_symbol);
}

static BalaDataType*
bala_signal_type_real_copy (BalaDataType* base)
{
	BalaSignalType * self;
	BalaSignal* _tmp0_;
	BalaSignal* _tmp1_;
	BalaSignalType* _tmp2_;
	BalaDataType* result = NULL;
	self = (BalaSignalType*) base;
	_tmp0_ = bala_signal_type_get_signal_symbol (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = bala_signal_type_new (_tmp1_);
	result = (BalaDataType*) _tmp2_;
	return result;
}

static gboolean
bala_signal_type_real_compatible (BalaDataType* base,
                                  BalaDataType* target_type)
{
	BalaSignalType * self;
	gboolean result = FALSE;
	self = (BalaSignalType*) base;
	g_return_val_if_fail (target_type != NULL, FALSE);
	result = FALSE;
	return result;
}

static gchar*
bala_signal_type_real_to_qualified_string (BalaDataType* base,
                                           BalaScope* scope)
{
	BalaSignalType * self;
	BalaSignal* _tmp0_;
	BalaSignal* _tmp1_;
	gchar* _tmp2_;
	gchar* result = NULL;
	self = (BalaSignalType*) base;
	_tmp0_ = bala_signal_type_get_signal_symbol (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = bala_symbol_get_full_name ((BalaSymbol*) _tmp1_);
	result = _tmp2_;
	return result;
}

static gpointer
_bala_code_node_ref0 (gpointer self)
{
	return self ? bala_code_node_ref (self) : NULL;
}

static gpointer
_bala_iterable_ref0 (gpointer self)
{
	return self ? bala_iterable_ref (self) : NULL;
}

BalaDelegateType*
bala_signal_type_get_handler_type (BalaSignalType* self)
{
	BalaObjectTypeSymbol* type_sym = NULL;
	BalaSignal* _tmp0_;
	BalaSignal* _tmp1_;
	BalaSymbol* _tmp2_;
	BalaSymbol* _tmp3_;
	BalaObjectTypeSymbol* _tmp4_;
	BalaDataType* sender_type = NULL;
	BalaObjectTypeSymbol* _tmp5_;
	BalaDataType* _tmp6_;
	BalaDelegateType* _result_ = NULL;
	BalaSignal* _tmp7_;
	BalaSignal* _tmp8_;
	BalaDataType* _tmp9_;
	BalaDelegate* _tmp10_;
	BalaDelegate* _tmp11_;
	BalaDelegateType* _tmp12_;
	BalaDelegateType* _tmp13_;
	BalaDelegateType* _tmp14_;
	BalaDelegateType* _tmp15_;
	BalaDelegate* _tmp16_;
	BalaDelegate* _tmp17_;
	BalaDelegateType* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = bala_signal_type_get_signal_symbol (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = bala_symbol_get_parent_symbol ((BalaSymbol*) _tmp1_);
	_tmp3_ = _tmp2_;
	_tmp4_ = _bala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp3_, BALA_TYPE_OBJECT_TYPE_SYMBOL, BalaObjectTypeSymbol));
	type_sym = _tmp4_;
	_tmp5_ = type_sym;
	_tmp6_ = bala_semantic_analyzer_get_data_type_for_symbol ((BalaSymbol*) _tmp5_);
	sender_type = _tmp6_;
	_tmp7_ = bala_signal_type_get_signal_symbol (self);
	_tmp8_ = _tmp7_;
	_tmp9_ = sender_type;
	_tmp10_ = bala_signal_get_delegate (_tmp8_, _tmp9_, (BalaCodeNode*) self);
	_tmp11_ = _tmp10_;
	_tmp12_ = bala_delegate_type_new (_tmp11_);
	_tmp13_ = _tmp12_;
	_bala_code_node_unref0 (_tmp11_);
	_result_ = _tmp13_;
	_tmp14_ = _result_;
	bala_data_type_set_value_owned ((BalaDataType*) _tmp14_, TRUE);
	_tmp15_ = _result_;
	_tmp16_ = bala_delegate_type_get_delegate_symbol (_tmp15_);
	_tmp17_ = _tmp16_;
	if (bala_delegate_has_type_parameters (_tmp17_)) {
		{
			BalaList* _type_param_list = NULL;
			BalaObjectTypeSymbol* _tmp18_;
			BalaList* _tmp19_;
			BalaList* _tmp20_;
			gint _type_param_size = 0;
			BalaList* _tmp21_;
			gint _tmp22_;
			gint _tmp23_;
			gint _type_param_index = 0;
			_tmp18_ = type_sym;
			_tmp19_ = bala_object_type_symbol_get_type_parameters (_tmp18_);
			_tmp20_ = _bala_iterable_ref0 (_tmp19_);
			_type_param_list = _tmp20_;
			_tmp21_ = _type_param_list;
			_tmp22_ = bala_collection_get_size ((BalaCollection*) _tmp21_);
			_tmp23_ = _tmp22_;
			_type_param_size = _tmp23_;
			_type_param_index = -1;
			while (TRUE) {
				gint _tmp24_;
				gint _tmp25_;
				BalaTypeParameter* type_param = NULL;
				BalaList* _tmp26_;
				gpointer _tmp27_;
				BalaGenericType* type_arg = NULL;
				BalaTypeParameter* _tmp28_;
				BalaGenericType* _tmp29_;
				BalaGenericType* _tmp30_;
				BalaDelegateType* _tmp31_;
				BalaGenericType* _tmp32_;
				_type_param_index = _type_param_index + 1;
				_tmp24_ = _type_param_index;
				_tmp25_ = _type_param_size;
				if (!(_tmp24_ < _tmp25_)) {
					break;
				}
				_tmp26_ = _type_param_list;
				_tmp27_ = bala_list_get (_tmp26_, _type_param_index);
				type_param = (BalaTypeParameter*) _tmp27_;
				_tmp28_ = type_param;
				_tmp29_ = bala_generic_type_new (_tmp28_);
				type_arg = _tmp29_;
				_tmp30_ = type_arg;
				bala_data_type_set_value_owned ((BalaDataType*) _tmp30_, TRUE);
				_tmp31_ = _result_;
				_tmp32_ = type_arg;
				bala_data_type_add_type_argument ((BalaDataType*) _tmp31_, (BalaDataType*) _tmp32_);
				_bala_code_node_unref0 (type_arg);
				_bala_code_node_unref0 (type_param);
			}
			_bala_iterable_unref0 (_type_param_list);
		}
	}
	result = _result_;
	_bala_code_node_unref0 (sender_type);
	_bala_code_node_unref0 (type_sym);
	return result;
}

static BalaMethod*
bala_signal_type_get_connect_method (BalaSignalType* self)
{
	BalaMethod* _tmp0_;
	BalaMethod* _tmp25_;
	BalaMethod* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->connect_method;
	if (_tmp0_ == NULL) {
		BalaIntegerType* ulong_type = NULL;
		BalaCodeContext* _tmp1_;
		BalaCodeContext* _tmp2_;
		BalaNamespace* _tmp3_;
		BalaNamespace* _tmp4_;
		BalaScope* _tmp5_;
		BalaScope* _tmp6_;
		BalaSymbol* _tmp7_;
		BalaStruct* _tmp8_;
		BalaIntegerType* _tmp9_;
		BalaIntegerType* _tmp10_;
		BalaIntegerType* _tmp11_;
		BalaMethod* _tmp12_;
		BalaMethod* _tmp13_;
		BalaMethod* _tmp14_;
		BalaMethod* _tmp15_;
		BalaSignal* _tmp16_;
		BalaSignal* _tmp17_;
		BalaScope* _tmp18_;
		BalaScope* _tmp19_;
		BalaMethod* _tmp20_;
		BalaDelegateType* _tmp21_;
		BalaDelegateType* _tmp22_;
		BalaParameter* _tmp23_;
		BalaParameter* _tmp24_;
		_tmp1_ = bala_code_context_get ();
		_tmp2_ = _tmp1_;
		_tmp3_ = bala_code_context_get_root (_tmp2_);
		_tmp4_ = _tmp3_;
		_tmp5_ = bala_symbol_get_scope ((BalaSymbol*) _tmp4_);
		_tmp6_ = _tmp5_;
		_tmp7_ = bala_scope_lookup (_tmp6_, "ulong");
		_tmp8_ = G_TYPE_CHECK_INSTANCE_CAST (_tmp7_, BALA_TYPE_STRUCT, BalaStruct);
		_tmp9_ = bala_integer_type_new (_tmp8_, NULL, NULL);
		_tmp10_ = _tmp9_;
		_bala_code_node_unref0 (_tmp8_);
		_bala_code_context_unref0 (_tmp2_);
		ulong_type = _tmp10_;
		_tmp11_ = ulong_type;
		_tmp12_ = bala_method_new ("connect", (BalaDataType*) _tmp11_, NULL, NULL);
		_bala_code_node_unref0 (self->priv->connect_method);
		self->priv->connect_method = _tmp12_;
		_tmp13_ = self->priv->connect_method;
		bala_symbol_set_access ((BalaSymbol*) _tmp13_, BALA_SYMBOL_ACCESSIBILITY_PUBLIC);
		_tmp14_ = self->priv->connect_method;
		bala_symbol_set_external ((BalaSymbol*) _tmp14_, TRUE);
		_tmp15_ = self->priv->connect_method;
		_tmp16_ = bala_signal_type_get_signal_symbol (self);
		_tmp17_ = _tmp16_;
		_tmp18_ = bala_symbol_get_scope ((BalaSymbol*) _tmp17_);
		_tmp19_ = _tmp18_;
		bala_symbol_set_owner ((BalaSymbol*) _tmp15_, _tmp19_);
		_tmp20_ = self->priv->connect_method;
		_tmp21_ = bala_signal_type_get_handler_type (self);
		_tmp22_ = _tmp21_;
		_tmp23_ = bala_parameter_new ("handler", (BalaDataType*) _tmp22_, NULL);
		_tmp24_ = _tmp23_;
		bala_callable_add_parameter ((BalaCallable*) _tmp20_, _tmp24_);
		_bala_code_node_unref0 (_tmp24_);
		_bala_code_node_unref0 (_tmp22_);
		_bala_code_node_unref0 (ulong_type);
	}
	_tmp25_ = self->priv->connect_method;
	result = _tmp25_;
	return result;
}

static BalaMethod*
bala_signal_type_get_connect_after_method (BalaSignalType* self)
{
	BalaMethod* _tmp0_;
	BalaMethod* _tmp25_;
	BalaMethod* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->connect_after_method;
	if (_tmp0_ == NULL) {
		BalaIntegerType* ulong_type = NULL;
		BalaCodeContext* _tmp1_;
		BalaCodeContext* _tmp2_;
		BalaNamespace* _tmp3_;
		BalaNamespace* _tmp4_;
		BalaScope* _tmp5_;
		BalaScope* _tmp6_;
		BalaSymbol* _tmp7_;
		BalaStruct* _tmp8_;
		BalaIntegerType* _tmp9_;
		BalaIntegerType* _tmp10_;
		BalaIntegerType* _tmp11_;
		BalaMethod* _tmp12_;
		BalaMethod* _tmp13_;
		BalaMethod* _tmp14_;
		BalaMethod* _tmp15_;
		BalaSignal* _tmp16_;
		BalaSignal* _tmp17_;
		BalaScope* _tmp18_;
		BalaScope* _tmp19_;
		BalaMethod* _tmp20_;
		BalaDelegateType* _tmp21_;
		BalaDelegateType* _tmp22_;
		BalaParameter* _tmp23_;
		BalaParameter* _tmp24_;
		_tmp1_ = bala_code_context_get ();
		_tmp2_ = _tmp1_;
		_tmp3_ = bala_code_context_get_root (_tmp2_);
		_tmp4_ = _tmp3_;
		_tmp5_ = bala_symbol_get_scope ((BalaSymbol*) _tmp4_);
		_tmp6_ = _tmp5_;
		_tmp7_ = bala_scope_lookup (_tmp6_, "ulong");
		_tmp8_ = G_TYPE_CHECK_INSTANCE_CAST (_tmp7_, BALA_TYPE_STRUCT, BalaStruct);
		_tmp9_ = bala_integer_type_new (_tmp8_, NULL, NULL);
		_tmp10_ = _tmp9_;
		_bala_code_node_unref0 (_tmp8_);
		_bala_code_context_unref0 (_tmp2_);
		ulong_type = _tmp10_;
		_tmp11_ = ulong_type;
		_tmp12_ = bala_method_new ("connect_after", (BalaDataType*) _tmp11_, NULL, NULL);
		_bala_code_node_unref0 (self->priv->connect_after_method);
		self->priv->connect_after_method = _tmp12_;
		_tmp13_ = self->priv->connect_after_method;
		bala_symbol_set_access ((BalaSymbol*) _tmp13_, BALA_SYMBOL_ACCESSIBILITY_PUBLIC);
		_tmp14_ = self->priv->connect_after_method;
		bala_symbol_set_external ((BalaSymbol*) _tmp14_, TRUE);
		_tmp15_ = self->priv->connect_after_method;
		_tmp16_ = bala_signal_type_get_signal_symbol (self);
		_tmp17_ = _tmp16_;
		_tmp18_ = bala_symbol_get_scope ((BalaSymbol*) _tmp17_);
		_tmp19_ = _tmp18_;
		bala_symbol_set_owner ((BalaSymbol*) _tmp15_, _tmp19_);
		_tmp20_ = self->priv->connect_after_method;
		_tmp21_ = bala_signal_type_get_handler_type (self);
		_tmp22_ = _tmp21_;
		_tmp23_ = bala_parameter_new ("handler", (BalaDataType*) _tmp22_, NULL);
		_tmp24_ = _tmp23_;
		bala_callable_add_parameter ((BalaCallable*) _tmp20_, _tmp24_);
		_bala_code_node_unref0 (_tmp24_);
		_bala_code_node_unref0 (_tmp22_);
		_bala_code_node_unref0 (ulong_type);
	}
	_tmp25_ = self->priv->connect_after_method;
	result = _tmp25_;
	return result;
}

static BalaMethod*
bala_signal_type_get_disconnect_method (BalaSignalType* self)
{
	BalaMethod* _tmp0_;
	BalaMethod* _tmp16_;
	BalaMethod* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->disconnect_method;
	if (_tmp0_ == NULL) {
		BalaVoidType* _tmp1_;
		BalaVoidType* _tmp2_;
		BalaMethod* _tmp3_;
		BalaMethod* _tmp4_;
		BalaMethod* _tmp5_;
		BalaMethod* _tmp6_;
		BalaSignal* _tmp7_;
		BalaSignal* _tmp8_;
		BalaScope* _tmp9_;
		BalaScope* _tmp10_;
		BalaMethod* _tmp11_;
		BalaDelegateType* _tmp12_;
		BalaDelegateType* _tmp13_;
		BalaParameter* _tmp14_;
		BalaParameter* _tmp15_;
		_tmp1_ = bala_void_type_new (NULL);
		_tmp2_ = _tmp1_;
		_tmp3_ = bala_method_new ("disconnect", (BalaDataType*) _tmp2_, NULL, NULL);
		_bala_code_node_unref0 (self->priv->disconnect_method);
		self->priv->disconnect_method = _tmp3_;
		_bala_code_node_unref0 (_tmp2_);
		_tmp4_ = self->priv->disconnect_method;
		bala_symbol_set_access ((BalaSymbol*) _tmp4_, BALA_SYMBOL_ACCESSIBILITY_PUBLIC);
		_tmp5_ = self->priv->disconnect_method;
		bala_symbol_set_external ((BalaSymbol*) _tmp5_, TRUE);
		_tmp6_ = self->priv->disconnect_method;
		_tmp7_ = bala_signal_type_get_signal_symbol (self);
		_tmp8_ = _tmp7_;
		_tmp9_ = bala_symbol_get_scope ((BalaSymbol*) _tmp8_);
		_tmp10_ = _tmp9_;
		bala_symbol_set_owner ((BalaSymbol*) _tmp6_, _tmp10_);
		_tmp11_ = self->priv->disconnect_method;
		_tmp12_ = bala_signal_type_get_handler_type (self);
		_tmp13_ = _tmp12_;
		_tmp14_ = bala_parameter_new ("handler", (BalaDataType*) _tmp13_, NULL);
		_tmp15_ = _tmp14_;
		bala_callable_add_parameter ((BalaCallable*) _tmp11_, _tmp15_);
		_bala_code_node_unref0 (_tmp15_);
		_bala_code_node_unref0 (_tmp13_);
	}
	_tmp16_ = self->priv->disconnect_method;
	result = _tmp16_;
	return result;
}

static BalaSymbol*
bala_signal_type_real_get_member (BalaDataType* base,
                                  const gchar* member_name)
{
	BalaSignalType * self;
	BalaSymbol* result = NULL;
	self = (BalaSignalType*) base;
	g_return_val_if_fail (member_name != NULL, NULL);
	if (g_strcmp0 (member_name, "connect") == 0) {
		BalaMethod* _tmp0_;
		BalaSymbol* _tmp1_;
		_tmp0_ = bala_signal_type_get_connect_method (self);
		_tmp1_ = _bala_code_node_ref0 ((BalaSymbol*) _tmp0_);
		result = _tmp1_;
		return result;
	} else {
		if (g_strcmp0 (member_name, "connect_after") == 0) {
			BalaMethod* _tmp2_;
			BalaSymbol* _tmp3_;
			_tmp2_ = bala_signal_type_get_connect_after_method (self);
			_tmp3_ = _bala_code_node_ref0 ((BalaSymbol*) _tmp2_);
			result = _tmp3_;
			return result;
		} else {
			if (g_strcmp0 (member_name, "disconnect") == 0) {
				BalaMethod* _tmp4_;
				BalaSymbol* _tmp5_;
				_tmp4_ = bala_signal_type_get_disconnect_method (self);
				_tmp5_ = _bala_code_node_ref0 ((BalaSymbol*) _tmp4_);
				result = _tmp5_;
				return result;
			}
		}
	}
	result = NULL;
	return result;
}

static gboolean
bala_signal_type_real_is_accessible (BalaDataType* base,
                                     BalaSymbol* sym)
{
	BalaSignalType * self;
	BalaSignal* _tmp0_;
	BalaSignal* _tmp1_;
	gboolean result = FALSE;
	self = (BalaSignalType*) base;
	g_return_val_if_fail (sym != NULL, FALSE);
	_tmp0_ = bala_signal_type_get_signal_symbol (self);
	_tmp1_ = _tmp0_;
	result = bala_symbol_is_accessible ((BalaSymbol*) _tmp1_, sym);
	return result;
}

static void
bala_signal_type_class_init (BalaSignalTypeClass * klass,
                             gpointer klass_data)
{
	bala_signal_type_parent_class = g_type_class_peek_parent (klass);
	((BalaCodeNodeClass *) klass)->finalize = bala_signal_type_finalize;
	g_type_class_adjust_private_offset (klass, &BalaSignalType_private_offset);
	((BalaDataTypeClass *) klass)->copy = (BalaDataType* (*) (BalaDataType*)) bala_signal_type_real_copy;
	((BalaDataTypeClass *) klass)->compatible = (gboolean (*) (BalaDataType*, BalaDataType*)) bala_signal_type_real_compatible;
	((BalaDataTypeClass *) klass)->to_qualified_string = (gchar* (*) (BalaDataType*, BalaScope*)) bala_signal_type_real_to_qualified_string;
	((BalaDataTypeClass *) klass)->get_member = (BalaSymbol* (*) (BalaDataType*, const gchar*)) bala_signal_type_real_get_member;
	((BalaDataTypeClass *) klass)->is_accessible = (gboolean (*) (BalaDataType*, BalaSymbol*)) bala_signal_type_real_is_accessible;
}

static void
bala_signal_type_instance_init (BalaSignalType * self,
                                gpointer klass)
{
	self->priv = bala_signal_type_get_instance_private (self);
}

static void
bala_signal_type_finalize (BalaCodeNode * obj)
{
	BalaSignalType * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_SIGNAL_TYPE, BalaSignalType);
	_bala_code_node_unref0 (self->priv->connect_method);
	_bala_code_node_unref0 (self->priv->connect_after_method);
	_bala_code_node_unref0 (self->priv->disconnect_method);
	BALA_CODE_NODE_CLASS (bala_signal_type_parent_class)->finalize (obj);
}

/**
 * The type of a signal referencea.
 */
static GType
bala_signal_type_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaSignalTypeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_signal_type_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaSignalType), 0, (GInstanceInitFunc) bala_signal_type_instance_init, NULL };
	GType bala_signal_type_type_id;
	bala_signal_type_type_id = g_type_register_static (BALA_TYPE_CALLABLE_TYPE, "BalaSignalType", &g_define_type_info, 0);
	BalaSignalType_private_offset = g_type_add_instance_private (bala_signal_type_type_id, sizeof (BalaSignalTypePrivate));
	return bala_signal_type_type_id;
}

GType
bala_signal_type_get_type (void)
{
	static volatile gsize bala_signal_type_type_id__volatile = 0;
	if (g_once_init_enter (&bala_signal_type_type_id__volatile)) {
		GType bala_signal_type_type_id;
		bala_signal_type_type_id = bala_signal_type_get_type_once ();
		g_once_init_leave (&bala_signal_type_type_id__volatile, bala_signal_type_type_id);
	}
	return bala_signal_type_type_id__volatile;
}

