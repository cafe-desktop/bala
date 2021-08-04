/* valapointerindirection.c generated by valac, the Vala compiler
 * generated from valapointerindirection.vala, do not modify */

/* valapointerindirection.vala
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
#include <stdlib.h>
#include <string.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _ValaPointerIndirectionPrivate {
	ValaExpression* _inner;
};

static gint ValaPointerIndirection_private_offset;
static gpointer vala_pointer_indirection_parent_class = NULL;

static void vala_pointer_indirection_real_accept (ValaCodeNode* base,
                                           ValaCodeVisitor* visitor);
static void vala_pointer_indirection_real_replace_expression (ValaCodeNode* base,
                                                       ValaExpression* old_node,
                                                       ValaExpression* new_node);
static gboolean vala_pointer_indirection_real_is_pure (ValaExpression* base);
static gboolean vala_pointer_indirection_real_is_accessible (ValaExpression* base,
                                                      ValaSymbol* sym);
static void vala_pointer_indirection_real_get_error_types (ValaCodeNode* base,
                                                    ValaCollection* collection,
                                                    ValaSourceReference* source_reference);
static gboolean vala_pointer_indirection_real_check (ValaCodeNode* base,
                                              ValaCodeContext* context);
static void vala_pointer_indirection_real_emit (ValaCodeNode* base,
                                         ValaCodeGenerator* codegen);
static void vala_pointer_indirection_real_get_defined_variables (ValaCodeNode* base,
                                                          ValaCollection* collection);
static void vala_pointer_indirection_real_get_used_variables (ValaCodeNode* base,
                                                       ValaCollection* collection);
static gchar* vala_pointer_indirection_real_to_string (ValaCodeNode* base);
static void vala_pointer_indirection_finalize (ValaCodeNode * obj);
static GType vala_pointer_indirection_get_type_once (void);

static inline gpointer
vala_pointer_indirection_get_instance_private (ValaPointerIndirection* self)
{
	return G_STRUCT_MEMBER_P (self, ValaPointerIndirection_private_offset);
}

ValaExpression*
vala_pointer_indirection_get_inner (ValaPointerIndirection* self)
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
vala_pointer_indirection_set_inner (ValaPointerIndirection* self,
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

/**
 * Creates a new pointer indirection.
 *
 * @param inner pointer to be dereferenced
 * @return      newly created pointer indirection
 */
ValaPointerIndirection*
vala_pointer_indirection_construct (GType object_type,
                                    ValaExpression* inner,
                                    ValaSourceReference* source_reference)
{
	ValaPointerIndirection* self = NULL;
	g_return_val_if_fail (inner != NULL, NULL);
	self = (ValaPointerIndirection*) vala_expression_construct (object_type);
	vala_code_node_set_source_reference ((ValaCodeNode*) self, source_reference);
	vala_pointer_indirection_set_inner (self, inner);
	return self;
}

ValaPointerIndirection*
vala_pointer_indirection_new (ValaExpression* inner,
                              ValaSourceReference* source_reference)
{
	return vala_pointer_indirection_construct (VALA_TYPE_POINTER_INDIRECTION, inner, source_reference);
}

static void
vala_pointer_indirection_real_accept (ValaCodeNode* base,
                                      ValaCodeVisitor* visitor)
{
	ValaPointerIndirection * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaPointerIndirection*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = vala_pointer_indirection_get_inner (self);
	_tmp1_ = _tmp0_;
	vala_code_node_accept ((ValaCodeNode*) _tmp1_, visitor);
	vala_code_visitor_visit_pointer_indirection (visitor, self);
	vala_code_visitor_visit_expression (visitor, (ValaExpression*) self);
}

static void
vala_pointer_indirection_real_replace_expression (ValaCodeNode* base,
                                                  ValaExpression* old_node,
                                                  ValaExpression* new_node)
{
	ValaPointerIndirection * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaPointerIndirection*) base;
	g_return_if_fail (old_node != NULL);
	g_return_if_fail (new_node != NULL);
	_tmp0_ = vala_pointer_indirection_get_inner (self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ == old_node) {
		vala_pointer_indirection_set_inner (self, new_node);
	}
}

static gboolean
vala_pointer_indirection_real_is_pure (ValaExpression* base)
{
	ValaPointerIndirection * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	gboolean result = FALSE;
	self = (ValaPointerIndirection*) base;
	_tmp0_ = vala_pointer_indirection_get_inner (self);
	_tmp1_ = _tmp0_;
	result = vala_expression_is_pure (_tmp1_);
	return result;
}

static gboolean
vala_pointer_indirection_real_is_accessible (ValaExpression* base,
                                             ValaSymbol* sym)
{
	ValaPointerIndirection * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	gboolean result = FALSE;
	self = (ValaPointerIndirection*) base;
	g_return_val_if_fail (sym != NULL, FALSE);
	_tmp0_ = vala_pointer_indirection_get_inner (self);
	_tmp1_ = _tmp0_;
	result = vala_expression_is_accessible (_tmp1_, sym);
	return result;
}

static void
vala_pointer_indirection_real_get_error_types (ValaCodeNode* base,
                                               ValaCollection* collection,
                                               ValaSourceReference* source_reference)
{
	ValaPointerIndirection * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaPointerIndirection*) base;
	g_return_if_fail (collection != NULL);
	_tmp0_ = vala_pointer_indirection_get_inner (self);
	_tmp1_ = _tmp0_;
	vala_code_node_get_error_types ((ValaCodeNode*) _tmp1_, collection, source_reference);
}

static gboolean
vala_pointer_indirection_real_check (ValaCodeNode* base,
                                     ValaCodeContext* context)
{
	ValaPointerIndirection * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	ValaExpression* _tmp4_;
	ValaExpression* _tmp5_;
	ValaExpression* _tmp6_;
	ValaExpression* _tmp7_;
	ValaDataType* _tmp8_;
	ValaDataType* _tmp9_;
	ValaExpression* _tmp12_;
	ValaExpression* _tmp13_;
	ValaDataType* _tmp14_;
	ValaDataType* _tmp15_;
	gboolean _tmp37_;
	gboolean _tmp38_;
	gboolean result = FALSE;
	self = (ValaPointerIndirection*) base;
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
	_tmp4_ = vala_pointer_indirection_get_inner (self);
	_tmp5_ = _tmp4_;
	if (!vala_code_node_check ((ValaCodeNode*) _tmp5_, context)) {
		result = FALSE;
		return result;
	}
	_tmp6_ = vala_pointer_indirection_get_inner (self);
	_tmp7_ = _tmp6_;
	_tmp8_ = vala_expression_get_value_type (_tmp7_);
	_tmp9_ = _tmp8_;
	if (_tmp9_ == NULL) {
		ValaSourceReference* _tmp10_;
		ValaSourceReference* _tmp11_;
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		_tmp10_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp11_ = _tmp10_;
		vala_report_error (_tmp11_, "internal error: unknown type of inner expression");
		result = FALSE;
		return result;
	}
	_tmp12_ = vala_pointer_indirection_get_inner (self);
	_tmp13_ = _tmp12_;
	_tmp14_ = vala_expression_get_value_type (_tmp13_);
	_tmp15_ = _tmp14_;
	if (VALA_IS_POINTER_TYPE (_tmp15_)) {
		ValaPointerType* pointer_type = NULL;
		ValaExpression* _tmp16_;
		ValaExpression* _tmp17_;
		ValaDataType* _tmp18_;
		ValaDataType* _tmp19_;
		ValaPointerType* _tmp20_;
		gboolean _tmp21_ = FALSE;
		ValaPointerType* _tmp22_;
		ValaDataType* _tmp23_;
		ValaDataType* _tmp24_;
		ValaPointerType* _tmp30_;
		ValaDataType* _tmp31_;
		ValaDataType* _tmp32_;
		ValaDataType* _tmp33_;
		ValaDataType* _tmp34_;
		_tmp16_ = vala_pointer_indirection_get_inner (self);
		_tmp17_ = _tmp16_;
		_tmp18_ = vala_expression_get_value_type (_tmp17_);
		_tmp19_ = _tmp18_;
		_tmp20_ = _vala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp19_, VALA_TYPE_POINTER_TYPE, ValaPointerType));
		pointer_type = _tmp20_;
		_tmp22_ = pointer_type;
		_tmp23_ = vala_pointer_type_get_base_type (_tmp22_);
		_tmp24_ = _tmp23_;
		if (VALA_IS_REFERENCE_TYPE (_tmp24_)) {
			_tmp21_ = TRUE;
		} else {
			ValaPointerType* _tmp25_;
			ValaDataType* _tmp26_;
			ValaDataType* _tmp27_;
			_tmp25_ = pointer_type;
			_tmp26_ = vala_pointer_type_get_base_type (_tmp25_);
			_tmp27_ = _tmp26_;
			_tmp21_ = VALA_IS_VOID_TYPE (_tmp27_);
		}
		if (_tmp21_) {
			ValaSourceReference* _tmp28_;
			ValaSourceReference* _tmp29_;
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			_tmp28_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp29_ = _tmp28_;
			vala_report_error (_tmp29_, "Pointer indirection not supported for this expression");
			result = FALSE;
			_vala_code_node_unref0 (pointer_type);
			return result;
		}
		_tmp30_ = pointer_type;
		_tmp31_ = vala_pointer_type_get_base_type (_tmp30_);
		_tmp32_ = _tmp31_;
		vala_expression_set_value_type ((ValaExpression*) self, _tmp32_);
		_tmp33_ = vala_expression_get_value_type ((ValaExpression*) self);
		_tmp34_ = _tmp33_;
		vala_data_type_set_value_owned (_tmp34_, FALSE);
		_vala_code_node_unref0 (pointer_type);
	} else {
		ValaSourceReference* _tmp35_;
		ValaSourceReference* _tmp36_;
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		_tmp35_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp36_ = _tmp35_;
		vala_report_error (_tmp36_, "Pointer indirection not supported for this expression");
		result = FALSE;
		return result;
	}
	_tmp37_ = vala_code_node_get_error ((ValaCodeNode*) self);
	_tmp38_ = _tmp37_;
	result = !_tmp38_;
	return result;
}

static void
vala_pointer_indirection_real_emit (ValaCodeNode* base,
                                    ValaCodeGenerator* codegen)
{
	ValaPointerIndirection * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaPointerIndirection*) base;
	g_return_if_fail (codegen != NULL);
	_tmp0_ = vala_pointer_indirection_get_inner (self);
	_tmp1_ = _tmp0_;
	vala_code_node_emit ((ValaCodeNode*) _tmp1_, codegen);
	vala_code_visitor_visit_pointer_indirection ((ValaCodeVisitor*) codegen, self);
	vala_code_visitor_visit_expression ((ValaCodeVisitor*) codegen, (ValaExpression*) self);
}

static void
vala_pointer_indirection_real_get_defined_variables (ValaCodeNode* base,
                                                     ValaCollection* collection)
{
	ValaPointerIndirection * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaPointerIndirection*) base;
	g_return_if_fail (collection != NULL);
	_tmp0_ = vala_pointer_indirection_get_inner (self);
	_tmp1_ = _tmp0_;
	vala_code_node_get_defined_variables ((ValaCodeNode*) _tmp1_, collection);
}

static void
vala_pointer_indirection_real_get_used_variables (ValaCodeNode* base,
                                                  ValaCollection* collection)
{
	ValaPointerIndirection * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaPointerIndirection*) base;
	g_return_if_fail (collection != NULL);
	_tmp0_ = vala_pointer_indirection_get_inner (self);
	_tmp1_ = _tmp0_;
	vala_code_node_get_used_variables ((ValaCodeNode*) _tmp1_, collection);
}

static gchar*
vala_pointer_indirection_real_to_string (ValaCodeNode* base)
{
	ValaPointerIndirection * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* result = NULL;
	self = (ValaPointerIndirection*) base;
	_tmp0_ = vala_pointer_indirection_get_inner (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = vala_code_node_to_string ((ValaCodeNode*) _tmp1_);
	_tmp3_ = _tmp2_;
	_tmp4_ = g_strdup_printf ("(*%s)", _tmp3_);
	_tmp5_ = _tmp4_;
	_g_free0 (_tmp3_);
	result = _tmp5_;
	return result;
}

static void
vala_pointer_indirection_class_init (ValaPointerIndirectionClass * klass,
                                     gpointer klass_data)
{
	vala_pointer_indirection_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_pointer_indirection_finalize;
	g_type_class_adjust_private_offset (klass, &ValaPointerIndirection_private_offset);
	((ValaCodeNodeClass *) klass)->accept = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_pointer_indirection_real_accept;
	((ValaCodeNodeClass *) klass)->replace_expression = (void (*) (ValaCodeNode*, ValaExpression*, ValaExpression*)) vala_pointer_indirection_real_replace_expression;
	((ValaExpressionClass *) klass)->is_pure = (gboolean (*) (ValaExpression*)) vala_pointer_indirection_real_is_pure;
	((ValaExpressionClass *) klass)->is_accessible = (gboolean (*) (ValaExpression*, ValaSymbol*)) vala_pointer_indirection_real_is_accessible;
	((ValaCodeNodeClass *) klass)->get_error_types = (void (*) (ValaCodeNode*, ValaCollection*, ValaSourceReference*)) vala_pointer_indirection_real_get_error_types;
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) vala_pointer_indirection_real_check;
	((ValaCodeNodeClass *) klass)->emit = (void (*) (ValaCodeNode*, ValaCodeGenerator*)) vala_pointer_indirection_real_emit;
	((ValaCodeNodeClass *) klass)->get_defined_variables = (void (*) (ValaCodeNode*, ValaCollection*)) vala_pointer_indirection_real_get_defined_variables;
	((ValaCodeNodeClass *) klass)->get_used_variables = (void (*) (ValaCodeNode*, ValaCollection*)) vala_pointer_indirection_real_get_used_variables;
	((ValaCodeNodeClass *) klass)->to_string = (gchar* (*) (ValaCodeNode*)) vala_pointer_indirection_real_to_string;
}

static void
vala_pointer_indirection_instance_init (ValaPointerIndirection * self,
                                        gpointer klass)
{
	self->priv = vala_pointer_indirection_get_instance_private (self);
}

static void
vala_pointer_indirection_finalize (ValaCodeNode * obj)
{
	ValaPointerIndirection * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_POINTER_INDIRECTION, ValaPointerIndirection);
	_vala_code_node_unref0 (self->priv->_inner);
	VALA_CODE_NODE_CLASS (vala_pointer_indirection_parent_class)->finalize (obj);
}

/**
 * Represents a pointer indirection.
 *
 * {{{ *foo }}}
 */
static GType
vala_pointer_indirection_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaPointerIndirectionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_pointer_indirection_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaPointerIndirection), 0, (GInstanceInitFunc) vala_pointer_indirection_instance_init, NULL };
	GType vala_pointer_indirection_type_id;
	vala_pointer_indirection_type_id = g_type_register_static (VALA_TYPE_EXPRESSION, "ValaPointerIndirection", &g_define_type_info, 0);
	ValaPointerIndirection_private_offset = g_type_add_instance_private (vala_pointer_indirection_type_id, sizeof (ValaPointerIndirectionPrivate));
	return vala_pointer_indirection_type_id;
}

GType
vala_pointer_indirection_get_type (void)
{
	static volatile gsize vala_pointer_indirection_type_id__volatile = 0;
	if (g_once_init_enter (&vala_pointer_indirection_type_id__volatile)) {
		GType vala_pointer_indirection_type_id;
		vala_pointer_indirection_type_id = vala_pointer_indirection_get_type_once ();
		g_once_init_leave (&vala_pointer_indirection_type_id__volatile, vala_pointer_indirection_type_id);
	}
	return vala_pointer_indirection_type_id__volatile;
}
