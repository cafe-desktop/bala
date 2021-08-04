/* valalocalvariable.c generated by valac, the Vala compiler
 * generated from valalocalvariable.vala, do not modify */

/* valalocalvariable.vala
 *
 * Copyright (C) 2006-2010  Jürg Billeter
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
#include <stdlib.h>
#include <string.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _ValaLocalVariablePrivate {
	gboolean _is_result;
	gboolean _captured;
	gboolean _init;
};

static gint ValaLocalVariable_private_offset;
static gpointer vala_local_variable_parent_class = NULL;

static void vala_local_variable_real_accept (ValaCodeNode* base,
                                      ValaCodeVisitor* visitor);
static void vala_local_variable_real_accept_children (ValaCodeNode* base,
                                               ValaCodeVisitor* visitor);
static void vala_local_variable_real_replace_expression (ValaCodeNode* base,
                                                  ValaExpression* old_node,
                                                  ValaExpression* new_node);
static void vala_local_variable_real_replace_type (ValaCodeNode* base,
                                            ValaDataType* old_type,
                                            ValaDataType* new_type);
static gboolean vala_local_variable_real_check (ValaCodeNode* base,
                                         ValaCodeContext* context);
static void vala_local_variable_finalize (ValaCodeNode * obj);
static GType vala_local_variable_get_type_once (void);

static inline gpointer
vala_local_variable_get_instance_private (ValaLocalVariable* self)
{
	return G_STRUCT_MEMBER_P (self, ValaLocalVariable_private_offset);
}

gboolean
vala_local_variable_get_is_result (ValaLocalVariable* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_is_result;
	return result;
}

void
vala_local_variable_set_is_result (ValaLocalVariable* self,
                                   gboolean value)
{
	g_return_if_fail (self != NULL);
	self->priv->_is_result = value;
}

gboolean
vala_local_variable_get_captured (ValaLocalVariable* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_captured;
	return result;
}

void
vala_local_variable_set_captured (ValaLocalVariable* self,
                                  gboolean value)
{
	g_return_if_fail (self != NULL);
	self->priv->_captured = value;
}

gboolean
vala_local_variable_get_init (ValaLocalVariable* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_init;
	return result;
}

void
vala_local_variable_set_init (ValaLocalVariable* self,
                              gboolean value)
{
	g_return_if_fail (self != NULL);
	self->priv->_init = value;
}

/**
 * Creates a new local variable.
 *
 * @param name              name of the variable
 * @param initializer       optional initializer expression
 * @param source_reference  reference to source code
 * @return                  newly created variable declarator
 */
ValaLocalVariable*
vala_local_variable_construct (GType object_type,
                               ValaDataType* variable_type,
                               const gchar* name,
                               ValaExpression* initializer,
                               ValaSourceReference* source_reference)
{
	ValaLocalVariable* self = NULL;
	g_return_val_if_fail (name != NULL, NULL);
	self = (ValaLocalVariable*) vala_variable_construct (object_type, variable_type, name, initializer, source_reference, NULL);
	return self;
}

ValaLocalVariable*
vala_local_variable_new (ValaDataType* variable_type,
                         const gchar* name,
                         ValaExpression* initializer,
                         ValaSourceReference* source_reference)
{
	return vala_local_variable_construct (BALA_TYPE_LOCAL_VARIABLE, variable_type, name, initializer, source_reference);
}

static void
vala_local_variable_real_accept (ValaCodeNode* base,
                                 ValaCodeVisitor* visitor)
{
	ValaLocalVariable * self;
	self = (ValaLocalVariable*) base;
	g_return_if_fail (visitor != NULL);
	vala_code_visitor_visit_local_variable (visitor, self);
}

static void
vala_local_variable_real_accept_children (ValaCodeNode* base,
                                          ValaCodeVisitor* visitor)
{
	ValaLocalVariable * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	ValaDataType* _tmp6_;
	ValaDataType* _tmp7_;
	self = (ValaLocalVariable*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = vala_variable_get_initializer ((ValaVariable*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ != NULL) {
		ValaExpression* _tmp2_;
		ValaExpression* _tmp3_;
		ValaExpression* _tmp4_;
		ValaExpression* _tmp5_;
		_tmp2_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp3_ = _tmp2_;
		vala_code_node_accept ((ValaCodeNode*) _tmp3_, visitor);
		_tmp4_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp5_ = _tmp4_;
		vala_code_visitor_visit_end_full_expression (visitor, _tmp5_);
	}
	_tmp6_ = vala_variable_get_variable_type ((ValaVariable*) self);
	_tmp7_ = _tmp6_;
	if (_tmp7_ != NULL) {
		ValaDataType* _tmp8_;
		ValaDataType* _tmp9_;
		_tmp8_ = vala_variable_get_variable_type ((ValaVariable*) self);
		_tmp9_ = _tmp8_;
		vala_code_node_accept ((ValaCodeNode*) _tmp9_, visitor);
	}
}

static void
vala_local_variable_real_replace_expression (ValaCodeNode* base,
                                             ValaExpression* old_node,
                                             ValaExpression* new_node)
{
	ValaLocalVariable * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaLocalVariable*) base;
	g_return_if_fail (old_node != NULL);
	g_return_if_fail (new_node != NULL);
	_tmp0_ = vala_variable_get_initializer ((ValaVariable*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ == old_node) {
		vala_variable_set_initializer ((ValaVariable*) self, new_node);
	}
}

static void
vala_local_variable_real_replace_type (ValaCodeNode* base,
                                       ValaDataType* old_type,
                                       ValaDataType* new_type)
{
	ValaLocalVariable * self;
	ValaDataType* _tmp0_;
	ValaDataType* _tmp1_;
	self = (ValaLocalVariable*) base;
	g_return_if_fail (old_type != NULL);
	g_return_if_fail (new_type != NULL);
	_tmp0_ = vala_variable_get_variable_type ((ValaVariable*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ == old_type) {
		vala_variable_set_variable_type ((ValaVariable*) self, new_type);
	}
}

static gboolean
vala_local_variable_real_check (ValaCodeNode* base,
                                ValaCodeContext* context)
{
	ValaLocalVariable * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	ValaDataType* _tmp4_;
	ValaDataType* _tmp5_;
	gboolean _tmp8_;
	gboolean _tmp9_;
	ValaDataType* _tmp21_;
	ValaDataType* _tmp22_;
	gboolean is_initializer_list = FALSE;
	gint initializer_size = 0;
	gboolean _tmp35_ = FALSE;
	ValaExpression* _tmp36_;
	ValaExpression* _tmp37_;
	ValaSemanticAnalyzer* _tmp60_;
	ValaSemanticAnalyzer* _tmp61_;
	ValaSymbol* _tmp62_;
	ValaSymbol* _tmp63_;
	ValaScope* _tmp64_;
	ValaScope* _tmp65_;
	const gchar* _tmp66_;
	const gchar* _tmp67_;
	gboolean _tmp68_;
	gboolean _tmp69_;
	ValaDataType* _tmp70_;
	ValaDataType* _tmp71_;
	gboolean _tmp123_;
	gboolean _tmp124_;
	ValaArrayType* variable_array_type = NULL;
	ValaDataType* _tmp137_;
	ValaDataType* _tmp138_;
	gboolean _tmp139_ = FALSE;
	gboolean _tmp140_ = FALSE;
	gboolean _tmp141_ = FALSE;
	ValaArrayType* _tmp142_;
	gboolean _tmp154_ = FALSE;
	gboolean _tmp155_ = FALSE;
	gboolean _tmp156_ = FALSE;
	ValaArrayType* _tmp157_;
	gboolean _tmp168_ = FALSE;
	ValaExpression* _tmp169_;
	ValaExpression* _tmp170_;
	ValaBlock* block = NULL;
	ValaSemanticAnalyzer* _tmp276_;
	ValaSemanticAnalyzer* _tmp277_;
	ValaSymbol* _tmp278_;
	ValaSymbol* _tmp279_;
	ValaBlock* _tmp280_;
	gboolean _tmp282_;
	gboolean _tmp283_;
	gboolean result = FALSE;
	self = (ValaLocalVariable*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	_tmp0_ = vala_code_node_get_checked ((ValaCodeNode*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_) {
		gboolean _tmp2_;
		gboolean _tmp3_;
		_tmp2_ = vala_code_node_get_error ((ValaCodeNode*) self);
		_tmp3_ = _tmp2_;
		result = !_tmp3_;
		return result;
	}
	vala_code_node_set_checked ((ValaCodeNode*) self, TRUE);
	_tmp4_ = vala_variable_get_variable_type ((ValaVariable*) self);
	_tmp5_ = _tmp4_;
	if (_tmp5_ == NULL) {
		ValaVarType* _tmp6_;
		ValaVarType* _tmp7_;
		_tmp6_ = vala_var_type_new (TRUE);
		_tmp7_ = _tmp6_;
		vala_variable_set_variable_type ((ValaVariable*) self, (ValaDataType*) _tmp7_);
		_vala_code_node_unref0 (_tmp7_);
	}
	_tmp8_ = vala_code_context_get_experimental_non_null (context);
	_tmp9_ = _tmp8_;
	if (!_tmp9_) {
		ValaDataType* _tmp10_;
		ValaDataType* _tmp11_;
		_tmp10_ = vala_variable_get_variable_type ((ValaVariable*) self);
		_tmp11_ = _tmp10_;
		if (BALA_IS_REFERENCE_TYPE (_tmp11_)) {
			ValaArrayType* array_type = NULL;
			ValaDataType* _tmp12_;
			ValaDataType* _tmp13_;
			gboolean _tmp14_ = FALSE;
			ValaArrayType* _tmp15_;
			_tmp12_ = vala_variable_get_variable_type ((ValaVariable*) self);
			_tmp13_ = _tmp12_;
			array_type = BALA_IS_ARRAY_TYPE (_tmp13_) ? ((ValaArrayType*) _tmp13_) : NULL;
			_tmp15_ = array_type;
			if (_tmp15_ != NULL) {
				ValaArrayType* _tmp16_;
				gboolean _tmp17_;
				gboolean _tmp18_;
				_tmp16_ = array_type;
				_tmp17_ = vala_array_type_get_fixed_length (_tmp16_);
				_tmp18_ = _tmp17_;
				_tmp14_ = _tmp18_;
			} else {
				_tmp14_ = FALSE;
			}
			if (_tmp14_) {
			} else {
				ValaDataType* _tmp19_;
				ValaDataType* _tmp20_;
				_tmp19_ = vala_variable_get_variable_type ((ValaVariable*) self);
				_tmp20_ = _tmp19_;
				vala_data_type_set_nullable (_tmp20_, TRUE);
			}
		}
	}
	_tmp21_ = vala_variable_get_variable_type ((ValaVariable*) self);
	_tmp22_ = _tmp21_;
	if (!BALA_IS_VAR_TYPE (_tmp22_)) {
		ValaDataType* _tmp23_;
		ValaDataType* _tmp24_;
		gboolean _tmp29_;
		gboolean _tmp30_;
		_tmp23_ = vala_variable_get_variable_type ((ValaVariable*) self);
		_tmp24_ = _tmp23_;
		if (BALA_IS_VOID_TYPE (_tmp24_)) {
			ValaSourceReference* _tmp25_;
			ValaSourceReference* _tmp26_;
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			_tmp25_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp26_ = _tmp25_;
			vala_report_error (_tmp26_, "'void' not supported as variable type");
		} else {
			ValaDataType* _tmp27_;
			ValaDataType* _tmp28_;
			_tmp27_ = vala_variable_get_variable_type ((ValaVariable*) self);
			_tmp28_ = _tmp27_;
			if (!vala_code_node_check ((ValaCodeNode*) _tmp28_, context)) {
				vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			}
		}
		_tmp29_ = vala_symbol_get_external_package ((ValaSymbol*) self);
		_tmp30_ = _tmp29_;
		if (!_tmp30_) {
			ValaSemanticAnalyzer* _tmp31_;
			ValaSemanticAnalyzer* _tmp32_;
			ValaDataType* _tmp33_;
			ValaDataType* _tmp34_;
			_tmp31_ = vala_code_context_get_analyzer (context);
			_tmp32_ = _tmp31_;
			_tmp33_ = vala_variable_get_variable_type ((ValaVariable*) self);
			_tmp34_ = _tmp33_;
			vala_semantic_analyzer_check_type (_tmp32_, _tmp34_);
		}
	}
	is_initializer_list = FALSE;
	initializer_size = -1;
	_tmp36_ = vala_variable_get_initializer ((ValaVariable*) self);
	_tmp37_ = _tmp36_;
	if (_tmp37_ != NULL) {
		gboolean _tmp38_;
		gboolean _tmp39_;
		_tmp38_ = vala_code_node_get_error ((ValaCodeNode*) self);
		_tmp39_ = _tmp38_;
		_tmp35_ = !_tmp39_;
	} else {
		_tmp35_ = FALSE;
	}
	if (_tmp35_) {
		ValaExpression* _tmp40_;
		ValaExpression* _tmp41_;
		ValaDataType* _tmp42_;
		ValaDataType* _tmp43_;
		ValaExpression* _tmp44_;
		ValaExpression* _tmp45_;
		ValaExpression* _tmp50_;
		ValaExpression* _tmp51_;
		_tmp40_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp41_ = _tmp40_;
		_tmp42_ = vala_variable_get_variable_type ((ValaVariable*) self);
		_tmp43_ = _tmp42_;
		vala_expression_set_target_type (_tmp41_, _tmp43_);
		_tmp44_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp45_ = _tmp44_;
		if (BALA_IS_INITIALIZER_LIST (_tmp45_)) {
			ValaExpression* _tmp46_;
			ValaExpression* _tmp47_;
			gint _tmp48_;
			gint _tmp49_;
			_tmp46_ = vala_variable_get_initializer ((ValaVariable*) self);
			_tmp47_ = _tmp46_;
			_tmp48_ = vala_initializer_list_get_size (G_TYPE_CHECK_INSTANCE_CAST (_tmp47_, BALA_TYPE_INITIALIZER_LIST, ValaInitializerList));
			_tmp49_ = _tmp48_;
			initializer_size = _tmp49_;
			is_initializer_list = TRUE;
		}
		_tmp50_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp51_ = _tmp50_;
		if (!vala_code_node_check ((ValaCodeNode*) _tmp51_, context)) {
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		} else {
			ValaExpression* _tmp52_;
			ValaExpression* _tmp53_;
			ValaDataType* _tmp54_;
			ValaDataType* _tmp55_;
			_tmp52_ = vala_variable_get_initializer ((ValaVariable*) self);
			_tmp53_ = _tmp52_;
			_tmp54_ = vala_expression_get_value_type (_tmp53_);
			_tmp55_ = _tmp54_;
			if (BALA_IS_VOID_TYPE (_tmp55_)) {
				ValaExpression* _tmp56_;
				ValaExpression* _tmp57_;
				ValaSourceReference* _tmp58_;
				ValaSourceReference* _tmp59_;
				vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
				_tmp56_ = vala_variable_get_initializer ((ValaVariable*) self);
				_tmp57_ = _tmp56_;
				_tmp58_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp57_);
				_tmp59_ = _tmp58_;
				vala_report_error (_tmp59_, "'void' not supported as initializer type");
			}
		}
	}
	_tmp60_ = vala_code_context_get_analyzer (context);
	_tmp61_ = _tmp60_;
	_tmp62_ = vala_semantic_analyzer_get_current_symbol (_tmp61_);
	_tmp63_ = _tmp62_;
	_tmp64_ = vala_symbol_get_scope (_tmp63_);
	_tmp65_ = _tmp64_;
	_tmp66_ = vala_symbol_get_name ((ValaSymbol*) self);
	_tmp67_ = _tmp66_;
	vala_scope_add (_tmp65_, _tmp67_, (ValaSymbol*) self);
	_tmp68_ = vala_code_node_get_error ((ValaCodeNode*) self);
	_tmp69_ = _tmp68_;
	if (_tmp69_) {
		result = FALSE;
		return result;
	}
	_tmp70_ = vala_variable_get_variable_type ((ValaVariable*) self);
	_tmp71_ = _tmp70_;
	if (BALA_IS_VAR_TYPE (_tmp71_)) {
		ValaExpression* _tmp72_;
		ValaExpression* _tmp73_;
		ValaExpression* _tmp76_;
		ValaExpression* _tmp77_;
		ValaDataType* _tmp78_;
		ValaDataType* _tmp79_;
		gboolean _tmp82_ = FALSE;
		ValaExpression* _tmp83_;
		ValaExpression* _tmp84_;
		ValaDataType* _tmp85_;
		ValaDataType* _tmp86_;
		gboolean value_owned = FALSE;
		ValaDataType* _tmp103_;
		ValaDataType* _tmp104_;
		gboolean _tmp105_;
		gboolean _tmp106_;
		ValaExpression* _tmp107_;
		ValaExpression* _tmp108_;
		ValaDataType* _tmp109_;
		ValaDataType* _tmp110_;
		ValaDataType* _tmp111_;
		ValaDataType* _tmp112_;
		ValaDataType* _tmp113_;
		ValaDataType* _tmp114_;
		ValaDataType* _tmp115_;
		ValaDataType* _tmp116_;
		ValaExpression* _tmp117_;
		ValaExpression* _tmp118_;
		ValaDataType* _tmp119_;
		ValaDataType* _tmp120_;
		ValaDataType* _tmp121_;
		ValaDataType* _tmp122_;
		_tmp72_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp73_ = _tmp72_;
		if (_tmp73_ == NULL) {
			ValaSourceReference* _tmp74_;
			ValaSourceReference* _tmp75_;
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			_tmp74_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp75_ = _tmp74_;
			vala_report_error (_tmp75_, "var declaration not allowed without initializer");
			result = FALSE;
			return result;
		}
		_tmp76_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp77_ = _tmp76_;
		_tmp78_ = vala_expression_get_value_type (_tmp77_);
		_tmp79_ = _tmp78_;
		if (_tmp79_ == NULL) {
			ValaSourceReference* _tmp80_;
			ValaSourceReference* _tmp81_;
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			_tmp80_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp81_ = _tmp80_;
			vala_report_error (_tmp81_, "var declaration not allowed with non-typed initializer");
			result = FALSE;
			return result;
		}
		_tmp83_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp84_ = _tmp83_;
		_tmp85_ = vala_expression_get_value_type (_tmp84_);
		_tmp86_ = _tmp85_;
		if (BALA_IS_FIELD_PROTOTYPE (_tmp86_)) {
			_tmp82_ = TRUE;
		} else {
			ValaExpression* _tmp87_;
			ValaExpression* _tmp88_;
			ValaDataType* _tmp89_;
			ValaDataType* _tmp90_;
			_tmp87_ = vala_variable_get_initializer ((ValaVariable*) self);
			_tmp88_ = _tmp87_;
			_tmp89_ = vala_expression_get_value_type (_tmp88_);
			_tmp90_ = _tmp89_;
			_tmp82_ = BALA_IS_PROPERTY_PROTOTYPE (_tmp90_);
		}
		if (_tmp82_) {
			ValaExpression* _tmp91_;
			ValaExpression* _tmp92_;
			ValaSourceReference* _tmp93_;
			ValaSourceReference* _tmp94_;
			ValaExpression* _tmp95_;
			ValaExpression* _tmp96_;
			ValaSymbol* _tmp97_;
			ValaSymbol* _tmp98_;
			gchar* _tmp99_;
			gchar* _tmp100_;
			gchar* _tmp101_;
			gchar* _tmp102_;
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			_tmp91_ = vala_variable_get_initializer ((ValaVariable*) self);
			_tmp92_ = _tmp91_;
			_tmp93_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp92_);
			_tmp94_ = _tmp93_;
			_tmp95_ = vala_variable_get_initializer ((ValaVariable*) self);
			_tmp96_ = _tmp95_;
			_tmp97_ = vala_expression_get_symbol_reference (_tmp96_);
			_tmp98_ = _tmp97_;
			_tmp99_ = vala_symbol_get_full_name (_tmp98_);
			_tmp100_ = _tmp99_;
			_tmp101_ = g_strdup_printf ("Access to instance member `%s' denied", _tmp100_);
			_tmp102_ = _tmp101_;
			vala_report_error (_tmp94_, _tmp102_);
			_g_free0 (_tmp102_);
			_g_free0 (_tmp100_);
			result = FALSE;
			return result;
		}
		_tmp103_ = vala_variable_get_variable_type ((ValaVariable*) self);
		_tmp104_ = _tmp103_;
		_tmp105_ = vala_data_type_get_value_owned (_tmp104_);
		_tmp106_ = _tmp105_;
		value_owned = _tmp106_;
		_tmp107_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp108_ = _tmp107_;
		_tmp109_ = vala_expression_get_value_type (_tmp108_);
		_tmp110_ = _tmp109_;
		_tmp111_ = vala_data_type_copy (_tmp110_);
		_tmp112_ = _tmp111_;
		vala_variable_set_variable_type ((ValaVariable*) self, _tmp112_);
		_vala_code_node_unref0 (_tmp112_);
		_tmp113_ = vala_variable_get_variable_type ((ValaVariable*) self);
		_tmp114_ = _tmp113_;
		vala_data_type_set_value_owned (_tmp114_, value_owned);
		_tmp115_ = vala_variable_get_variable_type ((ValaVariable*) self);
		_tmp116_ = _tmp115_;
		vala_data_type_set_floating_reference (_tmp116_, FALSE);
		_tmp117_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp118_ = _tmp117_;
		_tmp119_ = vala_variable_get_variable_type ((ValaVariable*) self);
		_tmp120_ = _tmp119_;
		vala_expression_set_target_type (_tmp118_, _tmp120_);
		_tmp121_ = vala_variable_get_variable_type ((ValaVariable*) self);
		_tmp122_ = _tmp121_;
		vala_code_node_check ((ValaCodeNode*) _tmp122_, context);
	}
	_tmp123_ = vala_symbol_get_external_package ((ValaSymbol*) self);
	_tmp124_ = _tmp123_;
	if (!_tmp124_) {
		ValaDataType* _tmp125_;
		ValaDataType* _tmp126_;
		ValaTypeSymbol* _tmp127_;
		ValaTypeSymbol* _tmp128_;
		_tmp125_ = vala_variable_get_variable_type ((ValaVariable*) self);
		_tmp126_ = _tmp125_;
		_tmp127_ = vala_data_type_get_type_symbol (_tmp126_);
		_tmp128_ = _tmp127_;
		if (_tmp128_ != NULL) {
			ValaDataType* _tmp129_;
			ValaDataType* _tmp130_;
			ValaTypeSymbol* _tmp131_;
			ValaTypeSymbol* _tmp132_;
			ValaVersionAttribute* _tmp133_;
			ValaVersionAttribute* _tmp134_;
			ValaSourceReference* _tmp135_;
			ValaSourceReference* _tmp136_;
			_tmp129_ = vala_variable_get_variable_type ((ValaVariable*) self);
			_tmp130_ = _tmp129_;
			_tmp131_ = vala_data_type_get_type_symbol (_tmp130_);
			_tmp132_ = _tmp131_;
			_tmp133_ = vala_symbol_get_version ((ValaSymbol*) _tmp132_);
			_tmp134_ = _tmp133_;
			_tmp135_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp136_ = _tmp135_;
			vala_version_attribute_check (_tmp134_, _tmp136_);
		}
	}
	_tmp137_ = vala_variable_get_variable_type ((ValaVariable*) self);
	_tmp138_ = _tmp137_;
	variable_array_type = BALA_IS_ARRAY_TYPE (_tmp138_) ? ((ValaArrayType*) _tmp138_) : NULL;
	_tmp142_ = variable_array_type;
	if (_tmp142_ != NULL) {
		ValaArrayType* _tmp143_;
		gboolean _tmp144_;
		gboolean _tmp145_;
		_tmp143_ = variable_array_type;
		_tmp144_ = vala_array_type_get_inline_allocated (_tmp143_);
		_tmp145_ = _tmp144_;
		_tmp141_ = _tmp145_;
	} else {
		_tmp141_ = FALSE;
	}
	if (_tmp141_) {
		ValaExpression* _tmp146_;
		ValaExpression* _tmp147_;
		_tmp146_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp147_ = _tmp146_;
		_tmp140_ = BALA_IS_ARRAY_CREATION_EXPRESSION (_tmp147_);
	} else {
		_tmp140_ = FALSE;
	}
	if (_tmp140_) {
		ValaExpression* _tmp148_;
		ValaExpression* _tmp149_;
		ValaInitializerList* _tmp150_;
		ValaInitializerList* _tmp151_;
		_tmp148_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp149_ = _tmp148_;
		_tmp150_ = vala_array_creation_expression_get_initializer_list (G_TYPE_CHECK_INSTANCE_CAST (_tmp149_, BALA_TYPE_ARRAY_CREATION_EXPRESSION, ValaArrayCreationExpression));
		_tmp151_ = _tmp150_;
		_tmp139_ = _tmp151_ == NULL;
	} else {
		_tmp139_ = FALSE;
	}
	if (_tmp139_) {
		ValaSourceReference* _tmp152_;
		ValaSourceReference* _tmp153_;
		_tmp152_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp153_ = _tmp152_;
		vala_report_warning (_tmp153_, "Inline allocated arrays don't require an explicit instantiation");
		vala_variable_set_initializer ((ValaVariable*) self, NULL);
	}
	_tmp157_ = variable_array_type;
	if (_tmp157_ != NULL) {
		ValaArrayType* _tmp158_;
		gboolean _tmp159_;
		gboolean _tmp160_;
		_tmp158_ = variable_array_type;
		_tmp159_ = vala_array_type_get_inline_allocated (_tmp158_);
		_tmp160_ = _tmp159_;
		_tmp156_ = _tmp160_;
	} else {
		_tmp156_ = FALSE;
	}
	if (_tmp156_) {
		ValaArrayType* _tmp161_;
		ValaExpression* _tmp162_;
		ValaExpression* _tmp163_;
		_tmp161_ = variable_array_type;
		_tmp162_ = vala_array_type_get_length (_tmp161_);
		_tmp163_ = _tmp162_;
		_tmp155_ = _tmp163_ == NULL;
	} else {
		_tmp155_ = FALSE;
	}
	if (_tmp155_) {
		ValaExpression* _tmp164_;
		ValaExpression* _tmp165_;
		_tmp164_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp165_ = _tmp164_;
		_tmp154_ = !BALA_IS_ARRAY_CREATION_EXPRESSION (_tmp165_);
	} else {
		_tmp154_ = FALSE;
	}
	if (_tmp154_) {
		ValaSourceReference* _tmp166_;
		ValaSourceReference* _tmp167_;
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		_tmp166_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp167_ = _tmp166_;
		vala_report_error (_tmp167_, "Inline allocated array requires either a given length or an initialize" \
"r");
	}
	_tmp169_ = vala_variable_get_initializer ((ValaVariable*) self);
	_tmp170_ = _tmp169_;
	if (_tmp170_ != NULL) {
		ValaExpression* _tmp171_;
		ValaExpression* _tmp172_;
		gboolean _tmp173_;
		gboolean _tmp174_;
		_tmp171_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp172_ = _tmp171_;
		_tmp173_ = vala_code_node_get_error ((ValaCodeNode*) _tmp172_);
		_tmp174_ = _tmp173_;
		_tmp168_ = !_tmp174_;
	} else {
		_tmp168_ = FALSE;
	}
	if (_tmp168_) {
		ValaExpression* _tmp175_;
		ValaExpression* _tmp176_;
		ValaDataType* _tmp177_;
		ValaDataType* _tmp178_;
		ValaExpression* _tmp214_;
		ValaExpression* _tmp215_;
		ValaDataType* _tmp216_;
		ValaDataType* _tmp217_;
		ValaDataType* _tmp218_;
		ValaDataType* _tmp219_;
		gboolean _tmp234_ = FALSE;
		gboolean _tmp235_ = FALSE;
		gboolean _tmp236_ = FALSE;
		ValaArrayType* _tmp237_;
		gboolean _tmp251_ = FALSE;
		gboolean _tmp252_ = FALSE;
		ValaArrayType* _tmp253_;
		ValaExpression* _tmp263_;
		ValaExpression* _tmp264_;
		ValaDataType* _tmp265_;
		ValaDataType* _tmp266_;
		_tmp175_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp176_ = _tmp175_;
		_tmp177_ = vala_expression_get_value_type (_tmp176_);
		_tmp178_ = _tmp177_;
		if (BALA_IS_METHOD_TYPE (_tmp178_)) {
			gboolean _tmp179_ = FALSE;
			ValaExpression* _tmp180_;
			ValaExpression* _tmp181_;
			ValaDataType* _tmp186_;
			ValaDataType* _tmp187_;
			_tmp180_ = vala_variable_get_initializer ((ValaVariable*) self);
			_tmp181_ = _tmp180_;
			if (!BALA_IS_MEMBER_ACCESS (_tmp181_)) {
				ValaExpression* _tmp182_;
				ValaExpression* _tmp183_;
				_tmp182_ = vala_variable_get_initializer ((ValaVariable*) self);
				_tmp183_ = _tmp182_;
				_tmp179_ = !BALA_IS_LAMBDA_EXPRESSION (_tmp183_);
			} else {
				_tmp179_ = FALSE;
			}
			if (_tmp179_) {
				ValaSourceReference* _tmp184_;
				ValaSourceReference* _tmp185_;
				vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
				_tmp184_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
				_tmp185_ = _tmp184_;
				vala_report_error (_tmp185_, "expression type not allowed as initializer");
				result = FALSE;
				return result;
			}
			_tmp186_ = vala_variable_get_variable_type ((ValaVariable*) self);
			_tmp187_ = _tmp186_;
			if (BALA_IS_DELEGATE_TYPE (_tmp187_)) {
				ValaExpression* _tmp188_;
				ValaExpression* _tmp189_;
				ValaDataType* _tmp190_;
				ValaDataType* _tmp191_;
				ValaDataType* _tmp192_;
				ValaDataType* _tmp193_;
				_tmp188_ = vala_variable_get_initializer ((ValaVariable*) self);
				_tmp189_ = _tmp188_;
				_tmp190_ = vala_expression_get_value_type (_tmp189_);
				_tmp191_ = _tmp190_;
				_tmp192_ = vala_variable_get_variable_type ((ValaVariable*) self);
				_tmp193_ = _tmp192_;
				if (!vala_data_type_compatible (_tmp191_, _tmp193_)) {
					ValaMethod* m = NULL;
					ValaExpression* _tmp194_;
					ValaExpression* _tmp195_;
					ValaSymbol* _tmp196_;
					ValaSymbol* _tmp197_;
					ValaDelegate* cb = NULL;
					ValaDataType* _tmp198_;
					ValaDataType* _tmp199_;
					ValaDelegate* _tmp200_;
					ValaDelegate* _tmp201_;
					ValaSourceReference* _tmp202_;
					ValaSourceReference* _tmp203_;
					ValaMethod* _tmp204_;
					gchar* _tmp205_;
					gchar* _tmp206_;
					ValaDelegate* _tmp207_;
					gchar* _tmp208_;
					gchar* _tmp209_;
					gchar* _tmp210_;
					gchar* _tmp211_;
					_tmp194_ = vala_variable_get_initializer ((ValaVariable*) self);
					_tmp195_ = _tmp194_;
					_tmp196_ = vala_expression_get_symbol_reference (_tmp195_);
					_tmp197_ = _tmp196_;
					m = G_TYPE_CHECK_INSTANCE_CAST (_tmp197_, BALA_TYPE_METHOD, ValaMethod);
					_tmp198_ = vala_variable_get_variable_type ((ValaVariable*) self);
					_tmp199_ = _tmp198_;
					_tmp200_ = vala_delegate_type_get_delegate_symbol (G_TYPE_CHECK_INSTANCE_CAST (_tmp199_, BALA_TYPE_DELEGATE_TYPE, ValaDelegateType));
					_tmp201_ = _tmp200_;
					cb = _tmp201_;
					vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
					_tmp202_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
					_tmp203_ = _tmp202_;
					_tmp204_ = m;
					_tmp205_ = vala_symbol_get_full_name ((ValaSymbol*) _tmp204_);
					_tmp206_ = _tmp205_;
					_tmp207_ = cb;
					_tmp208_ = vala_symbol_get_full_name ((ValaSymbol*) _tmp207_);
					_tmp209_ = _tmp208_;
					_tmp210_ = g_strdup_printf ("Declaration of method `%s' is not compatible with delegate `%s'", _tmp206_, _tmp209_);
					_tmp211_ = _tmp210_;
					vala_report_error (_tmp203_, _tmp211_);
					_g_free0 (_tmp211_);
					_g_free0 (_tmp209_);
					_g_free0 (_tmp206_);
					result = FALSE;
					return result;
				}
			} else {
				ValaSourceReference* _tmp212_;
				ValaSourceReference* _tmp213_;
				vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
				_tmp212_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
				_tmp213_ = _tmp212_;
				vala_report_error (_tmp213_, "expression type not allowed as initializer");
				result = FALSE;
				return result;
			}
		}
		_tmp214_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp215_ = _tmp214_;
		_tmp216_ = vala_expression_get_value_type (_tmp215_);
		_tmp217_ = _tmp216_;
		_tmp218_ = vala_variable_get_variable_type ((ValaVariable*) self);
		_tmp219_ = _tmp218_;
		if (!vala_data_type_compatible (_tmp217_, _tmp219_)) {
			ValaSourceReference* _tmp220_;
			ValaSourceReference* _tmp221_;
			ValaExpression* _tmp222_;
			ValaExpression* _tmp223_;
			ValaDataType* _tmp224_;
			ValaDataType* _tmp225_;
			gchar* _tmp226_;
			gchar* _tmp227_;
			ValaDataType* _tmp228_;
			ValaDataType* _tmp229_;
			gchar* _tmp230_;
			gchar* _tmp231_;
			gchar* _tmp232_;
			gchar* _tmp233_;
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			_tmp220_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp221_ = _tmp220_;
			_tmp222_ = vala_variable_get_initializer ((ValaVariable*) self);
			_tmp223_ = _tmp222_;
			_tmp224_ = vala_expression_get_value_type (_tmp223_);
			_tmp225_ = _tmp224_;
			_tmp226_ = vala_code_node_to_string ((ValaCodeNode*) _tmp225_);
			_tmp227_ = _tmp226_;
			_tmp228_ = vala_variable_get_variable_type ((ValaVariable*) self);
			_tmp229_ = _tmp228_;
			_tmp230_ = vala_code_node_to_string ((ValaCodeNode*) _tmp229_);
			_tmp231_ = _tmp230_;
			_tmp232_ = g_strdup_printf ("Assignment: Cannot convert from `%s' to `%s'", _tmp227_, _tmp231_);
			_tmp233_ = _tmp232_;
			vala_report_error (_tmp221_, _tmp233_);
			_g_free0 (_tmp233_);
			_g_free0 (_tmp231_);
			_g_free0 (_tmp227_);
			result = FALSE;
			return result;
		}
		_tmp237_ = variable_array_type;
		if (_tmp237_ != NULL) {
			ValaArrayType* _tmp238_;
			gboolean _tmp239_;
			gboolean _tmp240_;
			_tmp238_ = variable_array_type;
			_tmp239_ = vala_array_type_get_inline_allocated (_tmp238_);
			_tmp240_ = _tmp239_;
			_tmp236_ = _tmp240_;
		} else {
			_tmp236_ = FALSE;
		}
		if (_tmp236_) {
			ValaArrayType* _tmp241_;
			gboolean _tmp242_;
			gboolean _tmp243_;
			_tmp241_ = variable_array_type;
			_tmp242_ = vala_array_type_get_fixed_length (_tmp241_);
			_tmp243_ = _tmp242_;
			_tmp235_ = !_tmp243_;
		} else {
			_tmp235_ = FALSE;
		}
		if (_tmp235_) {
			_tmp234_ = is_initializer_list;
		} else {
			_tmp234_ = FALSE;
		}
		if (_tmp234_) {
			ValaArrayType* _tmp244_;
			gchar* _tmp245_;
			gchar* _tmp246_;
			ValaIntegerLiteral* _tmp247_;
			ValaIntegerLiteral* _tmp248_;
			ValaArrayType* _tmp249_;
			ValaArrayType* _tmp250_;
			_tmp244_ = variable_array_type;
			_tmp245_ = g_strdup_printf ("%i", initializer_size);
			_tmp246_ = _tmp245_;
			_tmp247_ = vala_integer_literal_new (_tmp246_, NULL);
			_tmp248_ = _tmp247_;
			vala_array_type_set_length (_tmp244_, (ValaExpression*) _tmp248_);
			_vala_code_node_unref0 (_tmp248_);
			_g_free0 (_tmp246_);
			_tmp249_ = variable_array_type;
			vala_array_type_set_fixed_length (_tmp249_, TRUE);
			_tmp250_ = variable_array_type;
			vala_data_type_set_nullable ((ValaDataType*) _tmp250_, FALSE);
		}
		_tmp253_ = variable_array_type;
		if (_tmp253_ != NULL) {
			ValaArrayType* _tmp254_;
			gboolean _tmp255_;
			gboolean _tmp256_;
			_tmp254_ = variable_array_type;
			_tmp255_ = vala_array_type_get_inline_allocated (_tmp254_);
			_tmp256_ = _tmp255_;
			_tmp252_ = _tmp256_;
		} else {
			_tmp252_ = FALSE;
		}
		if (_tmp252_) {
			ValaExpression* _tmp257_;
			ValaExpression* _tmp258_;
			ValaDataType* _tmp259_;
			ValaDataType* _tmp260_;
			_tmp257_ = vala_variable_get_initializer ((ValaVariable*) self);
			_tmp258_ = _tmp257_;
			_tmp259_ = vala_expression_get_value_type (_tmp258_);
			_tmp260_ = _tmp259_;
			_tmp251_ = BALA_IS_ARRAY_TYPE (_tmp260_) == FALSE;
		} else {
			_tmp251_ = FALSE;
		}
		if (_tmp251_) {
			ValaSourceReference* _tmp261_;
			ValaSourceReference* _tmp262_;
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			_tmp261_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp262_ = _tmp261_;
			vala_report_error (_tmp262_, "only arrays are allowed as initializer for arrays with fixed length");
			result = FALSE;
			return result;
		}
		_tmp263_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp264_ = _tmp263_;
		_tmp265_ = vala_expression_get_value_type (_tmp264_);
		_tmp266_ = _tmp265_;
		if (vala_data_type_is_disposable (_tmp266_)) {
			gboolean _tmp267_ = FALSE;
			ValaDataType* _tmp268_;
			ValaDataType* _tmp269_;
			_tmp268_ = vala_variable_get_variable_type ((ValaVariable*) self);
			_tmp269_ = _tmp268_;
			if (!BALA_IS_POINTER_TYPE (_tmp269_)) {
				ValaDataType* _tmp270_;
				ValaDataType* _tmp271_;
				gboolean _tmp272_;
				gboolean _tmp273_;
				_tmp270_ = vala_variable_get_variable_type ((ValaVariable*) self);
				_tmp271_ = _tmp270_;
				_tmp272_ = vala_data_type_get_value_owned (_tmp271_);
				_tmp273_ = _tmp272_;
				_tmp267_ = !_tmp273_;
			} else {
				_tmp267_ = FALSE;
			}
			if (_tmp267_) {
				ValaSourceReference* _tmp274_;
				ValaSourceReference* _tmp275_;
				vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
				_tmp274_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
				_tmp275_ = _tmp274_;
				vala_report_error (_tmp275_, "Invalid assignment from owned expression to unowned variable");
				result = FALSE;
				return result;
			}
		}
	}
	_tmp276_ = vala_code_context_get_analyzer (context);
	_tmp277_ = _tmp276_;
	_tmp278_ = vala_semantic_analyzer_get_current_symbol (_tmp277_);
	_tmp279_ = _tmp278_;
	block = BALA_IS_BLOCK (_tmp279_) ? ((ValaBlock*) _tmp279_) : NULL;
	_tmp280_ = block;
	if (_tmp280_ != NULL) {
		ValaBlock* _tmp281_;
		_tmp281_ = block;
		vala_block_add_local_variable (_tmp281_, self);
	}
	vala_symbol_set_active ((ValaSymbol*) self, TRUE);
	_tmp282_ = vala_code_node_get_error ((ValaCodeNode*) self);
	_tmp283_ = _tmp282_;
	result = !_tmp283_;
	return result;
}

static void
vala_local_variable_class_init (ValaLocalVariableClass * klass,
                                gpointer klass_data)
{
	vala_local_variable_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_local_variable_finalize;
	g_type_class_adjust_private_offset (klass, &ValaLocalVariable_private_offset);
	((ValaCodeNodeClass *) klass)->accept = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_local_variable_real_accept;
	((ValaCodeNodeClass *) klass)->accept_children = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_local_variable_real_accept_children;
	((ValaCodeNodeClass *) klass)->replace_expression = (void (*) (ValaCodeNode*, ValaExpression*, ValaExpression*)) vala_local_variable_real_replace_expression;
	((ValaCodeNodeClass *) klass)->replace_type = (void (*) (ValaCodeNode*, ValaDataType*, ValaDataType*)) vala_local_variable_real_replace_type;
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) vala_local_variable_real_check;
}

static void
vala_local_variable_instance_init (ValaLocalVariable * self,
                                   gpointer klass)
{
	self->priv = vala_local_variable_get_instance_private (self);
}

static void
vala_local_variable_finalize (ValaCodeNode * obj)
{
	ValaLocalVariable * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_LOCAL_VARIABLE, ValaLocalVariable);
	BALA_CODE_NODE_CLASS (vala_local_variable_parent_class)->finalize (obj);
}

/**
 * Represents a local variable declaration in the source code.
 */
static GType
vala_local_variable_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaLocalVariableClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_local_variable_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaLocalVariable), 0, (GInstanceInitFunc) vala_local_variable_instance_init, NULL };
	GType vala_local_variable_type_id;
	vala_local_variable_type_id = g_type_register_static (BALA_TYPE_VARIABLE, "ValaLocalVariable", &g_define_type_info, 0);
	ValaLocalVariable_private_offset = g_type_add_instance_private (vala_local_variable_type_id, sizeof (ValaLocalVariablePrivate));
	return vala_local_variable_type_id;
}

GType
vala_local_variable_get_type (void)
{
	static volatile gsize vala_local_variable_type_id__volatile = 0;
	if (g_once_init_enter (&vala_local_variable_type_id__volatile)) {
		GType vala_local_variable_type_id;
		vala_local_variable_type_id = vala_local_variable_get_type_once ();
		g_once_init_leave (&vala_local_variable_type_id__volatile, vala_local_variable_type_id);
	}
	return vala_local_variable_type_id__volatile;
}

