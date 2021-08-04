/* balagvaluemodule.c generated by balac, the Bala compiler
 * generated from balagvaluemodule.bala, do not modify */

/* balagvaluemodule.bala
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

#include "balacodegen.h"
#include <bala.h>
#include <balaccode.h>
#include <glib.h>
#include <balagee.h>
#include <glib-object.h>

#define _g_free0(var) (var = (g_free (var), NULL))
#define _bala_ccode_node_unref0(var) ((var == NULL) ? NULL : (var = (bala_ccode_node_unref (var), NULL)))
#define _bala_target_value_unref0(var) ((var == NULL) ? NULL : (var = (bala_target_value_unref (var), NULL)))
#define _bala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (bala_code_node_unref (var), NULL)))

static gpointer bala_gvalue_module_parent_class = NULL;

static void bala_gvalue_module_real_visit_cast_expression (BalaCodeVisitor* base,
                                                    BalaCastExpression* expr);
static BalaCCodeExpression* bala_gvalue_module_real_get_value_getter_function (BalaCCodeBaseModule* base,
                                                                        BalaDataType* type_reference);
static BalaCCodeExpression* bala_gvalue_module_real_get_value_setter_function (BalaCCodeBaseModule* base,
                                                                        BalaDataType* type_reference);
static BalaCCodeExpression* bala_gvalue_module_real_get_value_taker_function (BalaCCodeBaseModule* base,
                                                                       BalaDataType* type_reference);
static GType bala_gvalue_module_get_type_once (void);

static gpointer
_bala_ccode_node_ref0 (gpointer self)
{
	return self ? bala_ccode_node_ref (self) : NULL;
}

static gpointer
_bala_code_node_ref0 (gpointer self)
{
	return self ? bala_code_node_ref (self) : NULL;
}

static void
bala_gvalue_module_real_visit_cast_expression (BalaCodeVisitor* base,
                                               BalaCastExpression* expr)
{
	BalaGValueModule * self;
	BalaDataType* value_type = NULL;
	BalaExpression* _tmp0_;
	BalaExpression* _tmp1_;
	BalaDataType* _tmp2_;
	BalaDataType* _tmp3_;
	BalaDataType* target_type = NULL;
	BalaDataType* _tmp4_;
	BalaDataType* _tmp5_;
	gboolean _tmp6_ = FALSE;
	gboolean _tmp7_ = FALSE;
	gboolean _tmp8_ = FALSE;
	gboolean _tmp9_ = FALSE;
	gboolean _tmp10_ = FALSE;
	gboolean _tmp11_;
	gboolean _tmp12_;
	BalaDataType* _tmp26_;
	BalaDataType* _tmp27_;
	BalaCCodeFile* _tmp28_;
	BalaCCodeFunctionCall* ccall = NULL;
	BalaDataType* _tmp29_;
	BalaCCodeExpression* _tmp30_;
	BalaCCodeExpression* _tmp31_;
	BalaCCodeFunctionCall* _tmp32_;
	BalaCCodeFunctionCall* _tmp33_;
	BalaCCodeExpression* gvalue = NULL;
	BalaDataType* _tmp34_;
	gboolean _tmp35_;
	gboolean _tmp36_;
	BalaCCodeFunctionCall* _tmp45_;
	BalaCCodeExpression* _tmp46_;
	BalaDataType* _tmp47_;
	BalaCCodeExpression* rv = NULL;
	BalaCCodeFunctionCall* _tmp66_;
	BalaCCodeExpression* _tmp67_;
	gboolean _tmp68_ = FALSE;
	BalaCCodeExpression* _tmp128_;
	self = (BalaGValueModule*) base;
	g_return_if_fail (expr != NULL);
	_tmp0_ = bala_cast_expression_get_inner (expr);
	_tmp1_ = _tmp0_;
	_tmp2_ = bala_expression_get_value_type (_tmp1_);
	_tmp3_ = _tmp2_;
	value_type = _tmp3_;
	_tmp4_ = bala_cast_expression_get_type_reference (expr);
	_tmp5_ = _tmp4_;
	target_type = _tmp5_;
	_tmp11_ = bala_cast_expression_get_is_non_null_cast (expr);
	_tmp12_ = _tmp11_;
	if (_tmp12_) {
		_tmp10_ = TRUE;
	} else {
		BalaDataType* _tmp13_;
		_tmp13_ = value_type;
		_tmp10_ = _tmp13_ == NULL;
	}
	if (_tmp10_) {
		_tmp9_ = TRUE;
	} else {
		BalaStruct* _tmp14_;
		_tmp14_ = ((BalaCCodeBaseModule*) self)->gvalue_type;
		_tmp9_ = _tmp14_ == NULL;
	}
	if (_tmp9_) {
		_tmp8_ = TRUE;
	} else {
		BalaDataType* _tmp15_;
		BalaTypeSymbol* _tmp16_;
		BalaTypeSymbol* _tmp17_;
		BalaStruct* _tmp18_;
		_tmp15_ = value_type;
		_tmp16_ = bala_data_type_get_type_symbol (_tmp15_);
		_tmp17_ = _tmp16_;
		_tmp18_ = ((BalaCCodeBaseModule*) self)->gvalue_type;
		_tmp8_ = _tmp17_ != G_TYPE_CHECK_INSTANCE_CAST (_tmp18_, BALA_TYPE_TYPESYMBOL, BalaTypeSymbol);
	}
	if (_tmp8_) {
		_tmp7_ = TRUE;
	} else {
		BalaDataType* _tmp19_;
		BalaTypeSymbol* _tmp20_;
		BalaTypeSymbol* _tmp21_;
		BalaStruct* _tmp22_;
		_tmp19_ = target_type;
		_tmp20_ = bala_data_type_get_type_symbol (_tmp19_);
		_tmp21_ = _tmp20_;
		_tmp22_ = ((BalaCCodeBaseModule*) self)->gvalue_type;
		_tmp7_ = _tmp21_ == G_TYPE_CHECK_INSTANCE_CAST (_tmp22_, BALA_TYPE_TYPESYMBOL, BalaTypeSymbol);
	}
	if (_tmp7_) {
		_tmp6_ = TRUE;
	} else {
		BalaDataType* _tmp23_;
		gchar* _tmp24_;
		gchar* _tmp25_;
		_tmp23_ = target_type;
		_tmp24_ = bala_get_ccode_type_id ((BalaCodeNode*) _tmp23_);
		_tmp25_ = _tmp24_;
		_tmp6_ = g_strcmp0 (_tmp25_, "") == 0;
		_g_free0 (_tmp25_);
	}
	if (_tmp6_) {
		BALA_CODE_VISITOR_CLASS (bala_gvalue_module_parent_class)->visit_cast_expression ((BalaCodeVisitor*) G_TYPE_CHECK_INSTANCE_CAST (self, BALA_TYPE_GASYNC_MODULE, BalaGAsyncModule), expr);
		return;
	}
	_tmp26_ = bala_cast_expression_get_type_reference (expr);
	_tmp27_ = _tmp26_;
	_tmp28_ = ((BalaCCodeBaseModule*) self)->cfile;
	bala_ccode_base_module_generate_type_declaration ((BalaCCodeBaseModule*) self, _tmp27_, _tmp28_);
	_tmp29_ = target_type;
	_tmp30_ = bala_ccode_base_module_get_value_getter_function ((BalaCCodeBaseModule*) self, _tmp29_);
	_tmp31_ = _tmp30_;
	_tmp32_ = bala_ccode_function_call_new (_tmp31_);
	_tmp33_ = _tmp32_;
	_bala_ccode_node_unref0 (_tmp31_);
	ccall = _tmp33_;
	_tmp34_ = value_type;
	_tmp35_ = bala_data_type_get_nullable (_tmp34_);
	_tmp36_ = _tmp35_;
	if (_tmp36_) {
		BalaExpression* _tmp37_;
		BalaExpression* _tmp38_;
		BalaCCodeExpression* _tmp39_;
		BalaCCodeExpression* _tmp40_;
		_tmp37_ = bala_cast_expression_get_inner (expr);
		_tmp38_ = _tmp37_;
		_tmp39_ = bala_get_cvalue (_tmp38_);
		_tmp40_ = _bala_ccode_node_ref0 (_tmp39_);
		_bala_ccode_node_unref0 (gvalue);
		gvalue = _tmp40_;
	} else {
		BalaExpression* _tmp41_;
		BalaExpression* _tmp42_;
		BalaCCodeExpression* _tmp43_;
		BalaCCodeUnaryExpression* _tmp44_;
		_tmp41_ = bala_cast_expression_get_inner (expr);
		_tmp42_ = _tmp41_;
		_tmp43_ = bala_get_cvalue (_tmp42_);
		_tmp44_ = bala_ccode_unary_expression_new (BALA_CCODE_UNARY_OPERATOR_ADDRESS_OF, _tmp43_);
		_bala_ccode_node_unref0 (gvalue);
		gvalue = (BalaCCodeExpression*) _tmp44_;
	}
	_tmp45_ = ccall;
	_tmp46_ = gvalue;
	bala_ccode_function_call_add_argument (_tmp45_, _tmp46_);
	_tmp47_ = value_type;
	if (bala_data_type_is_disposable (_tmp47_)) {
		BalaLocalVariable* temp_var = NULL;
		BalaDataType* _tmp48_;
		BalaLocalVariable* _tmp49_;
		BalaLocalVariable* _tmp50_;
		BalaCCodeExpression* temp_ref = NULL;
		BalaLocalVariable* _tmp51_;
		const gchar* _tmp52_;
		const gchar* _tmp53_;
		BalaCCodeExpression* _tmp54_;
		BalaCCodeFunction* _tmp55_;
		BalaCCodeFunction* _tmp56_;
		BalaCCodeExpression* _tmp57_;
		BalaExpression* _tmp58_;
		BalaExpression* _tmp59_;
		BalaCCodeExpression* _tmp60_;
		BalaArrayList* _tmp61_;
		BalaArrayList* _tmp62_;
		BalaLocalVariable* _tmp63_;
		BalaTargetValue* _tmp64_;
		BalaTargetValue* _tmp65_;
		_tmp48_ = value_type;
		_tmp49_ = bala_ccode_base_module_get_temp_variable ((BalaCCodeBaseModule*) self, _tmp48_, TRUE, (BalaCodeNode*) expr, FALSE);
		temp_var = _tmp49_;
		_tmp50_ = temp_var;
		bala_ccode_base_module_emit_temp_var ((BalaCCodeBaseModule*) self, _tmp50_, FALSE);
		_tmp51_ = temp_var;
		_tmp52_ = bala_symbol_get_name ((BalaSymbol*) _tmp51_);
		_tmp53_ = _tmp52_;
		_tmp54_ = bala_ccode_base_module_get_variable_cexpression ((BalaCCodeBaseModule*) self, _tmp53_);
		temp_ref = _tmp54_;
		_tmp55_ = bala_ccode_base_module_get_ccode ((BalaCCodeBaseModule*) self);
		_tmp56_ = _tmp55_;
		_tmp57_ = temp_ref;
		_tmp58_ = bala_cast_expression_get_inner (expr);
		_tmp59_ = _tmp58_;
		_tmp60_ = bala_get_cvalue (_tmp59_);
		bala_ccode_function_add_assignment (_tmp56_, _tmp57_, _tmp60_);
		_tmp61_ = bala_ccode_base_module_get_temp_ref_values ((BalaCCodeBaseModule*) self);
		_tmp62_ = _tmp61_;
		_tmp63_ = temp_var;
		_tmp64_ = bala_ccode_base_module_get_local_cvalue ((BalaCCodeBaseModule*) self, _tmp63_);
		_tmp65_ = _tmp64_;
		bala_list_insert ((BalaList*) _tmp62_, 0, _tmp65_);
		_bala_target_value_unref0 (_tmp65_);
		_bala_ccode_node_unref0 (temp_ref);
		_bala_code_node_unref0 (temp_var);
	}
	_tmp66_ = ccall;
	_tmp67_ = _bala_ccode_node_ref0 ((BalaCCodeExpression*) _tmp66_);
	rv = _tmp67_;
	if (expr != NULL) {
		BalaDataType* _tmp69_;
		_tmp69_ = target_type;
		_tmp68_ = G_TYPE_CHECK_INSTANCE_TYPE (_tmp69_, BALA_TYPE_ARRAY_TYPE);
	} else {
		_tmp68_ = FALSE;
	}
	if (_tmp68_) {
		BalaCCodeFunctionCall* len_call = NULL;
		BalaCCodeIdentifier* _tmp70_;
		BalaCCodeIdentifier* _tmp71_;
		BalaCCodeFunctionCall* _tmp72_;
		BalaCCodeFunctionCall* _tmp73_;
		BalaCCodeFunctionCall* _tmp74_;
		BalaCCodeExpression* _tmp75_;
		BalaCCodeFunctionCall* _tmp76_;
		_tmp70_ = bala_ccode_identifier_new ("g_strv_length");
		_tmp71_ = _tmp70_;
		_tmp72_ = bala_ccode_function_call_new ((BalaCCodeExpression*) _tmp71_);
		_tmp73_ = _tmp72_;
		_bala_ccode_node_unref0 (_tmp71_);
		len_call = _tmp73_;
		_tmp74_ = len_call;
		_tmp75_ = rv;
		bala_ccode_function_call_add_argument (_tmp74_, _tmp75_);
		_tmp76_ = len_call;
		bala_append_array_length ((BalaExpression*) expr, (BalaCCodeExpression*) _tmp76_);
		_bala_ccode_node_unref0 (len_call);
	} else {
		BalaDataType* _tmp77_;
		_tmp77_ = target_type;
		if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp77_, BALA_TYPE_STRUCT_VALUE_TYPE)) {
			BalaCodeNode* _tmp78_ = NULL;
			BalaCodeNode* node = NULL;
			BalaCodeNode* _tmp80_;
			BalaTargetValue* temp_value = NULL;
			BalaDataType* _tmp81_;
			BalaCodeNode* _tmp82_;
			gboolean _tmp83_;
			BalaTargetValue* _tmp84_;
			BalaCCodeExpression* ctemp = NULL;
			BalaTargetValue* _tmp85_;
			BalaCCodeExpression* _tmp86_;
			BalaCCodeExpression* _tmp87_;
			BalaCCodeExpression* _tmp88_;
			BalaDataType* _tmp89_;
			BalaPointerType* _tmp90_;
			BalaPointerType* _tmp91_;
			gchar* _tmp92_;
			gchar* _tmp93_;
			BalaCCodeCastExpression* _tmp94_;
			BalaCCodeCastExpression* _tmp95_;
			BalaCCodeUnaryExpression* _tmp96_;
			BalaCCodeFunctionCall* holds = NULL;
			BalaCCodeIdentifier* _tmp97_;
			BalaCCodeIdentifier* _tmp98_;
			BalaCCodeFunctionCall* _tmp99_;
			BalaCCodeFunctionCall* _tmp100_;
			BalaCCodeFunctionCall* _tmp101_;
			BalaCCodeExpression* _tmp102_;
			BalaCCodeFunctionCall* _tmp103_;
			BalaDataType* _tmp104_;
			gchar* _tmp105_;
			gchar* _tmp106_;
			BalaCCodeIdentifier* _tmp107_;
			BalaCCodeIdentifier* _tmp108_;
			BalaCCodeBinaryExpression* cond = NULL;
			BalaCCodeFunctionCall* _tmp109_;
			BalaCCodeFunctionCall* _tmp110_;
			BalaCCodeBinaryExpression* _tmp111_;
			BalaCCodeFunctionCall* warn = NULL;
			BalaCCodeIdentifier* _tmp112_;
			BalaCCodeIdentifier* _tmp113_;
			BalaCCodeFunctionCall* _tmp114_;
			BalaCCodeFunctionCall* _tmp115_;
			BalaCCodeFunctionCall* _tmp116_;
			BalaCCodeConstant* _tmp117_;
			BalaCCodeConstant* _tmp118_;
			BalaCCodeCommaExpression* fail = NULL;
			BalaCCodeCommaExpression* _tmp119_;
			BalaCCodeCommaExpression* _tmp120_;
			BalaCCodeFunctionCall* _tmp121_;
			BalaCCodeCommaExpression* _tmp122_;
			BalaCCodeExpression* _tmp123_;
			BalaCCodeBinaryExpression* _tmp124_;
			BalaCCodeExpression* _tmp125_;
			BalaCCodeCommaExpression* _tmp126_;
			BalaCCodeConditionalExpression* _tmp127_;
			if (expr != NULL) {
				_tmp78_ = G_TYPE_CHECK_INSTANCE_CAST (expr, BALA_TYPE_CODE_NODE, BalaCodeNode);
			} else {
				BalaDataType* _tmp79_;
				_tmp79_ = target_type;
				_tmp78_ = (BalaCodeNode*) _tmp79_;
			}
			_tmp80_ = _bala_code_node_ref0 (_tmp78_);
			node = _tmp80_;
			_tmp81_ = target_type;
			_tmp82_ = node;
			_tmp83_ = TRUE;
			_tmp84_ = bala_ccode_base_module_create_temp_value ((BalaCCodeBaseModule*) self, _tmp81_, TRUE, _tmp82_, &_tmp83_);
			temp_value = _tmp84_;
			_tmp85_ = temp_value;
			_tmp86_ = bala_get_cvalue_ (_tmp85_);
			_tmp87_ = _bala_ccode_node_ref0 (_tmp86_);
			ctemp = _tmp87_;
			_tmp88_ = rv;
			_tmp89_ = target_type;
			_tmp90_ = bala_pointer_type_new (_tmp89_, NULL);
			_tmp91_ = _tmp90_;
			_tmp92_ = bala_get_ccode_name ((BalaCodeNode*) _tmp91_);
			_tmp93_ = _tmp92_;
			_tmp94_ = bala_ccode_cast_expression_new (_tmp88_, _tmp93_);
			_tmp95_ = _tmp94_;
			_tmp96_ = bala_ccode_unary_expression_new (BALA_CCODE_UNARY_OPERATOR_POINTER_INDIRECTION, (BalaCCodeExpression*) _tmp95_);
			_bala_ccode_node_unref0 (rv);
			rv = (BalaCCodeExpression*) _tmp96_;
			_bala_ccode_node_unref0 (_tmp95_);
			_g_free0 (_tmp93_);
			_bala_code_node_unref0 (_tmp91_);
			_tmp97_ = bala_ccode_identifier_new ("G_VALUE_HOLDS");
			_tmp98_ = _tmp97_;
			_tmp99_ = bala_ccode_function_call_new ((BalaCCodeExpression*) _tmp98_);
			_tmp100_ = _tmp99_;
			_bala_ccode_node_unref0 (_tmp98_);
			holds = _tmp100_;
			_tmp101_ = holds;
			_tmp102_ = gvalue;
			bala_ccode_function_call_add_argument (_tmp101_, _tmp102_);
			_tmp103_ = holds;
			_tmp104_ = target_type;
			_tmp105_ = bala_get_ccode_type_id ((BalaCodeNode*) _tmp104_);
			_tmp106_ = _tmp105_;
			_tmp107_ = bala_ccode_identifier_new (_tmp106_);
			_tmp108_ = _tmp107_;
			bala_ccode_function_call_add_argument (_tmp103_, (BalaCCodeExpression*) _tmp108_);
			_bala_ccode_node_unref0 (_tmp108_);
			_g_free0 (_tmp106_);
			_tmp109_ = holds;
			_tmp110_ = ccall;
			_tmp111_ = bala_ccode_binary_expression_new (BALA_CCODE_BINARY_OPERATOR_AND, (BalaCCodeExpression*) _tmp109_, (BalaCCodeExpression*) _tmp110_);
			cond = _tmp111_;
			_tmp112_ = bala_ccode_identifier_new ("g_warning");
			_tmp113_ = _tmp112_;
			_tmp114_ = bala_ccode_function_call_new ((BalaCCodeExpression*) _tmp113_);
			_tmp115_ = _tmp114_;
			_bala_ccode_node_unref0 (_tmp113_);
			warn = _tmp115_;
			_tmp116_ = warn;
			_tmp117_ = bala_ccode_constant_new ("\"Invalid GValue unboxing (wrong type or NULL)\"");
			_tmp118_ = _tmp117_;
			bala_ccode_function_call_add_argument (_tmp116_, (BalaCCodeExpression*) _tmp118_);
			_bala_ccode_node_unref0 (_tmp118_);
			_tmp119_ = bala_ccode_comma_expression_new ();
			fail = _tmp119_;
			_tmp120_ = fail;
			_tmp121_ = warn;
			bala_ccode_comma_expression_append_expression (_tmp120_, (BalaCCodeExpression*) _tmp121_);
			_tmp122_ = fail;
			_tmp123_ = ctemp;
			bala_ccode_comma_expression_append_expression (_tmp122_, _tmp123_);
			_tmp124_ = cond;
			_tmp125_ = rv;
			_tmp126_ = fail;
			_tmp127_ = bala_ccode_conditional_expression_new ((BalaCCodeExpression*) _tmp124_, _tmp125_, (BalaCCodeExpression*) _tmp126_);
			_bala_ccode_node_unref0 (rv);
			rv = (BalaCCodeExpression*) _tmp127_;
			_bala_ccode_node_unref0 (fail);
			_bala_ccode_node_unref0 (warn);
			_bala_ccode_node_unref0 (cond);
			_bala_ccode_node_unref0 (holds);
			_bala_ccode_node_unref0 (ctemp);
			_bala_target_value_unref0 (temp_value);
			_bala_code_node_unref0 (node);
		}
	}
	_tmp128_ = rv;
	bala_set_cvalue ((BalaExpression*) expr, _tmp128_);
	_bala_ccode_node_unref0 (rv);
	_bala_ccode_node_unref0 (gvalue);
	_bala_ccode_node_unref0 (ccall);
}

static BalaCCodeExpression*
bala_gvalue_module_real_get_value_getter_function (BalaCCodeBaseModule* base,
                                                   BalaDataType* type_reference)
{
	BalaGValueModule * self;
	BalaArrayType* array_type = NULL;
	BalaArrayType* _tmp0_;
	BalaTypeSymbol* _tmp1_;
	BalaTypeSymbol* _tmp2_;
	BalaCCodeExpression* result = NULL;
	self = (BalaGValueModule*) base;
	g_return_val_if_fail (type_reference != NULL, NULL);
	_tmp0_ = _bala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (type_reference, BALA_TYPE_ARRAY_TYPE) ? ((BalaArrayType*) type_reference) : NULL);
	array_type = _tmp0_;
	_tmp1_ = bala_data_type_get_type_symbol (type_reference);
	_tmp2_ = _tmp1_;
	if (_tmp2_ != NULL) {
		BalaTypeSymbol* _tmp3_;
		BalaTypeSymbol* _tmp4_;
		gchar* _tmp5_;
		gchar* _tmp6_;
		BalaCCodeIdentifier* _tmp7_;
		BalaCCodeExpression* _tmp8_;
		_tmp3_ = bala_data_type_get_type_symbol (type_reference);
		_tmp4_ = _tmp3_;
		_tmp5_ = bala_get_ccode_get_value_function ((BalaCodeNode*) _tmp4_);
		_tmp6_ = _tmp5_;
		_tmp7_ = bala_ccode_identifier_new (_tmp6_);
		_tmp8_ = (BalaCCodeExpression*) _tmp7_;
		_g_free0 (_tmp6_);
		result = _tmp8_;
		_bala_code_node_unref0 (array_type);
		return result;
	} else {
		gboolean _tmp9_ = FALSE;
		BalaArrayType* _tmp10_;
		_tmp10_ = array_type;
		if (_tmp10_ != NULL) {
			BalaArrayType* _tmp11_;
			BalaDataType* _tmp12_;
			BalaDataType* _tmp13_;
			BalaTypeSymbol* _tmp14_;
			BalaTypeSymbol* _tmp15_;
			BalaDataType* _tmp16_;
			BalaTypeSymbol* _tmp17_;
			BalaTypeSymbol* _tmp18_;
			_tmp11_ = array_type;
			_tmp12_ = bala_array_type_get_element_type (_tmp11_);
			_tmp13_ = _tmp12_;
			_tmp14_ = bala_data_type_get_type_symbol (_tmp13_);
			_tmp15_ = _tmp14_;
			_tmp16_ = ((BalaCCodeBaseModule*) self)->string_type;
			_tmp17_ = bala_data_type_get_type_symbol (_tmp16_);
			_tmp18_ = _tmp17_;
			_tmp9_ = _tmp15_ == _tmp18_;
		} else {
			_tmp9_ = FALSE;
		}
		if (_tmp9_) {
			BalaCCodeIdentifier* _tmp19_;
			_tmp19_ = bala_ccode_identifier_new ("g_value_get_boxed");
			result = (BalaCCodeExpression*) _tmp19_;
			_bala_code_node_unref0 (array_type);
			return result;
		} else {
			BalaCCodeIdentifier* _tmp20_;
			_tmp20_ = bala_ccode_identifier_new ("g_value_get_pointer");
			result = (BalaCCodeExpression*) _tmp20_;
			_bala_code_node_unref0 (array_type);
			return result;
		}
	}
	_bala_code_node_unref0 (array_type);
}

static BalaCCodeExpression*
bala_gvalue_module_real_get_value_setter_function (BalaCCodeBaseModule* base,
                                                   BalaDataType* type_reference)
{
	BalaGValueModule * self;
	BalaArrayType* array_type = NULL;
	BalaArrayType* _tmp0_;
	BalaTypeSymbol* _tmp1_;
	BalaTypeSymbol* _tmp2_;
	BalaCCodeExpression* result = NULL;
	self = (BalaGValueModule*) base;
	g_return_val_if_fail (type_reference != NULL, NULL);
	_tmp0_ = _bala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (type_reference, BALA_TYPE_ARRAY_TYPE) ? ((BalaArrayType*) type_reference) : NULL);
	array_type = _tmp0_;
	_tmp1_ = bala_data_type_get_type_symbol (type_reference);
	_tmp2_ = _tmp1_;
	if (_tmp2_ != NULL) {
		BalaTypeSymbol* _tmp3_;
		BalaTypeSymbol* _tmp4_;
		gchar* _tmp5_;
		gchar* _tmp6_;
		BalaCCodeIdentifier* _tmp7_;
		BalaCCodeExpression* _tmp8_;
		_tmp3_ = bala_data_type_get_type_symbol (type_reference);
		_tmp4_ = _tmp3_;
		_tmp5_ = bala_get_ccode_set_value_function ((BalaCodeNode*) _tmp4_);
		_tmp6_ = _tmp5_;
		_tmp7_ = bala_ccode_identifier_new (_tmp6_);
		_tmp8_ = (BalaCCodeExpression*) _tmp7_;
		_g_free0 (_tmp6_);
		result = _tmp8_;
		_bala_code_node_unref0 (array_type);
		return result;
	} else {
		gboolean _tmp9_ = FALSE;
		BalaArrayType* _tmp10_;
		_tmp10_ = array_type;
		if (_tmp10_ != NULL) {
			BalaArrayType* _tmp11_;
			BalaDataType* _tmp12_;
			BalaDataType* _tmp13_;
			BalaTypeSymbol* _tmp14_;
			BalaTypeSymbol* _tmp15_;
			BalaDataType* _tmp16_;
			BalaTypeSymbol* _tmp17_;
			BalaTypeSymbol* _tmp18_;
			_tmp11_ = array_type;
			_tmp12_ = bala_array_type_get_element_type (_tmp11_);
			_tmp13_ = _tmp12_;
			_tmp14_ = bala_data_type_get_type_symbol (_tmp13_);
			_tmp15_ = _tmp14_;
			_tmp16_ = ((BalaCCodeBaseModule*) self)->string_type;
			_tmp17_ = bala_data_type_get_type_symbol (_tmp16_);
			_tmp18_ = _tmp17_;
			_tmp9_ = _tmp15_ == _tmp18_;
		} else {
			_tmp9_ = FALSE;
		}
		if (_tmp9_) {
			BalaCCodeIdentifier* _tmp19_;
			_tmp19_ = bala_ccode_identifier_new ("g_value_set_boxed");
			result = (BalaCCodeExpression*) _tmp19_;
			_bala_code_node_unref0 (array_type);
			return result;
		} else {
			BalaCCodeIdentifier* _tmp20_;
			_tmp20_ = bala_ccode_identifier_new ("g_value_set_pointer");
			result = (BalaCCodeExpression*) _tmp20_;
			_bala_code_node_unref0 (array_type);
			return result;
		}
	}
	_bala_code_node_unref0 (array_type);
}

static BalaCCodeExpression*
bala_gvalue_module_real_get_value_taker_function (BalaCCodeBaseModule* base,
                                                  BalaDataType* type_reference)
{
	BalaGValueModule * self;
	BalaArrayType* array_type = NULL;
	BalaArrayType* _tmp0_;
	BalaTypeSymbol* _tmp1_;
	BalaTypeSymbol* _tmp2_;
	BalaCCodeExpression* result = NULL;
	self = (BalaGValueModule*) base;
	g_return_val_if_fail (type_reference != NULL, NULL);
	_tmp0_ = _bala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (type_reference, BALA_TYPE_ARRAY_TYPE) ? ((BalaArrayType*) type_reference) : NULL);
	array_type = _tmp0_;
	_tmp1_ = bala_data_type_get_type_symbol (type_reference);
	_tmp2_ = _tmp1_;
	if (_tmp2_ != NULL) {
		BalaTypeSymbol* _tmp3_;
		BalaTypeSymbol* _tmp4_;
		gchar* _tmp5_;
		gchar* _tmp6_;
		BalaCCodeIdentifier* _tmp7_;
		BalaCCodeExpression* _tmp8_;
		_tmp3_ = bala_data_type_get_type_symbol (type_reference);
		_tmp4_ = _tmp3_;
		_tmp5_ = bala_get_ccode_take_value_function ((BalaCodeNode*) _tmp4_);
		_tmp6_ = _tmp5_;
		_tmp7_ = bala_ccode_identifier_new (_tmp6_);
		_tmp8_ = (BalaCCodeExpression*) _tmp7_;
		_g_free0 (_tmp6_);
		result = _tmp8_;
		_bala_code_node_unref0 (array_type);
		return result;
	} else {
		gboolean _tmp9_ = FALSE;
		BalaArrayType* _tmp10_;
		_tmp10_ = array_type;
		if (_tmp10_ != NULL) {
			BalaArrayType* _tmp11_;
			BalaDataType* _tmp12_;
			BalaDataType* _tmp13_;
			BalaTypeSymbol* _tmp14_;
			BalaTypeSymbol* _tmp15_;
			BalaDataType* _tmp16_;
			BalaTypeSymbol* _tmp17_;
			BalaTypeSymbol* _tmp18_;
			_tmp11_ = array_type;
			_tmp12_ = bala_array_type_get_element_type (_tmp11_);
			_tmp13_ = _tmp12_;
			_tmp14_ = bala_data_type_get_type_symbol (_tmp13_);
			_tmp15_ = _tmp14_;
			_tmp16_ = ((BalaCCodeBaseModule*) self)->string_type;
			_tmp17_ = bala_data_type_get_type_symbol (_tmp16_);
			_tmp18_ = _tmp17_;
			_tmp9_ = _tmp15_ == _tmp18_;
		} else {
			_tmp9_ = FALSE;
		}
		if (_tmp9_) {
			BalaCCodeIdentifier* _tmp19_;
			_tmp19_ = bala_ccode_identifier_new ("g_value_take_boxed");
			result = (BalaCCodeExpression*) _tmp19_;
			_bala_code_node_unref0 (array_type);
			return result;
		} else {
			BalaCCodeIdentifier* _tmp20_;
			_tmp20_ = bala_ccode_identifier_new ("g_value_set_pointer");
			result = (BalaCCodeExpression*) _tmp20_;
			_bala_code_node_unref0 (array_type);
			return result;
		}
	}
	_bala_code_node_unref0 (array_type);
}

BalaGValueModule*
bala_gvalue_module_construct (GType object_type)
{
	BalaGValueModule* self = NULL;
	self = (BalaGValueModule*) bala_gasync_module_construct (object_type);
	return self;
}

BalaGValueModule*
bala_gvalue_module_new (void)
{
	return bala_gvalue_module_construct (BALA_TYPE_GVALUE_MODULE);
}

static void
bala_gvalue_module_class_init (BalaGValueModuleClass * klass,
                               gpointer klass_data)
{
	bala_gvalue_module_parent_class = g_type_class_peek_parent (klass);
	((BalaCodeVisitorClass *) klass)->visit_cast_expression = (void (*) (BalaCodeVisitor*, BalaCastExpression*)) bala_gvalue_module_real_visit_cast_expression;
	((BalaCCodeBaseModuleClass *) klass)->get_value_getter_function = (BalaCCodeExpression* (*) (BalaCCodeBaseModule*, BalaDataType*)) bala_gvalue_module_real_get_value_getter_function;
	((BalaCCodeBaseModuleClass *) klass)->get_value_setter_function = (BalaCCodeExpression* (*) (BalaCCodeBaseModule*, BalaDataType*)) bala_gvalue_module_real_get_value_setter_function;
	((BalaCCodeBaseModuleClass *) klass)->get_value_taker_function = (BalaCCodeExpression* (*) (BalaCCodeBaseModule*, BalaDataType*)) bala_gvalue_module_real_get_value_taker_function;
}

static void
bala_gvalue_module_instance_init (BalaGValueModule * self,
                                  gpointer klass)
{
}

static GType
bala_gvalue_module_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaGValueModuleClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_gvalue_module_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaGValueModule), 0, (GInstanceInitFunc) bala_gvalue_module_instance_init, NULL };
	GType bala_gvalue_module_type_id;
	bala_gvalue_module_type_id = g_type_register_static (BALA_TYPE_GASYNC_MODULE, "BalaGValueModule", &g_define_type_info, 0);
	return bala_gvalue_module_type_id;
}

GType
bala_gvalue_module_get_type (void)
{
	static volatile gsize bala_gvalue_module_type_id__volatile = 0;
	if (g_once_init_enter (&bala_gvalue_module_type_id__volatile)) {
		GType bala_gvalue_module_type_id;
		bala_gvalue_module_type_id = bala_gvalue_module_get_type_once ();
		g_once_init_leave (&bala_gvalue_module_type_id__volatile, bala_gvalue_module_type_id);
	}
	return bala_gvalue_module_type_id__volatile;
}

