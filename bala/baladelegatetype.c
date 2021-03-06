/* baladelegatetype.c generated by balac, the Bala compiler
 * generated from baladelegatetype.bala, do not modify */

/* baladelegatetype.bala
 *
 * Copyright (C) 2007-2012  Jürg Billeter
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
#define _g_free0(var) (var = (g_free (var), NULL))
#define _bala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (bala_iterable_unref (var), NULL)))
#define _bala_iterator_unref0(var) ((var == NULL) ? NULL : (var = (bala_iterator_unref (var), NULL)))

struct _BalaDelegateTypePrivate {
	gboolean _is_called_once;
	BalaDelegateTargetField* target_field;
	BalaDelegateDestroyField* destroy_field;
};

static gint BalaDelegateType_private_offset;
static gpointer bala_delegate_type_parent_class = NULL;

static BalaSymbol* bala_delegate_type_real_get_member (BalaDataType* base,
                                                const gchar* member_name);
static BalaDelegateTargetField* bala_delegate_type_get_target_field (BalaDelegateType* self);
static BalaDelegateDestroyField* bala_delegate_type_get_destroy_field (BalaDelegateType* self);
static BalaDataType* bala_delegate_type_real_copy (BalaDataType* base);
static gboolean bala_delegate_type_real_equals (BalaDataType* base,
                                         BalaDataType* type2);
static gboolean bala_delegate_type_real_is_accessible (BalaDataType* base,
                                                BalaSymbol* sym);
static gboolean bala_delegate_type_real_check (BalaCodeNode* base,
                                        BalaCodeContext* context);
static gboolean bala_delegate_type_real_compatible (BalaDataType* base,
                                             BalaDataType* target_type);
static gboolean bala_delegate_type_real_is_disposable (BalaDataType* base);
static void bala_delegate_type_finalize (BalaCodeNode * obj);
static GType bala_delegate_type_get_type_once (void);

static inline gpointer
bala_delegate_type_get_instance_private (BalaDelegateType* self)
{
	return G_STRUCT_MEMBER_P (self, BalaDelegateType_private_offset);
}

BalaDelegate*
bala_delegate_type_get_delegate_symbol (BalaDelegateType* self)
{
	BalaDelegate* result;
	BalaSymbol* _tmp0_;
	BalaSymbol* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = bala_data_type_get_symbol ((BalaDataType*) self);
	_tmp1_ = _tmp0_;
	result = G_TYPE_CHECK_INSTANCE_CAST (_tmp1_, BALA_TYPE_DELEGATE, BalaDelegate);
	return result;
}

gboolean
bala_delegate_type_get_is_called_once (BalaDelegateType* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_is_called_once;
	return result;
}

void
bala_delegate_type_set_is_called_once (BalaDelegateType* self,
                                       gboolean value)
{
	g_return_if_fail (self != NULL);
	self->priv->_is_called_once = value;
}

BalaDelegateType*
bala_delegate_type_construct (GType object_type,
                              BalaDelegate* delegate_symbol)
{
	BalaDelegateType* self = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_val_if_fail (delegate_symbol != NULL, NULL);
	self = (BalaDelegateType*) bala_callable_type_construct (object_type, (BalaSymbol*) delegate_symbol);
	_tmp0_ = bala_code_node_get_attribute_string ((BalaCodeNode*) delegate_symbol, "CCode", "scope", NULL);
	_tmp1_ = _tmp0_;
	bala_delegate_type_set_is_called_once (self, g_strcmp0 (_tmp1_, "async") == 0);
	_g_free0 (_tmp1_);
	return self;
}

BalaDelegateType*
bala_delegate_type_new (BalaDelegate* delegate_symbol)
{
	return bala_delegate_type_construct (BALA_TYPE_DELEGATE_TYPE, delegate_symbol);
}

static gpointer
_bala_code_node_ref0 (gpointer self)
{
	return self ? bala_code_node_ref (self) : NULL;
}

static BalaSymbol*
bala_delegate_type_real_get_member (BalaDataType* base,
                                    const gchar* member_name)
{
	BalaDelegateType * self;
	BalaSymbol* result = NULL;
	self = (BalaDelegateType*) base;
	g_return_val_if_fail (member_name != NULL, NULL);
	if (g_strcmp0 (member_name, "target") == 0) {
		BalaDelegateTargetField* _tmp0_;
		BalaSymbol* _tmp1_;
		_tmp0_ = bala_delegate_type_get_target_field (self);
		_tmp1_ = _bala_code_node_ref0 ((BalaSymbol*) _tmp0_);
		result = _tmp1_;
		return result;
	} else {
		if (g_strcmp0 (member_name, "destroy") == 0) {
			BalaDelegateDestroyField* _tmp2_;
			BalaSymbol* _tmp3_;
			_tmp2_ = bala_delegate_type_get_destroy_field (self);
			_tmp3_ = _bala_code_node_ref0 ((BalaSymbol*) _tmp2_);
			result = _tmp3_;
			return result;
		}
	}
	result = NULL;
	return result;
}

static BalaDelegateTargetField*
bala_delegate_type_get_target_field (BalaDelegateType* self)
{
	BalaDelegateTargetField* _tmp0_;
	BalaDelegateTargetField* _tmp5_;
	BalaDelegateTargetField* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->target_field;
	if (_tmp0_ == NULL) {
		BalaSourceReference* _tmp1_;
		BalaSourceReference* _tmp2_;
		BalaDelegateTargetField* _tmp3_;
		BalaDelegateTargetField* _tmp4_;
		_tmp1_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
		_tmp2_ = _tmp1_;
		_tmp3_ = bala_delegate_target_field_new (_tmp2_);
		_bala_code_node_unref0 (self->priv->target_field);
		self->priv->target_field = _tmp3_;
		_tmp4_ = self->priv->target_field;
		bala_symbol_set_access ((BalaSymbol*) _tmp4_, BALA_SYMBOL_ACCESSIBILITY_PUBLIC);
	}
	_tmp5_ = self->priv->target_field;
	result = _tmp5_;
	return result;
}

static BalaDelegateDestroyField*
bala_delegate_type_get_destroy_field (BalaDelegateType* self)
{
	BalaDelegateDestroyField* _tmp0_;
	BalaDelegateDestroyField* _tmp5_;
	BalaDelegateDestroyField* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->destroy_field;
	if (_tmp0_ == NULL) {
		BalaSourceReference* _tmp1_;
		BalaSourceReference* _tmp2_;
		BalaDelegateDestroyField* _tmp3_;
		BalaDelegateDestroyField* _tmp4_;
		_tmp1_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
		_tmp2_ = _tmp1_;
		_tmp3_ = bala_delegate_destroy_field_new (_tmp2_);
		_bala_code_node_unref0 (self->priv->destroy_field);
		self->priv->destroy_field = _tmp3_;
		_tmp4_ = self->priv->destroy_field;
		bala_symbol_set_access ((BalaSymbol*) _tmp4_, BALA_SYMBOL_ACCESSIBILITY_PUBLIC);
	}
	_tmp5_ = self->priv->destroy_field;
	result = _tmp5_;
	return result;
}

static gpointer
_bala_iterable_ref0 (gpointer self)
{
	return self ? bala_iterable_ref (self) : NULL;
}

static BalaDataType*
bala_delegate_type_real_copy (BalaDataType* base)
{
	BalaDelegateType * self;
	BalaDelegateType* _result_ = NULL;
	BalaDelegate* _tmp0_;
	BalaDelegate* _tmp1_;
	BalaDelegateType* _tmp2_;
	BalaDelegateType* _tmp3_;
	BalaSourceReference* _tmp4_;
	BalaSourceReference* _tmp5_;
	BalaDelegateType* _tmp6_;
	gboolean _tmp7_;
	gboolean _tmp8_;
	BalaDelegateType* _tmp9_;
	gboolean _tmp10_;
	gboolean _tmp11_;
	BalaDelegateType* _tmp25_;
	gboolean _tmp26_;
	BalaDataType* result = NULL;
	self = (BalaDelegateType*) base;
	_tmp0_ = bala_delegate_type_get_delegate_symbol (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = bala_delegate_type_new (_tmp1_);
	_result_ = _tmp2_;
	_tmp3_ = _result_;
	_tmp4_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
	_tmp5_ = _tmp4_;
	bala_code_node_set_source_reference ((BalaCodeNode*) _tmp3_, _tmp5_);
	_tmp6_ = _result_;
	_tmp7_ = bala_data_type_get_value_owned ((BalaDataType*) self);
	_tmp8_ = _tmp7_;
	bala_data_type_set_value_owned ((BalaDataType*) _tmp6_, _tmp8_);
	_tmp9_ = _result_;
	_tmp10_ = bala_data_type_get_nullable ((BalaDataType*) self);
	_tmp11_ = _tmp10_;
	bala_data_type_set_nullable ((BalaDataType*) _tmp9_, _tmp11_);
	{
		BalaList* _arg_list = NULL;
		BalaList* _tmp12_;
		BalaList* _tmp13_;
		gint _arg_size = 0;
		BalaList* _tmp14_;
		gint _tmp15_;
		gint _tmp16_;
		gint _arg_index = 0;
		_tmp12_ = bala_data_type_get_type_arguments ((BalaDataType*) self);
		_tmp13_ = _bala_iterable_ref0 (_tmp12_);
		_arg_list = _tmp13_;
		_tmp14_ = _arg_list;
		_tmp15_ = bala_collection_get_size ((BalaCollection*) _tmp14_);
		_tmp16_ = _tmp15_;
		_arg_size = _tmp16_;
		_arg_index = -1;
		while (TRUE) {
			gint _tmp17_;
			gint _tmp18_;
			BalaDataType* arg = NULL;
			BalaList* _tmp19_;
			gpointer _tmp20_;
			BalaDelegateType* _tmp21_;
			BalaDataType* _tmp22_;
			BalaDataType* _tmp23_;
			BalaDataType* _tmp24_;
			_arg_index = _arg_index + 1;
			_tmp17_ = _arg_index;
			_tmp18_ = _arg_size;
			if (!(_tmp17_ < _tmp18_)) {
				break;
			}
			_tmp19_ = _arg_list;
			_tmp20_ = bala_list_get (_tmp19_, _arg_index);
			arg = (BalaDataType*) _tmp20_;
			_tmp21_ = _result_;
			_tmp22_ = arg;
			_tmp23_ = bala_data_type_copy (_tmp22_);
			_tmp24_ = _tmp23_;
			bala_data_type_add_type_argument ((BalaDataType*) _tmp21_, _tmp24_);
			_bala_code_node_unref0 (_tmp24_);
			_bala_code_node_unref0 (arg);
		}
		_bala_iterable_unref0 (_arg_list);
	}
	_tmp25_ = _result_;
	_tmp26_ = self->priv->_is_called_once;
	bala_delegate_type_set_is_called_once (_tmp25_, _tmp26_);
	result = (BalaDataType*) _result_;
	return result;
}

static gboolean
bala_delegate_type_real_equals (BalaDataType* base,
                                BalaDataType* type2)
{
	BalaDelegateType * self;
	gboolean result = FALSE;
	self = (BalaDelegateType*) base;
	g_return_val_if_fail (type2 != NULL, FALSE);
	result = bala_data_type_compatible ((BalaDataType*) self, type2);
	return result;
}

static gboolean
bala_delegate_type_real_is_accessible (BalaDataType* base,
                                       BalaSymbol* sym)
{
	BalaDelegateType * self;
	BalaDelegate* _tmp0_;
	BalaDelegate* _tmp1_;
	gboolean result = FALSE;
	self = (BalaDelegateType*) base;
	g_return_val_if_fail (sym != NULL, FALSE);
	_tmp0_ = bala_delegate_type_get_delegate_symbol (self);
	_tmp1_ = _tmp0_;
	result = bala_symbol_is_accessible ((BalaSymbol*) _tmp1_, sym);
	return result;
}

static gboolean
bala_delegate_type_real_check (BalaCodeNode* base,
                               BalaCodeContext* context)
{
	BalaDelegateType * self;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_;
	BalaDelegate* _tmp6_;
	BalaDelegate* _tmp7_;
	gboolean result = FALSE;
	self = (BalaDelegateType*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	_tmp1_ = self->priv->_is_called_once;
	if (_tmp1_) {
		gboolean _tmp2_;
		gboolean _tmp3_;
		_tmp2_ = bala_data_type_get_value_owned ((BalaDataType*) self);
		_tmp3_ = _tmp2_;
		_tmp0_ = !_tmp3_;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		BalaSourceReference* _tmp4_;
		BalaSourceReference* _tmp5_;
		_tmp4_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
		_tmp5_ = _tmp4_;
		bala_report_warning (_tmp5_, "delegates with scope=\"async\" must be owned");
	}
	_tmp6_ = bala_delegate_type_get_delegate_symbol (self);
	_tmp7_ = _tmp6_;
	if (!bala_code_node_check ((BalaCodeNode*) _tmp7_, context)) {
		result = FALSE;
		return result;
	}
	if (!bala_data_type_check_type_arguments ((BalaDataType*) self, context, TRUE)) {
		result = FALSE;
		return result;
	}
	result = TRUE;
	return result;
}

static gboolean
bala_delegate_type_real_compatible (BalaDataType* base,
                                    BalaDataType* target_type)
{
	BalaDelegateType * self;
	BalaDelegateType* dt_target = NULL;
	BalaDelegateType* _tmp0_;
	BalaDelegate* _tmp1_;
	BalaDelegate* _tmp2_;
	BalaDelegateType* _tmp3_;
	BalaDelegate* _tmp4_;
	BalaDelegate* _tmp5_;
	BalaDelegate* _tmp6_;
	BalaDelegate* _tmp7_;
	gboolean _tmp8_;
	gboolean _tmp9_;
	BalaDelegateType* _tmp10_;
	BalaDelegate* _tmp11_;
	BalaDelegate* _tmp12_;
	gboolean _tmp13_;
	gboolean _tmp14_;
	BalaDataType* _tmp15_;
	BalaDelegateType* _tmp16_;
	BalaDataType* _tmp17_;
	BalaDelegateType* _tmp18_;
	BalaDataType* _tmp19_;
	BalaDataType* _tmp20_;
	gboolean _tmp21_;
	BalaList* parameters = NULL;
	BalaList* _tmp22_;
	BalaList* _tmp23_;
	BalaIterator* params_it = NULL;
	BalaList* _tmp24_;
	BalaIterator* _tmp25_;
	gboolean _tmp26_ = FALSE;
	gboolean _tmp27_ = FALSE;
	BalaDelegateType* _tmp28_;
	BalaDelegate* _tmp29_;
	BalaDelegate* _tmp30_;
	BalaSymbol* _tmp31_;
	BalaSymbol* _tmp32_;
	BalaIterator* _tmp78_;
	BalaArrayList* error_types = NULL;
	GEqualFunc _tmp79_;
	BalaArrayList* _tmp80_;
	BalaArrayList* _tmp81_;
	gboolean result = FALSE;
	self = (BalaDelegateType*) base;
	g_return_val_if_fail (target_type != NULL, FALSE);
	dt_target = BALA_IS_DELEGATE_TYPE (target_type) ? ((BalaDelegateType*) target_type) : NULL;
	_tmp0_ = dt_target;
	if (_tmp0_ == NULL) {
		result = FALSE;
		return result;
	}
	_tmp1_ = bala_delegate_type_get_delegate_symbol (self);
	_tmp2_ = _tmp1_;
	_tmp3_ = dt_target;
	_tmp4_ = bala_delegate_type_get_delegate_symbol (_tmp3_);
	_tmp5_ = _tmp4_;
	if (_tmp2_ == _tmp5_) {
		result = TRUE;
		return result;
	}
	_tmp6_ = bala_delegate_type_get_delegate_symbol (self);
	_tmp7_ = _tmp6_;
	_tmp8_ = bala_delegate_get_has_target (_tmp7_);
	_tmp9_ = _tmp8_;
	_tmp10_ = dt_target;
	_tmp11_ = bala_delegate_type_get_delegate_symbol (_tmp10_);
	_tmp12_ = _tmp11_;
	_tmp13_ = bala_delegate_get_has_target (_tmp12_);
	_tmp14_ = _tmp13_;
	if (_tmp9_ != _tmp14_) {
		result = FALSE;
		return result;
	}
	_tmp15_ = bala_data_type_get_return_type ((BalaDataType*) self);
	_tmp16_ = dt_target;
	_tmp17_ = bala_data_type_get_return_type ((BalaDataType*) _tmp16_);
	_tmp18_ = dt_target;
	_tmp19_ = bala_data_type_get_actual_type (_tmp17_, (BalaDataType*) _tmp18_, NULL, (BalaCodeNode*) self);
	_tmp20_ = _tmp19_;
	_tmp21_ = !bala_data_type_stricter (_tmp15_, _tmp20_);
	_bala_code_node_unref0 (_tmp20_);
	if (_tmp21_) {
		result = FALSE;
		return result;
	}
	_tmp22_ = bala_data_type_get_parameters ((BalaDataType*) self);
	_tmp23_ = _bala_iterable_ref0 (_tmp22_);
	parameters = _tmp23_;
	_tmp24_ = parameters;
	_tmp25_ = bala_iterable_iterator ((BalaIterable*) _tmp24_);
	params_it = _tmp25_;
	_tmp28_ = dt_target;
	_tmp29_ = bala_delegate_type_get_delegate_symbol (_tmp28_);
	_tmp30_ = _tmp29_;
	_tmp31_ = bala_symbol_get_parent_symbol ((BalaSymbol*) _tmp30_);
	_tmp32_ = _tmp31_;
	if (BALA_IS_SIGNAL (_tmp32_)) {
		BalaDelegateType* _tmp33_;
		BalaDelegate* _tmp34_;
		BalaDelegate* _tmp35_;
		BalaDataType* _tmp36_;
		BalaDataType* _tmp37_;
		_tmp33_ = dt_target;
		_tmp34_ = bala_delegate_type_get_delegate_symbol (_tmp33_);
		_tmp35_ = _tmp34_;
		_tmp36_ = bala_delegate_get_sender_type (_tmp35_);
		_tmp37_ = _tmp36_;
		_tmp27_ = _tmp37_ != NULL;
	} else {
		_tmp27_ = FALSE;
	}
	if (_tmp27_) {
		BalaList* _tmp38_;
		gint _tmp39_;
		gint _tmp40_;
		BalaDelegateType* _tmp41_;
		BalaList* _tmp42_;
		gint _tmp43_;
		gint _tmp44_;
		_tmp38_ = parameters;
		_tmp39_ = bala_collection_get_size ((BalaCollection*) _tmp38_);
		_tmp40_ = _tmp39_;
		_tmp41_ = dt_target;
		_tmp42_ = bala_data_type_get_parameters ((BalaDataType*) _tmp41_);
		_tmp43_ = bala_collection_get_size ((BalaCollection*) _tmp42_);
		_tmp44_ = _tmp43_;
		_tmp26_ = _tmp40_ == (_tmp44_ + 1);
	} else {
		_tmp26_ = FALSE;
	}
	if (_tmp26_) {
		BalaIterator* _tmp45_;
		BalaParameter* p = NULL;
		BalaIterator* _tmp46_;
		gpointer _tmp47_;
		BalaDelegateType* _tmp48_;
		BalaDelegate* _tmp49_;
		BalaDelegate* _tmp50_;
		BalaDataType* _tmp51_;
		BalaDataType* _tmp52_;
		BalaParameter* _tmp53_;
		BalaDataType* _tmp54_;
		BalaDataType* _tmp55_;
		_tmp45_ = params_it;
		bala_iterator_next (_tmp45_);
		_tmp46_ = params_it;
		_tmp47_ = bala_iterator_get (_tmp46_);
		p = (BalaParameter*) _tmp47_;
		_tmp48_ = dt_target;
		_tmp49_ = bala_delegate_type_get_delegate_symbol (_tmp48_);
		_tmp50_ = _tmp49_;
		_tmp51_ = bala_delegate_get_sender_type (_tmp50_);
		_tmp52_ = _tmp51_;
		_tmp53_ = p;
		_tmp54_ = bala_variable_get_variable_type ((BalaVariable*) _tmp53_);
		_tmp55_ = _tmp54_;
		if (!bala_data_type_stricter (_tmp52_, _tmp55_)) {
			result = FALSE;
			_bala_code_node_unref0 (p);
			_bala_iterator_unref0 (params_it);
			_bala_iterable_unref0 (parameters);
			return result;
		}
		_bala_code_node_unref0 (p);
	}
	{
		BalaList* _param_list = NULL;
		BalaDelegateType* _tmp56_;
		BalaList* _tmp57_;
		BalaList* _tmp58_;
		gint _param_size = 0;
		BalaList* _tmp59_;
		gint _tmp60_;
		gint _tmp61_;
		gint _param_index = 0;
		_tmp56_ = dt_target;
		_tmp57_ = bala_data_type_get_parameters ((BalaDataType*) _tmp56_);
		_tmp58_ = _bala_iterable_ref0 (_tmp57_);
		_param_list = _tmp58_;
		_tmp59_ = _param_list;
		_tmp60_ = bala_collection_get_size ((BalaCollection*) _tmp59_);
		_tmp61_ = _tmp60_;
		_param_size = _tmp61_;
		_param_index = -1;
		while (TRUE) {
			gint _tmp62_;
			gint _tmp63_;
			BalaParameter* param = NULL;
			BalaList* _tmp64_;
			gpointer _tmp65_;
			BalaIterator* _tmp66_;
			BalaParameter* p = NULL;
			BalaIterator* _tmp67_;
			gpointer _tmp68_;
			BalaParameter* _tmp69_;
			BalaDataType* _tmp70_;
			BalaDataType* _tmp71_;
			BalaDataType* _tmp72_;
			BalaDataType* _tmp73_;
			BalaParameter* _tmp74_;
			BalaDataType* _tmp75_;
			BalaDataType* _tmp76_;
			gboolean _tmp77_;
			_param_index = _param_index + 1;
			_tmp62_ = _param_index;
			_tmp63_ = _param_size;
			if (!(_tmp62_ < _tmp63_)) {
				break;
			}
			_tmp64_ = _param_list;
			_tmp65_ = bala_list_get (_tmp64_, _param_index);
			param = (BalaParameter*) _tmp65_;
			_tmp66_ = params_it;
			if (!bala_iterator_next (_tmp66_)) {
				result = FALSE;
				_bala_code_node_unref0 (param);
				_bala_iterable_unref0 (_param_list);
				_bala_iterator_unref0 (params_it);
				_bala_iterable_unref0 (parameters);
				return result;
			}
			_tmp67_ = params_it;
			_tmp68_ = bala_iterator_get (_tmp67_);
			p = (BalaParameter*) _tmp68_;
			_tmp69_ = param;
			_tmp70_ = bala_variable_get_variable_type ((BalaVariable*) _tmp69_);
			_tmp71_ = _tmp70_;
			_tmp72_ = bala_data_type_get_actual_type (_tmp71_, (BalaDataType*) self, NULL, (BalaCodeNode*) self);
			_tmp73_ = _tmp72_;
			_tmp74_ = p;
			_tmp75_ = bala_variable_get_variable_type ((BalaVariable*) _tmp74_);
			_tmp76_ = _tmp75_;
			_tmp77_ = !bala_data_type_stricter (_tmp73_, _tmp76_);
			_bala_code_node_unref0 (_tmp73_);
			if (_tmp77_) {
				result = FALSE;
				_bala_code_node_unref0 (p);
				_bala_code_node_unref0 (param);
				_bala_iterable_unref0 (_param_list);
				_bala_iterator_unref0 (params_it);
				_bala_iterable_unref0 (parameters);
				return result;
			}
			_bala_code_node_unref0 (p);
			_bala_code_node_unref0 (param);
		}
		_bala_iterable_unref0 (_param_list);
	}
	_tmp78_ = params_it;
	if (bala_iterator_next (_tmp78_)) {
		result = FALSE;
		_bala_iterator_unref0 (params_it);
		_bala_iterable_unref0 (parameters);
		return result;
	}
	_tmp79_ = g_direct_equal;
	_tmp80_ = bala_array_list_new (BALA_TYPE_DATA_TYPE, (GBoxedCopyFunc) bala_code_node_ref, (GDestroyNotify) bala_code_node_unref, _tmp79_);
	error_types = _tmp80_;
	_tmp81_ = error_types;
	bala_code_node_get_error_types ((BalaCodeNode*) self, (BalaCollection*) _tmp81_, NULL);
	{
		BalaArrayList* _error_type_list = NULL;
		BalaArrayList* _tmp82_;
		BalaArrayList* _tmp83_;
		gint _error_type_size = 0;
		BalaArrayList* _tmp84_;
		gint _tmp85_;
		gint _tmp86_;
		gint _error_type_index = 0;
		_tmp82_ = error_types;
		_tmp83_ = _bala_iterable_ref0 (_tmp82_);
		_error_type_list = _tmp83_;
		_tmp84_ = _error_type_list;
		_tmp85_ = bala_collection_get_size ((BalaCollection*) _tmp84_);
		_tmp86_ = _tmp85_;
		_error_type_size = _tmp86_;
		_error_type_index = -1;
		while (TRUE) {
			gint _tmp87_;
			gint _tmp88_;
			BalaDataType* error_type = NULL;
			BalaArrayList* _tmp89_;
			gpointer _tmp90_;
			gboolean match = FALSE;
			BalaArrayList* delegate_error_types = NULL;
			GEqualFunc _tmp91_;
			BalaArrayList* _tmp92_;
			BalaDelegateType* _tmp93_;
			BalaArrayList* _tmp94_;
			_error_type_index = _error_type_index + 1;
			_tmp87_ = _error_type_index;
			_tmp88_ = _error_type_size;
			if (!(_tmp87_ < _tmp88_)) {
				break;
			}
			_tmp89_ = _error_type_list;
			_tmp90_ = bala_list_get ((BalaList*) _tmp89_, _error_type_index);
			error_type = (BalaDataType*) _tmp90_;
			match = FALSE;
			_tmp91_ = g_direct_equal;
			_tmp92_ = bala_array_list_new (BALA_TYPE_DATA_TYPE, (GBoxedCopyFunc) bala_code_node_ref, (GDestroyNotify) bala_code_node_unref, _tmp91_);
			delegate_error_types = _tmp92_;
			_tmp93_ = dt_target;
			_tmp94_ = delegate_error_types;
			bala_code_node_get_error_types ((BalaCodeNode*) _tmp93_, (BalaCollection*) _tmp94_, NULL);
			{
				BalaArrayList* _delegate_error_type_list = NULL;
				BalaArrayList* _tmp95_;
				BalaArrayList* _tmp96_;
				gint _delegate_error_type_size = 0;
				BalaArrayList* _tmp97_;
				gint _tmp98_;
				gint _tmp99_;
				gint _delegate_error_type_index = 0;
				_tmp95_ = delegate_error_types;
				_tmp96_ = _bala_iterable_ref0 (_tmp95_);
				_delegate_error_type_list = _tmp96_;
				_tmp97_ = _delegate_error_type_list;
				_tmp98_ = bala_collection_get_size ((BalaCollection*) _tmp97_);
				_tmp99_ = _tmp98_;
				_delegate_error_type_size = _tmp99_;
				_delegate_error_type_index = -1;
				while (TRUE) {
					gint _tmp100_;
					gint _tmp101_;
					BalaDataType* delegate_error_type = NULL;
					BalaArrayList* _tmp102_;
					gpointer _tmp103_;
					BalaDataType* _tmp104_;
					BalaDataType* _tmp105_;
					_delegate_error_type_index = _delegate_error_type_index + 1;
					_tmp100_ = _delegate_error_type_index;
					_tmp101_ = _delegate_error_type_size;
					if (!(_tmp100_ < _tmp101_)) {
						break;
					}
					_tmp102_ = _delegate_error_type_list;
					_tmp103_ = bala_list_get ((BalaList*) _tmp102_, _delegate_error_type_index);
					delegate_error_type = (BalaDataType*) _tmp103_;
					_tmp104_ = error_type;
					_tmp105_ = delegate_error_type;
					if (bala_data_type_compatible (_tmp104_, _tmp105_)) {
						match = TRUE;
						_bala_code_node_unref0 (delegate_error_type);
						break;
					}
					_bala_code_node_unref0 (delegate_error_type);
				}
				_bala_iterable_unref0 (_delegate_error_type_list);
			}
			if (!match) {
				result = FALSE;
				_bala_iterable_unref0 (delegate_error_types);
				_bala_code_node_unref0 (error_type);
				_bala_iterable_unref0 (_error_type_list);
				_bala_iterable_unref0 (error_types);
				_bala_iterator_unref0 (params_it);
				_bala_iterable_unref0 (parameters);
				return result;
			}
			_bala_iterable_unref0 (delegate_error_types);
			_bala_code_node_unref0 (error_type);
		}
		_bala_iterable_unref0 (_error_type_list);
	}
	result = TRUE;
	_bala_iterable_unref0 (error_types);
	_bala_iterator_unref0 (params_it);
	_bala_iterable_unref0 (parameters);
	return result;
}

static gboolean
bala_delegate_type_real_is_disposable (BalaDataType* base)
{
	BalaDelegateType * self;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	BalaDelegate* _tmp2_;
	BalaDelegate* _tmp3_;
	gboolean _tmp4_;
	gboolean _tmp5_;
	gboolean result = FALSE;
	self = (BalaDelegateType*) base;
	_tmp2_ = bala_delegate_type_get_delegate_symbol (self);
	_tmp3_ = _tmp2_;
	_tmp4_ = bala_delegate_get_has_target (_tmp3_);
	_tmp5_ = _tmp4_;
	if (_tmp5_) {
		gboolean _tmp6_;
		gboolean _tmp7_;
		_tmp6_ = bala_data_type_get_value_owned ((BalaDataType*) self);
		_tmp7_ = _tmp6_;
		_tmp1_ = _tmp7_;
	} else {
		_tmp1_ = FALSE;
	}
	if (_tmp1_) {
		gboolean _tmp8_;
		_tmp8_ = self->priv->_is_called_once;
		_tmp0_ = !_tmp8_;
	} else {
		_tmp0_ = FALSE;
	}
	result = _tmp0_;
	return result;
}

static void
bala_delegate_type_class_init (BalaDelegateTypeClass * klass,
                               gpointer klass_data)
{
	bala_delegate_type_parent_class = g_type_class_peek_parent (klass);
	((BalaCodeNodeClass *) klass)->finalize = bala_delegate_type_finalize;
	g_type_class_adjust_private_offset (klass, &BalaDelegateType_private_offset);
	((BalaDataTypeClass *) klass)->get_member = (BalaSymbol* (*) (BalaDataType*, const gchar*)) bala_delegate_type_real_get_member;
	((BalaDataTypeClass *) klass)->copy = (BalaDataType* (*) (BalaDataType*)) bala_delegate_type_real_copy;
	((BalaDataTypeClass *) klass)->equals = (gboolean (*) (BalaDataType*, BalaDataType*)) bala_delegate_type_real_equals;
	((BalaDataTypeClass *) klass)->is_accessible = (gboolean (*) (BalaDataType*, BalaSymbol*)) bala_delegate_type_real_is_accessible;
	((BalaCodeNodeClass *) klass)->check = (gboolean (*) (BalaCodeNode*, BalaCodeContext*)) bala_delegate_type_real_check;
	((BalaDataTypeClass *) klass)->compatible = (gboolean (*) (BalaDataType*, BalaDataType*)) bala_delegate_type_real_compatible;
	((BalaDataTypeClass *) klass)->is_disposable = (gboolean (*) (BalaDataType*)) bala_delegate_type_real_is_disposable;
}

static void
bala_delegate_type_instance_init (BalaDelegateType * self,
                                  gpointer klass)
{
	self->priv = bala_delegate_type_get_instance_private (self);
}

static void
bala_delegate_type_finalize (BalaCodeNode * obj)
{
	BalaDelegateType * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_DELEGATE_TYPE, BalaDelegateType);
	_bala_code_node_unref0 (self->priv->target_field);
	_bala_code_node_unref0 (self->priv->destroy_field);
	BALA_CODE_NODE_CLASS (bala_delegate_type_parent_class)->finalize (obj);
}

/**
 * The type of an instance of a delegate.
 */
static GType
bala_delegate_type_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaDelegateTypeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_delegate_type_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaDelegateType), 0, (GInstanceInitFunc) bala_delegate_type_instance_init, NULL };
	GType bala_delegate_type_type_id;
	bala_delegate_type_type_id = g_type_register_static (BALA_TYPE_CALLABLE_TYPE, "BalaDelegateType", &g_define_type_info, 0);
	BalaDelegateType_private_offset = g_type_add_instance_private (bala_delegate_type_type_id, sizeof (BalaDelegateTypePrivate));
	return bala_delegate_type_type_id;
}

GType
bala_delegate_type_get_type (void)
{
	static volatile gsize bala_delegate_type_type_id__volatile = 0;
	if (g_once_init_enter (&bala_delegate_type_type_id__volatile)) {
		GType bala_delegate_type_type_id;
		bala_delegate_type_type_id = bala_delegate_type_get_type_once ();
		g_once_init_leave (&bala_delegate_type_type_id__volatile, bala_delegate_type_type_id);
	}
	return bala_delegate_type_type_id__volatile;
}

