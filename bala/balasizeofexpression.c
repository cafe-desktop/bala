/* balasizeofexpression.c generated by balac, the Bala compiler
 * generated from balasizeofexpression.bala, do not modify */

/* balasizeofexpression.bala
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

#include "bala.h"
#include <glib.h>

#define _bala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (bala_code_node_unref (var), NULL)))

struct _BalaSizeofExpressionPrivate {
	BalaDataType* _data_type;
};

static gint BalaSizeofExpression_private_offset;
static gpointer bala_sizeof_expression_parent_class = NULL;

static void bala_sizeof_expression_real_accept (BalaCodeNode* base,
                                         BalaCodeVisitor* visitor);
static void bala_sizeof_expression_real_accept_children (BalaCodeNode* base,
                                                  BalaCodeVisitor* visitor);
static gboolean bala_sizeof_expression_real_is_pure (BalaExpression* base);
static gboolean bala_sizeof_expression_real_is_constant (BalaExpression* base);
static void bala_sizeof_expression_real_replace_type (BalaCodeNode* base,
                                               BalaDataType* old_type,
                                               BalaDataType* new_type);
static gboolean bala_sizeof_expression_real_check (BalaCodeNode* base,
                                            BalaCodeContext* context);
static void bala_sizeof_expression_real_emit (BalaCodeNode* base,
                                       BalaCodeGenerator* codegen);
static void bala_sizeof_expression_finalize (BalaCodeNode * obj);
static GType bala_sizeof_expression_get_type_once (void);

static inline gpointer
bala_sizeof_expression_get_instance_private (BalaSizeofExpression* self)
{
	return G_STRUCT_MEMBER_P (self, BalaSizeofExpression_private_offset);
}

BalaDataType*
bala_sizeof_expression_get_type_reference (BalaSizeofExpression* self)
{
	BalaDataType* result;
	BalaDataType* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_data_type;
	result = _tmp0_;
	return result;
}

static gpointer
_bala_code_node_ref0 (gpointer self)
{
	return self ? bala_code_node_ref (self) : NULL;
}

void
bala_sizeof_expression_set_type_reference (BalaSizeofExpression* self,
                                           BalaDataType* value)
{
	BalaDataType* _tmp0_;
	BalaDataType* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _bala_code_node_ref0 (value);
	_bala_code_node_unref0 (self->priv->_data_type);
	self->priv->_data_type = _tmp0_;
	_tmp1_ = self->priv->_data_type;
	bala_code_node_set_parent_node ((BalaCodeNode*) _tmp1_, (BalaCodeNode*) self);
}

/**
 * Creates a new sizeof expression.
 *
 * @param type   a data type
 * @param source reference to source code
 * @return       newly created sizeof expression
 */
BalaSizeofExpression*
bala_sizeof_expression_construct (GType object_type,
                                  BalaDataType* type,
                                  BalaSourceReference* source)
{
	BalaSizeofExpression* self = NULL;
	g_return_val_if_fail (type != NULL, NULL);
	self = (BalaSizeofExpression*) bala_expression_construct (object_type);
	bala_sizeof_expression_set_type_reference (self, type);
	bala_code_node_set_source_reference ((BalaCodeNode*) self, source);
	return self;
}

BalaSizeofExpression*
bala_sizeof_expression_new (BalaDataType* type,
                            BalaSourceReference* source)
{
	return bala_sizeof_expression_construct (BALA_TYPE_SIZEOF_EXPRESSION, type, source);
}

static void
bala_sizeof_expression_real_accept (BalaCodeNode* base,
                                    BalaCodeVisitor* visitor)
{
	BalaSizeofExpression * self;
	self = (BalaSizeofExpression*) base;
	g_return_if_fail (visitor != NULL);
	bala_code_visitor_visit_sizeof_expression (visitor, self);
	bala_code_visitor_visit_expression (visitor, (BalaExpression*) self);
}

static void
bala_sizeof_expression_real_accept_children (BalaCodeNode* base,
                                             BalaCodeVisitor* visitor)
{
	BalaSizeofExpression * self;
	BalaDataType* _tmp0_;
	BalaDataType* _tmp1_;
	self = (BalaSizeofExpression*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = bala_sizeof_expression_get_type_reference (self);
	_tmp1_ = _tmp0_;
	bala_code_node_accept ((BalaCodeNode*) _tmp1_, visitor);
}

static gboolean
bala_sizeof_expression_real_is_pure (BalaExpression* base)
{
	BalaSizeofExpression * self;
	gboolean result = FALSE;
	self = (BalaSizeofExpression*) base;
	result = TRUE;
	return result;
}

static gboolean
bala_sizeof_expression_real_is_constant (BalaExpression* base)
{
	BalaSizeofExpression * self;
	gboolean result = FALSE;
	self = (BalaSizeofExpression*) base;
	result = TRUE;
	return result;
}

static void
bala_sizeof_expression_real_replace_type (BalaCodeNode* base,
                                          BalaDataType* old_type,
                                          BalaDataType* new_type)
{
	BalaSizeofExpression * self;
	BalaDataType* _tmp0_;
	BalaDataType* _tmp1_;
	self = (BalaSizeofExpression*) base;
	g_return_if_fail (old_type != NULL);
	g_return_if_fail (new_type != NULL);
	_tmp0_ = bala_sizeof_expression_get_type_reference (self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ == old_type) {
		bala_sizeof_expression_set_type_reference (self, new_type);
	}
}

static gboolean
bala_sizeof_expression_real_check (BalaCodeNode* base,
                                   BalaCodeContext* context)
{
	BalaSizeofExpression * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	BalaDataType* _tmp4_;
	BalaDataType* _tmp5_;
	BalaSemanticAnalyzer* _tmp6_;
	BalaSemanticAnalyzer* _tmp7_;
	BalaDataType* _tmp8_;
	gboolean _tmp9_;
	gboolean _tmp10_;
	gboolean result = FALSE;
	self = (BalaSizeofExpression*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	_tmp0_ = bala_code_node_get_checked ((BalaCodeNode*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_) {
		gboolean _tmp2_;
		gboolean _tmp3_;
		_tmp2_ = bala_code_node_get_error ((BalaCodeNode*) self);
		_tmp3_ = _tmp2_;
		result = !_tmp3_;
		return result;
	}
	bala_code_node_set_checked ((BalaCodeNode*) self, TRUE);
	_tmp4_ = bala_sizeof_expression_get_type_reference (self);
	_tmp5_ = _tmp4_;
	bala_code_node_check ((BalaCodeNode*) _tmp5_, context);
	_tmp6_ = bala_code_context_get_analyzer (context);
	_tmp7_ = _tmp6_;
	_tmp8_ = _tmp7_->ulong_type;
	bala_expression_set_value_type ((BalaExpression*) self, _tmp8_);
	_tmp9_ = bala_code_node_get_error ((BalaCodeNode*) self);
	_tmp10_ = _tmp9_;
	result = !_tmp10_;
	return result;
}

static void
bala_sizeof_expression_real_emit (BalaCodeNode* base,
                                  BalaCodeGenerator* codegen)
{
	BalaSizeofExpression * self;
	self = (BalaSizeofExpression*) base;
	g_return_if_fail (codegen != NULL);
	bala_code_visitor_visit_sizeof_expression ((BalaCodeVisitor*) codegen, self);
	bala_code_visitor_visit_expression ((BalaCodeVisitor*) codegen, (BalaExpression*) self);
}

static void
bala_sizeof_expression_class_init (BalaSizeofExpressionClass * klass,
                                   gpointer klass_data)
{
	bala_sizeof_expression_parent_class = g_type_class_peek_parent (klass);
	((BalaCodeNodeClass *) klass)->finalize = bala_sizeof_expression_finalize;
	g_type_class_adjust_private_offset (klass, &BalaSizeofExpression_private_offset);
	((BalaCodeNodeClass *) klass)->accept = (void (*) (BalaCodeNode*, BalaCodeVisitor*)) bala_sizeof_expression_real_accept;
	((BalaCodeNodeClass *) klass)->accept_children = (void (*) (BalaCodeNode*, BalaCodeVisitor*)) bala_sizeof_expression_real_accept_children;
	((BalaExpressionClass *) klass)->is_pure = (gboolean (*) (BalaExpression*)) bala_sizeof_expression_real_is_pure;
	((BalaExpressionClass *) klass)->is_constant = (gboolean (*) (BalaExpression*)) bala_sizeof_expression_real_is_constant;
	((BalaCodeNodeClass *) klass)->replace_type = (void (*) (BalaCodeNode*, BalaDataType*, BalaDataType*)) bala_sizeof_expression_real_replace_type;
	((BalaCodeNodeClass *) klass)->check = (gboolean (*) (BalaCodeNode*, BalaCodeContext*)) bala_sizeof_expression_real_check;
	((BalaCodeNodeClass *) klass)->emit = (void (*) (BalaCodeNode*, BalaCodeGenerator*)) bala_sizeof_expression_real_emit;
}

static void
bala_sizeof_expression_instance_init (BalaSizeofExpression * self,
                                      gpointer klass)
{
	self->priv = bala_sizeof_expression_get_instance_private (self);
}

static void
bala_sizeof_expression_finalize (BalaCodeNode * obj)
{
	BalaSizeofExpression * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_SIZEOF_EXPRESSION, BalaSizeofExpression);
	_bala_code_node_unref0 (self->priv->_data_type);
	BALA_CODE_NODE_CLASS (bala_sizeof_expression_parent_class)->finalize (obj);
}

/**
 * Represents a sizeof expression in the source code.
 */
static GType
bala_sizeof_expression_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaSizeofExpressionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_sizeof_expression_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaSizeofExpression), 0, (GInstanceInitFunc) bala_sizeof_expression_instance_init, NULL };
	GType bala_sizeof_expression_type_id;
	bala_sizeof_expression_type_id = g_type_register_static (BALA_TYPE_EXPRESSION, "BalaSizeofExpression", &g_define_type_info, 0);
	BalaSizeofExpression_private_offset = g_type_add_instance_private (bala_sizeof_expression_type_id, sizeof (BalaSizeofExpressionPrivate));
	return bala_sizeof_expression_type_id;
}

GType
bala_sizeof_expression_get_type (void)
{
	static volatile gsize bala_sizeof_expression_type_id__volatile = 0;
	if (g_once_init_enter (&bala_sizeof_expression_type_id__volatile)) {
		GType bala_sizeof_expression_type_id;
		bala_sizeof_expression_type_id = bala_sizeof_expression_get_type_once ();
		g_once_init_leave (&bala_sizeof_expression_type_id__volatile, bala_sizeof_expression_type_id);
	}
	return bala_sizeof_expression_type_id__volatile;
}

