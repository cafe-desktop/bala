/* valacastexpression.c generated by valac, the Vala compiler
 * generated from valacastexpression.vala, do not modify */

/* valacastexpression.vala
 *
 * Copyright (C) 2006-2011  Jürg Billeter
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
#include <valagee.h>
#include <glib-object.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _ValaCastExpressionPrivate {
	gboolean _is_silent_cast;
	gboolean _is_non_null_cast;
	ValaExpression* _inner;
	ValaDataType* _data_type;
};

static gint ValaCastExpression_private_offset;
static gpointer vala_cast_expression_parent_class = NULL;

static void vala_cast_expression_set_is_silent_cast (ValaCastExpression* self,
                                              gboolean value);
static void vala_cast_expression_set_is_non_null_cast (ValaCastExpression* self,
                                                gboolean value);
static void vala_cast_expression_real_accept (ValaCodeNode* base,
                                       ValaCodeVisitor* visitor);
static void vala_cast_expression_real_accept_children (ValaCodeNode* base,
                                                ValaCodeVisitor* visitor);
static gchar* vala_cast_expression_real_to_string (ValaCodeNode* base);
static void vala_cast_expression_real_replace_expression (ValaCodeNode* base,
                                                   ValaExpression* old_node,
                                                   ValaExpression* new_node);
static gboolean vala_cast_expression_real_is_pure (ValaExpression* base);
static gboolean vala_cast_expression_real_is_accessible (ValaExpression* base,
                                                  ValaSymbol* sym);
static void vala_cast_expression_real_replace_type (ValaCodeNode* base,
                                             ValaDataType* old_type,
                                             ValaDataType* new_type);
static void vala_cast_expression_real_get_error_types (ValaCodeNode* base,
                                                ValaCollection* collection,
                                                ValaSourceReference* source_reference);
static gboolean vala_cast_expression_real_check (ValaCodeNode* base,
                                          ValaCodeContext* context);
static gboolean vala_cast_expression_is_gvariant (ValaCastExpression* self,
                                           ValaCodeContext* context,
                                           ValaDataType* type);
static gboolean vala_cast_expression_is_gvalue (ValaCastExpression* self,
                                         ValaCodeContext* context,
                                         ValaDataType* type);
static void vala_cast_expression_real_emit (ValaCodeNode* base,
                                     ValaCodeGenerator* codegen);
static void vala_cast_expression_real_get_defined_variables (ValaCodeNode* base,
                                                      ValaCollection* collection);
static void vala_cast_expression_real_get_used_variables (ValaCodeNode* base,
                                                   ValaCollection* collection);
static gboolean vala_cast_expression_real_is_constant (ValaExpression* base);
static void vala_cast_expression_finalize (ValaCodeNode * obj);
static GType vala_cast_expression_get_type_once (void);

static inline gpointer
vala_cast_expression_get_instance_private (ValaCastExpression* self)
{
	return G_STRUCT_MEMBER_P (self, ValaCastExpression_private_offset);
}

ValaExpression*
vala_cast_expression_get_inner (ValaCastExpression* self)
{
	ValaExpression* result;
	ValaExpression* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_inner;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

void
vala_cast_expression_set_inner (ValaCastExpression* self,
                                ValaExpression* value)
{
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_inner);
	self->priv->_inner = _tmp0_;
	_tmp1_ = self->priv->_inner;
	vala_code_node_set_parent_node ((ValaCodeNode*) _tmp1_, (ValaCodeNode*) self);
}

ValaDataType*
vala_cast_expression_get_type_reference (ValaCastExpression* self)
{
	ValaDataType* result;
	ValaDataType* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_data_type;
	result = _tmp0_;
	return result;
}

void
vala_cast_expression_set_type_reference (ValaCastExpression* self,
                                         ValaDataType* value)
{
	ValaDataType* _tmp0_;
	ValaDataType* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_data_type);
	self->priv->_data_type = _tmp0_;
	_tmp1_ = self->priv->_data_type;
	vala_code_node_set_parent_node ((ValaCodeNode*) _tmp1_, (ValaCodeNode*) self);
}

gboolean
vala_cast_expression_get_is_silent_cast (ValaCastExpression* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_is_silent_cast;
	return result;
}

static void
vala_cast_expression_set_is_silent_cast (ValaCastExpression* self,
                                         gboolean value)
{
	g_return_if_fail (self != NULL);
	self->priv->_is_silent_cast = value;
}

gboolean
vala_cast_expression_get_is_non_null_cast (ValaCastExpression* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_is_non_null_cast;
	return result;
}

static void
vala_cast_expression_set_is_non_null_cast (ValaCastExpression* self,
                                           gboolean value)
{
	g_return_if_fail (self != NULL);
	self->priv->_is_non_null_cast = value;
}

/**
 * Creates a new cast expression.
 *
 * @param inner           expression to be cast
 * @param type_reference  target type
 * @return                newly created cast expression
 */
ValaCastExpression*
vala_cast_expression_construct (GType object_type,
                                ValaExpression* inner,
                                ValaDataType* type_reference,
                                ValaSourceReference* source_reference)
{
	ValaCastExpression* self = NULL;
	g_return_val_if_fail (inner != NULL, NULL);
	g_return_val_if_fail (type_reference != NULL, NULL);
	self = (ValaCastExpression*) vala_expression_construct (object_type);
	vala_cast_expression_set_type_reference (self, type_reference);
	vala_code_node_set_source_reference ((ValaCodeNode*) self, source_reference);
	vala_cast_expression_set_is_silent_cast (self, FALSE);
	vala_cast_expression_set_is_non_null_cast (self, FALSE);
	vala_cast_expression_set_inner (self, inner);
	return self;
}

ValaCastExpression*
vala_cast_expression_new (ValaExpression* inner,
                          ValaDataType* type_reference,
                          ValaSourceReference* source_reference)
{
	return vala_cast_expression_construct (BALA_TYPE_CAST_EXPRESSION, inner, type_reference, source_reference);
}

ValaCastExpression*
vala_cast_expression_construct_silent (GType object_type,
                                       ValaExpression* inner,
                                       ValaDataType* type_reference,
                                       ValaSourceReference* source_reference)
{
	ValaCastExpression* self = NULL;
	g_return_val_if_fail (inner != NULL, NULL);
	g_return_val_if_fail (type_reference != NULL, NULL);
	self = (ValaCastExpression*) vala_expression_construct (object_type);
	vala_cast_expression_set_type_reference (self, type_reference);
	vala_code_node_set_source_reference ((ValaCodeNode*) self, source_reference);
	vala_cast_expression_set_is_silent_cast (self, TRUE);
	vala_cast_expression_set_is_non_null_cast (self, FALSE);
	vala_cast_expression_set_inner (self, inner);
	return self;
}

ValaCastExpression*
vala_cast_expression_new_silent (ValaExpression* inner,
                                 ValaDataType* type_reference,
                                 ValaSourceReference* source_reference)
{
	return vala_cast_expression_construct_silent (BALA_TYPE_CAST_EXPRESSION, inner, type_reference, source_reference);
}

ValaCastExpression*
vala_cast_expression_construct_non_null (GType object_type,
                                         ValaExpression* inner,
                                         ValaSourceReference* source_reference)
{
	ValaCastExpression* self = NULL;
	g_return_val_if_fail (inner != NULL, NULL);
	self = (ValaCastExpression*) vala_expression_construct (object_type);
	vala_cast_expression_set_inner (self, inner);
	vala_cast_expression_set_is_non_null_cast (self, TRUE);
	vala_code_node_set_source_reference ((ValaCodeNode*) self, source_reference);
	return self;
}

ValaCastExpression*
vala_cast_expression_new_non_null (ValaExpression* inner,
                                   ValaSourceReference* source_reference)
{
	return vala_cast_expression_construct_non_null (BALA_TYPE_CAST_EXPRESSION, inner, source_reference);
}

static void
vala_cast_expression_real_accept (ValaCodeNode* base,
                                  ValaCodeVisitor* visitor)
{
	ValaCastExpression * self;
	self = (ValaCastExpression*) base;
	g_return_if_fail (visitor != NULL);
	vala_code_visitor_visit_cast_expression (visitor, self);
	vala_code_visitor_visit_expression (visitor, (ValaExpression*) self);
}

static void
vala_cast_expression_real_accept_children (ValaCodeNode* base,
                                           ValaCodeVisitor* visitor)
{
	ValaCastExpression * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	gboolean _tmp2_;
	self = (ValaCastExpression*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = vala_cast_expression_get_inner (self);
	_tmp1_ = _tmp0_;
	vala_code_node_accept ((ValaCodeNode*) _tmp1_, visitor);
	_tmp2_ = self->priv->_is_non_null_cast;
	if (!_tmp2_) {
		ValaDataType* _tmp3_;
		ValaDataType* _tmp4_;
		_tmp3_ = vala_cast_expression_get_type_reference (self);
		_tmp4_ = _tmp3_;
		vala_code_node_accept ((ValaCodeNode*) _tmp4_, visitor);
	}
}

static gchar*
vala_cast_expression_real_to_string (ValaCodeNode* base)
{
	ValaCastExpression * self;
	gboolean _tmp0_;
	gchar* result = NULL;
	self = (ValaCastExpression*) base;
	_tmp0_ = self->priv->_is_non_null_cast;
	if (_tmp0_) {
		ValaExpression* _tmp1_;
		ValaExpression* _tmp2_;
		gchar* _tmp3_;
		gchar* _tmp4_;
		gchar* _tmp5_;
		gchar* _tmp6_;
		_tmp1_ = vala_cast_expression_get_inner (self);
		_tmp2_ = _tmp1_;
		_tmp3_ = vala_code_node_to_string ((ValaCodeNode*) _tmp2_);
		_tmp4_ = _tmp3_;
		_tmp5_ = g_strdup_printf ("(!) %s", _tmp4_);
		_tmp6_ = _tmp5_;
		_g_free0 (_tmp4_);
		result = _tmp6_;
		return result;
	} else {
		gboolean _tmp7_;
		_tmp7_ = self->priv->_is_silent_cast;
		if (_tmp7_) {
			ValaExpression* _tmp8_;
			ValaExpression* _tmp9_;
			gchar* _tmp10_;
			gchar* _tmp11_;
			ValaDataType* _tmp12_;
			ValaDataType* _tmp13_;
			gchar* _tmp14_;
			gchar* _tmp15_;
			gchar* _tmp16_;
			gchar* _tmp17_;
			_tmp8_ = vala_cast_expression_get_inner (self);
			_tmp9_ = _tmp8_;
			_tmp10_ = vala_code_node_to_string ((ValaCodeNode*) _tmp9_);
			_tmp11_ = _tmp10_;
			_tmp12_ = vala_cast_expression_get_type_reference (self);
			_tmp13_ = _tmp12_;
			_tmp14_ = vala_code_node_to_string ((ValaCodeNode*) _tmp13_);
			_tmp15_ = _tmp14_;
			_tmp16_ = g_strdup_printf ("%s as %s", _tmp11_, _tmp15_);
			_tmp17_ = _tmp16_;
			_g_free0 (_tmp15_);
			_g_free0 (_tmp11_);
			result = _tmp17_;
			return result;
		} else {
			ValaDataType* _tmp18_;
			ValaDataType* _tmp19_;
			gchar* _tmp20_;
			gchar* _tmp21_;
			ValaExpression* _tmp22_;
			ValaExpression* _tmp23_;
			gchar* _tmp24_;
			gchar* _tmp25_;
			gchar* _tmp26_;
			gchar* _tmp27_;
			_tmp18_ = vala_cast_expression_get_type_reference (self);
			_tmp19_ = _tmp18_;
			_tmp20_ = vala_code_node_to_string ((ValaCodeNode*) _tmp19_);
			_tmp21_ = _tmp20_;
			_tmp22_ = vala_cast_expression_get_inner (self);
			_tmp23_ = _tmp22_;
			_tmp24_ = vala_code_node_to_string ((ValaCodeNode*) _tmp23_);
			_tmp25_ = _tmp24_;
			_tmp26_ = g_strdup_printf ("(%s) %s", _tmp21_, _tmp25_);
			_tmp27_ = _tmp26_;
			_g_free0 (_tmp25_);
			_g_free0 (_tmp21_);
			result = _tmp27_;
			return result;
		}
	}
}

static void
vala_cast_expression_real_replace_expression (ValaCodeNode* base,
                                              ValaExpression* old_node,
                                              ValaExpression* new_node)
{
	ValaCastExpression * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaCastExpression*) base;
	g_return_if_fail (old_node != NULL);
	g_return_if_fail (new_node != NULL);
	_tmp0_ = vala_cast_expression_get_inner (self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ == old_node) {
		vala_cast_expression_set_inner (self, new_node);
	}
}

static gboolean
vala_cast_expression_real_is_pure (ValaExpression* base)
{
	ValaCastExpression * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	gboolean result = FALSE;
	self = (ValaCastExpression*) base;
	_tmp0_ = vala_cast_expression_get_inner (self);
	_tmp1_ = _tmp0_;
	result = vala_expression_is_pure (_tmp1_);
	return result;
}

static gboolean
vala_cast_expression_real_is_accessible (ValaExpression* base,
                                         ValaSymbol* sym)
{
	ValaCastExpression * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	gboolean result = FALSE;
	self = (ValaCastExpression*) base;
	g_return_val_if_fail (sym != NULL, FALSE);
	_tmp0_ = vala_cast_expression_get_inner (self);
	_tmp1_ = _tmp0_;
	result = vala_expression_is_accessible (_tmp1_, sym);
	return result;
}

static void
vala_cast_expression_real_replace_type (ValaCodeNode* base,
                                        ValaDataType* old_type,
                                        ValaDataType* new_type)
{
	ValaCastExpression * self;
	ValaDataType* _tmp0_;
	ValaDataType* _tmp1_;
	self = (ValaCastExpression*) base;
	g_return_if_fail (old_type != NULL);
	g_return_if_fail (new_type != NULL);
	_tmp0_ = vala_cast_expression_get_type_reference (self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ == old_type) {
		vala_cast_expression_set_type_reference (self, new_type);
	}
}

static void
vala_cast_expression_real_get_error_types (ValaCodeNode* base,
                                           ValaCollection* collection,
                                           ValaSourceReference* source_reference)
{
	ValaCastExpression * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaCastExpression*) base;
	g_return_if_fail (collection != NULL);
	_tmp0_ = vala_cast_expression_get_inner (self);
	_tmp1_ = _tmp0_;
	vala_code_node_get_error_types ((ValaCodeNode*) _tmp1_, collection, source_reference);
}

static gboolean
vala_cast_expression_real_check (ValaCodeNode* base,
                                 ValaCodeContext* context)
{
	ValaCastExpression * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	ValaExpression* _tmp4_;
	ValaExpression* _tmp5_;
	ValaExpression* _tmp6_;
	ValaExpression* _tmp7_;
	ValaDataType* _tmp8_;
	ValaDataType* _tmp9_;
	gboolean _tmp12_;
	ValaDataType* _tmp21_;
	ValaDataType* _tmp22_;
	gboolean _tmp23_ = FALSE;
	ValaDataType* _tmp24_;
	ValaDataType* _tmp25_;
	gboolean _tmp44_ = FALSE;
	gboolean _tmp45_ = FALSE;
	gboolean _tmp46_ = FALSE;
	gboolean _tmp47_;
	ValaDataType* _tmp96_;
	ValaDataType* _tmp97_;
	ValaDataType* _tmp98_;
	ValaDataType* _tmp99_;
	ValaExpression* _tmp100_;
	ValaExpression* _tmp101_;
	ValaDataType* _tmp102_;
	ValaDataType* _tmp103_;
	gboolean _tmp104_;
	gboolean _tmp105_;
	ValaDataType* _tmp106_;
	ValaDataType* _tmp107_;
	ValaExpression* _tmp108_;
	ValaExpression* _tmp109_;
	ValaDataType* _tmp110_;
	ValaDataType* _tmp111_;
	gboolean _tmp112_;
	gboolean _tmp113_;
	gboolean _tmp114_;
	gboolean _tmp117_ = FALSE;
	gboolean _tmp118_ = FALSE;
	ValaProfile _tmp119_;
	ValaProfile _tmp120_;
	gboolean _tmp142_ = FALSE;
	gboolean _tmp143_ = FALSE;
	ValaProfile _tmp144_;
	ValaProfile _tmp145_;
	ValaExpression* _tmp176_;
	ValaExpression* _tmp177_;
	ValaExpression* _tmp178_;
	ValaExpression* _tmp179_;
	ValaDataType* _tmp180_;
	ValaDataType* _tmp181_;
	ValaDataType* _tmp182_;
	ValaDataType* _tmp183_;
	gboolean _tmp184_;
	gboolean _tmp185_;
	gboolean result = FALSE;
	self = (ValaCastExpression*) base;
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
	_tmp4_ = vala_cast_expression_get_inner (self);
	_tmp5_ = _tmp4_;
	if (!vala_code_node_check ((ValaCodeNode*) _tmp5_, context)) {
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		result = FALSE;
		return result;
	}
	_tmp6_ = vala_cast_expression_get_inner (self);
	_tmp7_ = _tmp6_;
	_tmp8_ = vala_expression_get_value_type (_tmp7_);
	_tmp9_ = _tmp8_;
	if (_tmp9_ == NULL) {
		ValaSourceReference* _tmp10_;
		ValaSourceReference* _tmp11_;
		_tmp10_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp11_ = _tmp10_;
		vala_report_error (_tmp11_, "Invalid cast expression");
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		result = FALSE;
		return result;
	}
	_tmp12_ = self->priv->_is_non_null_cast;
	if (_tmp12_) {
		ValaExpression* _tmp13_;
		ValaExpression* _tmp14_;
		ValaDataType* _tmp15_;
		ValaDataType* _tmp16_;
		ValaDataType* _tmp17_;
		ValaDataType* _tmp18_;
		ValaDataType* _tmp19_;
		ValaDataType* _tmp20_;
		_tmp13_ = vala_cast_expression_get_inner (self);
		_tmp14_ = _tmp13_;
		_tmp15_ = vala_expression_get_value_type (_tmp14_);
		_tmp16_ = _tmp15_;
		_tmp17_ = vala_data_type_copy (_tmp16_);
		_tmp18_ = _tmp17_;
		vala_cast_expression_set_type_reference (self, _tmp18_);
		_vala_code_node_unref0 (_tmp18_);
		_tmp19_ = vala_cast_expression_get_type_reference (self);
		_tmp20_ = _tmp19_;
		vala_data_type_set_nullable (_tmp20_, FALSE);
	}
	_tmp21_ = vala_cast_expression_get_type_reference (self);
	_tmp22_ = _tmp21_;
	vala_code_node_check ((ValaCodeNode*) _tmp22_, context);
	_tmp24_ = vala_cast_expression_get_type_reference (self);
	_tmp25_ = _tmp24_;
	if (BALA_IS_DELEGATE_TYPE (_tmp25_)) {
		ValaExpression* _tmp26_;
		ValaExpression* _tmp27_;
		ValaDataType* _tmp28_;
		ValaDataType* _tmp29_;
		_tmp26_ = vala_cast_expression_get_inner (self);
		_tmp27_ = _tmp26_;
		_tmp28_ = vala_expression_get_value_type (_tmp27_);
		_tmp29_ = _tmp28_;
		_tmp23_ = BALA_IS_METHOD_TYPE (_tmp29_);
	} else {
		_tmp23_ = FALSE;
	}
	if (_tmp23_) {
		ValaDataType* _tmp30_;
		ValaDataType* _tmp31_;
		_tmp30_ = vala_expression_get_target_type ((ValaExpression*) self);
		_tmp31_ = _tmp30_;
		if (_tmp31_ != NULL) {
			ValaExpression* _tmp32_;
			ValaExpression* _tmp33_;
			ValaDataType* _tmp34_;
			ValaDataType* _tmp35_;
			ValaDataType* _tmp36_;
			ValaDataType* _tmp37_;
			gboolean _tmp38_;
			gboolean _tmp39_;
			_tmp32_ = vala_cast_expression_get_inner (self);
			_tmp33_ = _tmp32_;
			_tmp34_ = vala_expression_get_value_type (_tmp33_);
			_tmp35_ = _tmp34_;
			_tmp36_ = vala_expression_get_target_type ((ValaExpression*) self);
			_tmp37_ = _tmp36_;
			_tmp38_ = vala_data_type_get_value_owned (_tmp37_);
			_tmp39_ = _tmp38_;
			vala_data_type_set_value_owned (_tmp35_, _tmp39_);
		} else {
			ValaExpression* _tmp40_;
			ValaExpression* _tmp41_;
			ValaDataType* _tmp42_;
			ValaDataType* _tmp43_;
			_tmp40_ = vala_cast_expression_get_inner (self);
			_tmp41_ = _tmp40_;
			_tmp42_ = vala_expression_get_value_type (_tmp41_);
			_tmp43_ = _tmp42_;
			vala_data_type_set_value_owned (_tmp43_, TRUE);
		}
	}
	_tmp47_ = self->priv->_is_silent_cast;
	if (_tmp47_) {
		_tmp46_ = TRUE;
	} else {
		gboolean _tmp48_;
		_tmp48_ = self->priv->_is_non_null_cast;
		_tmp46_ = _tmp48_;
	}
	if (!_tmp46_) {
		gboolean _tmp49_ = FALSE;
		ValaDataType* _tmp50_;
		ValaDataType* _tmp51_;
		_tmp50_ = vala_cast_expression_get_type_reference (self);
		_tmp51_ = _tmp50_;
		if (BALA_IS_VALUE_TYPE (_tmp51_)) {
			ValaDataType* _tmp52_;
			ValaDataType* _tmp53_;
			gboolean _tmp54_;
			gboolean _tmp55_;
			_tmp52_ = vala_cast_expression_get_type_reference (self);
			_tmp53_ = _tmp52_;
			_tmp54_ = vala_data_type_get_nullable (_tmp53_);
			_tmp55_ = _tmp54_;
			_tmp49_ = _tmp55_;
		} else {
			_tmp49_ = FALSE;
		}
		_tmp45_ = _tmp49_;
	} else {
		_tmp45_ = FALSE;
	}
	if (_tmp45_) {
		ValaExpression* _tmp56_;
		ValaExpression* _tmp57_;
		ValaDataType* _tmp58_;
		ValaDataType* _tmp59_;
		_tmp56_ = vala_cast_expression_get_inner (self);
		_tmp57_ = _tmp56_;
		_tmp58_ = vala_expression_get_value_type (_tmp57_);
		_tmp59_ = _tmp58_;
		_tmp44_ = vala_data_type_is_non_null_simple_type (_tmp59_);
	} else {
		_tmp44_ = FALSE;
	}
	if (_tmp44_) {
		ValaLocalVariable* local = NULL;
		ValaDataType* _tmp60_;
		ValaDataType* _tmp61_;
		gchar* _tmp62_;
		gchar* _tmp63_;
		ValaExpression* _tmp64_;
		ValaExpression* _tmp65_;
		ValaSourceReference* _tmp66_;
		ValaSourceReference* _tmp67_;
		ValaLocalVariable* _tmp68_;
		ValaLocalVariable* _tmp69_;
		ValaDeclarationStatement* decl = NULL;
		ValaLocalVariable* _tmp70_;
		ValaSourceReference* _tmp71_;
		ValaSourceReference* _tmp72_;
		ValaDeclarationStatement* _tmp73_;
		ValaSemanticAnalyzer* _tmp74_;
		ValaSemanticAnalyzer* _tmp75_;
		ValaBlock* _tmp76_;
		ValaDeclarationStatement* _tmp77_;
		ValaExpression* temp_access = NULL;
		ValaLocalVariable* _tmp78_;
		ValaDataType* _tmp79_;
		ValaDataType* _tmp80_;
		ValaExpression* _tmp81_;
		ValaExpression* _tmp82_;
		ValaDataType* _tmp83_;
		ValaDataType* _tmp84_;
		ValaLocalVariable* _tmp85_;
		ValaExpression* _tmp86_;
		ValaExpression* _tmp87_;
		ValaDeclarationStatement* _tmp88_;
		ValaSemanticAnalyzer* _tmp89_;
		ValaSemanticAnalyzer* _tmp90_;
		ValaList* _tmp91_;
		ValaCodeNode* _tmp92_;
		ValaCodeNode* _tmp93_;
		ValaExpression* _tmp94_;
		ValaExpression* _tmp95_;
		_tmp60_ = vala_cast_expression_get_type_reference (self);
		_tmp61_ = _tmp60_;
		_tmp62_ = vala_code_node_get_temp_name ();
		_tmp63_ = _tmp62_;
		_tmp64_ = vala_cast_expression_get_inner (self);
		_tmp65_ = _tmp64_;
		_tmp66_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp65_);
		_tmp67_ = _tmp66_;
		_tmp68_ = vala_local_variable_new (_tmp61_, _tmp63_, NULL, _tmp67_);
		_tmp69_ = _tmp68_;
		_g_free0 (_tmp63_);
		local = _tmp69_;
		_tmp70_ = local;
		_tmp71_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp72_ = _tmp71_;
		_tmp73_ = vala_declaration_statement_new ((ValaSymbol*) _tmp70_, _tmp72_);
		decl = _tmp73_;
		_tmp74_ = vala_code_context_get_analyzer (context);
		_tmp75_ = _tmp74_;
		_tmp76_ = _tmp75_->insert_block;
		_tmp77_ = decl;
		vala_expression_insert_statement ((ValaExpression*) self, _tmp76_, (ValaStatement*) _tmp77_);
		_tmp78_ = local;
		_tmp79_ = vala_expression_get_target_type ((ValaExpression*) self);
		_tmp80_ = _tmp79_;
		_tmp81_ = vala_semantic_analyzer_create_temp_access (_tmp78_, _tmp80_);
		temp_access = _tmp81_;
		_tmp82_ = temp_access;
		_tmp83_ = vala_expression_get_formal_target_type ((ValaExpression*) self);
		_tmp84_ = _tmp83_;
		vala_expression_set_formal_target_type (_tmp82_, _tmp84_);
		_tmp85_ = local;
		_tmp86_ = vala_cast_expression_get_inner (self);
		_tmp87_ = _tmp86_;
		vala_variable_set_initializer ((ValaVariable*) _tmp85_, _tmp87_);
		_tmp88_ = decl;
		vala_code_node_check ((ValaCodeNode*) _tmp88_, context);
		_tmp89_ = vala_code_context_get_analyzer (context);
		_tmp90_ = _tmp89_;
		_tmp91_ = _tmp90_->replaced_nodes;
		vala_collection_add ((ValaCollection*) _tmp91_, (ValaCodeNode*) self);
		_tmp92_ = vala_code_node_get_parent_node ((ValaCodeNode*) self);
		_tmp93_ = _tmp92_;
		_tmp94_ = temp_access;
		vala_code_node_replace_expression (_tmp93_, (ValaExpression*) self, _tmp94_);
		_tmp95_ = temp_access;
		result = vala_code_node_check ((ValaCodeNode*) _tmp95_, context);
		_vala_code_node_unref0 (temp_access);
		_vala_code_node_unref0 (decl);
		_vala_code_node_unref0 (local);
		return result;
	}
	_tmp96_ = vala_cast_expression_get_type_reference (self);
	_tmp97_ = _tmp96_;
	vala_expression_set_value_type ((ValaExpression*) self, _tmp97_);
	_tmp98_ = vala_expression_get_value_type ((ValaExpression*) self);
	_tmp99_ = _tmp98_;
	_tmp100_ = vala_cast_expression_get_inner (self);
	_tmp101_ = _tmp100_;
	_tmp102_ = vala_expression_get_value_type (_tmp101_);
	_tmp103_ = _tmp102_;
	_tmp104_ = vala_data_type_get_value_owned (_tmp103_);
	_tmp105_ = _tmp104_;
	vala_data_type_set_value_owned (_tmp99_, _tmp105_);
	_tmp106_ = vala_expression_get_value_type ((ValaExpression*) self);
	_tmp107_ = _tmp106_;
	_tmp108_ = vala_cast_expression_get_inner (self);
	_tmp109_ = _tmp108_;
	_tmp110_ = vala_expression_get_value_type (_tmp109_);
	_tmp111_ = _tmp110_;
	_tmp112_ = vala_data_type_get_floating_reference (_tmp111_);
	_tmp113_ = _tmp112_;
	vala_data_type_set_floating_reference (_tmp107_, _tmp113_);
	_tmp114_ = self->priv->_is_silent_cast;
	if (_tmp114_) {
		ValaDataType* _tmp115_;
		ValaDataType* _tmp116_;
		_tmp115_ = vala_expression_get_value_type ((ValaExpression*) self);
		_tmp116_ = _tmp115_;
		vala_data_type_set_nullable (_tmp116_, TRUE);
	}
	_tmp119_ = vala_code_context_get_profile (context);
	_tmp120_ = _tmp119_;
	if (_tmp120_ == BALA_PROFILE_GOBJECT) {
		ValaExpression* _tmp121_;
		ValaExpression* _tmp122_;
		ValaDataType* _tmp123_;
		ValaDataType* _tmp124_;
		_tmp121_ = vala_cast_expression_get_inner (self);
		_tmp122_ = _tmp121_;
		_tmp123_ = vala_expression_get_value_type (_tmp122_);
		_tmp124_ = _tmp123_;
		_tmp118_ = vala_cast_expression_is_gvariant (self, context, _tmp124_);
	} else {
		_tmp118_ = FALSE;
	}
	if (_tmp118_) {
		ValaDataType* _tmp125_;
		ValaDataType* _tmp126_;
		_tmp125_ = vala_expression_get_value_type ((ValaExpression*) self);
		_tmp126_ = _tmp125_;
		_tmp117_ = !vala_cast_expression_is_gvariant (self, context, _tmp126_);
	} else {
		_tmp117_ = FALSE;
	}
	if (_tmp117_) {
		ValaDataType* _tmp127_;
		ValaDataType* _tmp128_;
		ValaDataType* _tmp129_;
		ValaDataType* _tmp130_;
		gchar* _tmp131_;
		gchar* _tmp132_;
		gboolean _tmp133_;
		_tmp127_ = vala_expression_get_value_type ((ValaExpression*) self);
		_tmp128_ = _tmp127_;
		vala_data_type_set_value_owned (_tmp128_, TRUE);
		_tmp129_ = vala_expression_get_value_type ((ValaExpression*) self);
		_tmp130_ = _tmp129_;
		_tmp131_ = vala_data_type_get_type_signature (_tmp130_, NULL);
		_tmp132_ = _tmp131_;
		_tmp133_ = _tmp132_ == NULL;
		_g_free0 (_tmp132_);
		if (_tmp133_) {
			ValaSourceReference* _tmp134_;
			ValaSourceReference* _tmp135_;
			ValaDataType* _tmp136_;
			ValaDataType* _tmp137_;
			gchar* _tmp138_;
			gchar* _tmp139_;
			gchar* _tmp140_;
			gchar* _tmp141_;
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			_tmp134_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp135_ = _tmp134_;
			_tmp136_ = vala_expression_get_value_type ((ValaExpression*) self);
			_tmp137_ = _tmp136_;
			_tmp138_ = vala_data_type_to_qualified_string (_tmp137_, NULL);
			_tmp139_ = _tmp138_;
			_tmp140_ = g_strdup_printf ("Casting of `GLib.Variant' to `%s' is not supported", _tmp139_);
			_tmp141_ = _tmp140_;
			vala_report_error (_tmp135_, _tmp141_);
			_g_free0 (_tmp141_);
			_g_free0 (_tmp139_);
		}
	}
	_tmp144_ = vala_code_context_get_profile (context);
	_tmp145_ = _tmp144_;
	if (_tmp145_ == BALA_PROFILE_GOBJECT) {
		ValaExpression* _tmp146_;
		ValaExpression* _tmp147_;
		ValaDataType* _tmp148_;
		ValaDataType* _tmp149_;
		_tmp146_ = vala_cast_expression_get_inner (self);
		_tmp147_ = _tmp146_;
		_tmp148_ = vala_expression_get_value_type (_tmp147_);
		_tmp149_ = _tmp148_;
		_tmp143_ = vala_cast_expression_is_gvalue (self, context, _tmp149_);
	} else {
		_tmp143_ = FALSE;
	}
	if (_tmp143_) {
		ValaDataType* _tmp150_;
		ValaDataType* _tmp151_;
		_tmp150_ = vala_expression_get_value_type ((ValaExpression*) self);
		_tmp151_ = _tmp150_;
		_tmp142_ = !vala_cast_expression_is_gvalue (self, context, _tmp151_);
	} else {
		_tmp142_ = FALSE;
	}
	if (_tmp142_) {
		ValaDataType* _tmp152_;
		ValaDataType* _tmp153_;
		gboolean _tmp154_ = FALSE;
		gboolean _tmp155_ = FALSE;
		ValaDataType* _tmp156_;
		ValaDataType* _tmp157_;
		gboolean _tmp158_;
		gboolean _tmp159_;
		_tmp152_ = vala_expression_get_value_type ((ValaExpression*) self);
		_tmp153_ = _tmp152_;
		vala_data_type_set_value_owned (_tmp153_, FALSE);
		_tmp156_ = vala_expression_get_value_type ((ValaExpression*) self);
		_tmp157_ = _tmp156_;
		_tmp158_ = vala_data_type_get_nullable (_tmp157_);
		_tmp159_ = _tmp158_;
		if (_tmp159_) {
			ValaDataType* _tmp160_;
			ValaDataType* _tmp161_;
			ValaTypeSymbol* _tmp162_;
			ValaTypeSymbol* _tmp163_;
			_tmp160_ = vala_expression_get_value_type ((ValaExpression*) self);
			_tmp161_ = _tmp160_;
			_tmp162_ = vala_data_type_get_type_symbol (_tmp161_);
			_tmp163_ = _tmp162_;
			_tmp155_ = _tmp163_ != NULL;
		} else {
			_tmp155_ = FALSE;
		}
		if (_tmp155_) {
			ValaDataType* _tmp164_;
			ValaDataType* _tmp165_;
			ValaTypeSymbol* _tmp166_;
			ValaTypeSymbol* _tmp167_;
			_tmp164_ = vala_expression_get_value_type ((ValaExpression*) self);
			_tmp165_ = _tmp164_;
			_tmp166_ = vala_data_type_get_type_symbol (_tmp165_);
			_tmp167_ = _tmp166_;
			_tmp154_ = !vala_typesymbol_is_reference_type (_tmp167_);
		} else {
			_tmp154_ = FALSE;
		}
		if (_tmp154_) {
			ValaSourceReference* _tmp168_;
			ValaSourceReference* _tmp169_;
			ValaDataType* _tmp170_;
			ValaDataType* _tmp171_;
			gchar* _tmp172_;
			gchar* _tmp173_;
			gchar* _tmp174_;
			gchar* _tmp175_;
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			_tmp168_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp169_ = _tmp168_;
			_tmp170_ = vala_expression_get_value_type ((ValaExpression*) self);
			_tmp171_ = _tmp170_;
			_tmp172_ = vala_data_type_to_qualified_string (_tmp171_, NULL);
			_tmp173_ = _tmp172_;
			_tmp174_ = g_strdup_printf ("Casting of `GLib.Value' to `%s' is not supported", _tmp173_);
			_tmp175_ = _tmp174_;
			vala_report_error (_tmp169_, _tmp175_);
			_g_free0 (_tmp175_);
			_g_free0 (_tmp173_);
		}
	}
	_tmp176_ = vala_cast_expression_get_inner (self);
	_tmp177_ = _tmp176_;
	_tmp178_ = vala_cast_expression_get_inner (self);
	_tmp179_ = _tmp178_;
	_tmp180_ = vala_expression_get_value_type (_tmp179_);
	_tmp181_ = _tmp180_;
	_tmp182_ = vala_data_type_copy (_tmp181_);
	_tmp183_ = _tmp182_;
	vala_expression_set_target_type (_tmp177_, _tmp183_);
	_vala_code_node_unref0 (_tmp183_);
	_tmp184_ = vala_code_node_get_error ((ValaCodeNode*) self);
	_tmp185_ = _tmp184_;
	result = !_tmp185_;
	return result;
}

static gboolean
vala_cast_expression_is_gvariant (ValaCastExpression* self,
                                  ValaCodeContext* context,
                                  ValaDataType* type)
{
	gboolean _tmp0_ = FALSE;
	ValaTypeSymbol* _tmp1_;
	ValaTypeSymbol* _tmp2_;
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (context != NULL, FALSE);
	g_return_val_if_fail (type != NULL, FALSE);
	_tmp1_ = vala_data_type_get_type_symbol (type);
	_tmp2_ = _tmp1_;
	if (_tmp2_ != NULL) {
		ValaTypeSymbol* _tmp3_;
		ValaTypeSymbol* _tmp4_;
		ValaSemanticAnalyzer* _tmp5_;
		ValaSemanticAnalyzer* _tmp6_;
		ValaObjectType* _tmp7_;
		ValaTypeSymbol* _tmp8_;
		ValaTypeSymbol* _tmp9_;
		_tmp3_ = vala_data_type_get_type_symbol (type);
		_tmp4_ = _tmp3_;
		_tmp5_ = vala_code_context_get_analyzer (context);
		_tmp6_ = _tmp5_;
		_tmp7_ = _tmp6_->gvariant_type;
		_tmp8_ = vala_data_type_get_type_symbol ((ValaDataType*) _tmp7_);
		_tmp9_ = _tmp8_;
		_tmp0_ = vala_typesymbol_is_subtype_of (_tmp4_, _tmp9_);
	} else {
		_tmp0_ = FALSE;
	}
	result = _tmp0_;
	return result;
}

static gboolean
vala_cast_expression_is_gvalue (ValaCastExpression* self,
                                ValaCodeContext* context,
                                ValaDataType* type)
{
	gboolean _tmp0_ = FALSE;
	ValaTypeSymbol* _tmp1_;
	ValaTypeSymbol* _tmp2_;
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (context != NULL, FALSE);
	g_return_val_if_fail (type != NULL, FALSE);
	_tmp1_ = vala_data_type_get_type_symbol (type);
	_tmp2_ = _tmp1_;
	if (_tmp2_ != NULL) {
		ValaTypeSymbol* _tmp3_;
		ValaTypeSymbol* _tmp4_;
		ValaSemanticAnalyzer* _tmp5_;
		ValaSemanticAnalyzer* _tmp6_;
		ValaStructValueType* _tmp7_;
		ValaTypeSymbol* _tmp8_;
		ValaTypeSymbol* _tmp9_;
		_tmp3_ = vala_data_type_get_type_symbol (type);
		_tmp4_ = _tmp3_;
		_tmp5_ = vala_code_context_get_analyzer (context);
		_tmp6_ = _tmp5_;
		_tmp7_ = _tmp6_->gvalue_type;
		_tmp8_ = vala_data_type_get_type_symbol ((ValaDataType*) _tmp7_);
		_tmp9_ = _tmp8_;
		_tmp0_ = vala_typesymbol_is_subtype_of (_tmp4_, _tmp9_);
	} else {
		_tmp0_ = FALSE;
	}
	result = _tmp0_;
	return result;
}

static void
vala_cast_expression_real_emit (ValaCodeNode* base,
                                ValaCodeGenerator* codegen)
{
	ValaCastExpression * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaCastExpression*) base;
	g_return_if_fail (codegen != NULL);
	_tmp0_ = vala_cast_expression_get_inner (self);
	_tmp1_ = _tmp0_;
	vala_code_node_emit ((ValaCodeNode*) _tmp1_, codegen);
	vala_code_visitor_visit_cast_expression ((ValaCodeVisitor*) codegen, self);
	vala_code_visitor_visit_expression ((ValaCodeVisitor*) codegen, (ValaExpression*) self);
}

static void
vala_cast_expression_real_get_defined_variables (ValaCodeNode* base,
                                                 ValaCollection* collection)
{
	ValaCastExpression * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaCastExpression*) base;
	g_return_if_fail (collection != NULL);
	_tmp0_ = vala_cast_expression_get_inner (self);
	_tmp1_ = _tmp0_;
	vala_code_node_get_defined_variables ((ValaCodeNode*) _tmp1_, collection);
}

static void
vala_cast_expression_real_get_used_variables (ValaCodeNode* base,
                                              ValaCollection* collection)
{
	ValaCastExpression * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaCastExpression*) base;
	g_return_if_fail (collection != NULL);
	_tmp0_ = vala_cast_expression_get_inner (self);
	_tmp1_ = _tmp0_;
	vala_code_node_get_used_variables ((ValaCodeNode*) _tmp1_, collection);
}

static gboolean
vala_cast_expression_real_is_constant (ValaExpression* base)
{
	ValaCastExpression * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	gboolean result = FALSE;
	self = (ValaCastExpression*) base;
	_tmp0_ = vala_cast_expression_get_inner (self);
	_tmp1_ = _tmp0_;
	result = vala_expression_is_constant (_tmp1_);
	return result;
}

static void
vala_cast_expression_class_init (ValaCastExpressionClass * klass,
                                 gpointer klass_data)
{
	vala_cast_expression_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_cast_expression_finalize;
	g_type_class_adjust_private_offset (klass, &ValaCastExpression_private_offset);
	((ValaCodeNodeClass *) klass)->accept = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_cast_expression_real_accept;
	((ValaCodeNodeClass *) klass)->accept_children = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_cast_expression_real_accept_children;
	((ValaCodeNodeClass *) klass)->to_string = (gchar* (*) (ValaCodeNode*)) vala_cast_expression_real_to_string;
	((ValaCodeNodeClass *) klass)->replace_expression = (void (*) (ValaCodeNode*, ValaExpression*, ValaExpression*)) vala_cast_expression_real_replace_expression;
	((ValaExpressionClass *) klass)->is_pure = (gboolean (*) (ValaExpression*)) vala_cast_expression_real_is_pure;
	((ValaExpressionClass *) klass)->is_accessible = (gboolean (*) (ValaExpression*, ValaSymbol*)) vala_cast_expression_real_is_accessible;
	((ValaCodeNodeClass *) klass)->replace_type = (void (*) (ValaCodeNode*, ValaDataType*, ValaDataType*)) vala_cast_expression_real_replace_type;
	((ValaCodeNodeClass *) klass)->get_error_types = (void (*) (ValaCodeNode*, ValaCollection*, ValaSourceReference*)) vala_cast_expression_real_get_error_types;
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) vala_cast_expression_real_check;
	((ValaCodeNodeClass *) klass)->emit = (void (*) (ValaCodeNode*, ValaCodeGenerator*)) vala_cast_expression_real_emit;
	((ValaCodeNodeClass *) klass)->get_defined_variables = (void (*) (ValaCodeNode*, ValaCollection*)) vala_cast_expression_real_get_defined_variables;
	((ValaCodeNodeClass *) klass)->get_used_variables = (void (*) (ValaCodeNode*, ValaCollection*)) vala_cast_expression_real_get_used_variables;
	((ValaExpressionClass *) klass)->is_constant = (gboolean (*) (ValaExpression*)) vala_cast_expression_real_is_constant;
}

static void
vala_cast_expression_instance_init (ValaCastExpression * self,
                                    gpointer klass)
{
	self->priv = vala_cast_expression_get_instance_private (self);
}

static void
vala_cast_expression_finalize (ValaCodeNode * obj)
{
	ValaCastExpression * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_CAST_EXPRESSION, ValaCastExpression);
	_vala_code_node_unref0 (self->priv->_inner);
	_vala_code_node_unref0 (self->priv->_data_type);
	BALA_CODE_NODE_CLASS (vala_cast_expression_parent_class)->finalize (obj);
}

/**
 * Represents a type cast in the source code.
 */
static GType
vala_cast_expression_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaCastExpressionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_cast_expression_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaCastExpression), 0, (GInstanceInitFunc) vala_cast_expression_instance_init, NULL };
	GType vala_cast_expression_type_id;
	vala_cast_expression_type_id = g_type_register_static (BALA_TYPE_EXPRESSION, "ValaCastExpression", &g_define_type_info, 0);
	ValaCastExpression_private_offset = g_type_add_instance_private (vala_cast_expression_type_id, sizeof (ValaCastExpressionPrivate));
	return vala_cast_expression_type_id;
}

GType
vala_cast_expression_get_type (void)
{
	static volatile gsize vala_cast_expression_type_id__volatile = 0;
	if (g_once_init_enter (&vala_cast_expression_type_id__volatile)) {
		GType vala_cast_expression_type_id;
		vala_cast_expression_type_id = vala_cast_expression_get_type_once ();
		g_once_init_leave (&vala_cast_expression_type_id__volatile, vala_cast_expression_type_id);
	}
	return vala_cast_expression_type_id__volatile;
}

