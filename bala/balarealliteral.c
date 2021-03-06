/* balarealliteral.c generated by balac, the Bala compiler
 * generated from balarealliteral.bala, do not modify */

/* balarealliteral.bala
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
#include <stdlib.h>
#include <string.h>
#include <glib.h>

#define _g_free0(var) (var = (g_free (var), NULL))
#define _bala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (bala_code_node_unref (var), NULL)))

struct _BalaRealLiteralPrivate {
	gchar* _value;
};

static gint BalaRealLiteral_private_offset;
static gpointer bala_real_literal_parent_class = NULL;

static void bala_real_literal_real_accept (BalaCodeNode* base,
                                    BalaCodeVisitor* visitor);
static gboolean bala_real_literal_real_is_pure (BalaExpression* base);
static gchar* bala_real_literal_real_to_string (BalaCodeNode* base);
static gboolean bala_real_literal_real_check (BalaCodeNode* base,
                                       BalaCodeContext* context);
static void bala_real_literal_real_emit (BalaCodeNode* base,
                                  BalaCodeGenerator* codegen);
static void bala_real_literal_finalize (BalaCodeNode * obj);
static GType bala_real_literal_get_type_once (void);

static inline gpointer
bala_real_literal_get_instance_private (BalaRealLiteral* self)
{
	return G_STRUCT_MEMBER_P (self, BalaRealLiteral_private_offset);
}

const gchar*
bala_real_literal_get_value (BalaRealLiteral* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_value;
	result = _tmp0_;
	return result;
}

void
bala_real_literal_set_value (BalaRealLiteral* self,
                             const gchar* value)
{
	gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup (value);
	_g_free0 (self->priv->_value);
	self->priv->_value = _tmp0_;
}

/**
 * Creates a new real literal.
 *
 * @param r      literal value
 * @param source reference to source code
 * @return       newly created real literal
 */
BalaRealLiteral*
bala_real_literal_construct (GType object_type,
                             const gchar* r,
                             BalaSourceReference* source)
{
	BalaRealLiteral* self = NULL;
	g_return_val_if_fail (r != NULL, NULL);
	self = (BalaRealLiteral*) bala_literal_construct (object_type);
	bala_real_literal_set_value (self, r);
	bala_code_node_set_source_reference ((BalaCodeNode*) self, source);
	return self;
}

BalaRealLiteral*
bala_real_literal_new (const gchar* r,
                       BalaSourceReference* source)
{
	return bala_real_literal_construct (BALA_TYPE_REAL_LITERAL, r, source);
}

static void
bala_real_literal_real_accept (BalaCodeNode* base,
                               BalaCodeVisitor* visitor)
{
	BalaRealLiteral * self;
	self = (BalaRealLiteral*) base;
	g_return_if_fail (visitor != NULL);
	bala_code_visitor_visit_real_literal (visitor, self);
	bala_code_visitor_visit_expression (visitor, (BalaExpression*) self);
}

/**
 * Returns the type name of the value this literal represents.
 *
 * @return the name of literal type
 */
gchar*
bala_real_literal_get_type_name (BalaRealLiteral* self)
{
	gboolean _tmp0_ = FALSE;
	const gchar* _tmp1_;
	gchar* _tmp4_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp1_ = self->priv->_value;
	if (g_str_has_suffix (_tmp1_, "f")) {
		_tmp0_ = TRUE;
	} else {
		const gchar* _tmp2_;
		_tmp2_ = self->priv->_value;
		_tmp0_ = g_str_has_suffix (_tmp2_, "F");
	}
	if (_tmp0_) {
		gchar* _tmp3_;
		_tmp3_ = g_strdup ("float");
		result = _tmp3_;
		return result;
	}
	_tmp4_ = g_strdup ("double");
	result = _tmp4_;
	return result;
}

static gboolean
bala_real_literal_real_is_pure (BalaExpression* base)
{
	BalaRealLiteral * self;
	gboolean result = FALSE;
	self = (BalaRealLiteral*) base;
	result = TRUE;
	return result;
}

static gchar*
bala_real_literal_real_to_string (BalaCodeNode* base)
{
	BalaRealLiteral * self;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result = NULL;
	self = (BalaRealLiteral*) base;
	_tmp0_ = self->priv->_value;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}

static gboolean
bala_real_literal_real_check (BalaCodeNode* base,
                              BalaCodeContext* context)
{
	BalaRealLiteral * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	BalaStruct* st = NULL;
	BalaNamespace* _tmp4_;
	BalaNamespace* _tmp5_;
	BalaScope* _tmp6_;
	BalaScope* _tmp7_;
	gchar* _tmp8_;
	gchar* _tmp9_;
	BalaSymbol* _tmp10_;
	BalaStruct* _tmp11_;
	BalaStruct* _tmp12_;
	BalaStruct* _tmp13_;
	BalaFloatingType* _tmp14_;
	BalaFloatingType* _tmp15_;
	gboolean _tmp16_;
	gboolean _tmp17_;
	gboolean result = FALSE;
	self = (BalaRealLiteral*) base;
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
	_tmp4_ = bala_code_context_get_root (context);
	_tmp5_ = _tmp4_;
	_tmp6_ = bala_symbol_get_scope ((BalaSymbol*) _tmp5_);
	_tmp7_ = _tmp6_;
	_tmp8_ = bala_real_literal_get_type_name (self);
	_tmp9_ = _tmp8_;
	_tmp10_ = bala_scope_lookup (_tmp7_, _tmp9_);
	_tmp11_ = G_TYPE_CHECK_INSTANCE_CAST (_tmp10_, BALA_TYPE_STRUCT, BalaStruct);
	_g_free0 (_tmp9_);
	st = _tmp11_;
	_tmp12_ = st;
	bala_code_node_check ((BalaCodeNode*) _tmp12_, context);
	_tmp13_ = st;
	_tmp14_ = bala_floating_type_new (_tmp13_);
	_tmp15_ = _tmp14_;
	bala_expression_set_value_type ((BalaExpression*) self, (BalaDataType*) _tmp15_);
	_bala_code_node_unref0 (_tmp15_);
	_tmp16_ = bala_code_node_get_error ((BalaCodeNode*) self);
	_tmp17_ = _tmp16_;
	result = !_tmp17_;
	_bala_code_node_unref0 (st);
	return result;
}

static void
bala_real_literal_real_emit (BalaCodeNode* base,
                             BalaCodeGenerator* codegen)
{
	BalaRealLiteral * self;
	self = (BalaRealLiteral*) base;
	g_return_if_fail (codegen != NULL);
	bala_code_visitor_visit_real_literal ((BalaCodeVisitor*) codegen, self);
	bala_code_visitor_visit_expression ((BalaCodeVisitor*) codegen, (BalaExpression*) self);
}

static void
bala_real_literal_class_init (BalaRealLiteralClass * klass,
                              gpointer klass_data)
{
	bala_real_literal_parent_class = g_type_class_peek_parent (klass);
	((BalaCodeNodeClass *) klass)->finalize = bala_real_literal_finalize;
	g_type_class_adjust_private_offset (klass, &BalaRealLiteral_private_offset);
	((BalaCodeNodeClass *) klass)->accept = (void (*) (BalaCodeNode*, BalaCodeVisitor*)) bala_real_literal_real_accept;
	((BalaExpressionClass *) klass)->is_pure = (gboolean (*) (BalaExpression*)) bala_real_literal_real_is_pure;
	((BalaCodeNodeClass *) klass)->to_string = (gchar* (*) (BalaCodeNode*)) bala_real_literal_real_to_string;
	((BalaCodeNodeClass *) klass)->check = (gboolean (*) (BalaCodeNode*, BalaCodeContext*)) bala_real_literal_real_check;
	((BalaCodeNodeClass *) klass)->emit = (void (*) (BalaCodeNode*, BalaCodeGenerator*)) bala_real_literal_real_emit;
}

static void
bala_real_literal_instance_init (BalaRealLiteral * self,
                                 gpointer klass)
{
	self->priv = bala_real_literal_get_instance_private (self);
}

static void
bala_real_literal_finalize (BalaCodeNode * obj)
{
	BalaRealLiteral * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_REAL_LITERAL, BalaRealLiteral);
	_g_free0 (self->priv->_value);
	BALA_CODE_NODE_CLASS (bala_real_literal_parent_class)->finalize (obj);
}

/**
 * Represents a real literal in the source code.
 */
static GType
bala_real_literal_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaRealLiteralClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_real_literal_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaRealLiteral), 0, (GInstanceInitFunc) bala_real_literal_instance_init, NULL };
	GType bala_real_literal_type_id;
	bala_real_literal_type_id = g_type_register_static (BALA_TYPE_LITERAL, "BalaRealLiteral", &g_define_type_info, 0);
	BalaRealLiteral_private_offset = g_type_add_instance_private (bala_real_literal_type_id, sizeof (BalaRealLiteralPrivate));
	return bala_real_literal_type_id;
}

GType
bala_real_literal_get_type (void)
{
	static volatile gsize bala_real_literal_type_id__volatile = 0;
	if (g_once_init_enter (&bala_real_literal_type_id__volatile)) {
		GType bala_real_literal_type_id;
		bala_real_literal_type_id = bala_real_literal_get_type_once ();
		g_once_init_leave (&bala_real_literal_type_id__volatile, bala_real_literal_type_id);
	}
	return bala_real_literal_type_id__volatile;
}

