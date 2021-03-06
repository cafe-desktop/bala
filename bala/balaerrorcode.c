/* balaerrorcode.c generated by balac, the Bala compiler
 * generated from balaerrorcode.bala, do not modify */

/* balaerrorcode.bala
 *
 * Copyright (C) 2008  Jürg Billeter
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

#define _bala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (bala_code_node_unref (var), NULL)))

struct _BalaErrorCodePrivate {
	BalaExpression* _value;
	BalaConstant* _code;
};

static gint BalaErrorCode_private_offset;
static gpointer bala_error_code_parent_class = NULL;

static void bala_error_code_set_code (BalaErrorCode* self,
                               BalaConstant* value);
static void bala_error_code_real_accept (BalaCodeNode* base,
                                  BalaCodeVisitor* visitor);
static void bala_error_code_real_accept_children (BalaCodeNode* base,
                                           BalaCodeVisitor* visitor);
static gboolean bala_error_code_real_check (BalaCodeNode* base,
                                     BalaCodeContext* context);
static void bala_error_code_finalize (BalaCodeNode * obj);
static GType bala_error_code_get_type_once (void);

static inline gpointer
bala_error_code_get_instance_private (BalaErrorCode* self)
{
	return G_STRUCT_MEMBER_P (self, BalaErrorCode_private_offset);
}

BalaExpression*
bala_error_code_get_value (BalaErrorCode* self)
{
	BalaExpression* result;
	BalaExpression* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_value;
	result = _tmp0_;
	return result;
}

static gpointer
_bala_code_node_ref0 (gpointer self)
{
	return self ? bala_code_node_ref (self) : NULL;
}

void
bala_error_code_set_value (BalaErrorCode* self,
                           BalaExpression* value)
{
	BalaExpression* _tmp0_;
	BalaExpression* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _bala_code_node_ref0 (value);
	_bala_code_node_unref0 (self->priv->_value);
	self->priv->_value = _tmp0_;
	_tmp1_ = self->priv->_value;
	if (_tmp1_ != NULL) {
		BalaExpression* _tmp2_;
		_tmp2_ = self->priv->_value;
		bala_code_node_set_parent_node ((BalaCodeNode*) _tmp2_, (BalaCodeNode*) self);
	}
}

BalaConstant*
bala_error_code_get_code (BalaErrorCode* self)
{
	BalaConstant* result;
	BalaConstant* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_code;
	result = _tmp0_;
	return result;
}

static void
bala_error_code_set_code (BalaErrorCode* self,
                          BalaConstant* value)
{
	BalaConstant* _tmp0_;
	BalaConstant* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _bala_code_node_ref0 (value);
	_bala_code_node_unref0 (self->priv->_code);
	self->priv->_code = _tmp0_;
	_tmp1_ = self->priv->_code;
	if (_tmp1_ != NULL) {
		BalaConstant* _tmp2_;
		BalaScope* _tmp3_;
		BalaScope* _tmp4_;
		_tmp2_ = self->priv->_code;
		_tmp3_ = bala_symbol_get_owner ((BalaSymbol*) self);
		_tmp4_ = _tmp3_;
		bala_symbol_set_owner ((BalaSymbol*) _tmp2_, _tmp4_);
	}
}

/**
 * Creates a new enum value.
 *
 * @param name enum value name
 * @return     newly created enum value
 */
BalaErrorCode*
bala_error_code_construct (GType object_type,
                           const gchar* name,
                           BalaSourceReference* source_reference,
                           BalaComment* comment)
{
	BalaErrorCode* self = NULL;
	g_return_val_if_fail (name != NULL, NULL);
	self = (BalaErrorCode*) bala_typesymbol_construct (object_type, name, source_reference, comment);
	return self;
}

BalaErrorCode*
bala_error_code_new (const gchar* name,
                     BalaSourceReference* source_reference,
                     BalaComment* comment)
{
	return bala_error_code_construct (BALA_TYPE_ERROR_CODE, name, source_reference, comment);
}

/**
 * Creates a new enum value with the specified numerical representation.
 *
 * @param name  enum value name
 * @param value numerical representation
 * @return      newly created enum value
 */
BalaErrorCode*
bala_error_code_construct_with_value (GType object_type,
                                      const gchar* name,
                                      BalaExpression* value,
                                      BalaSourceReference* source_reference)
{
	BalaErrorCode* self = NULL;
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (value != NULL, NULL);
	self = (BalaErrorCode*) bala_error_code_construct (object_type, name, source_reference, NULL);
	bala_error_code_set_value (self, value);
	return self;
}

BalaErrorCode*
bala_error_code_new_with_value (const gchar* name,
                                BalaExpression* value,
                                BalaSourceReference* source_reference)
{
	return bala_error_code_construct_with_value (BALA_TYPE_ERROR_CODE, name, value, source_reference);
}

static void
bala_error_code_real_accept (BalaCodeNode* base,
                             BalaCodeVisitor* visitor)
{
	BalaErrorCode * self;
	self = (BalaErrorCode*) base;
	g_return_if_fail (visitor != NULL);
	bala_code_visitor_visit_error_code (visitor, self);
}

static void
bala_error_code_real_accept_children (BalaCodeNode* base,
                                      BalaCodeVisitor* visitor)
{
	BalaErrorCode * self;
	BalaExpression* _tmp0_;
	BalaExpression* _tmp1_;
	self = (BalaErrorCode*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = bala_error_code_get_value (self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ != NULL) {
		BalaExpression* _tmp2_;
		BalaExpression* _tmp3_;
		_tmp2_ = bala_error_code_get_value (self);
		_tmp3_ = _tmp2_;
		bala_code_node_accept ((BalaCodeNode*) _tmp3_, visitor);
	}
}

static gboolean
bala_error_code_real_check (BalaCodeNode* base,
                            BalaCodeContext* context)
{
	BalaErrorCode * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	BalaExpression* _tmp4_;
	BalaExpression* _tmp5_;
	const gchar* _tmp8_;
	const gchar* _tmp9_;
	BalaSemanticAnalyzer* _tmp10_;
	BalaSemanticAnalyzer* _tmp11_;
	BalaDataType* _tmp12_;
	BalaDataType* _tmp13_;
	BalaDataType* _tmp14_;
	BalaSourceReference* _tmp15_;
	BalaSourceReference* _tmp16_;
	BalaComment* _tmp17_;
	BalaComment* _tmp18_;
	BalaConstant* _tmp19_;
	BalaConstant* _tmp20_;
	BalaConstant* _tmp21_;
	BalaConstant* _tmp22_;
	BalaConstant* _tmp23_;
	BalaConstant* _tmp24_;
	gboolean _tmp25_;
	gboolean _tmp26_;
	gboolean result = FALSE;
	self = (BalaErrorCode*) base;
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
	_tmp4_ = bala_error_code_get_value (self);
	_tmp5_ = _tmp4_;
	if (_tmp5_ != NULL) {
		BalaExpression* _tmp6_;
		BalaExpression* _tmp7_;
		_tmp6_ = bala_error_code_get_value (self);
		_tmp7_ = _tmp6_;
		bala_code_node_check ((BalaCodeNode*) _tmp7_, context);
	}
	_tmp8_ = bala_symbol_get_name ((BalaSymbol*) self);
	_tmp9_ = _tmp8_;
	_tmp10_ = bala_code_context_get_analyzer (context);
	_tmp11_ = _tmp10_;
	_tmp12_ = _tmp11_->int_type;
	_tmp13_ = bala_data_type_copy (_tmp12_);
	_tmp14_ = _tmp13_;
	_tmp15_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
	_tmp16_ = _tmp15_;
	_tmp17_ = bala_symbol_get_comment ((BalaSymbol*) self);
	_tmp18_ = _tmp17_;
	_tmp19_ = bala_constant_new (_tmp9_, _tmp14_, NULL, _tmp16_, _tmp18_);
	_tmp20_ = _tmp19_;
	bala_error_code_set_code (self, _tmp20_);
	_bala_code_node_unref0 (_tmp20_);
	_bala_code_node_unref0 (_tmp14_);
	_tmp21_ = bala_error_code_get_code (self);
	_tmp22_ = _tmp21_;
	bala_symbol_set_external ((BalaSymbol*) _tmp22_, TRUE);
	_tmp23_ = bala_error_code_get_code (self);
	_tmp24_ = _tmp23_;
	bala_code_node_check ((BalaCodeNode*) _tmp24_, context);
	_tmp25_ = bala_code_node_get_error ((BalaCodeNode*) self);
	_tmp26_ = _tmp25_;
	result = !_tmp26_;
	return result;
}

static void
bala_error_code_class_init (BalaErrorCodeClass * klass,
                            gpointer klass_data)
{
	bala_error_code_parent_class = g_type_class_peek_parent (klass);
	((BalaCodeNodeClass *) klass)->finalize = bala_error_code_finalize;
	g_type_class_adjust_private_offset (klass, &BalaErrorCode_private_offset);
	((BalaCodeNodeClass *) klass)->accept = (void (*) (BalaCodeNode*, BalaCodeVisitor*)) bala_error_code_real_accept;
	((BalaCodeNodeClass *) klass)->accept_children = (void (*) (BalaCodeNode*, BalaCodeVisitor*)) bala_error_code_real_accept_children;
	((BalaCodeNodeClass *) klass)->check = (gboolean (*) (BalaCodeNode*, BalaCodeContext*)) bala_error_code_real_check;
}

static void
bala_error_code_instance_init (BalaErrorCode * self,
                               gpointer klass)
{
	self->priv = bala_error_code_get_instance_private (self);
}

static void
bala_error_code_finalize (BalaCodeNode * obj)
{
	BalaErrorCode * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_ERROR_CODE, BalaErrorCode);
	_bala_code_node_unref0 (self->priv->_value);
	_bala_code_node_unref0 (self->priv->_code);
	BALA_CODE_NODE_CLASS (bala_error_code_parent_class)->finalize (obj);
}

/**
 * Represents an error value member in the source code.
 */
static GType
bala_error_code_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaErrorCodeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_error_code_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaErrorCode), 0, (GInstanceInitFunc) bala_error_code_instance_init, NULL };
	GType bala_error_code_type_id;
	bala_error_code_type_id = g_type_register_static (BALA_TYPE_TYPESYMBOL, "BalaErrorCode", &g_define_type_info, 0);
	BalaErrorCode_private_offset = g_type_add_instance_private (bala_error_code_type_id, sizeof (BalaErrorCodePrivate));
	return bala_error_code_type_id;
}

GType
bala_error_code_get_type (void)
{
	static volatile gsize bala_error_code_type_id__volatile = 0;
	if (g_once_init_enter (&bala_error_code_type_id__volatile)) {
		GType bala_error_code_type_id;
		bala_error_code_type_id = bala_error_code_get_type_once ();
		g_once_init_leave (&bala_error_code_type_id__volatile, bala_error_code_type_id);
	}
	return bala_error_code_type_id__volatile;
}

